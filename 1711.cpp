#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long Answer = 0;
vector<pair<long long, long long>> VEC;
void Check(long long a1, long long a2, long long b1, long long b2, long long c1, long long c2) {
	long long distABsq = (a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2);
	long long distBCsq = (c1 - b1) * (c1 - b1) + (c2 - b2) * (c2 - b2);
	long long distACsq = (a1 - c1) * (a1 - c1) + (a2 - c2) * (a2 - c2);
	if (distABsq + distACsq == distBCsq) { Answer++; return; }
	else if (distABsq + distBCsq == distACsq) { Answer++; return; }
	else if (distACsq + distBCsq == distABsq) { Answer++; return; }
}

void Dfs(int index, int picked, vector<pair<long long, long long>>& pick) {
	if (picked == 3)return Check(pick[0].first, pick[0].second, pick[1].first, pick[1].second, pick[2].first, pick[2].second);
	pick.push_back({ 0,0 });
	for (int i = index; i < VEC.size(); ++i) {
		pick[picked] = VEC[i];
		Dfs(i + 1, picked + 1, pick);
	}
}
int main() {
	int n; cin >> n;

	for (int i = 0; i < n; ++i) {
		long long a, b; cin >> a >> b;
		VEC.push_back({ a,b });
	}
	vector<pair<long long, long long>> Pick;
	Dfs(0, 0, Pick);

	cout << Answer << "\n";
}