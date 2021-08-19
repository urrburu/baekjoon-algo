#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<vector<int>> arr(101, vector<int>(101));

vector<int> count(vector<int>& a) {
	vector<int> answer;
	int sorting[101] = { 0, };
	for (int i = 0; i < a.size(); ++i) {
		sorting[a[i]]++;
	}
	pair<int, int> max;
	int num = 987654321;
	while (num != 0) {
		num = 0;
		for (int i = 0; i < 101; ++i) {
			if (sorting[i] != 0 && max.second < sorting[i]) {
				max.first = i; max.second = sorting[i];
				num += sorting[i];
			}
		}
		answer.push_back(max.first);
		answer.push_back(max.second);
		sorting[max.first] = 0;
		max = { 0,-1 };

	}

	return answer;
}
int main() {
	int time = 100;
	while (time--) {



	}


}


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n = 3;
int m = 3;
int a[100][100];
int main() {
    int r, c, k;
    cin >> r >> c >> k;
    r -= 1;
    c -= 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (a[r][c] == k) {
        cout << 0 << '\n';
        return 0;
    }
    for (int t = 1; t <= 100; t++) {
        if (n >= m) {
            int mm = m;
            for (int i = 0; i < n; i++) {
                map<int, int> d;
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 0) continue;
                    d[a[i][j]] += 1;
                }
                vector<pair<int, int>> v;
                for (auto& p : d) {
                    v.push_back(make_pair(p.second, p.first));
                }
                sort(v.begin(), v.end());
                int l = min((int)v.size(), 50);
                for (int j = 0; j < l; j++) {
                    a[i][j * 2] = v[j].second;
                    a[i][j * 2 + 1] = v[j].first;
                }
                for (int j = l * 2; j < 100; j++) {
                    a[i][j] = 0;
                }
                if (mm < (int)v.size() * 2) {
                    mm = (int)v.size() * 2;
                }
            }
            m = mm;
        }
        else {
            int nn = n;
            for (int j = 0; j < m; j++) {
                map<int, int> d;

                // map 자료구조의 유리한 점을 알아두자
                //python의 딕셔너리처럼 쓸 수 있음. 굉장히 편함
                //중복이 허용되지 않는다는 점도 유리하게 사용할 수 있음
                for (int i = 0; i < n; i++) {
                    if (a[i][j] == 0) continue;
                    d[a[i][j]] += 1;
                }
                vector<pair<int, int>> v;
                for (auto& p : d) {
                    v.push_back(make_pair(p.second, p.first));
                }
                sort(v.begin(), v.end());
                //pair의 앞 값으로 소팅하는 방법 기억
                int l = min((int)v.size(), 50);
                for (int i = 0; i < l; i++) {
                    a[i * 2][j] = v[i].second;
                    a[i * 2 + 1][j] = v[i].first;
                }
                for (int i = l * 2; i < 100; i++) {
                    a[i][j] = 0;
                }
                if (nn < (int)v.size() * 2) {
                    nn = (int)v.size() * 2;
                }
            }
            n = nn;
        }
        if (a[r][c] == k) {
            cout << t << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}