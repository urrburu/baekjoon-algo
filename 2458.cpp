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
//int ans  //���(����)
//
//int cnt  //����i�� ����Ǿ� �ִ� ������ ����
//
//
//
//if (map[i][j] != INF || map[j][i] != INF)  //i���� ū ����� ���� �Ǵ� i���� ���� ����� �����ϸ�
//
//cnt++;   //�������� ����+1
//
//
//
//if (cnt == N - 1) ans++;   //i�� �ڽ��� ������ ��� ������ ����Ǿ� ����(Ű ������ ��Ȯ�� �ľ� ����), ��+1