#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
int r, c, d;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int map[51][51];
bool visit[51][51];
void print() {
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << map[i][j] << " ";

        }
        cout << "\n";
    }
    cout << "\n";*/
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << visit[i][j] << " ";

        }
        cout << "\n";
    }
    cout << "\n";
}
int turndir(int dir) {
    if (dir > 0)return --dir;
    return 3;
}
void clean(int i, int j, int dir) {
    visit[i][j] = true;
    int d = dir;
    int x = i;
    int y = j;
    while (1) {
        for (int i = 0; i < 4; ++i, d = turndir(d)) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (map[nx][ny] == 0 && visit[nx][ny] == false) {
                //print();

                clean(nx, ny, d);
                //print();
            }

        }
        int back = turndir(turndir(d));
        x = x + dx[back];
        y = y + dy[back];
        cout << x << " " << y << " " << "\n";
        if (map[x][y] == 1)return;
    }
}

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    clean(r, c, d);
    int area = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visit[i][j] == true)area++;
        }
    }
    cout << area << "\n";
}

#include <iostream>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int a[55][55];
int main() {
    int n, m;
    cin >> n >> m;
    int x, y, dir;
    cin >> x >> y >> dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    // a[x][y] == 0 (청소하지 않은 공간)
    // a[x][y] == 1 (벽)
    // a[x][y] == 2 (청소한 공간)
    while (true) {
        if (a[x][y] == 0) {
            // 1. 현재 위치를 청소한다.
            a[x][y] = 2;
        }
        // 2-3, 2-4. 네 방향 모두 청소가 이미 되어있거나 벽인 경우
        if (a[x + 1][y] != 0 && a[x - 1][y] != 0 && a[x][y - 1] != 0 && a[x][y + 1] != 0) {
            if (a[x - dx[dir]][y - dy[dir]] == 1) {
                // 2-4. 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
                break;
            }
            else {
                // 2-3. 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
                x -= dx[dir];
                y -= dy[dir];
            }
        }
        else {
            // 2-1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음
            // 2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.

            dir = (dir + 3) % 4;
            if (a[x + dx[dir]][y + dy[dir]] == 0) {
                // 2-1. 한 칸을 전진하고 1번부터 진행한다.
                x += dx[dir];
                y += dy[dir];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 2) {
                cnt += 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, m;
int r, c, d;
int room[55][55];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[55][55] = { false, };
int change_dir(int dir) { return (dir + 3) % 4; }
int main() {
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> room[i][j];
        }
    }
    while (1) {
        visit[r][c] = true;
        int i = 0;
        for (i = 0; i < 4; ++i) {
            d = change_dir(d);
            int nx = r + dx[d];	int ny = c + dy[d];
            if (visit[nx][ny] == false && room[nx][ny] == 0) {
                r = nx; c = ny; break;
            }
        }
        if (i == 4) { r = r - dx[d]; c = c - dy[d]; }
        if (room[r][c] == 1) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (visit[i][j] == true)cnt++;
                }
            }
            cout << cnt << "\n";
            return 0;
        }
    }
}///더 나은 코드 완성