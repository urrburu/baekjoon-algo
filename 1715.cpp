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

//PQ를 봤을때 이미 끝난게임...... 떠올렸어야 했는데
//처음에 set으로 해결해보려고 한게 잘못. 더 좋은 해결책 없었나...
