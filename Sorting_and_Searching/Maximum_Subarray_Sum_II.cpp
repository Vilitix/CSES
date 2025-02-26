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
    int n,a,b;
    cin >> n >> a >> b;
    vector<ll> tab(n) ;
    vector<pair<ll,ll>> prefix(n);
    for(int k=0;k<n;k++) {
        cin>> tab[k];
        if(k==0)prefix[k] = mp(tab[k],k);
        else{prefix[k]=mp(tab[k]+prefix[k-1].first,k);}
        }
    priority_queue pq(prefix.begin()+a-1,prefix.begin()+b);
    ll maxi = pq.top().first;
    for(int i =0 ;i<(n-a);i++){
        if (i<(n-b))pq.push(prefix[i+b]);
        while(pq.top().second<i+a && !pq.empty())pq.pop();
        if (!pq.empty()) maxi = max(pq.top().first-prefix[i].first,maxi);
    }
    cout << maxi << endl;

}

int main()
{
    fastio();
    solve();
    return 0;
}