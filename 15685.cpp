#include<iostream>

using namespace std;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int board[101][101];
bool check(int x, int y) {
    if (board[x][y] != 0 && board[x + 1][y] != 0 && board[x][y + 1] != 0 && board[x + 1][y + 1] != 0)return true;
    return false;
}
int main() {
    int n;
    int x, y, d, g;
    while (n--) {
        cin >> x >> y >> d >> g;
        for (int i = 0; i < g; ++i) {


        }
    }




}
//실패코드


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool c[101][101];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
vector<int> curve(int x, int y, int dir, int gen) {
    vector<int> ans = { dir };
    for (int g = 1; g <= gen; g++) {
        vector<int> temp(ans);
        reverse(temp.begin(), temp.end());
        for (int& i : temp) {
            i = (i + 1) % 4;
        }
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, y, dir, gen;
        cin >> y >> x >> dir >> gen;
        vector<int> dirs = curve(x, y, dir, gen);
        c[x][y] = true;
        for (int d : dirs) {
            x += dx[d];
            y += dy[d];
            c[x][y] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 99; i++) {
        for (int j = 0; j <= 99; j++) {
            if (c[i][j] && c[i][j + 1] && c[i + 1][j] && c[i + 1][j + 1]) {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}