#include<iostream>
#include<queue>

using namespace std;

int main() {
	int Total = 0;
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> Deck;
	while (n--) { int x; cin >> x; Deck.push(x); }
	int sum = 0; int Pair[2] = { 0, };
	while (Deck.size() != 1) {
		for (int i = 0; i < 2; ++i) {
			Pair[i] = Deck.top(); Deck.pop();
		}
		sum = Pair[0] + Pair[1];
		Deck.push(sum);
		Total += sum;
		sum = Pair[0] = Pair[1] = 0;
	}
	cout << Total << "\n";
}

//PQ�� ������ �̹� ��������...... ���÷Ⱦ�� �ߴµ�
//ó���� set���� �ذ��غ����� �Ѱ� �߸�. �� ���� �ذ�å ������...
