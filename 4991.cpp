#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int w, h;
char board[21][21];
int visit[21][21];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector<pair<int, int>> v;
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= h || y >= w; }
tuple<int, int, int> bfs(int x, int y, int target_x, int target_y) {
	memset(visit, -1, sizeof(visit));

	visit[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int xx, yy;
		tie(xx, yy) = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = xx + dx[i]; int ny = yy + dy[i];
			if (!OOB(nx, ny) && board[nx][ny] != 'x' && visit[nx][ny] == -1) {
				q.push({ nx,ny });
				visit[nx][ny] = visit[xx][yy] + 1;
			}
		}

	}
	return make_tuple(visit[target_x][target_y], target_x, target_y);
}
int main() {
	while (1) {
		int min_num = 987654321;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		int rx, ry;
		v.clear();
		for (int i = 0; i < h; ++i) {
			string s; cin >> s;
			for (int j = 0; j < w; ++j) {
				board[i][j] = s[j];
				if (board[i][j] == '*') {
					v.push_back({ i,j });
				}
				if (board[i][j] == 'o') {
					rx = i; ry = j;
				}
			}
		}
		sort(v.begin(), v.end());
		do {
			int sx = rx; int sy = ry;
			int dist_sum = 0;
			for (int i = 0; i < v.size(); ++i) {
				int target_x = v[i].first;
				int target_y = v[i].second;
				int dist = 0;
				tie(dist, sx, sy) = bfs(sx, sy, target_x, target_y);
				if (dist == -1) { cout << -1; return 0; }
				dist_sum += dist;
			}
			//cout << dist_sum << " ";
			min_num = min(min_num, dist_sum);
		} while (next_permutation(v.begin(), v.end()));
		cout << min_num << "\n";
	}

}///오답코드초기화 신경 쓸 것!, TLE이기때문에 오답
//#include <iostream>
//#include <vector>
//#include <stdio.h>
//#include <string.h>
//#include <queue>
//#define INF 987654321
//#define MAX 21
//#define CLEAN '.'
//#define DIRTY '*'
//#define FURNITURE 'x'
//#define ROBOT 'o'
//
//using namespace std;
//typedef vector<vector<int>> table;
//typedef pair<int, int> pos;
//
//vector<pos>tasks;
//bool selected[11];
//table dist;
//int dy[4]{ -1, 1, 0, 0 };
//int dx[4]{ 0, 0, -1, 1 };
//int ret;
//char map[MAX][MAX];
//
//int w, h;
//
//bool inRange(int y, int x) {
//    return 0 <= y && y < h && 0 <= x && x < w;
//}
//
////start를 기준으로 한 거리를 반환하기 위한 BFS 함수
//table bfs(int y, int x) {
//    int sy, sx, ny, nx;
//    table visited = table(h, vector<int>(w, -1));
//    queue<pos> q;
//    q.push(pos(y, x));
//    visited[y][x] = 0;
//    while (!q.empty()) {
//        pos here = q.front();
//        sy = here.first;
//        sx = here.second;
//        q.pop();
//        for (int i = 0; i < 4; i++) {
//            ny = sy + dy[i];
//            nx = sx + dx[i];
//            if (!inRange(ny, nx))
//                continue;
//            if (visited[ny][nx] != -1)
//                continue;
//            if (map[ny][nx] == FURNITURE)
//                continue;
//
//            visited[ny][nx] = visited[sy][sx] + 1;
//            q.push(pos(ny, nx));
//        }
//    }
//    return visited;
//}
//
////청소 순서를 위한 순열 생성 함수
//void dfs(int here, int cnt, int sum) {
//    if (cnt == tasks.size() - 1) {
//        //cout<<cnt<<" "<<sum<<endl;
//        ret = min(ret, sum);
//        return;
//    }
//    //주의 : 로봇부터 시작해야 하므로 1부터 시작
//    for (int there = 1; there < tasks.size(); there++) {
//        if (!selected[there]) {
//            selected[there] = true;
//            //주의 : 기존 값을 변경하지 않기위해 새로운 변수 사용
//            int next = sum + dist[here][there];
//            dfs(there, cnt + 1, next);
//            selected[there] = false;
//        }
//    }
//}
//
//void build() {
//    char ch;
//    tasks.clear();
//    memset(selected, false, sizeof(selected));
//    //robot일경우 배열의 맨 앞에 위치 추가
//    //쓰레기일 경우 배열의 맨 뒤에 위치 추가
//    for (int y = 0; y < h; y++) {
//        for (int x = 0; x < w; x++) {
//            cin >> ch;
//            if (ch == ROBOT) {
//                tasks.insert(tasks.begin(), pos(y, x));
//            }
//            else if (ch == DIRTY) {
//                tasks.push_back(pos(y, x));
//            }
//            map[y][x] = ch;
//
//        }
//    }
//
//}
//
//void solve() {
//    build();
//    ret = INF;
//    int sy, sx, dy, dx;
//    table path;
//    //MST를 위한 배열 선언
//    dist = table(tasks.size(), vector<int>(tasks.size(), 0));
//    //task 순화
//    for (int i = 0; i < tasks.size(); i++) {
//        sy = tasks[i].first;
//        sx = tasks[i].second;
//        //각기 다른 시작점을 기준으로 한 거리 받음
//        path = bfs(sy, sx);
//        for (int j = 0; j < tasks.size(); j++) {
//            dy = tasks[j].first;
//            dx = tasks[j].second;
//            //MST 배열에 값 할당
//            //i = 출발지, j = 도착지
//            dist[i][j] = path[dy][dx];
//            if (dist[i][j] == -1) {
//                cout << -1 << endl;
//                return;
//            }
//        }
//    }
//    //순열 생성 및 최소값 갱신
//    dfs(0, 0, 0);
//    //정답 출력
//    cout << ret << endl;
//}
//
//
//int main(int argc, const char* argv[]) {
//    while (true) {
//        cin >> w >> h;
//        if (w == 0 && h == 0) {
//            break;
//        }
//        solve();
//    }
//    return 0;
//}