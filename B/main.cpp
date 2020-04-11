#include<bits/stdc++.h>
/**/
#include <random>
using namespace std;


class combination {
public:

	//Nの最大値がわかれば代入する
	combination(long long int combinationThreshold = 1e7) {
		(*this).combinationThreshold = combinationThreshold + 2;
	}

	//a^p % mod
	long long int powmod(long long int A, long long int P, long long int M = LLONG_MAX) {
		long long int ans = 1;
		long long int mul = A;
		for(; P > 0; P >>= 1, mul = (mul * mul) % M) {
			if((P & 1) == 1) ans = (ans * mul) % M;
		}
		return ans;
	}

	//nCk mod m
	long long int cb(long long int N, long long int K, long long int M = LLONG_MAX) {
		if(N < combinationThreshold) {// 事前計算O(N)、答えるのはO(1)
			if(inv.size() == 0) {
				inv = vector<long long int>(combinationThreshold);
				inv[1] = 1;
				for(long long int i = 2; i < combinationThreshold; i++) {
					inv[i] = M - (M / i) * inv[M % i] % M;
				}
				fact = vector<long long int>(combinationThreshold);
				fact[0] = 1;
				revFact = vector<long long int>
					(combinationThreshold);
				revFact[0] = 1;
				for(long long int i = 1; i < combinationThreshold; i++) {
					fact[i] = (fact[i - 1] * i) % M;
					revFact[i] = (revFact[i - 1] * inv[i]) % M;
				}
			}
			return (((fact[N] * revFact[K]) % M) * revFact[N - K]) % M;
		} else {
			return cbOnce(N, K, M);
		}
	}

	//一回だけなら最速 O(K + log(M))
	long long int cbOnce(long long int N, long long int K, long long int M = LLONG_MAX) {
		if(K > N / 2) return cb(N, N - K, M);
		long long int ans = 1;
		long long int div = 1;
		for(long long int i = 0; i < K; i++) {
			ans *= N - i;
			ans %= M;
			div *= i + 1;
			div %= M;
		}
		ans *= powmod(div, M - 2, M);
		return ans % M;
	}

private:
	vector<vector<long long int>>C;//3000以下の答え
	vector<long long int>fact;//階乗
	vector<long long int>revFact;//階乗の逆元
	vector<long long int>inv;//mod pでの逆元

	long long int combinationThreshold;//Nの最大値がわかれば入れる。
};





int main() {
	long long int testCaseNum = 0;
	cin >> testCaseNum;

	combination cb = combination(501);

	vector<vector<long long int>>input;
	for(long long int testCase = 1; testCase <= testCaseNum; testCase++) {
		long long int N;
		cin >> N;

		long long int downnum = 0;
		while(downnum * (downnum + 1) / 2 < N) {
			downnum++;
		}
		downnum--;
		long long int leftnum = N - 1 - downnum * (downnum + 1) / 2;



		cout << "Case #" << testCase << ":" << endl;
		cout << 1 << " " << 1 << endl;
		for(long long int i = 0; i < downnum; i++) {
			cout << i + 2 << " " << 2 << endl;
			if(leftnum > 0) {
				leftnum--;
				cout << i + 2 << " " << 1 << endl;
			}
		}
		//cout << endl;
	}
}

