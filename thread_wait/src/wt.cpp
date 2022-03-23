#include <iostream>
#include <thread>


void work(int &count, std::mutex &mtx) {
    for (int i = 0; i < 1E6; i++) {
        // unique_lock can also be used
        std::lock_guard<std::mutex> guard(mtx);
        ++count;
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
