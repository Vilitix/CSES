#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
        tree_order_statistics_node_update>
    mod_set;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{ 
    int n,k;
    cin >> n >> k;
    vector<int> tab(n) ;
    for(int i=0;i<n;i++) cin>> tab[i];
    mod_set s;
    for(int i = 0;i<k;i++)s.insert(mp(tab[i],i));
    cout << (*s.find_by_order(((k-1)/2))).first << " ";
    for(int i = 0;i<n-k;i++){
        int l = tab[i];
        int r = tab[i+k];
        s.erase(s.find(mp(l,i)));
        s.insert(mp(r,i+k));
        cout << (*s.find_by_order(((k-1)/2))).first << " ";
    } 
    cout << endl;
    
    
}

int main()
{
    fastio();
    solve();
    return 0;
}