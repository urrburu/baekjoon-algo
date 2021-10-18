#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, k;
vector<vector< pair<int, int> > > Map(301, vector<pair<int, int>>());
int Meal[303][301];
//Meal[m][n]
int dfs(int node, int visited) {

	if (node == n)return 0;
	if (visited == m)return -987654321;
	if (Meal[visited][node] != -1)return Meal[visited][node];
	int Max_meal = -987654321;
	for (pair<int, int> pa : Map[node]) {
		if (pa.first > node) {
			Max_meal = max(dfs(pa.first, visited + 1) + pa.second, Max_meal);
		}
	}
	Meal[visited][node] = Max_meal;
	return Meal[visited][node];
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		Map[a].push_back({ b,c });
	}
	memset(Meal, -1, sizeof(Meal));
	cout << dfs(1, 1) << "\n";
}