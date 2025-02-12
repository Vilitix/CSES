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
    vector<pair<int,int>> tab(n) ;
    for(int k=0;k<n;k++){
        int x;
        cin >> x;
        tab[k] = mp(x,k);
    }
    sort(tab.begin(),tab.end());
    set<int> s;
    int round = 1;
    for(int i = 1;i<n;i++){
        if (tab[i].second < tab[i-1].second){
            s.insert(i);
            round++;
        }
    }
    vector<int> to_ind(n);
    for(int i = 0;i<n;i++){
        to_ind[tab[i].second] = i;
    }
    for (int i = 0;i<m;i++){
        int x,y;
        cin >> x >> y;
        y--,x--;
        int realy= to_ind[y],realx=to_ind[x];
        swap(tab[realy].second,tab[realx].second);
        swap(to_ind[y],to_ind[x]);
        if (x){
            bool b = tab[realx].second < tab[realx-1].second;
            if (b){
                if (s.find(realx) == s.end()) round++,s.insert(realx);
            }
            else{
                if (s.find(realx) != s.end()) round--,s.erase(realx);
            }
        } 
        if (y){
            bool b = tab[realy].second < tab[realy-1].second;
            if (b){
                if (s.find(realy) == s.end()) round++,s.insert(realy);
            }
            else{
                if (s.find(realy) != s.end()) round--,s.erase(realy);
            }
        }
        
        cout << round << endl;
    }
}

int main()
{
    fastio();
    solve();
    return 0;
}