#include<bits/stdc++.h>
/**/
#include <random>
using namespace std;

int main() {
	long long int testCaseNum = 0;
	cin >> testCaseNum;

	vector<vector<long long int>>input;
	for(long long int testCase = 1; testCase <= testCaseNum; testCase++) {
		long long int N;
		cin >> N;
		string ans = "";
		vector<string>strBegin, strEnd, strs;
		for(long long int i = 0; i < N; i++) {
			string S;
			cin >> S;

			int x = 0;
			if(S[0] != '*') {
				string T;
				while(S[x] != '*') {
					T.push_back(S[x]);
					x++;
				}
				strBegin.push_back(T);
			}

			x++;
			string T;
			while(x < S.length()) {
				while(x < S.length() && S[x] != '*') {
					T.push_back(S[x]);
					x++;
				}
				if(x < S.length()) {
					strs.push_back(T);
					ans += T;
					T = "";
				}
				x++;
			}

			if(T != "") {
				strEnd.push_back(T);
			}
		}

		string startString = "", endString = "";
		for(auto s : strBegin) {
			for(long long int i = 0; i < min(s.length(), startString.length()); i++) {
				if(s[i] != startString[i]) {
					ans = "*";
					//cout << 1 << " " << s << endl;
					break;
				}

			}
			if(ans == "*") {
				break;
			} else {
				if(s.length() > startString.length()) {
					startString = s;
				}
			}
		}

		if(ans != "*") {
			for(auto s : strEnd) {
				for(long long int i = 0; i < min(s.length(), endString.length()); i++) {
					if(s[s.length() - i - 1] != endString[endString.length() - i - 1]) {
						ans = "*";
						//cout << 2 << " " << s << endl;
						break;
					}
				}

				if(ans == "*") {
					break;
				} else {
					if(s.length() > endString.length()) {
						endString = s;
					}
				}
			}
		}

		if(ans != "*") {
			ans = startString + ans + endString;
		}

		cout << "Case #" << testCase << ": ";
		cout << ans;
		cout << endl;
	}
}

