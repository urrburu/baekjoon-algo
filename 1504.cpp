#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<vector<pair<int, int>>> Graph(810);
int dijkstra(int start, int end) {
	int distance[810];
	memset(distance, 98765432, sizeof(distance));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > PQ;
	PQ.push({ 0,start });
	distance[start] = 0;
	while (!PQ.empty()) {
		int cur = PQ.top().second;
		int dis = PQ.top().first;
		PQ.pop();
		for (int i = 0; i < Graph[cur].size(); ++i) {
			int nxt = Graph[cur][i].first;
			int Ndis = Graph[cur][i].second;
			if (distance[nxt] > dis + Ndis) {
				distance[nxt] = dis + Ndis;
				PQ.push({ distance[nxt], nxt });
			}
		}
	}
	return distance[end];
}
int main() {
	int N, E;

	cin >> N >> E;
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		Graph[a].push_back({ b,c });
		Graph[b].push_back({ a,c });
	}
	int target1, target2;
	cin >> target1 >> target2;
	int route1 = 0;
	route1 += dijkstra(1, target1);
	route1 += dijkstra(target1, target2);
	route1 += dijkstra(target2, N);
	int route2 = 0;
	route2 += dijkstra(1, target2);
	route2 += dijkstra(target2, target1);
	route2 += dijkstra(target1, N);
	if (route1 > 987654321 && route2 > 987654321) {
		cout << -1 << "\n"; return 0;
	}
	cout << min(route1, route2) << "\n";

}
