#include <iostream>
#include <queue>
#include <string>

using namespace std;
int main() {
	queue<int> q;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string comm;
		cin >> comm;
		if (comm == "push") {
			int x = 0;
			cin >> x;
			q.push(x);
		}
		if (comm == "front"){
			if (q.empty()) {cout << -1 << endl;}
			else {cout << q.front() << endl;}
		}
		if (comm == "back") {
			if (q.empty()) { cout << -1 << endl; }
			else { cout << q.back() << endl; }
		}
		if (comm == "size") {
			cout << q.size()<<endl;
		}
		if (comm == "empty") {
			cout << q.empty()<<endl;
		}
		if (comm == "pop") {
			if (q.empty()) { cout << -1 << endl; }
			else { 
				cout << q.front() << endl; 
				q.pop(); 
			}
		}
	}
	return 0;
}

