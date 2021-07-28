#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int n, m;
int map[51][51];
int ans = 987654321;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                house.push_back(make_pair(i, j));
            }
            if (map[i][j] == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    vector<bool> selc(chicken.size(), false);
    fill(selc.end() - m, selc.end(), true);
    do {
        int dist = 0;
        for (int i = 0; i < house.size(); ++i) {
            int sub_dist = 987654321;
            for (int j = 0; j < chicken.size(); ++j) {
                if (selc[j] == false)continue;
                sub_dist = min(sub_dist, abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second));
            }
            dist += sub_dist;
        }
        ans = min(ans, dist);
    } while (next_permutation(selc.begin(), selc.end()));
    cout << ans << "\n";
}