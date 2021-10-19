#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int main() {

    int count = 0;
    const int ITERATIONS = 1E6;
    std::mutex mtx;

    auto func = [&](){
        for (int i = 0; i < ITERATIONS; i++) {
            mtx.lock();
            ++count;
            mtx.unlock();
        }
    };

    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();

    std::cout << count << std::endl;

    return 0;
}
