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
// �����չ���. ��Ȯ�� �ľ������� �����ϴµ� �ټ� �ð��� �ɸ�. 
//������ �����տ��� ��� �ε����� � ���� �����־���ϴ����� 
//�Ǵ��� ���κ� �ҿ�Ǿ���. �� ���� ��ĥ �� �ֵ��� �Ұ�
//�ű⿡ ios_base::sync_with_stdio(false);, cin.tie(NULL);, cout.tie(NULL); 
//�� �����ϰ� ����߾�� �ϴµ� �׷��� ���ߴ�. 