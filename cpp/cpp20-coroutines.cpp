#include <iostream>
#include <coroutine>

template <typename T>
struct Generator {
	struct promise_type {
		T value_;
		std::suspend_always yield_value(T value) {
			value_ = value;
			return {};
		}
		std::suspend_always initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		Generator get_return_object() {
			return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
		}
		void unhandled_exception() { std::terminate(); }
	};

	std::coroutine_handle<promise_type> h_;

	explicit Generator(std::coroutine_handle<promise_type> h) : h_(h) {}
	~Generator() {
		if (h_) {
			h_.destroy();
		}
	}

	T next() {
		h_.resume();
		return h_.promise().value_;
	}
};

Generator<int> fibonacci() {
	int a = 0, b = 1;
	while (true) {
		co_yield a;
		int next_fib = a + b;
		a = b;
		b = next_fib;
	}
}

int main() {
	Generator<int> gen = fibonacci();
	for (int i = 0; i < 100; ++i) {
		std::cout << gen.next() << " ";
	}
	std::cout << std::endl;
	return 0;
}
