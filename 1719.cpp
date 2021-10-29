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
	// ��θ� �����Ѵٴ� �ǹ̸� ���� Ʋ�� ����. 
	//���ͽ�Ʈ��� ������ ��������� �̿����� Ȯ���� ��Ȯ�� ����.
	//����� �������� ���ؼ� ��Ȯ�� ������, �������� �����س����� ������ 
	//��Ȯ�� �ߴ���� ���� �� �־��� ����. 
}