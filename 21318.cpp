#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> hard;
vector<int> num;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp; cin >> tmp; hard.push_back(tmp);
		if (i == 0) {
			num.push_back(0);
		}
		else {
			if (hard[i - 1] > hard[i])num.push_back(num[i - 1] + 1);
			else { num.push_back(num[i - 1]); }
		}
	}



	//for (int i = 0; i < num.size(); ++i)cout << num[i] << " ";
	int m; cin >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		cout << num[y - 1] - num[x - 1] << "\n";
	}
}
// 누적합문제. 정확히 파악했으나 구현하는데 다소 시간이 걸림. 
//문제는 누적합에서 어느 인덱스가 어떤 값을 갖고있어야하는지에 
//판단이 상당부분 소요되었다. 이 점을 고칠 수 있도록 할것
//거기에 ios_base::sync_with_stdio(false);, cin.tie(NULL);, cout.tie(NULL); 
//을 적절하게 사용했어야 하는데 그러지 못했다. 