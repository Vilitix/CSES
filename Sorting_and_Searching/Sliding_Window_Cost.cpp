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
    int n,k;
    cin >> n >> k;
    vector<int> tab(n) ;
    for(int i=0;i<n;i++) cin>> tab[i];
    set<pair<int,int>> l;
    set<pair<int,int>> r;
    ll sum_l = 0;
    ll sum_r = 0;
    vector<pair<int,int>> init_med;
    for(int i = 0;i<k;i++){
        init_med.pb(mp(tab[i],i));
    }
    sort(init_med.begin(),init_med.end());
    for(int i = 0;i<k;i++){
        if (i<=(k-1)/2) l.insert(init_med[i]),sum_l+=init_med[i].first;
        else{r.insert(init_med[i]),sum_r+=init_med[i].first;}
    }
    auto compute_cost = [&](int x){
        return (((k+1)/2)*x - sum_l) + (sum_r-((k)/2)*x);
    };
    cout << compute_cost((*l.rbegin()).first) << " ";
    for(int i = 0;i<n-k;i++){
        int rm = tab[i];
        int add = tab[i+k];
        auto itrm = l.find(mp(rm,i));
        if (itrm != l.end()) l.erase(itrm),sum_l-=rm;
        else{r.erase(r.find(mp(rm,i))),sum_r-=rm;}
        if (l.upper_bound(mp(add,i+k)) != l.end()) l.insert(mp(add,i+k)),sum_l+=add;
        else{r.insert(mp(add,i+k)),sum_r+=add;}
        // correcting problem of sizes 
        while (!((l.size() - r.size())<=1)){
            if (l.size() < (k+1)/2){
                auto el = r.begin();
                l.insert(*el);
                sum_l+=el->first;
                sum_r-=el->first;
                r.erase(*el);
            }
            else{
                auto el = l.rbegin();
                r.insert(*el);
                sum_l-=el->first;
                sum_r+=el->first;
                l.erase(*el);
            }
        }
        cout << compute_cost((*l.rbegin()).first) << " ";
    } 
    cout << endl;
    
    
}

int main()
{
    fastio();
    solve();
    return 0;
}