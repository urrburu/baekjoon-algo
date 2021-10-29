#include<iostream>
#include<queue>
#include<vector>

using namespace std;
void isBipartiteGraph(vector<vector<int>>& Graph, vector<int>& Group) {
	for (int i = 1; i < Graph.size(); ++i) {
		int Size = Graph[i].size();
		for (int j = 0; j < Size; ++j) {
			int next = Graph[i][j];
			if (Group[i] == Group[next]) {
				cout << "NO" << "\n";
				return;
			}
		}
	}
	cout << "YES" << "\n";
	return;
}
int main() {
	int TestCase = 0; cin >> TestCase;
	while (TestCase--) {
		bool EndFlag = false;
		int v, e; cin >> v >> e;
		vector<vector<int>> Graph(v + 1);
		vector<int> Group(v + 1, 0);
		for (int i = 0; i < e; ++i) {
			int a, b; cin >> a >> b;
			Graph[a].push_back(b);
			Graph[b].push_back(a);
		}
		queue<pair<int, int>> que;
		for (int iter = 1; iter <= v; ++iter) {
			//그래프가 완전히 탐색되지 않은 경우에는 모든 점을 다 한번씩 들러야 한다는 걸 
			//생각해주지 않았다. 
			if (Group[iter] == 0) {
				que.push({ iter,1 });
				Group[iter] = 1;
				while (!que.empty() && EndFlag == false) {
					int cur = que.front().first;
					int status = que.front().second;
					que.pop();
					for (int i = 0; i < Graph[cur].size(); ++i) {
						int next = Graph[cur][i];
						if (Group[next] == 0) {
							Group[next] = 3 - status;
							que.push({ next, 3 - status });
							//cout <<" \n"<< next << " " << Group[next] << " \n";
						}
					}
				}
			}
		}
		isBipartiteGraph(Graph, Group);

	}

}

//재풀이 필요....