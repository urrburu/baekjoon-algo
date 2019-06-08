#include <iostream>
using namespace std;

int main() {
	int size;
	unsigned long long int input[100001] = {0,};
	unsigned long long sum = 0;
	unsigned long long ans = 0;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		cin >> input[i];
		ans += sum * input[i];
		sum = sum + input[i];
	}
	
	cout << ans<<endl;
	return 0;
}