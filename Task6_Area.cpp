#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//dùng ma trận thu được dp để tính diện tích lớn nhất
int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    int n = heights.size();
    int maxArea = 0;

    for (int i = 0; i <= n; ++i) {
        while (!stk.empty() && (i == n || heights[stk.top()] > heights[i])) {
            int h = heights[stk.top()];
            stk.pop();
            int w = stk.empty() ? i : (i - stk.top() - 1);
            maxArea = max(maxArea, h * w);
        }
        stk.push(i);
    }

    return maxArea;
}

int main() {
    int N, M;
    cin >> N;
    cin >> M;

    // Nhập ma trận đất
    vector<vector<int>> land(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> land[i][j];
        }
    }

    // Khởi tạo ma trận dp
    vector<int> dp(M, 0);
    int maxArea = 0;

    // Duyệt qua từng hàng của ma trận đất
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            //cập nhật chiều cao vào ma trận dp
            if (land[i][j] == 1) {
                dp[j] = (i == 0) ? 1 : (dp[j] + 1);
            } else {
                dp[j] = 0;
            }
        }
        maxArea = max(maxArea, largestRectangleArea(dp));
    }

    cout << maxArea << endl;

    return 0;
}