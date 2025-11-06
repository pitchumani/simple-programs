#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
std::vector<int> list;
std::mutex mtx1;


void thread_func1() {
     // create lock, locks the mutex mtx1
    std::lock_guard<std::mutex> lock(mtx1);
    list.push_back(12);
    // unlocking the mutex is not required, it is automatic
}

void thread_func2() {
    // create lock, locks the mutex mtx1
    std::unique_lock<std::mutex> lock(mtx1);
    list.push_back(12);
    lock.unlock();  // optional, unlocked at the end of scope
}

void thread_func3() {
    // create the lock WITHOUT locking the mutex
    std::unique_lock<std::mutex> lock(mtx1, std::defer_lock);
    std::cout << "Statement is executed without locking the mutex\n";
    lock.lock();  // lock the mutex
    // do something
    lock.unlock();
    // do something
}

int main() {
    std::thread t1(thread_func1);
    std::thread t2(thread_func2);
    std::thread t3(thread_func3);
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
