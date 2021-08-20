#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
tuple<int, int, int> bfs(vector<vector<int>>& a, int x, int y, int size) {
    int n = a.size();
    vector<tuple<int, int, int>> ans;
    vector<vector<int>> d(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    d[x][y] = 0;
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && d[nx][ny] == -1) {
                bool ok = false;
                bool eat = false;
                // 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
                if (a[nx][ny] == 0) {
                    ok = true;
                }
                else if (a[nx][ny] < size) { // 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 
                    ok = eat = true;
                }
                else if (a[nx][ny] == size) { // 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.
                    ok = true;
                }
                if (ok) {
                    q.push(make_pair(nx, ny));
                    d[nx][ny] = d[x][y] + 1;
                    if (eat) {
                        ans.push_back(make_tuple(d[nx][ny], nx, ny));
                    }
                }
            }
        }
    }
    if (ans.empty()) {
        return make_tuple(-1, -1, -1);
    }
    sort(ans.begin(), ans.end());
    return ans[0];
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                tie(x, y) = make_pair(i, j);
                a[i][j] = 0;
            }
        }
    }
    int ans = 0;
    int size = 2;
    int exp = 0;
    while (true) {
        int nx, ny, dist;
        tie(dist, nx, ny) = bfs(a, x, y, size);
        if (dist == -1) break;
        a[nx][ny] = 0;
        ans += dist;
        exp += 1;
        if (size == exp) {
            size += 1;
            exp = 0;
        }
        tie(x, y) = make_pair(nx, ny);
    }
    cout << ans << '\n';
    return 0;
}
/////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int map[21][21];
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
tuple<int, int, int> bfs(int x, int y, int body) {
    queue<tuple<int, int, int>> q;
    bool visited[21][21];
    q.push(make_tuple(x, y, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    }
    while (!q.empty()) {
        int xx, yy, sec;
        tie(xx, yy, sec) = q.front(); q.pop();
        if (map[xx][yy] != 0 && map[xx][yy] < body) {
            map[xx][yy] = 0;
            return make_tuple(xx, yy, sec);
        }
        for (int i = 0; i < 4; ++i) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (!OOB(nx, ny) && map[nx][ny] <= body && visited[nx][ny] == false) {
                q.push(make_tuple(nx, ny, sec + 1));
                //cout << nx << " " << ny << " " << sec << " ";
                visited[nx][ny] = true;
            }
        }

    }
    return make_tuple(-1, -1, 0);
}
int main() {
    cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                x = i; y = j;
            }
        }
    }
    int body = 2;
    int time = 0;

    while (1) {

        for (int i = 0; i < body; ++i) {

            int sec;
            tie(x, y, sec) = bfs(x, y, body);
            cout << x + 1 << " " << y + 1 << " " << sec << " " << body << " \n";
            if (y == -1) {
                cout << time << "\n";
                return 0;
            }
            time += sec;
        }
        body++;
    }
}

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
using namespace std;
int n;
int map[21][21];
int dist[21][21];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }
tuple<int, int, int> bfs(int x, int y, int size) {
    vector<tuple<int, int, int>> result;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = -1;
        }
    }
    q.push({ x,y });
    dist[x][y] = 0;
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        /*for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";*/
        for (int i = 0; i < 4; ++i) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (!OOB(nx, ny) && dist[nx][ny] == -1 && map[nx][ny] <= size) {
                //cout << nx << " " << ny << " " << "\n";
                if (map[nx][ny] == size || map[nx][ny] == 0) {
                    q.push({ nx,ny });
                    dist[nx][ny] = dist[xx][yy] + 1;
                }
                else {
                    q.push({ nx,ny });
                    dist[nx][ny] = dist[xx][yy] + 1;
                    result.push_back(make_tuple(dist[nx][ny], nx, ny));

                }
            }
        }
    }
    if (result.empty())return make_tuple(-1, -1, -1);
    sort(result.begin(), result.end());
    int rdis, rx, ry;
    tie(rdis, rx, ry) = result[0];
    map[rx][ry] = 0;
    return result[0];
}
int main() {
    int size = 2;
    int x, y, sum = 0, dis;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                x = i; y = j;
                map[x][y] = 0;
            }
        }
    }
    while (1) {

        for (int i = 0; i < size; ++i) {

            tie(dis, x, y) = bfs(x, y, size);
            //cout << x << " " << y << " " << dis << "\n";
            if (x == -1) {
                cout << sum << "\n";
                return 0;
            }
            sum += dis;
        }
        size += 1;
    }
}//솔브드. 가장먼저 찾은 고기가 가장 짧은 경로에 있을거라는 착각. 먹을 수 있는 고기를 다 간추린 다음
//그 중에 가장 가까운 놈을 찾는 것. 문제의 의도대로 구현할것. 철저히.