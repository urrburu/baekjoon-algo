#include <cstdio>
#include <vector>
#include <queue>
#define INF 10000000001
#define ll long long
using namespace std;

int n, m;
vector<int> disable;
vector<vector<pair<int, int>>> g;

int main() {
	scanf("%d%d", &n, &m);
	disable = vector<int>(n);
	g = vector<vector<pair<int, int>>>(n);

	for (int i = 0; i < n; i++)scanf("%d", &disable[i]);
	for (int i = 0, a, b, t; i < m; i++) {
		scanf("%d%d%d", &a, &b, &t);
		g[a].push_back(make_pair(t, b));
		g[b].push_back(make_pair(t, a));
	}


	vector<bool> visit(n, false);
	vector<ll> dist(n, INF);
	priority_queue<pair<ll, int>> pq;

	dist[0] = 0;
	pq.push(make_pair(0, 0));

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (visit[cur.second])continue;

		visit[cur.second] = true;
		for (auto x : g[cur.second]) {
			if (!(disable[x.second] && x.second != n - 1) && (dist[x.second] > dist[cur.second] + x.first)) {
				dist[x.second] = x.first + dist[cur.second];
				pq.push(make_pair(-dist[x.second], x.second));
			}
		}
	}

	printf("%lld", dist[n - 1] == INF ? -1 : dist[n - 1]);

	return 0;
}//참고코드. 다익스트라가 익숙하지 않아서 방문체크를 하지 않은것이 틀린 원인.
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 10000000001
using namespace std;
int unable[100001];
long long dist[100001];
bool visit[100001];
vector<vector<pair<int, int> > > vec(100001, vector<pair<int, int> >());
int n, m;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) { cin >> unable[i];	dist[i] = INF; }
	unable[n - 1] = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, t; cin >> a >> b >> t;
		vec[a].push_back({ b,t });
		vec[b].push_back({ a,t });
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
	pq.push({ 0,0 });
	dist[0] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		long long cost = pq.top().first;
		pq.pop();
		if (visit[cur] == true)continue;
		visit[cur] = true;
		for (int i = 0; i < vec[cur].size(); ++i) {
			int next = vec[cur][i].first;
			long long ncost = vec[cur][i].second;
			if (dist[next] > cost + ncost && unable[next] == 0) {
				dist[next] = cost + ncost;
				pq.push({ dist[next], next });
			}
		}
	}
	long long ans = (dist[n - 1] == INF) ? -1 : dist[n - 1];
	cout << ans << "\n";
}//최종 제출코드. 재학습 필요. 다익스트라에 쓰이는 부분들을 다시 점검해볼것.
//아쉬움이 많은 문제였다. 가장 적절한 해결법을 찾고도 쉽게 풀지 못했다.
//더 꼼꼼하게 코드를 살펴보는 버릇을 길러야함.