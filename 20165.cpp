#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, r;
int Board[101][101];
bool Stand[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int Round(int Ax, int Ay, char dir, int Dx, int Dy) {
	/*cout<<"\n" << Ax << " " << Ay << " ";*/
	int ans = (Stand[Ax][Ay] == true) ? 1 : 0;
	int height = (Stand[Ax][Ay] == true) ? Board[Ax][Ay] : 1;
	Stand[Ax][Ay] = false;
	if (dir == 'E') {
		int nx = Ax; int ny = Ay;
		for (int i = 1; i < height; ++i) {
			nx += dx[0]; ny += dy[0];
			if (ny < m)ans += Round(nx, ny, 'E', Dx, Dy);
		}
	}
	else if (dir == 'S') {
		int nx = Ax; int ny = Ay;
		for (int i = 1; i < height; ++i) {
			nx += dx[1]; ny += dy[1];
			if (nx < n)ans += Round(nx, ny, 'S', Dx, Dy);
		}
	}
	else if (dir == 'W') {
		int nx = Ax; int ny = Ay;
		for (int i = 1; i < height; ++i) {
			nx += dx[2]; ny += dy[2];
			if (ny >= 0)ans += Round(nx, ny, 'W', Dx, Dy);
		}
	}
	else if (dir == 'N') {
		int nx = Ax; int ny = Ay;
		for (int i = 1; i < height; ++i) {
			nx += dx[3]; ny += dy[3];
			if (nx >= 0)ans += Round(nx, ny, 'N', Dx, Dy);
		}
	}

	return ans;
}

int main() {
	cin >> n >> m >> r;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> Board[i][j];
		}
	}

	memset(Stand, true, sizeof(Stand));
	int Answer = 0;
	for (int i = 0; i < r; ++i) {
		int a, b, c, d; char dir;
		cin >> a >> b >> dir >> c >> d;
		Answer += Round(a - 1, b - 1, dir, c - 1, d - 1);
		Stand[c - 1][d - 1] = true;
	}
	cout << Answer << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Stand[i][j] == true) {
				cout << "S ";
			}
			else {
				cout << "F ";
			}
		}
		cout << "\n";
	}
}