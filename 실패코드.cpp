#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> progress;
    queue<int> speed;
    int cnt = 0;
    
    for (int i = 0; i < progresses.size(); ++i) {
        progress.push(progresses[i]);

    }
    for (int i = 0; i < speeds.size(); ++i) {
        speed.push(speeds[i]);

    }
    while (!progress.empty()) {
        for (int i = 0; i < progress.size(); ++i) {
            progress.front() = progress.front() + speed.front();
            progress.push(progress.front());
            speed.push(speed.front());
            progress.pop();
            speed.pop();

        }
        while (progress.front() >= 100) {
            cnt++;
            progress.pop();
        }
        if (cnt != 0) {
            
            answer.push_back(cnt);
            cnt = 0;
        }
    }


    return answer;
}

//성공코드
#include <string> 
#include <vector>
#include <iostream>
#include <queue> 
using namespace std; 
vector<int> solution(vector<int> progresses, vector<int> speeds) 
{ vector<int> answer; 
vector<int> days; 
queue<int> q; 
for(int i=0; i<progresses.size(); i++) 
{ int d = (100 - progresses[i])/speeds[i]; 
if((progresses[i] + d*speeds[i])!=100) d++; 
days.push_back(d); 
} 
q.push(days[0]); 
for(int i=1; i<days.size(); i++) 
{ 
    if(q.front() >= days[i]) { q.push(days[i]); } 

    else { answer.push_back(q.size()); 
    while(!q.empty())q.pop(); 
    q.push(days[i]); 
    } 
} 
if(!q.empty()) answer.push_back(q.size()); return answer; }
