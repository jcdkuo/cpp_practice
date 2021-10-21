#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

class App
{
private:
  int count_ = 0;
  std::mutex mtx_;

public:
  void operator()() {
    for (int i = 0; i < 1E6; i++) {
      std::lock_guard<std::mutex> guard(mtx_);
      ++count_;
    }
  }

  int getCount() { return count_; }
};

int main() {

  App app;

  std::thread t1(std::ref(app));
  std::thread t2(std::ref(app));

  t1.join();
  t2.join();

  std::cout << app.getCount() << std::endl;

  return 0;
}

