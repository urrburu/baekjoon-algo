#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 987654321
using namespace std;
int n, x, m;
vector<vector<pair<int, int>>> vec(1001);
vector<int> per_dist(1001, 0);
int dist[1001];
int dijkstra(int start, int end) {
	for (int i = 1; i <= n; ++i) { dist[i] = INF; }
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
	//먼저 발생한 오답의 원인. 항상 이 부분에서 실수함.
	//제일 주의해야할 부분.
	bool visit[1001] = { false, };
	pq.push({ 0,start }); dist[start] = 0;
	while (!pq.empty()) {
		int distance = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		for (int iter = 0; iter < vec[curr].size(); ++iter) {
			int ndist = vec[curr][iter].first;
			int nxt = vec[curr][iter].second;
			if (dist[nxt] > distance + ndist) {
				dist[nxt] = distance + ndist;
				pq.push({ dist[nxt], nxt });
			}
		}
	}
	return dist[end];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> x;
	for (int i = 0; i < m; ++i) {
		int s, e, t; cin >> s >> e >> t;
		vec[s].push_back({ t,e });
	}
	for (int i = 1; i <= n; ++i) {
		per_dist[i] += dijkstra(i, x);
	}
	dijkstra(x, n);
	int max_dis = 0;
	for (int i = 1; i <= n; ++i) {
		per_dist[i] += dist[i];
		//cout<<per_dist[i]<<" ";
		max_dis = max(max_dis, per_dist[i]);
	}
	cout << max_dis << "\n";
}