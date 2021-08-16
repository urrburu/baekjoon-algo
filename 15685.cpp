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

#include<iostream>
#include<vector>

using namespace std;
bool map[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int turn_dir(int dir) {
	return (dir + 1) % 4;
}
int main() {
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		int dir;
		int gen;
		vector<int> d;

		cin >> x >> y >> dir >> gen;
		d.push_back(dir);
		for (int j = 0; j < gen; ++j) {
			int s = d.size();
			for (int k = d.size() - 1; k >= 0; --k) {
				d.push_back(turn_dir(d[k]));
			}
		}
		map[x][y] = true;
		for (int j = 0; j < d.size(); ++j) {
			//cout << d[j] << " ";
			x = x + dx[d[j]];
			y = y + dy[d[j]];
			if (x >= 0 && x < 101 && y >= 0 && y < 101) {
				map[x][y] = true;
			}

		}
		//cout << "\n ";
		/*for (int i = 0; i < 101; ++i) {
			for (int j = 0; j < 101; ++j) {
				if (map[i][j] == true) {
					cout << 1 << " ";
				}
				else {
					cout << 0 << " ";
				}
			}
			cout << "\n";
		}
		cout << "\n";*/
	}
	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j) {
			if (map[i][j] == true && map[i + 1][j] == true && map[i][j + 1] == true && map[i + 1][j + 1] == true) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
}