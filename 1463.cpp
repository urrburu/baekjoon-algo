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

	//�ش� �������� min�� �˻縦 �������ߴµ� ���ؼ� ���ư��� �ʹ� �Ǵ�.
	//�Լ��� return�� ���ǵ� ���� �ʰ� �Լ����� ����Ϸ��� �� ������ �ִ�.
}
int main() {
	int n = 0;
	cin >> n;
	found(n);
	
	cout << result[n];
	return 0;
}