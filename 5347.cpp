/*
�� �������� ���� ������ ��Ŭ���� ȣ������ �𸥴ٴ� ���� �Բ� ���� ��������.  
�鸸������ ���ѽð� ���� ������ ��üŽ���� �����ϴ�. �׷��� �Ű澲�� �ʾҴµ�
�ð����� Ȯ���� ������ �ش�. 
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
* ��Ŭ���� ȣ������ ������������ �ұ��ϰ�, ���������� Ʋ�� �ڵ��.
* ��Ŭ���� ȣ������ �� �˾Ƶ־���.
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
	������ �����ڵ��. gcd�� ����ϰ� �̷κ��� lcm�� ����Ѵ�.
	���� ����ϰ� �´� Ǯ�̴�. ������ �Ѿ�� �ʰ� ��Ʈ���ϴ°͵� ����.
	�������� ����, ������ ���߿� �ϴ� ���� �� �����ϴ�. 
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
	������ �����ڵ带 ������, �����ڵ�� ����� ����̴�. ������ �ߴ�.
	���� ������ �����ΰ� �����ߴµ�, �����غ��� ������ �����ؼ� ���������
	�����ϴ� ���� �� ū ���� ���Ҵ�. �ֳ��ϸ� ������� �׳� long long�ȿ� �־
	������ ��쿡�� ������ ���ӱ� �����̴�. 
*/