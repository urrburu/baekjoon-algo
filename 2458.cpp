#include <iostream>
using namespace std;

const int INF = 9999999;
const int MAX = 502;
int N, M;
int map[MAX][MAX];

void floyd() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }

    floyd();

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (map[i][j] != INF || map[j][i] != INF) {
                cnt++;
            }
        }
        if (cnt == N - 1) ans++;
    }
    cout << ans << endl;

    return 0;
}
//int ans  //출력(정답)
//
//int cnt  //정점i와 연결되어 있는 정점의 개수
//
//
//
//if (map[i][j] != INF || map[j][i] != INF)  //i보다 큰 사람이 존재 또는 i보다 작은 사람이 존재하면
//
//cnt++;   //연결정점 개수+1
//
//
//
//if (cnt == N - 1) ans++;   //i가 자신을 제외한 모든 정점과 연결되어 있음(키 순서를 정확히 파악 가능), 답+1