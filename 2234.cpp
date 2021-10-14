#include <iostream>

#include <queue>

#include <algorithm>

using namespace std;



const int MAX = 50;



typedef struct

{

    int y, x;

}Dir;



Dir moveDir[4] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };



int N, M;

int area;

int graph[MAX][MAX];

bool visited[MAX][MAX];



int BFS(int y, int x)

{

    queue<pair<int, int>> q;

    q.push({ y, x });

    visited[y][x] = true;

    int cnt = 1;



    while (!q.empty())

    {

        int curY = q.front().first;

        int curX = q.front().second;

        q.pop();



        int bit = 1;

        //��,��,��,�� �� Ȯ��

        for (int i = 0; i < 4; i++)

        {

            if (!(graph[curY][curX] & bit))

            {

                int nextY = curY + moveDir[i].y;

                int nextX = curX + moveDir[i].x;

                //�νø� �ȵǴ� �� �μ��� ���

                if (!(0 <= nextY && nextY < M && 0 <= nextX && nextX < N))

                    continue;



                //�湮���� ���� ��

                if (!visited[nextY][nextX]) {

                    cnt++;

                    visited[nextY][nextX] = true;

                    q.push({ nextY, nextX });

                }

            }

            bit <<= 1;

        }

    }

    return cnt;

}



int main(void)

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin >> N >> M;



    for (int i = 0; i < M; i++)

        for (int j = 0; j < N; j++)

            cin >> graph[i][j];



    int cnt = 0;

    for (int i = 0; i < M; i++)

        for (int j = 0; j < N; j++)

            if (!visited[i][j])

            {

                area = max(area, BFS(i, j));

                cnt++;

            }



    cout << cnt << "\n";

    cout << area << "\n";

    //���� ���ֺ���

    for (int i = 0; i < M; i++)

        for (int j = 0; j < N; j++)

            for (int k = 1; k <= 8; k <<= 1)

                if (graph[i][j] & k)

                {

                    memset(visited, false, sizeof(visited));

                    graph[i][j] -= k;

                    area = max(area, BFS(i, j));

                    graph[i][j] += k;

                }



    cout << area << "\n";

    return 0;

}