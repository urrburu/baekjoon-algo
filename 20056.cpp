#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int dy[] = { 0,1,1,1,0,-1,-1,-1,0 };
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int n;
struct fire_ball
{
    int m;
    int s;
    int d;

};
vector<fire_ball> balllist;
fire_ball field[51][51];
int main() {


    for (int i = 0; i < n; i++) {

    }
}
#include <iostream>
#include <vector>
using namespace std;
struct Shark {
    int m, s, d;
};
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<Shark>>> a(n, vector<vector<Shark>>(n));
    for (int i = 0; i < m; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        r -= 1;
        c -= 1;
        a[r][c].push_back(Shark({ m,s,d }));
    }
    for (int l = 0; l < k; l++) {
        vector<vector<vector<Shark>>> b(n, vector<vector<Shark>>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (auto shark : a[i][j]) {
                    int x = i + dx[shark.d] * shark.s;
                    int y = j + dy[shark.d] * shark.s;
                    x = (x % n + n) % n;
                    y = (y % n + n) % n;
                    b[x][y].push_back(shark);
                }
            }
        }
        a = b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j].size() > 1) {
                    int total_m = 0;
                    int total_s = 0;
                    int cnt = a[i][j].size();
                    int compare_d = a[i][j][0].d % 2;
                    int result_d = 0;
                    for (auto shark : a[i][j]) {
                        if (shark.d % 2 != compare_d) {
                            result_d = 1;
                        }
                        total_m += shark.m;
                        total_s += shark.s;
                    }
                    a[i][j].clear();
                    int shark_m = total_m / 5;
                    int shark_s = total_s / cnt;
                    if (shark_m > 0) {
                        for (int dir = 0; dir < 4; dir++) {
                            a[i][j].push_back(Shark({ shark_m,shark_s,dir * 2 + result_d }));
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto shark : a[i][j]) {
                ans += shark.m;
            }
        }
    }
    cout << ans << endl;
    return 0;
}