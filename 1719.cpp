#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<pair<int, int>>> Edge(201);
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		Edge[a].push_back({ c,b });
		Edge[b].push_back({ c,a });
	}
	for (int i = 1; i <= n; ++i) {
		vector<pair<int, int>> Dist(n + 1);
		for (int j = 1; j <= n; ++j) { Dist[j] = { 987654321, 0 }; }
		priority_queue<pair<int, int>> pq;
		pq.push({ 0,i });
		Dist[i].first = 0;
		Dist[i].second = 0;
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = -(pq.top().first);
			pq.pop();
			for (int j = 0; j < Edge[cur].size(); ++j) {
				int Next = Edge[cur][j].second;
				int Ncost = Edge[cur][j].first;
				if (Dist[Next].first > cost + Ncost) {
					Dist[Next].second = cur;
					Dist[Next].first = cost + Ncost;
					pq.push({ -(cost + Ncost), Next });
				}
			}
		}
		for (int j = 1; j <= n; ++j) {
			if (i == j) { cout << "- "; }
			else if (Dist[j].second == i) {
				cout << j << " ";
			}
			else {
				int Cur_node = j;
				while (true) {
					if (Dist[Cur_node].second == i) {
						cout << Cur_node << " ";
						break;
					}
					else {
						Cur_node = Dist[Cur_node].second;
					}
				}

			}
		}
		cout << "\n";
	}
	// 경로를 추적한다는 의미를 몰라서 틀린 문제. 
	//다익스트라는 적절히 사용했으나 이에대한 확장을 명확히 못함.
	//경로의 이전점에 대해서 명확히 밝히고, 이전점을 추적해나가는 과정을 
	//명확히 했더라면 맞출 수 있었던 문제. 
}