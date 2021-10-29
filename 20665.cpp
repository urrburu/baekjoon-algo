#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int N, T, P;
int TimeTable[12][60][101];
set<pair<string, string> > Timeset;

int Dist(int Hour, int Min, int Seat) {
	int MinDist = 101;
	for (int Next = 1; Next < N; ++Next) {
		if (Next == Seat)continue;
		if (TimeTable[Hour][Min][Next]) {
			int d = abs(Seat - Next);
			if (d < MinDist)MinDist = d;
		}
	}
	return MinDist;
}
int FindSeat(int Hour, int Min) {
	int MaxDist = 0;
	int pos = -1;
	for (int i = 1; i <= N; ++i) {
		if (TimeTable[Hour][Min][i] == 0) {
			int Distance = Dist(Hour, Min, i);
			if (Distance > MaxDist) { MaxDist = Distance; pos = i; }
		}
	}
	return pos;
}
void CheckTime() {
	int GetTime = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 60; j++) {
			if (TimeTable[i][j][P] == 0)GetTime++;
		}
	}
	cout << GetTime << "\n";
}
int main() {
	cin >> N >> T >> P;
	for (int i = 0; i < T; ++i) {
		string start, end; cin >> start >> end;
		Timeset.insert({ start,end });

	}
	for (auto Time : Timeset) {
		int StartHour = stoi(Time.first.substr(0, 2)) - 9;
		int StartMin = stoi(Time.first.substr(2, 2));
		int EndHour = stoi(Time.second.substr(0, 2)) - 9;
		int EndMin = stoi(Time.second.substr(2, 2));
		int Seat = FindSeat(StartHour, StartMin);
		for (int i = StartHour; i <= EndHour; ++i) {
			if (StartHour == EndHour) {
				for (int Min = StartMin; Min < EndMin; ++Min) {
					TimeTable[i][Min][Seat] = 1;
				}
				break;
			}
			if (i == StartHour) {
				for (int Min = StartMin; Min < 60; ++Min) {
					TimeTable[i][Min][Seat] = 1;
				}
			}
			else if (i == EndHour) {
				for (int Min = 0; Min < EndMin; ++Min) {
					TimeTable[i][Min][Seat] = 1;
				}
			}
			else {
				for (int Min = 0; Min < 60; ++Min) {
					TimeTable[i][Min][Seat] = 1;
				}
			}
		}

	}
	CheckTime();
}