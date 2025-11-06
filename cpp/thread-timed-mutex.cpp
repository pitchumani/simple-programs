#include <iostream>
#include <mutex>
#include <thread>

std::timed_mutex mtx1;

void thread_func1() {
    if (mtx1.try_lock_for(std::chrono::seconds(1))) {
        std::cout << "Mutex locked within 1 second\n";
		mtx1.unlock();
    } else {
        std::cout << "Failed to lock Mutex within 1 second\n";
    }

	std::unique_lock<std::timed_mutex> lock(mtx1, std::defer_lock);
	if (lock.try_lock_for(std::chrono::milliseconds(200))) {
		std::cout << "Lock acquired within timeout\n";
	} else {
		std::cout << "Failed to acquire lock within timeout\n";
	}
    // unlocks at the end of scope
}

int main() {
	std::thread t1(thread_func1);
	t1.join();
	return 0;
}
