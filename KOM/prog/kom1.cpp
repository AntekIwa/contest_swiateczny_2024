/*
	23.12.2024
	Rozwiązanie O((n*m)log (inf)) - Antoni Iwanowski
*/

#include<bits/stdc++.h>

using namespace std;

const int maxn = 8007;
const int inf = 1e9 + 7;
int dp[maxn][maxn];
int grid[maxn][maxn];
int n, m,k;

bool check(int M){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++) dp[i][j] = inf;
	}
	dp[0][0] = 0;
	for(int i = 1; i < m; i++){
		if(dp[0][i-1] == inf) continue;

		if(grid[0][i] == -1) continue;
		else if(grid[0][i] == 0) dp[0][i] = 0;
		else if(grid[0][i] <= grid[0][i-1]) dp[0][i] = dp[0][i-1];
		else if(grid[0][i] <= grid[0][i-1] + M){
			if(dp[0][i-1] == k) dp[0][i] = inf;
			else dp[0][i] = dp[0][i - 1] + 1;
		}
	}
	for(int i = 1; i < n; i++){
		if(dp[i - 1][0] == inf) continue;

		if(grid[i][0] == -1) continue;
		else if(grid[i][0] == 0) dp[i][0] = 0;
		else if(grid[i][0] <= grid[i - 1][0]) dp[i][0] = dp[i-1][0];
		else if(grid[i][0] <= grid[i - 1][0] + M){
			if(dp[i - 1][0] == k) dp[i][0] = inf;
			else dp[i][0] = dp[i - 1][0] + 1;
		}
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(grid[i][j] == -1) continue;
			if(dp[i - 1][j] != inf){
				if(grid[i][j] == 0) dp[i][j] = 0;
				else if(grid[i][j] <= grid[i - 1][j]) dp[i][j] = dp[i - 1][j];
				else if(grid[i][j] <= grid[i-1][j] + M){
					if(dp[i - 1][j] == k) dp[i][j] = inf;
					else dp[i][j] = dp[i - 1][j] + 1;
				}
			}
			if(dp[i][j - 1] != inf){
				if(grid[i][j] == 0) dp[i][j] = 0;
				else if(grid[i][j] <= grid[i][j - 1]) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				else if(grid[i][j] <= grid[i][j-1] + M){
					if(dp[i][j - 1] == k) dp[i][j] = min(dp[i][j],inf);
					else dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
				}
			}
		}
	}
	return (dp[n - 1][m - 1] <= k);
}

int solve(){
	int l = 0, r = inf, mid, res = inf;
	while(l <= r){
		mid = (l + r)/2;
		if(check(mid)){
			res = min(res, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> grid[i][j];
	}
	int res = solve();
	if(res == inf) cout << "NIE\n";
	else cout << res;
}
