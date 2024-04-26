#include <iostream>
#include <vector>

using namespace std;

//tạo ds lưu đồ thị
vector<vector<int>> graph;
vector<bool> visited; // trạng thái của đỉnh

//đánh dấu các đỉnh
void dfs(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int N, M;
    cin >> N;
    cin >> M;

    graph.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //Vì N máy cần ít nhất N-1 dây để liên kết
    if(M >= (N-1)){
        int components = 0;
        //duyệt qua các đỉnh, nếu chưa xét thì gọi hàm dfs
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                dfs(i);
                components++;
            }
        }
        //nếu có n tplt thì ta cần thay đổi n-1 dây để có thể liên thông hết
        int cables_needed = components - 1;
        cout << cables_needed << endl;
    }else 
    {
        cout << -1 << endl;
    }

    return 0;
}
