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

ll b_search(ll x,ll no1, ll no2,vector<pair<ll,ll>> &tab){
    int l=0,r=size(tab)-1;
    while(l<=r){
        int mid = (l+r)/2;
        if (tab[mid].first == x ){ 
            if (tab[mid].second != no1 && tab[mid].second != no2) return tab[mid].second;
            else{
                int current = mid+1;
                while(current<size(tab) && tab[current].first == x){
                    if(tab[current].second != no1 && tab[current].second != no2) return tab[current].second;
                    current++;
                }
                current = mid-1;
                while(current>=0 && tab[current].first == x){
                    if(tab[current].second != no1 && tab[current].second != no2) return tab[current].second;
                    current--;
                } 
                return -1;
            }
        }
        else if (tab[mid].first<x){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}

void solve()
{ 
    int n,x;
    cin >> n >> x;
    vector<pair<ll,ll>> tab(n) ;
    for(ll k=0;k<n;k++){ 
        ll el;
        cin>> el;
        tab[k] = mp(el,k+1);}
    sort(tab.begin(),tab.end());
    for(ll i = 0;i<n;i++){
        for(ll j = i+1;j<n;j++){
            if (tab[i].first + tab[j].first < x){
                ll el = b_search(x - tab[i].first - tab[j].first,tab[i].second,tab[j].second,tab);
                if (el != -1){
                    ll res[3] = {tab[i].second,tab[j].second,el};
                    sort(res,res+3);
                    cout << res[0] << " " << res[1] << " "<<  res[2] << endl;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}