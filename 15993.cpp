#include<iostream>
#include <cstring>

using namespace std;
int odd[100001];
int even[100001];
int main() {
	memset(odd, -1, sizeof(odd));
	memset(even, -1, sizeof(even));
	odd[0] = 0; even[0] = 0;
	odd[1] = 1; even[1] = 0;
	odd[2] = 1; even[2] = 1;
	odd[3] = 2; even[3] = 2;
	for (int i = 4; i <= 100000; ++i) {
		odd[i] = ((even[i - 1] + even[i - 2]) % 1000000009 + even[i - 3]) % 1000000009;
		even[i] = ((odd[i - 1] + odd[i - 2]) % 1000000009 + odd[i - 3]) % 1000000009;
	}
	int tc; cin >> tc;
	while (tc--) {
		int num; cin >> num;
		cout << odd[num] << " " << even[num] << "\n";
	}


}// 이 문제에서 가장 유의해야 할 부분은 10억9로 나누는 부분이다
//long long 배열을 쓰지 않을 경우 int 의 최대값은 21억이다. 
//하다못해 unsigned를 썼으면 에러가 나지 않았을 것이다.
//int 값 두개를 더했을때 예상되는 최대값은 20억16, 여기에 나머지 하나를 더 더해
//버리면 범위를 벗어나 오버플로우가 일어난다. 
//이를 유의했어야 한다. 