#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int ground[11][11];
int a[11][11];
vector<vector<vector<int>>> tree(11, vector<vector<int>>(11));
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int N, M, K;
void spring() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!tree[i][j].empty()) {
				sort(tree[i][j].begin(), tree[i][j].end());
				for (int iter = 0; iter < tree[i][j].size(); ++iter) {
					if (ground[i][j] > tree[i][j][iter]) { ground[i][j] -= tree[i][j][iter]; }
					else { tree[i][j][iter] *= -1; }

				}
			}
		}
	}
}
void summer() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!tree[i][j].empty()) {
				int dead_sum = 0;
				for (int iter = 0; iter < tree[i][j].size(); ++iter) {
					if (tree[i][j][iter] < 0) {
						dead_sum += tree[i][j][iter];
						tree[i][j].erase(tree[i][j].begin() + iter);
						iter--;
					}
				}
				dead_sum *= -1;
				dead_sum /= 2;
				ground[i][j] += dead_sum;
			}
		}
	}

}
void fall() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!tree[i][j].empty()) {

				for (int iter = 0; iter < tree[i][j].size(); ++iter) {
					if (tree[i][j][iter] % 5 == 0) {
						for (int itera = 0; itera < 8; ++itera) {
							tree[i + dx[itera]][j + dy[itera]].push_back(1);
						}
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ground[i][j] += a[i][j];
		}
	}
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> a[i][j];
			ground[i][j] = 5;
		}
	}
	for (int i = 0; i < M; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}
	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cnt += tree[i][j].size();
		}
	}
	cout << cnt << "\n";
}//wrong code

#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int ground[11][11];
int a[11][11];
vector<vector<vector<int>>> tree(11, vector<vector<int>>(11));
vector<tuple<int, int, int>> dead;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int N, M, K;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= N || y >= N; }
void spring() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!tree[i][j].empty()) {
				sort(tree[i][j].begin(), tree[i][j].end());
				for (int iter = 0; iter < tree[i][j].size(); ++iter) {
					if (ground[i][j] >= tree[i][j][iter]) { ground[i][j] -= tree[i][j][iter];	tree[i][j][iter]++; }
					else { dead.push_back(make_tuple(i, j, tree[i][j][iter])); tree[i][j].erase(tree[i][j].begin() + iter); iter--; }
				}
			}
		}
	}
}
void summer() {
	for (int i = 0; i < dead.size(); ++i) {
		int x, y, z;
		tie(x, y, z) = dead[i];
		ground[x][y] += z / 2;
	}
	dead.clear();
}
void fall() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!tree[i][j].empty()) {
				for (int iter = 0; iter < tree[i][j].size(); ++iter) {
					if (tree[i][j][iter] % 5 == 0) {
						for (int itera = 0; itera < 8; ++itera) {
							if (!OOB(i + dx[itera], j + dy[itera]))tree[i + dx[itera]][j + dy[itera]].push_back(1);
						}
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ground[i][j] += a[i][j];
		}
	}
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> a[i][j];
			ground[i][j] = 5;
		}
	}
	for (int i = 0; i < M; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}
	while (K--) {
		spring();

		summer();

		fall();

		winter();
		//cout << 4;
		//cout << "\n";	
		//for (int i = 0; i < N; ++i) {
		//	for (int j = 0; j < N; ++j) {
		//		if (tree[i][j].size() == 0) { cout << "0"; }
		//		else {
		//			for (int iter = 0; iter < tree[i][j].size(); ++iter) {
		//				cout << tree[i][j][iter];
		//			}
		//			//cout << tree[i][j].size();
		//		}
		//		
		//		cout << " ";
		//	}
		//	cout << "\n";
		//}
		//for (int i = 0; i < N; ++i) {
		//	for (int j = 0; j < N; ++j) {
		//		cout << ground[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cnt += tree[i][j].size();

		}
	}
	cout << cnt << "\n";
}//right code