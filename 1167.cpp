#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int v;
pair<int, int> Max_node = { 0,0 };
bool Visit[100010] = { false, };
vector<vector<pair<int, int>>> Graph(100010, vector<pair<int, int>>());
void Max_length(int start, int length) {

	if (Visit[start] == true)return;
	if (Max_node.second < length) {
		Max_node.second = length;
		Max_node.first = start;

	}
	Visit[start] = true;
	for (int i = 0; i < Graph[start].size(); ++i) {
		int next = Graph[start][i].first;
		int cost = Graph[start][i].second;
		Max_length(next, cost + length);
	}
	return;
}
int main() {
	cin >> v;
	for (int iter = 1; iter <= v; ++iter) {
		int node; cin >> node;
		while (1) {
			int leng, target;
			cin >> target;
			if (target == -1)break;
			cin >> leng;
			Graph[node].push_back({ target, leng });
		}
	}
	memset(Visit, false, sizeof(Visit));
	Max_length(1, 0);
	memset(Visit, false, sizeof(Visit));
	Max_length(Max_node.first, 0);
	cout << Max_node.second << "\n";
}