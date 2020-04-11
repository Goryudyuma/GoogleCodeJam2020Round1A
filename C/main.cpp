#include<bits/stdc++.h>
/**/
#include <random>
using namespace std;




int main() {
	long long int testCaseNum = 0;
	cin >> testCaseNum;

	vector<vector<long long int>>input;
	for(long long int testCase = 1; testCase <= testCaseNum; testCase++) {
		long long int R, C;
		cin >> R >> C;

		vector<vector<long long int>>M = vector < vector < long long int >>(R, vector<long long int>(C));

		long long int ans = 0, prevScore = 0;
		for(long long int i = 0; i < R; i++) {
			for(long long int j = 0; j < C; j++) {
				cin >> M[i][j];
				prevScore += M[i][j];
			}
		}
		ans = prevScore;

		int dx[] = { 1,0,-1,0 };
		int dy[] = { 0,1,0,-1 };

		while(true) {
			auto nextM = M;
			for(long long int i = 0; i < R; i++) {
				for(long long int j = 0; j < C; j++) {
					long long int count = 0;
					long long int sum = 0;
					for(long long int k = 0; k < 4; k++) {
						long long int x = i + dx[k];
						long long int y = j + dy[k];
						while(0 <= x && x < R && 0 <= y && y < C && M[x][y] == 0) {
							x += dx[k];
							y += dy[k];
						}
						if(0 <= x && x < R && 0 <= y && y < C && M[x][y] != 0) {
							count++;
							sum += M[x][y];
						}
					}
					if(M[i][j] != 0 && count * M[i][j] < sum) {
						nextM[i][j] = 0;
					}
				}
			}

			long long int nowScore = 0;
			for(long long int i = 0; i < R; i++) {
				for(long long int j = 0; j < C; j++) {
					nowScore += nextM[i][j];
				}
			}

			if(nowScore == prevScore) {
				break;
			}
			prevScore = nowScore;
			ans += nowScore;
			M = nextM;
		}


		cout << "Case #" << testCase << ": ";
		cout << ans;
		cout << endl;
	}
}

