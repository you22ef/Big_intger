#include <iostream>
using namespace std;

bool bears(int x) {
    int product = (x % 10) * ((x / 10) % 10);
    if (x == 42) {
        return true;
    }
    else if (x < 42) {
        return false;
    }
    else if (x % 2 == 0 && bears(x / 2)) {
        cout << x << " is even and gives " << (x / 2) << '\n';
        return true;
    }
    else if (x % 5 == 0 && bears(x - 42)) {
        cout << x << " is divisible by 5 and gives " << (x - 42) << '\n';
        return true;
    }
    else if (product > 0 && (x % 4 == 0 || x % 3 == 0) && bears(x - product)) {
        if (x % 3 == 0) {
            cout << x << " is divisible by 3 and gives " << (x - product) << '\n';
        }
        else {
            cout << x << " is divisible by 4 and gives " << (x - product) << '\n';
        }
        return true;
    }
    return false;
}

int main() {
    int x;
    cout << "please enter number of bears: ";
    cin >> x;
    if (bears(x)) {
        cout << "it's possible to win :)";
    }
    else {
        cout << "it's not possible to win :(";
    }
}
