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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool check(vector<int>& l, vector<char>& c) {
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] == '<' && l[i] > l[i + 1]) {
            return false;
        }
        if (c[i] == '>' && l[i] < l[i + 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> n;
    vector<int> small(n + 1);
    vector<int> big(n + 1);
    vector<char> c(n);
    for (int i = 0; i < c.size(); ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < small.size(); ++i) {
        small[i] = i;
        big[i] = 9 - i;
    }
    do {
        if (check(big, c)) {
            for (int i = 0; i < big.size(); ++i) {
                cout << big[i];
            }
            cout << "\n";
            break;
        }
    } while (prev_permutation(big.begin(), big.end()));
    do {
        if (check(small, c)) {
            for (int i = 0; i < small.size(); ++i) {
                cout << small[i];
            }
            cout << "\n";
            break;
        }
    } while (next_permutation(small.begin(), small.end()));

}
