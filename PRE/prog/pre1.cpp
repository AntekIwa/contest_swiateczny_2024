#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q; cin >> n >> q;
	int mini = 1e9, maxx = 0;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		mini = min(mini,a);
		maxx = max(maxx, a);
	}
	cout << maxx - mini << "\n";
	while(q--){
		char typ; cin >> typ;
		if(typ == '?') cout << maxx- mini << "\n";
		else{
			cin >> a;
			mini = min(mini,a);
			maxx = max(maxx, a);
		}
	}
}
