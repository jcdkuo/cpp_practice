#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

void work(int &count, std::mutex &mtx) {
    for (int i = 0; i < 1E6; i++) {
        mtx.lock();
        ++count;
        mtx.unlock();
    }
}

int main() {

    int count = 0;
    std::mutex mtx;

    std::thread t1(work, std::ref(count), std::ref(mtx));
    std::thread t2(work, std::ref(count), std::ref(mtx));

    t1.join();
    t2.join();

    std::cout << count << std::endl;

    return 0;
}
