#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<char> word(n + m);
	for (int i = 0; i < n + m; ++i) {
		if (i < n)word[i] = 'a';
		else { word[i] = 'z'; }
	}
	for (int i = 1; i < k; ++i) {
		next_permutation(word.begin(), word.end());
	}
	for (int i = 0; i < n + m; ++i) {
		cout << word[i];
	}
}

//�����ڵ�
//�׳� ������ ���վ�
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



int n = 0, m = 0;
int k = 0;

long long dp[101][101];




int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= 100; i++)
		dp[i][0] = 1, dp[0][i] = 1;

	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (dp[i][j] > 1000000000) dp[i][j] = 1000000000;
		}

	int a_cnt = n;
	int z_cnt = m;
	if (dp[n][m] < k) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < n + m; i++) {
		int a_start = dp[a_cnt - 1][z_cnt];
		int z_start = dp[a_cnt][z_cnt - 1];

		//cout << a_start << endl;
		if (a_cnt == 0) {
			cout << 'z';
			z_cnt--;
			continue;
		}
		else if (z_cnt == 0) {
			cout << 'a';
			a_cnt--;
			continue;
		}

		if (k <= a_start) {
			cout << 'a';
			a_cnt--;
		}
		else {
			k = k - a_start;
			cout << 'z';
			z_cnt--;
		}


	}

	cout << "\n";
	return 0;
}

#include <iostream>

#include <string>

#include <algorithm>

#include <cstring>

using namespace std;



const int MAX = 100 + 1;



int N, M, K;

string word;

bool noWord;

int cache[MAX][MAX];



int possibleNumOfWord(int A, int Z)

{

	//���� ���

	if (A == 0 || Z == 0)return 1;
	int& result = cache[A][Z];

	if (result != -1)

		return result;



	//a�� ���� ���� z�� ���� ��� ��� ���

	//1,000,000,000�� ������ ���� �����ϴ� �ܾ� X

	result = min(possibleNumOfWord(A - 1, Z) + possibleNumOfWord(A, Z - 1), 1000000000 + 1);

	return result;

}



void getWord(int A, int Z, int skip)

{

	//z�� ������ ���

	if (A == 0)

	{

		for (int i = 0; i < Z; i++)

			word += 'z';

		return;

	}

	//a�� ������ ���

	if (Z == 0)

	{

		for (int i = 0; i < A; i++)

			word += 'a';

		return;

	}



	int idx = possibleNumOfWord(A - 1, Z); //a�� �� �տ� ���Ͽ��� ��� ������ ������ ��

	//�� ����� ������ �ǳʶپ���� ���� ���ٸ� a �߰�

	if (skip < idx)

	{

		word += 'a';

		getWord(A - 1, Z, skip);

	}

	//�� ����� ������ �ǳʶپ���� ���� ũ�� 1,000,000,000���� ���ų� �۴ٸ� z �߰�

	else  if (skip <= 1000000000)

	{

		word += 'z';

		getWord(A, Z - 1, skip - idx);

	}

	else //a�� z ��� �߰� �Ұ����ϹǷ� ���� �����ϴ� �ܾ ����

		noWord = true;

}



int main(void)

{

	cin >> N >> M >> K;



	noWord = false;

	memset(cache, -1, sizeof(cache));



	if (K > possibleNumOfWord(N, M)) //������ �����ϴ� �ܾ���� �������� ū K��° �ܾ ���� �� ����

		noWord = true; //���� �����ϴ� �ܾ ����

	else

		getWord(N, M, K - 1); //K - 1�� �ǳ� �� �ܾ ���Ѵ�



	if (noWord) //���� �����ϴ� �ܾ ���� ���

		cout << -1 << endl;

	else

		cout << word << endl;



	return 0;

}
