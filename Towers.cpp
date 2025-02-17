#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{ 
    int n;
    cin >> n;
    vector<int> tab(n) ;
    for(int k=0;k<n;k++) cin>> tab[k];
    multiset<int> s;
    int res = 0;
    for(int i = 0;i<n;i++){
        auto el = s.upper_bound(tab[i]);
        if (el==s.end()){
            res++;
            s.insert(tab[i]);
        }
        else{
            s.erase(el);
            s.insert(tab[i]);
        }
        
    }
    cout << res << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}