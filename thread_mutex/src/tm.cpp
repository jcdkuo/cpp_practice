#include <iostream>
#include <thread>

int main() {

    int count = 0;
    const int ITERATIONS = 1E6;

    std::thread t1([&count](){
        for (int i = 0; i < ITERATIONS; i++) {
            ++count;
        }
    });

    std::thread t2([&count](){
        for (int i = 0; i < ITERATIONS; i++) {
            ++count;
        }
    });

    t1.join();
    t2.join();

    std::cout << count << std::endl;

    return 0;
}
