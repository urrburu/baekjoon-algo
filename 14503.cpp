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
    // a[x][y] == 0 (û������ ���� ����)
    // a[x][y] == 1 (��)
    // a[x][y] == 2 (û���� ����)
    while (true) {
        if (a[x][y] == 0) {
            // 1. ���� ��ġ�� û���Ѵ�.
            a[x][y] = 2;
        }
        // 2-3, 2-4. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ���
        if (a[x + 1][y] != 0 && a[x - 1][y] != 0 && a[x][y - 1] != 0 && a[x][y + 1] != 0) {
            if (a[x - dx[dir]][y - dy[dir]] == 1) {
                // 2-4. ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
                break;
            }
            else {
                // 2-3. �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
                x -= dx[dir];
                y -= dy[dir];
            }
        }
        else {
            // 2-1. ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ����
            // 2-2. ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.

            dir = (dir + 3) % 4;
            if (a[x + dx[dir]][y + dy[dir]] == 0) {
                // 2-1. �� ĭ�� �����ϰ� 1������ �����Ѵ�.
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
}///�� ���� �ڵ� �ϼ�