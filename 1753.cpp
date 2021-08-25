#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 20000;
const int INF = 1000000000; // ���� ���� �� ���� ��ΰ�
typedef pair<int, int> P;

int main() {
    int V, E, K;
    vector<P> adj[MAX_V]; // (�̾��� ���� ��ȣ, �Ÿ�)
    cin >> V >> E >> K;
    K--;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back(P(v - 1, w));
    }

    int dist[MAX_V];
    fill(dist, dist + MAX_V, INF);
    bool visited[MAX_V] = { 0 };

    priority_queue<P, vector<P>, greater<P>> PQ;

    // ���ͽ�Ʈ�� �˰���
    dist[K] = 0; // ������������ �Ÿ��� 0
    PQ.push(P(0, K)); // �������� PQ�� �ְ� ����
    while (!PQ.empty()) { // PQ�� ��� ����
        int curr;
        do {
            curr = PQ.top().second;
            PQ.pop();
        } while (!PQ.empty() && visited[curr]); // curr�� �湮�� �����̸� ����
        // �� �̻� �湮�� �� �ִ� ������ ������ ����
        if (visited[curr]) break;

        visited[curr] = true; // �湮
        for (auto& p : adj[curr]) {
            int next = p.first, d = p.second;
            // �Ÿ��� ���ŵ� ��� PQ�� ���� ����
            if (dist[next] > dist[curr] + d) {
                dist[next] = dist[curr] + d;
                PQ.push(P(dist[next], next));
            }
        }
    }

    // ���
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) puts("INF");
        else cout << dist[i];
    }
}
#include<iostream>
#include<queue>
#include<vector>

#define MAX 20010
using namespace std;


int V, E, K;
vector<pair<int, int>> ver[MAX];
int dist[MAX];
int main() {
    cin >> V >> E >> K;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        ver[u].push_back({ v,w });
    }
    for (int i = 0; i <= V; ++i) { dist[i] = 987654321; }
    priority_queue<pair<int, int>> PQ;
    // Priority_queue�� ���� ū ���� top�� ���� �ڷᱸ��. 
    //�⺻�� less<�ڷ���>���� ��. �� ��� ��� ���� ��������.
    //�ݴ�� greater<�ڷ���> �� ���,  ���� ��ü�� �ٲ����� 
    //priority_queue<pair<int.int> , vector<pair<int,int>>, greater<int>> PQ; �� ����̴�.
    //���� �� ���� ������, ��°���� ���������� �ȴ�
    PQ.push({ 0,K });
    dist[K] = 0;
    while (!PQ.empty()) {
        int cost = -PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < ver[cur].size(); ++i) {
            int next = ver[cur][i].first;
            int nCost = ver[cur][i].second;
            if (dist[next] > cost + nCost) {
                dist[next] = cost + nCost;
                PQ.push({ -nCost, next });
            }
        }
    }

}


#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 987654321
using namespace std;
int dist[20001];
vector<pair<int, int>> graph[20001];
int main() {
    int V, E, K;
    cin >> V >> E;
    cin >> K;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    fill(dist, dist + 20001, INF);
    for (int i = 0; i < E; ++i) {
        int st, en, we;
        cin >> st >> en >> we;
        graph[st].push_back({ en,we });
    }
    dist[K] = 0;
    PQ.push({ 0,K });
    while (!PQ.empty()) {
        int cur = PQ.top().second;
        int cost = PQ.top().first;
        PQ.pop();
        for (int i = 0; i < graph[cur].size(); ++i) {
            int next = graph[cur][i].first;
            int n_dist = graph[cur][i].second;
            if (dist[next] > cost + n_dist) {
                dist[next] = cost + n_dist;
                PQ.push({ dist[next], next });
            }
        }
    }
    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF)cout << "INF\n";
        else { cout << dist[i] << "\n"; }
    }
}//solved!!