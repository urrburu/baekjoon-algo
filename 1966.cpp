#include <iostream>
#include <queue>

using namespace std;
int main() {
	int test_case;
	int n, m, count;
	
	cin >> test_case;
	for (int dontuse = 0; dontuse < test_case; dontuse++) {
		cin >> n >> m;
		count = 0;
		queue <int> print;
		queue <int> index;
		priority_queue <int> prior;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			print.push(a);
			index.push(i);
			prior.push(a);
		}

		while (!print.empty()) {
			int idx = index.front();
			int pri = print.front();
			index.pop();
			print.pop();

			if (prior.top() == pri) {
				prior.pop();
				count++;
				if (idx == m) {
					cout << count << endl;
					while (!print.empty())print.pop();
				}
			}
			else {
				print.push(pri);
				index.push(idx);
			}
		}
	}
	

	return 0;
}

