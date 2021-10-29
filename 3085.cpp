#include<iostream>
#include<algorithm>
using namespace std;

int N;
char Board[55][55];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int ans = 0;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= N || y >= N; }
void Check() {
	int Max_length = 0;
	for (int i = 0; i < N; ++i) {
		int length = 1; int left = 0, right = 0;
		while (right < N) {
			if (Board[i][left] == Board[i][right]) {
				Max_length = max(length, Max_length);
				right++; length++;
			}
			else {
				left = right; length = 1;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		int length = 1; int left = 0, right = 0;
		while (right < N) {
			if (Board[left][i] == Board[right][i]) {
				Max_length = max(length, Max_length);
				right++; length++;
			}
			else {
				left = right; length = 1;
			}
		}
	}
	ans = max(ans, Max_length);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s; cin >> s;
		for (int j = 0; j < N; ++j) {
			Board[i][j] = s[j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int Tar = 0; Tar < 4; ++Tar) {
				int nx = i + dx[Tar]; int ny = j + dy[Tar];
				if (!OOB(nx, ny) && Board[i][j] != Board[nx][ny]) {
					char temp = Board[i][j]; Board[i][j] = Board[nx][ny]; Board[nx][ny] = temp;
					Check();
					temp = Board[i][j]; Board[i][j] = Board[nx][ny]; Board[nx][ny] = temp;
				}
			}
		}
	}
	cout << ans << "\n";
}