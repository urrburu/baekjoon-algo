/*
이 문제에서 가장 관건은 유클리드 호제법을 모른다는 점과 함께 수의 범위였다.  
백만정도면 제한시간 내에 무조건 전체탐색이 가능하다. 그래서 신경쓰지 않았는데
시간에는 확실히 영향을 준다. 
*/

#include<iostream>
using namespace std;
int main() {
	long long n, a, b;
	cin >> n;
	while (n--) {
		long long biggest = 1;
		cin >> a >> b;
		if (a <= b) {
			long long mod = b % a;
			while (mod) {
				b = a; a = mod; mod = b % a;
			}
			biggest = a;
		}
		else if (a > b) {
			long long mod = a % b;
			while (mod) {
				a = b; b = mod; mod = a % b;
			}
			biggest = b;
		}
		cout << a * b / biggest << "\n";
	}
}
/*
* 유클리드 호제법을 적용했음에도 불구하고, 마지막까지 틀린 코드다.
* 유클리드 호제법을 잘 알아둬야함.
*/

#include<iostream>
using namespace std;

int gcd(int n, int m) {
	return n % m ? gcd(m, n % m) : m;
}
int lcm(int n, int m) {
	return n / gcd(n, m) * m;
}
int main() {
	long long n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;

		cout << lcm(a, b) << "\n";
	}
}
/*
	최초의 정답코드다. gcd를 계산하고 이로부터 lcm을 계산한다.
	가장 깔끔하고 맞는 풀이다. 범위를 넘어가지 않게 컨트롤하는것도 좋다.
	나눗셈을 먼저, 곱셈을 나중에 하는 편이 더 유리하다. 
*/

#include<iostream>
using namespace std;
int main() {
	int n, a, b;
	cin >> n;
	while (n--) {
		int biggest = 1;
		cin >> a >> b;
		for (int i = 2; i < 1000001; ++i) {
			if (a % i == 0 && b % i == 0) {
				biggest = i;
			}
		}

		cout << a / biggest * b << "\n";
	}
}
/*
	최초의 오답코드를 수정해, 정답코드로 만드는 경우이다. 가능은 했다.
	수의 범위가 문제인가 생각했는데, 생각해보면 범위를 생각해서 연산순서를
	조정하는 것이 더 큰 문제 같았다. 왜냐하면 결과값을 그냥 long long안에 넣어서
	나누는 경우에는 오답이 나왓기 때문이다. 
*/