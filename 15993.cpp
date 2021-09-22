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


}// �� �������� ���� �����ؾ� �� �κ��� 10��9�� ������ �κ��̴�
//long long �迭�� ���� ���� ��� int �� �ִ밪�� 21���̴�. 
//�ϴٸ��� unsigned�� ������ ������ ���� �ʾ��� ���̴�.
//int �� �ΰ��� �������� ����Ǵ� �ִ밪�� 20��16, ���⿡ ������ �ϳ��� �� ����
//������ ������ ��� �����÷ο찡 �Ͼ��. 
//�̸� �����߾�� �Ѵ�. 