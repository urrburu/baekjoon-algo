#include<iostream>
#include<map>

using namespace std;
int n;
map<string, int> books;
int main() {
	cin >> n;
	string s;
	int num = 0;
	while (n--) {
		cin >> s;
		if (books.find(s) == books.end()) {
			books.insert({ s,1 });
		}
		else { books.find(s)->second++; }
	}

	for (auto book : books) {

		if (num < book.second) {
			s = book.first;
			num = book.second;
		}
	}
	cout << s << "\n";
}