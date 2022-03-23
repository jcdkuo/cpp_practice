#include <iostream>
#include <thread>
#include <chrono>
#include <future>

int fib(int n) {
    if (n<3) return 1;
    else return fib(n-1) + fib(n-2);
}

int main() {

    std::future<int> f1 = std::async(std::launch::async, [](){
        std::this_thread::sleep_for(std::chrono::seconds(15));
        return fib(20);
    });

    std::future<int> f2 = std::async(std::launch::async, [](){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return fib(25);
    });

    std::cout << "waiting...\n";
    f1.wait();
    f2.wait();

    std::cout << "f1:" << f1.get() << '\n';
    std::cout << "f2:" << f2.get() << '\n';
    
    return 0;
}

