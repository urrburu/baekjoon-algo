//#include<iostream>
//#include<vector>
//using namespace std;
//실패코드
//int map[101][101];
//int copy_map[101][101];
//int n, m;
//void print() {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cout << map[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}
//void one() {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			copy_map[i][j] = map[n - i - 1][j];
//		}
//	}
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			map[i][j] = copy_map[i][j];
//		}
//	}
//
//}
//void two() {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			copy_map[i][j] = map[i][m - j - 1];
//		}
//	}
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			map[i][j] = copy_map[i][j];
//		}
//	}
//}
//void three() {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			copy_map[i][j] = map[j][n - 1 - i];
//		}
//	}
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			map[i][j] = copy_map[i][j];
//		}
//	}
//}
//void four() {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			copy_map[i][j] = map[m - 1 - j][i];
//		}
//	}
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			map[i][j] = copy_map[i][j];
//		}
//	}
//}
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> operation1(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = a[n - i - 1][j];
        }
    }
    return ans;
}
vector<vector<int>> operation2(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = a[i][m - j - 1];
        }
    }
    return ans;
}
vector<vector<int>> operation3(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = a[n - j - 1][i];
        }
    }
    return ans;
}
vector<vector<int>> operation4(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = a[j][m - i - 1];
        }
    }
    return ans;
}
vector<vector<int>> operation5(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            ans[i][j + m / 2] = a[i][j];
            ans[i + n / 2][j + m / 2] = a[i][j + m / 2];
            ans[i + n / 2][j] = a[i + n / 2][j + m / 2];
            ans[i][j] = a[i + n / 2][j];
        }
    }
    return ans;
}
vector<vector<int>> operation6(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            ans[i + n / 2][j] = a[i][j];
            ans[i][j] = a[i][j + m / 2];
            ans[i][j + m / 2] = a[i + n / 2][j + m / 2];
            ans[i + n / 2][j + m / 2] = a[i + n / 2][j];
        }
    }
    return ans;
}
int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (r--) {
        int op;
        cin >> op;
        if (op == 1) {
            a = operation1(a);
        }
        else if (op == 2) {
            a = operation2(a);
        }
        else if (op == 3) {
            a = operation3(a);
        }
        else if (op == 4) {
            a = operation4(a);
        }
        else if (op == 5) {
            a = operation5(a);
        }
        else if (op == 6) {
            a = operation6(a);
        }
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
