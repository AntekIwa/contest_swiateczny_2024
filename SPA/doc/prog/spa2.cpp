/*
  22.12.2024
  Rozwiązanie O(n*k) - Antoni Iwanowski
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
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= k || i - j >= 0; j++) dp[i] = (dp[i] + dp[i - j])%mod;
	}
	cout << dp[n];
}
