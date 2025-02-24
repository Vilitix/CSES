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
    vector<pair<pair<int,int>, int>> tab; // ((start,end),index)
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        auto p = mp(l, r);
        tab.pb({p,i});
    }
    sort(tab.begin(),tab.end());
    multiset<pair<int,int>> q;
    vector<int> affected(n);
    int maxi = 1;
    for(int i = 0;i<n;i++){
        auto it = q.lower_bound(mp(tab[i].first.first,0));
        if (it!=q.begin()){
            it--;
            int num = (*it).second;
            q.erase(it);
            q.insert(mp(tab[i].first.second,num));
            affected[tab[i].second] = num;
        }
        else{
            q.insert(mp(tab[i].first.second,q.size()+1));
            maxi = max(maxi,(int)q.size());
            affected[tab[i].second] = q.size();
        }
    }
    cout << maxi << endl;
    for(auto x:affected){
        cout << x << " " ;
    }
    cout << endl;
}

int main()
{
    fastio();
    solve();

    return 0;
}