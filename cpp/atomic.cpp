
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic_int acnt;
int cnt;

void foo() {
	for (auto n{1000}; n; --n) {
		acnt++;
		cnt++;
	}
}

int main() {
	{   // create block scope
		std::vector<std::jthread> pool;
		for (auto n = 0; n < 10; ++n) {
			pool.emplace_back(foo);
		}
	}   // jthreads are joined upon destruction at the end of scope
	std::cout << "The atomic counter is: " << acnt << std::endl;
	std::cout << "The non-atomic counter is: " << cnt << std::endl;
	
	return 0;
}

/*
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
 
std::atomic_int acnt;
int cnt;
 
void f()
{
    for (auto n{10000}; n; --n)
    {
        ++acnt;
        ++cnt;
        // Note: for this example, relaxed memory order is sufficient,
        // e.g. acnt.fetch_add(1, std::memory_order_relaxed);
    }
}
 
int main()
{
    {
        std::vector<std::jthread> pool;
        for (int n = 0; n < 10; ++n)
            pool.emplace_back(f);
    }
 
    std::cout << "The atomic counter is " << acnt << '\n'
              << "The non-atomic counter is " << cnt << '\n';
}
*/
