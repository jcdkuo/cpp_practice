// g++ function-pointer-callback.cpp -o a.out
#include <iostream>
#include <string>
using namespace std;

void keyevent(int keycode, int status) {
    cout << "keycode = " << keycode << " status = " << status << endl;
}

int main() {
    void (*callback_keyevent)(int, int) = NULL;
    callback_keyevent = keyevent;

    if (callback_keyevent)
        callback_keyevent(1, 0);

    return 0;
}

