#include <iostream>
#include <cmath>

using namespace std;

// hàm đệ quy, tham số thời điểm n và vị trí k 
char getCell(int n, int k) {
    // Nếu n = 1, thời điểm ban đầu tế bào = X
    if (n == 1) {
        return 'X';
    }

    // 2 mũ (n-1), tương đương với số lượng tế bào tại thời điểm n.
    int totalCells = pow(2, n - 1);
    //chia số lượng tế bào tìm vị trí giữa
    int middle = totalCells / 2;
    // nếu k nằm phía trái gọi đệ quy từ k
    if (k <= middle) {
        // Gọi đệ quy về thời điểm trước đó (n -1) và vị trí K
        return getCell(n - 1, k);
    } else { 
        // nếu k nằm phía phải gọi đệ vị trí trong nửa phải còn lại
        char cell = getCell(n - 1, k - middle);
        if (cell == 'X') {
            return 'Y';
        } else {
            return 'X';
        }
    }
}


int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        char result = getCell(n, k);
        cout << result << endl;
    }

    return 0;
}
