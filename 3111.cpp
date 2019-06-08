#include <stdio.h>
#include <string.h>
#include <list>
using namespace std;
char A[30];
char T[300003];
list<char> L;
int lenA = 0;
int lenT = 0;
bool stringCmp(list<char>* L, list<char>::iterator it) {
	for (int i = 0; i < lenA; i++) {
		if (it == L->end())
			return false;
		if (*it != A[i])
			return false;
		it++;
	}
	return true;
}
bool stringCmp_Reverse(list<char>* L, list<char>::iterator it) {
	for (int i = lenA - 1; i >= 0; i--) {
		if (it == L->begin())
			return false;
		if (*it != A[i])
			return false;
		it--;
	}
	return true;
}
int main(void) {
	scanf("%s", &A);
	scanf("%s", &T);
	lenA = strlen(A);
	lenT = strlen(T);
	for (int i = 0; i < lenT; i++)
		L.push_back(T[i]);
	L.push_front('-'); // ���� ���� �� ���� ���ڸ� ��, �ڿ� �־��
	L.push_back('=');
	auto it1 = L.begin(); // iterator
	auto it2 = L.end(); // reverse_interator
	bool dir = false; // true : ���ʿ������� false : ���ʿ�������
	int cnt = 0;
	while (true) {
		if (dir) {
			if (it1 == L.end())
				break;
			if (stringCmp(&L, it1)) {
				for (int i = 0; i < lenA; i++)
					it1 = L.erase(it1); // ���ڿ��� ã�������� ����
				for (int i = 0; i < 2 * lenA; i++) { // ���ŵ����μ� ���ڿ��� ���Ӱ� ���� �� �����Ƿ� it1�� 2*lenA��ŭ �����Ŵ
					if (it1 == L.begin())
						break;
					it1--;
				}
				dir = false; // ���� ����
			}
			else
				it1++;
		}
		else {
			if (it2 == L.begin())
				break;
			if (stringCmp_Reverse(&L, it2)) {
				for (int i = 0; i < lenA; i++) {
					it2 = L.erase(it2);
					it2--;
				}
				for (int i = 0; i < 2 * lenA; i++) {
					if (*it2 == '=')
						break;
					it2++;
				}
				dir = true;
			}
			else
				it2--;
		}
	}
	L.pop_front();
	L.pop_back(); // �����״� �� ���ڸ� ����
	for (auto elem : L)
		printf("%c", elem);
}