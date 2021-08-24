#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int num[10];
vector<pair<int, int>> map[33];
void input() {
	//first: next second: point
	map[0].push_back({ 1,2 });
	map[1].push_back({ 2,4 });
	map[2].push_back({ 3,6 });
	map[3].push_back({ 4,8 });
	map[4].push_back({ 5,10 });
	map[5].push_back({ 6,12 });

	map[5].push_back({ 20,13 });
	map[20].push_back({ 21,16 });
	map[21].push_back({ 22,19 });
	map[22].push_back({ 23,25 });

	map[6].push_back({ 7,14 });
	map[7].push_back({ 8,16 });
	map[8].push_back({ 9,18 });
	map[9].push_back({ 10,20 });
	map[10].push_back({ 11,22 });

	map[10].push_back({ 24,22 });
	map[24].push_back({ 25,24 });
	map[25].push_back({ 23,25 });

	map[11].push_back({ 12,24 });
	map[12].push_back({ 13,26 });
	map[13].push_back({ 14,28 });
	map[14].push_back({ 15,30 });
	map[15].push_back({ 16,32 });

	map[15].push_back({ 26,28 });
	map[26].push_back({ 27,27 });
	map[27].push_back({ 28,26 });
	map[28].push_back({ 23,25 });

	map[16].push_back({ 17,34 });
	map[17].push_back({ 18,36 });
	map[18].push_back({ 19,38 });
	map[19].push_back({ 20,40 });

	map[23].push_back({ 29,30 });
	map[29].push_back({ 30,35 });
	map[30].push_back({ 20,40 });


}
pair<int, int> move(int num, int start, int p) {
	int point = p;
	int next = start;
	if (next > 30) return make_pair(next, point);
	if (map[start].size() > 1) {
		next = map[start][1].first;
		point += map[start][1].second;
		num--;
	}
	for (int i = 0; i < num; ++i) {
		next = map[next][0].first;
		point += map[next][0].second;
	}
	return make_pair(next, point);
}
int main() {
	input();
	int ans = 0;
	for (int i = 0; i < 10; ++i) { cin >> num[i]; }
	for (int tmp = 0; tmp < (1 << 20); ++tmp) {
		int temp = tmp;
		vector<int> one;
		vector<int> two;
		vector<int> three;
		vector<int> four;
		for (int i = 0; i < 10; ++i) {
			int dir = temp % 4;
			temp /= temp;
			if (dir == 0) { one.push_back(num[i]); }
			if (dir == 1) { two.push_back(num[i]); }
			if (dir == 2) { three.push_back(num[i]); }
			if (dir == 3) { four.push_back(num[i]); }
		}

		pair<int, int> o_p = { 0,0 };
		pair<int, int> t_p = { 0,0 };
		pair<int, int> th_p = { 0,0 };
		pair<int, int> f_p = { 0,0 };
		for (int i = 0; i < one.size(); ++i) {
			o_p = move(one[i], o_p.first, o_p.second);
		}
		for (int i = 0; i < two.size(); ++i) {
			t_p = move(two[i], t_p.first, t_p.second);
		}
		for (int i = 0; i < three.size(); ++i) {
			th_p = move(three[i], th_p.first, th_p.second);
		}
		for (int i = 0; i < four.size(); ++i) {
			f_p = move(four[i], f_p.first, f_p.second);
		}
		int sum = o_p.second + t_p.second + th_p.second + f_p.second;
		ans = max(sum, ans);
	}
	cout << ans << "\n";

}