/*
  22.12.2024
  rozwiazanie O(n) - Antoni Iwanowski
*/

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 +  7;
const long long mod = 1e9 + 7;
long long dp[maxn];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	dp[1] = 1;
	dp[0] = 1;
	long long ostK = 2;
	for(int i = 2; i <= n; i++){
		if(i > k) ostK = (ostK + mod - dp[i - k - 1])%mod;
		dp[i] = ostK;
		ostK = (ostK + dp[i])%mod;
	}
	cout << dp[n];
}
