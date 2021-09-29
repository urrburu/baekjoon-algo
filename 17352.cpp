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
//DFS �ڵ��. �ٸ� ����� Ǯ�̸� ã�ƺ��� ���Ͽ� ���ε�� �ذ��ϴ���, 
//�� ����� ���� ���ߴ�. ù°, �־��� ���� 30���� Ž�� + 30���� �˻�
//���� �־��̴��� �����ٰ� �����ߴ�. �̰� ��°, 
//���Ͽ����ε�� ��Ǯ�� �ؾ��Ѵ�. 