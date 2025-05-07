#include <iostream>
#include <thread>

void count10() {
    std::cout << "Executing a function..." << std::endl;
    int i = 10;
    while (i) { std::cout << ".." << i--; } 
}

void countN(int arg) {
    std::cout << "Executing a function with argument..." << std::endl;
    while (arg) { std::cout << ".." << arg--; } 
}

int main() {
    // thread with a function
    std::thread thread1(count10);
    // thread with a function that has an argument
    std::thread thread2(countN, 8);
    // thread with a lambda function
    std::thread thread3([](int arg) -> void {
        std::cout << "Executing task using lambda function" << std::endl;
        while (arg) {
            std::cout << ".." << arg--;
        }
    }, 5);

    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << std::endl << "All tasks are completed." << std::endl;

    return 0;
}

