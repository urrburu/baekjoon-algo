#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>
#include<queue>
#define MAX 1000000000
using namespace std;
typedef pair<int, int> PP;
vector<PP> map[5001];
int main() {
	int V, E, P;
	cin >> V >> E >> P;

	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
	}
	int dist[5001];
	fill(dist, dist + 5001, MAX);
	bool visited[5001] = { 0, };
	priority_queue<PP> pq;

	dist[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curr] == true);
		if (visited[curr] == true)break;
		visited[curr] = true;
		for (auto& p : map[curr]) {
			int next = p.first, d = p.second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				pq.push(PP(dist[next], next));
			}
		}
	}


}


#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

int v, e, p;
vector<vector<pii>> g;

int dijkstra(int source, int sink) {
	vector<int> dist(g.size(), INF);
	vector<bool> visit(g.size(), false);
	priority_queue<pii> pq;

	pq.push(make_pair(0, source));
	dist[source] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();
		if (visit[cur])continue;

		visit[cur] = true;
		for (auto x : g[cur])
			if (!visit[x.second] && (dist[x.second] > dist[cur] + x.first)) {
				dist[x.second] = dist[cur] + x.first;
				pq.push(make_pair(-dist[x.second], x.second));
			}
	}

	return dist[sink];
}

int main() {
	scanf("%d%d%d", &v, &e, &p);
	g = vector<vector<pii>>(v + 1);

	for (int i = 0, u, v, w; i < e; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(w, v));
		g[v].push_back(make_pair(w, u));
	}

	if ((dijkstra(1, p) + dijkstra(p, v)) <= dijkstra(1, v))printf("SAVE HIM");
	else printf("GOOD BYE");
	return 0;
}