//Antoni Iwanowski
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define int long long


void solve(){
    int n; cin >> n;
    vector<int> p(n + 7, 0), skladowe(n + 7, 0), vist(n + 7,0), ktora(n + 7, 0);
    for(int i = 1; i <= n; i++) cin >> p[i];
    string s; cin >> s;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(vist[i] == 0){
            cnt++;
            queue<int> q;
            q.push(i);
            int v;
            while(!q.empty()){
                v = q.front();
                ktora[v] = cnt;
                vist[v] = 1;
                q.pop();
                if(s[v - 1] == '0') skladowe[cnt]++;
                if(!vist[p[v]]){
                    vist[p[v]] = 1;
                    q.push(p[v]);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << skladowe[ktora[i]] << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}
