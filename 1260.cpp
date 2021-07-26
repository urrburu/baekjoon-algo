#include <iostream>
#include <queue>
#include<cstring>
using namespace std;
int graph[1001][1001] = { {0,} };
int visited[1001] = { 0, };
int n, m, v;
void bfs(int x) {
	visited[x] = 1;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 1; i <= n; ++i) {
			if (graph[x][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;

			}
		}
	}
}
void dfs(int x) {
	visited[x] = 1;
	cout << x << " ";
	for (int i = 1; i <= n; ++i) {
		if (graph[x][i] == 1 && visited[i] == 0) {
			dfs(i);
		}
	}
}
int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}
	dfs(v);
	memset(visited, 0, sizeof(visited));
	cout << endl;
	bfs(v);
	return 0;
}