#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Hàm tính số cách trồng hoa theo yêu cầu đề bài
long long countWaysToPlantFlowers(int N) {
    vector<vector<long long>> dp(N + 1, vector<long long>(5, 0));

    // Bước cơ sở: Khởi tạo dp[1][0..4] = 1
    for (int i = 0; i < 5; ++i) {
        dp[1][i] = 1;
    }

    // Lặp qua các vị trí từ 2 đến N
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][3] = (dp[i - 1][1] + dp[i - 1][4]) % MOD;
        dp[i][4] = (dp[i - 1][0] + dp[i - 1][3]) % MOD;
    }

    // Tính tổng kết quả
    long long result = 0;
    for (int i = 0; i < 5; ++i) {
        result = (result + dp[N][i]) % MOD;
    }

    return result;
}

int main() {
    int N;
    cout << "Nhap so luong hoa N: ";
    cin >> N;

    // Tính số cách trồng hoa và in ra kết quả
    long long ways = countWaysToPlantFlowers(N);
    cout << "So cach trong hoa la: " << ways << endl;

    return 0;
}
