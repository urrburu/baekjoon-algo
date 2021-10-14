#include <iostream> 
#include <vector>
#include <algorithm> 
using namespace std; 
int main(void) { 
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int N; cin >> N; 
	vector<pair<int, int>> v; 
	for (int i = 0; i < N; i++) 
	{ 
		pair<int, int> a, b; cin >> a.first >> a.second >> b.first >> b.second; // MMdd 
		v.push_back({ a.first * 100 + a.second, b.first * 100 + b.second }); 
	} 
	sort(v.begin(), v.end()); 
	int idx = -1; int temp = 0; int result = 0; // 3월 1일부터 11월 30일 
	for (int i = 301; i <= 1130 && idx < N; i = temp) 
	{ 
		bool flag = false; idx++; 
		for (int j = idx; j < v.size(); j++) { 
			if (v[j].first > i) { break; } 
			if (temp < v[j].second) { temp = v[j].second; idx = j; flag = true; } 
		} 
		if (flag) { result++; } 
		else { cout << 0 << "\n"; return 0; } 
	} 
	cout << result << "\n"; return 0; 
}

