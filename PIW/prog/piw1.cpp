/*
  22.12.2024
  Rozwiazanie O(n log max(h[i])) - Filip Nowak
*/

#include <bits/stdc++.h>
#define nl endl
#define pb push_back
#define ll long long
using namespace std;
const int maxn = 1e5+5;
int n, v;
// n log n
int ans = 0;
vector <int> h;

ll sumuj(int H) {
    ll suma = 0;
    for (int i = 0; i < n; i++) suma += min(h[i], H);
    return suma;
}

void f() {
    sort(h.begin(), h.end());
    
    int l = 0, r = h[n-1];
    int s;
    ans = r;
    while (l <= r) {
        s = (l+r+1) / 2;
        ll temp = sumuj(s);
        if(temp >= v) {
            ans = s;
            r = s-1;
        } 
        else l = s + 1;
    }
}
    
    

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> v;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h.pb(x);
    }
    
    f();
    if (sumuj(ans) < v) cout << "NIE" << nl;
    else cout << ans << nl;
}