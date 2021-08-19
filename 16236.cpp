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
                // �Ʊ� ���� �ڽ��� ũ�⺸�� ū ����Ⱑ �ִ� ĭ�� ������ �� ����, ������ ĭ�� ��� ������ �� �ִ�.
                if (a[nx][ny] == 0) {
                    ok = true;
                }
                else if (a[nx][ny] < size) { // �Ʊ� ���� �ڽ��� ũ�⺸�� ���� ����⸸ ���� �� �ִ�. 
                    ok = eat = true;
                }
                else if (a[nx][ny] == size) { // ũ�Ⱑ ���� ������ ���� �� ������, �� ����Ⱑ �ִ� ĭ�� ������ �� �ִ�.
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