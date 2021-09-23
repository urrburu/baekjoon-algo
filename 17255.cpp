#include<iostream>
#include<vector>

using namespace std;
int route[10000001];
int dfs(int n) {
	if (route[n] != 0) { return route[n]; }
	int head = n / 10;
	int cnt = 0; int temp = n;
	while (temp) {
		temp /= 10; cnt++;
	}
	temp = 1;
	for (int i = 1; i < cnt; ++i) {
		temp *= 10;
	}
	int tail = n % temp;
	//cout << head <<" "<<temp<<" "<< tail << "\n";
	if (head == tail)return route[n] = dfs(head);
	return route[n] = dfs(head) + dfs(tail);
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < 10; ++i)route[i] = 1;
	cout << dfs(n) << "\n";
}//�����ڵ�
//������ �������̾���. ������ �� ������ string �������� �����ϰ�
//���� �����͸� DP �ҷ��� �ߴ��� �߸��̾���. 
//������ ������ 30001�� ���� �����͸� ������
//3000�� 1, 3�� 0001�� ���������°� �ƴ϶� 
//���ǰ��� 3�� 1�� �ۿ� ���������� �ʴ´�. 0���� ���� ��ε� ����ε�
//�̸� ���� ó���ϸ� ó���� �� ����. 


#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string, int> route;
int dfs(string n) {
	map<string, int> ::iterator Finditer = route.find(n);
	if (Finditer != route.end()) { return Finditer->second; }
	string head = n.substr(0, n.length() - 1);
	//	cout << head;
	string tail = n.substr(1, n.length() - 1);
	//cout<<" " << tail<<"\n";
	if (head == tail) {
		route.insert({ head, dfs(head) }); return dfs(head);
	}
	route.insert({ head, dfs(head) });
	route.insert({ tail, dfs(tail) });
	return route.find(head)->second + route.find(tail)->second;
}
int main() {
	string n; cin >> n;
	for (int i = 0; i < 10; ++i)route.insert({ to_string(i), 1 });
	cout << dfs(n) << "\n";
} //AC �ڵ�
// �ٸ� �����ڵ忡���� set�� ��µ�, map�� �Ἥ Ǯ����. 
// �ߺ��� ������ �Ѵٴ� ����... set�� map�� �� ���������� ����ؼ� 
//Ǯ���ؾ߰ڴ�. 