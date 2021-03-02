#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result[1000001] = { 0, };
int found(int n) {
	
	if (result[n] != 0 || n == 1) {
		return result[n];
	}
	result[n] = found(n - 1)+1;
	if (n % 3 == 0) {
		result[n] = min(result[n],found(n / 3)+1);
	}
	if (n % 2 == 0) {
		result[n] = min(result[n], found(n / 2) + 1);
	}
	return result[n];

	//해당 층위에서 min값 검사를 해줬어야했는데 안해서 돌아간게 너무 컸다.
	//함수의 return값 정의도 하지 않고 함수값을 사용하려고 한 패착이 있다.
}
int main() {
	int n = 0;
	cin >> n;
	found(n);
	
	cout << result[n];
	return 0;
}