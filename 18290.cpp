#include<iostream>
#include<vector>
using namespace std;
int n, m, k;
int board[11][11];
bool isused[11][11];
int ans = -987654321;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
void go(int px, int py, int cnt, int sum) {
	if (cnt == k) { ans = (sum > ans) ? sum : ans; return; }
	else {
		for (int i = px; i < n; ++i) {
			for (int j = (i == px ? py : 0); j < m; ++j) {
				if (isused[i][j] == true)continue;
				bool ok = true;
				for (int iter = 0; iter < 4; ++iter) {
					int nx = i + dx[iter]; int ny = j + dy[iter];
					if (!OOB(nx, ny) && isused[nx][ny] == true) {
						ok = false;
					}
				}
				if (ok == true) {
					isused[i][j] = true;
					go(i, j, cnt + 1, sum + board[i][j]);
					isused[i][j] = false;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			isused[i][j] = false;
		}
	}
	go(0, 0, 0, 0);
	cout << ans << "\n";
}//성공코드. 


#include<iostream>
#include<vector>
using namespace std;
int n, m, k;
int board[11][11];
bool isused[11][11];
int ans = -987654321;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
void go(int cnt, int sum) {
	if (cnt == k) { ans = (sum > ans) ? sum : ans;	return; }
	else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (isused[i][j] == true)continue;
				isused[i][j] = true;
				for (int iter = 0; iter < 4; ++iter) {
					int nx = i + dx[iter]; int ny = j + dy[iter];
					if (!OOB(nx, ny))isused[nx][ny] = true;
				}
				go(cnt + 1, sum + board[i][j]);
				isused[i][j] = false;
				for (int iter = 0; iter < 4; ++iter) {
					int nx = i + dx[iter]; int ny = j + dy[iter];
					if (!OOB(nx, ny))isused[nx][ny] = false;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			isused[i][j] = false;
		}
	}
	go(0, 0);
	cout << ans << "\n";
}// 초기 실패코드. 뭘 잘못했을까에 유의해서 코드를 다시봤다. 
//사용한 블럭이 근처에 있다는 정보와 내가 고른 블럭이 사용된 블럭 근처에 
//있다는 정보는 전혀 다른 결이다. 거기에 추가해
//다시 사용하지 않았다는 정보를 되돌려주면서 원래의 정보에 왜곡이 발생했다. 
//만약 1,1과 1,3을 고른다는 선택지는 같은 의미를 지닌다. 
//하지만 다음 탐색에서 1,3이 1,4의 선택으로 바뀌면 0,3, 1,2, 2,3, 1,4는 
//사용했다는 정보값이 없어진다. 여전히 1,2의 경우 사용할 수 없지만 이 점이 
//왜곡된다. 결국 선택할때마다 확실한 값을 탐색해 주는 것이 더 확실한 정보를 
//전달한다. 