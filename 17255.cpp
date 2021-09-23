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
}//오답코드
//접근은 정상적이었다. 하지만 이 문제가 string 문제임을 간과하고
//수로 데이터를 DP 할려고 했던게 잘못이었다. 
//짐작은 했지만 30001과 같은 데이터를 넣을때
//3000과 1, 3과 0001로 나누어지는게 아니라 
//뒤의것은 3과 1로 밖에 나누어지지 않는다. 0으로 가는 경로도 경로인데
//이를 수로 처리하면 처리할 수 없다. 


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
} //AC 코드
// 다른 정답코드에서는 set을 썼는데, map을 써서 풀었다. 
// 중복이 없도록 한다는 취지... set과 map을 더 적극적으로 사용해서 
//풀이해야겠다. 