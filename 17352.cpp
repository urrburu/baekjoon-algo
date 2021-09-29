#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
bool visit[300001] = { false, };
vector<vector<int> > graph(300001);
void dfs(int n) {
	visit[n] = true;
	int con = graph[n].size();
	//cout << con << "\n";
	if (con == 0)return;
	for (int i = 0; i < con; ++i) {
		int next = graph[n][i];
		if (visit[next] == false) { dfs(next); }
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n - 2; ++i) {
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1);
	int tar = 0;
	for (int i = 2; i <= n; ++i) { if (visit[i] == false) { tar = i; break; } }
	cout << 1 << " " << tar << "\n";

}
//DFS 코드다. 다른 사람들 풀이를 찾아보니 유니온 파인드로 해결하던데, 
//그 방법을 생각 못했다. 첫째, 최악의 경우라도 30만개 탐색 + 30만개 검색
//으로 최악이더라도 괜찮다고 생각했다. 이게 둘째, 
//유니온파인드로 재풀이 해야한다. 