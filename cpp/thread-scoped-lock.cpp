#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx1;
std::mutex mtx2;

void thread_func(int id) {
	std::cout << "Thread id: " << id << std::endl;
	std::scoped_lock lock(mtx1, mtx2);
	std::cout << id << ": Acquired lock for both mtx1 and mtx2" << std::endl;
	// lock released upon destruction
}

int main() {
	std::thread t1(thread_func, 1);
	std::thread t2(thread_func, 2);

	t1.join();
	t2.join();
	return 0;
}
