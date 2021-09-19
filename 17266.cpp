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