#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int N, int K, vector<int>& projects) {
    int totalProfit = 0;
    int consecutiveCount = 0;

    for (int i = 0; i < N; ++i) {
        if (consecutiveCount == K) {
            consecutiveCount = 0; // Đặt lại biến đếm khi đã chọn K dự án liên tiếp
            continue; // Bỏ qua dự án khi đã chọn K dự án liên tiếp
        }

        totalProfit += projects[i];
        consecutiveCount++;
    }

    return totalProfit;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> projects(N);
    for (int i = 0; i < N; ++i) {
        cin >> projects[i];
    }

    int result = maxProfit(N, K, projects);
    cout << result << endl;

    return 0;
}
