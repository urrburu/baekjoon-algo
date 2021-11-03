#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int>& pos, int n, int h);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> pos(m);
    for (int i = 0; i < m; ++i) {
        cin >> pos[i];
    }

    int left = 1, right = n;
    int mid, ans = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (isPossible(pos, n, mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}

bool isPossible(vector<int>& pos, int n, int h) {
    int len = pos.size();
    int darkStart = 0;
    for (int i = 0; i < len; ++i) {
        if (pos[i] - h <= darkStart) {
            darkStart = pos[i] + h;
        }
        else break;
    }

    return n - darkStart <= 0;
}

#include<iostream>
#include<vector>

using namespace std;
int n, m;
int ans = 987654321;
vector<int> Place;
bool Chk(int length) {
    for (int i = 0; i < Place.size(); ++i) {
        if (i == 0) {
            if (Place[i] - length > 0)return false;
        }
        if (i == Place.size() - 1) {
            if (Place[i] + length < n)return false;
            if (i != 0 && Place[i - 1] + length < Place[i] - length)return false;
        }
        if (i > 0 && i < Place.size() - 1) {
            if (Place[i - 1] + length < Place[i] - length)return false;
        }
    }
    return true;
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) { int a; cin >> a; Place.push_back(a); }

    int start = 0, end = n;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (Chk(mid)) { end = mid - 1; ans = min(ans, mid); }
        else { start = mid + 1; }
    }
    cout << ans << "\n";
}