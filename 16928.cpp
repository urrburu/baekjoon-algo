#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int route[101];
bool visit[101];
int main() {
    int n, m; cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 1; i <= 100; ++i) {
        route[i] = i;
    }
    for (int i = 0; i < n + m; ++i) {
        int x; int y; cin >> x >> y;
        route[x] = y;
    }
    q.push({ 1,0 });
    while (!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (x == 100) {
            cout << cnt << "\n";
            return 0;
        }
        for (int i = 1; i <= 6; ++i) {
            int nx = x + i;
            if (nx > 100)continue;
            nx = route[nx];
            if (visit[nx] == false) {
                q.push({ nx, cnt + 1 });
                visit[nx] = true;
            }
        }
    }
}

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	int Map[110] = { 0, };
	vector<pair<int, int>> Route;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		Route.push_back({ a,b });
	}
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		Route.push_back({ a,b });
	}
	queue<int> que;
	que.push(1);
	Map[1] = 0;
	while (!que.empty()) {
		int Current = que.front();
		que.pop();
		if (Current > 100)continue;
		for (int i = 1; i <= 6; ++i) {
			int Next = Current + i;
			for (int j = 0; j < Route.size(); ++j) {
				if (Route[j].first == Next)Next = Route[j].second;
			}
			if (Map[Next] == 0) {
				Map[Next] = Map[Current] + 1;
				que.push(Next);
			}
		}
	}
	cout << Map[100] << "\n";
}