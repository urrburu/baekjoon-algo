#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check(vector<int>& perm, vector<char>& a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '<' && perm[i] > perm[i + 1]) {
            return false;
        }
        if (a[i] == '>' && perm[i] < perm[i + 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    vector<char> li(n);
    vector<int> num_up(n + 1);
    vector<int> num_down(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> li[i];
    }
    for (int i = 0; i < n + 1; ++i) {
        num_up[i] = i;
        num_down[i] = (9 - i);
    }

    do {
        if (check(num_up, li)) {
            break;
        }
    } while (next_permutation(num_up.begin(), num_up.end()));
    do {
        if (check(num_down, li)) {
            break;
        }
    } while (prev_permutation(num_down.begin(), num_down.end()));
    for (int i = 0; i < n + 1; ++i) {
        cout << num_down[i];
    }
    cout << "\n";
    for (int i = 0; i < n + 1; ++i) {
        cout << num_up[i];
    }
    cout << "\n";
    return 0;
}