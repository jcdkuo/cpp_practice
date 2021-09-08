#include <iostream>       // std::cout
#include <thread> 
#include <chrono> 

int enable = 1;

void foo(){
  while( enable == 1 ){
    // do something
    std::cout << "hello" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5)); // this function holds the foo execution for 60 sec
  }

  std::cout << "go to die" << std::endl;
}

void qoo() {

    std::this_thread::sleep_for(std::chrono::seconds(15));
    enable = 0;
}

int main(){
    std::thread th(foo);
    std::thread ty(qoo);

    std::cout << "outside" << std::endl;

//    th.join();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout << "hihi" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(50));

    std::cout << "ready to close" << std::endl;

//    enable = 0;

//    std::thread th(qoo);
//    th.join();
}

