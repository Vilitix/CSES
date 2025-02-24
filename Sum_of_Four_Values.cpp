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

pair<ll,ll> b_search(ll x,ll no1, ll no2,vector<pair<ll,pair<ll,ll>>> &tab){
    int l=0,r=size(tab)-1;
    while(l<=r){
        int mid = (l+r)/2;
        if (tab[mid].first == x ){ 
            if (tab[mid].second.first != no1 && tab[mid].second.first != no2 && tab[mid].second.second != no1 && tab[mid].second.second != no2) return tab[mid].second;
            else{
                int current = mid+1;
                while(current<size(tab) && tab[current].first == x){
                    if(tab[current].second.first != no1 && tab[current].second.first != no2 && tab[current].second.second != no1 && tab[current].second.second != no2) return tab[current].second;
                    current++;
                }
                current = mid-1;
                while(current>=0 && tab[current].first == x){
                    if(tab[current].second.first != no1 && tab[current].second.first != no2 && tab[current].second.second != no1 && tab[current].second.second != no2) return tab[current].second;
                    current--;
                } 
                return mp(-1,-1);
            }
        }
        else if (tab[mid].first<x){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return mp(-1,-1);
}

void solve()
{ 
    int n,x;
    cin >> n >> x;
    vector<ll> tab(n) ;
    for(int k=0;k<n;k++) cin>> tab[k];
    vector<pair<ll,pair<ll,ll>>> dtab(n*n,mp(LLONG_MAX,mp(0,0))) ;
    for(int i = 0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dtab[i*n+j] = mp(tab[i]+tab[j],mp(i+1,j+1));
        }
    }
    sort(dtab.begin(),dtab.end());
    for(int i = 0;i<size(dtab);i++){
        if (x-dtab[i].first > 1 ){
            pair<ll,ll> el = b_search(x-dtab[i].first,dtab[i].second.first,dtab[i].second.second,dtab);
            if (el.first != -1){
                ll res[4] = {dtab[i].second.first,dtab[i].second.second,el.first,el.second};
                sort(res,res+4);
                cout << res[0] << " " << res[1] << " "<<  res[2] << " " << res[3] << endl;
                return;
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