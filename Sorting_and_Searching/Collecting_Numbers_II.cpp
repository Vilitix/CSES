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
    int n,m;
    cin >> n >> m;
    vector<int> tab(n+1) ;
    vector<int> pos(n+1);
    for(int k=1;k<=n;k++){
        int x;
        cin >> x;
        tab[k] = x;
        pos[x] = k;
    }
    int round = 1;
    for(int i = 1;i<n;i++){
        if (pos[i] > pos[i+1])round++;
    }
    set<pair<int,int>> to_check;
    for(int i = 0;i<m;i++){
        int x,y;
        cin >> x >> y;
        if (tab[x]>1) to_check.insert(mp(tab[x]-1,tab[x]));
        if (tab[y]>1) to_check.insert(mp(tab[y]-1,tab[y]));
        if (tab[y]<(n)) to_check.insert(mp(tab[y],tab[y]+1));
        if (tab[x]<(n)) to_check.insert(mp(tab[x],tab[x]+1));
        for (auto [a,b]:to_check){
            round -= (pos[a] > pos[b]);
        }
        swap(tab[x],tab[y]);
        pos[tab[x]]= x;
        pos[tab[y]]= y;
        for (auto [a,b]:to_check){
            round += (pos[a] > pos[b]);
        }
        cout << round << endl;
        to_check.clear();
    }

}

int main()
{
    fastio();
    solve();
    return 0;
}