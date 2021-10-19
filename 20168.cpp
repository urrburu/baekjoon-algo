#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
int n, m, c, a, b;
vector < vector<pair<int, int>> > Map(11, vector<pair<int, int> >());
vector <int> Visit(11, 987654321);

int main() {
	cin >> n >> m >> a >> b >> c;
	for (int i = 0; i < m; ++i) {
		int aa, bb, fair;
		cin >> aa >> bb >> fair;
		Map[aa].push_back({ bb,fair });
		Map[bb].push_back({ aa,fair });
	}
	priority_queue<tuple<int, int, int> > que;
	que.push(make_tuple(0, a, 0));
	Visit[a] = 0;
	while (!que.empty()) {
		int cur, maxi, sum;
		tie(maxi, cur, sum) = que.top(); que.pop();
		for (int i = 0; i < Map[cur].size(); ++i) {
			int next = Map[cur][i].first;
			int ncost = Map[cur][i].second;
			if (c >= sum + ncost && Visit[next] > (maxi > ncost ? maxi : ncost)) {
				Visit[next] = (maxi > ncost ? maxi : ncost);
				que.push(make_tuple(Visit[next], next, sum + ncost));
			}
		}
	}
	if (Visit[b] == 987654321) { cout << -1 << "\n"; return 0; }
	cout << Visit[b] << " \n";
}