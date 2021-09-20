#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int dist[501];
		memset(dist, 98765432, sizeof(dist));
		int n, m, w; cin >> n >> m >> w;
		vector< vector< pair<int, int> > > road(n + 1);
		for (int i = 0; i < m; ++i) {
			int s, e, t; cin >> s >> e >> t;
			road[s].push_back({ t,e });
			road[e].push_back({ t,s });
		}
		for (int i = 0; i < w; ++i) {
			int s, e, t; cin >> s >> e >> t;
			road[s].push_back({ -t,e });
		}
		priority_queue<pair<int, int>> pq;
		pq.push({ 0,1 });
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = pq.top().first;
			pq.pop();
			if (cur == 1 && cost < 0) {
				cout << "YES" << "\n"; return 0;
			}
			for (int i = 0; i < road[cur].size(); ++i) {
				int next = road[cur][i].second;
				int ncost = road[cur][i].first;
				if (dist[next] > cost + ncost) {
					dist[next] = cost + ncost;
					pq.push({ dist[next], next });
				}

			}
		}
		cout << "NO" << "\n";
	}

}///다익스트라로 호기롭게 짜서 틀린 문제
//음수간선에서는 다익스트라가 통하지 않음을 간과
//벨만포드 공부할것.