#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 20000;
const int INF = 1000000000; // 절대 나올 수 없는 경로값
typedef pair<int, int> P;

int main() {
    int V, E, K;
    vector<P> adj[MAX_V]; // (이어진 정점 번호, 거리)
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

    // 다익스트라 알고리즘
    dist[K] = 0; // 시작점으로의 거리는 0
    PQ.push(P(0, K)); // 시작점만 PQ에 넣고 시작
    while (!PQ.empty()) { // PQ가 비면 종료
        int curr;
        do {
            curr = PQ.top().second;
            PQ.pop();
        } while (!PQ.empty() && visited[curr]); // curr가 방문한 정점이면 무시
        // 더 이상 방문할 수 있는 정점이 없으면 종료
        if (visited[curr]) break;

        visited[curr] = true; // 방문
        for (auto& p : adj[curr]) {
            int next = p.first, d = p.second;
            // 거리가 갱신될 경우 PQ에 새로 넣음
            if (dist[next] > dist[curr] + d) {
                dist[next] = dist[curr] + d;
                PQ.push(P(dist[next], next));
            }
        }
    }

    // 결과
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
    // Priority_queue는 가장 큰 값이 top에 오는 자료구조. 
    //기본은 less<자료형>으로 들어감. 이 경우 출력 순은 내림차순.
    //반대로 greater<자료형> 일 경우,  선언 자체가 바뀌어야함 
    //priority_queue<pair<int.int> , vector<pair<int,int>>, greater<int>> PQ; 의 방식이다.
    //작은 놈 부터 나오며, 출력결과는 오름차순이 된다
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


#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int v, e;
int dist[20001];
int main() {

    int start;
    cin >> v >> e >> start;
    vector<vector<pair<int, int> > > vec(v + 1, vector<pair<int, int> >());
    for (int i = 0; i < e; ++i) {
        int s, e, w; cin >> s >> e >> w;
        vec[s].push_back({ w,e });

    }
    for (int i = 1; i <= v; ++i) { dist[i] = 987654321; }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({ 0,start });	dist[start] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for (int i = 0; i < vec[cur].size(); ++i) {
            int next = vec[cur][i].second;
            int ncost = vec[cur][i].first;
            if (dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push({ cost + ncost, next });
            }
        }

    }
    for (int i = 1; i <= v; ++i) {
        if (dist[i] == 987654321) { cout << "INF" << "\n"; }
        else {
            cout << dist[i] << "\n";
        }
//로직은 맞추나 세세한 부분에서 오답. 천천히 생각하고 접근할것