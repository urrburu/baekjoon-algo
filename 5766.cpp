#include<iostream>
#include<queue>
using namespace std;



int main() {
	int n, m;
	while (1) {
		cin >> n >> m; int point[10001] = { 0, };
		if (n == 0 && m == 0)break;
		for (int i = 0; i < n * m; ++i) {
			int tmp; cin >> tmp; point[tmp]++;
		}


		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		for (int i = 1; i < 10001; ++i) {
			pq.push({ -point[i],i });
		}
		pq.pop();
		int tar = pq.top().first;

		while (pq.top().first == tar) {
			cout << pq.top().second << " ";
			pq.pop();
		}
		cout << "\n";

	}

}