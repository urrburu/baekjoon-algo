#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int board[51][51];
int board_copy[51][51];
int l, r;
bool OOB(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= n;
}
bool check(int x, int y, int nx, int ny) {
    int sub = abs(board[x][y] - board[nx][ny]);
    return sub >= l && sub <= r;
}
bool board_check() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != board_copy[i][j])return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            board_copy[i][j] = board[i][j];
        }
    }
    int time = 0;
    while (1) {


        bool visit[51][51];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                visit[i][j] = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<pair<int, int>> member;
                if (visit[i][j] == false) {
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    member.push_back({ i,j });
                    visit[i][j] = true;
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (visit[nx][ny] == false && !OOB(nx, ny) && check(x, y, nx, ny)) {
                                q.push({ nx,ny });
                                member.push_back({ nx,ny });
                                visit[nx][ny] = true;
                            }
                        }
                    }

                    int sum = 0;
                    for (int i = 0; i < member.size(); ++i) {
                        sum += board[member[i].first][member[i].second];
                    }
                    int aver = sum / member.size();
                    for (int i = 0; i < member.size(); ++i) {
                        board_copy[member[i].first][member[i].second] = aver;
                    }
                }



            }
        }
        if (board_check() == false) {
            cout << time << "\n";
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = board_copy[i][j];
            }
        }
        time++;
    }

}


//solved

//아래는 백준 풀이
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool bfs(vector<vector<int>>& a, int l, int r) {
    int n = a.size();
    vector<vector<bool>> c(n, vector<bool>(n, false));
    bool ok = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] == false) {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                c[i][j] = true;
                stack<pair<int, int>> s;
                s.push(make_pair(i, j));
                int sum = a[i][j];
                while (!q.empty()) {
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                            if (c[nx][ny]) continue;
                            int diff = a[nx][ny] - a[x][y];
                            if (diff < 0) diff = -diff;
                            if (l <= diff && diff <= r) {
                                q.push(make_pair(nx, ny));
                                s.push(make_pair(nx, ny));
                                c[nx][ny] = true;
                                ok = true;
                                sum += a[nx][ny];
                            }
                        }
                    }
                }
                int val = sum / s.size();
                while (!s.empty()) {
                    int x, y;
                    tie(x, y) = s.top();
                    s.pop();
                    a[x][y] = val;
                }
            }
        }
    }
    return ok;
}
int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    while (true) {
        if (bfs(a, l, r)) {
            ans += 1;
        }
        else {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
