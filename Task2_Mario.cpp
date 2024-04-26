#include <iostream>

using namespace std;

bool marioWins(int n) {
    // Nếu số đồng tiền vàng là bội số của 4, quỷ dữ luôn thắng
    if (n % 4 == 0) {
        return false;
    }
    // Ngược lại, Mario thắng
    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        bool result = marioWins(n);
        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}