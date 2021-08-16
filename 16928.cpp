#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int route[101];
bool visit[101];
int main() {
    int n, m; cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 1; i <= 100; ++i) {
        route[i] = i;
    }
    for (int i = 0; i < n + m; ++i) {
        int x; int y; cin >> x >> y;
        route[x] = y;
    }
    q.push({ 1,0 });
    while (!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (x == 100) {
            cout << cnt << "\n";
            return 0;
        }
        for (int i = 1; i <= 6; ++i) {
            int nx = x + i;
            if (nx > 100)continue;
            nx = route[nx];
            if (visit[nx] == false) {
                q.push({ nx, cnt + 1 });
                visit[nx] = true;
            }
        }
    }


}