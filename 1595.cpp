#include<bits/stdc++.h>

using namespace std;

int visit[10010], child[10010];
vector<pair<int, int>> v[10010];
vector<int> li;

int dfs(int x);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y, w;
	while (true) {
		cin >> x;
		if (cin.eof())break;

		//������ ������ �Է��� �޴´�. 
		cin >> y >> w;

		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
	}

	dfs(1);
	sort(li.begin(), li.end(), [](const int& a, const int& b) {
		return a > b;
		});
	if (li.size() >= 2)
		cout << li[0] + li[1];
	else if (li.size() == 1)
		cout << li[0];
	else
		cout << 0;
	return 0;
}
int dfs(int x)
{
	visit[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		if (!visit[v[x][i].first]) {
			int ret = dfs(v[x][i].first) + v[x][i].second;
			if (x == 1)
				li.push_back(ret);
			child[x] = max(child[x], ret);
		}
	}
	return child[x];
}// Ʈ���� ������ ���ϴ� ���� �ٽ��̶�� �ߴµ�, �� ���ش� ���� �ʴ´�
//���ΰ� �� �ʿ��ϴ�.