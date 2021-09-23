#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, k;
int map[1001][1001] = { {0,} };
bool visit[1001][1001][11];
int ans = 987654321;
bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}
int main() {

    queue<pair<pair<int, int>, pair<int, int>>> move;
    //ff=x, fs=y, sf = step, ss=break wall
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            map[i][j] = (int)s[j] - 48;
        }
    }

    move.push({ {0,0},{1,0} });
    visit[0][0][0] = true;
    while (!move.empty()) {
        int x = move.front().first.first;
        int y = move.front().first.second;
        int step = move.front().second.first;
        int brk = move.front().second.second;

        move.pop();
        if (x == n - 1 && y == m - 1) {
            ans = min(ans, step);
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!OOB(nx, ny) && map[nx][ny] == 0 && visit[nx][ny][brk] == false) {
                move.push({ { nx,ny }, { step + 1,brk } });

                visit[nx][ny][brk] = true;
            }
            if (!OOB(nx, ny) && map[nx][ny] == 1 && brk < k && visit[nx][ny][brk] == false && (step % 2) == 1) {
                move.push({ { nx,ny }, { step + 1,brk + 1 } });

                visit[nx][ny][brk + 1] = true;
            }
            if (!OOB(nx, ny) && map[nx][ny] == 1 && brk < k && visit[nx][ny][brk] == false && (step % 2) == 0) {
                move.push({ { x,y }, { step + 1,brk} });
            }
        }
    }
    if (ans == 987654321) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << "\n";
    return 0;
}//메모리 초과 코드. 무턱대고 큐에 집어넣는것이 좋지 않았다. 

#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
#include <cstring>
using namespace std;
int a[1000][1000];
int d[1000][1000][11][2];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main() {
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    queue<tuple<int, int, int, int>> q;
    d[0][0][0][0] = 1;
    q.push(make_tuple(0, 0, 0, 0));
    while (!q.empty()) {
        int x, y, z, night;
        tie(x, y, z, night) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == 0 && d[nx][ny][z][1 - night] == 0) {
                d[nx][ny][z][1 - night] = d[x][y][z][night] + 1;
                q.push(make_tuple(nx, ny, z, 1 - night));
            }
            if (night == 0 && z + 1 <= l && a[nx][ny] == 1 && d[nx][ny][z + 1][1 - night] == 0) {
                d[nx][ny][z + 1][1 - night] = d[x][y][z][night] + 1;
                q.push(make_tuple(nx, ny, z + 1, 1 - night));
            }
        }
        if (d[x][y][z][1 - night] == 0) {
            d[x][y][z][1 - night] = d[x][y][z][night] + 1;
            q.push(make_tuple(x, y, z, 1 - night));
        }
    }
    int ans = -1;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i <= l; i++) {
            if (d[n - 1][m - 1][i][j] == 0) continue;
            if (ans == -1) {
                ans = d[n - 1][m - 1][i][j];
            }
            else if (ans > d[n - 1][m - 1][i][j]) {
                ans = d[n - 1][m - 1][i][j];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}//백준의 해결법은 밤의 변수까지 배열에 넣어서 컨트롤하는 것. 이 경우 위치와 벽을 뚫은 횟수를 고정하고 시간만 밤으로 바꿔준다.


#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int n, m, k;
int map[1001][1001];
int visit[1001][1001][11][2];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
int main() {
    memset(visit, -1, sizeof(visit));
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            map[i][j] = s[j] - '0';
        }
    }


    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(0, 0, 0, 0));//0==day, 1==night;
    visit[0][0][0][0] = 1;
    int ans = 987654321;
    while (!q.empty()) {
        int x, y, brk, bri;
        tie(x, y, brk, bri) = q.front(); q.pop();
        if (x == n - 1 && y == m - 1) {
            ans = min(ans, visit[x][y][brk][bri]);
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i]; int ny = y + dy[i]; int nbri = (bri + 1) % 2;
            if (!OOB(nx, ny) && map[nx][ny] == 0 && visit[nx][ny][brk][nbri] == -1) {
                q.push(make_tuple(nx, ny, brk, nbri));
                visit[nx][ny][brk][nbri] = visit[x][y][brk][bri] + 1;
            }
            else if (!OOB(nx, ny) && map[nx][ny] == 1 && visit[nx][ny][brk + 1][nbri] == -1 && bri == 0 && brk < k) {
                q.push(make_tuple(nx, ny, brk + 1, nbri));
                visit[nx][ny][brk + 1][nbri] = visit[x][y][brk][bri] + 1;
            }
            else if (!OOB(nx, ny) && map[nx][ny] == 1 && visit[x][y][brk][nbri] == -1 && bri == 1 && brk < k) {
                q.push(make_tuple(x, y, brk, nbri));
                visit[x][y][brk][nbri] = visit[x][y][brk][bri] + 1;
            }
        }
    }
    if (ans == 987654321) { cout << -1 << "\n"; return 0; }
    cout << ans << "\n"; return 0;
}//솔브코드! 방법을 기억해서 시도해봤지만 몇번 실패가 있었다. 
//여기에서 중요한 것은, 확인하는 부분과 실제로 가는 부분을 일치시켜 주는 것이었다. 
/*
else if (!OOB(nx, ny) && map[nx][ny] == 1 && visit[nx][ny][brk+1][bri] == -1 && bri == 1 && brk < k) {
                q.push(make_tuple(nx, ny, brk+1, bri));
                visit[nx][ny][brk+1][bri] = visit[x][y][brk][bri] + 2;
            }
            이게 메모리 초과가 난 코드의 마지막 부분이었다. 자기가 갈 곳이 아니라 '앞으로'갈 곳을 확인하고 있었다.
            최대한 동작을 단순하게 설계할 것.


*/