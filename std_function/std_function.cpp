// g++ std-function-callback.cpp -o a.out -std=c++11
#include <iostream>
#include <string>
#include <functional>
using namespace std;

void keyevent(int keycode, int status) {
    cout << "keycode = " << keycode << " status = " << status << endl;
}

int main() {
    std::function<void(int, int)> callback_keyevent = nullptr;
    callback_keyevent = keyevent;

    if (callback_keyevent)
        callback_keyevent(1, 0);

    return 0;
}

