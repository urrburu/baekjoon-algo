#include<iostream>
#include<string>
using namespace std;
string make_burger(int n) {
    if (n == 0)return "p";
    return "b" + make_burger(n - 1) + "p" + make_burger(n - 1) + "b";
}
int main() {

    int n, x;
    cin >> n >> x;
    string s = make_burger(n);
    cout << s;
    int cnt = 0;
    int len = s.length();
    for (int i = 0; i < x; ++i) {
        if (s[len - 1 - i] == 'p')cnt++;
    }
    cout << cnt;
}