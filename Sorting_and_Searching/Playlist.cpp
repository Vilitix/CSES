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
    int current = 0;
    int max_cur = 0;
    map<int,int> s;
    for(int i =0;i<n;i++){
        if (!s[tab[i]]){
            s[tab[i]]=i+1;
            current++;
        }
        else{
            if ((s[tab[i]] - current) != tab[i])current = min(current+1,i-s[tab[i]]+1);
            else {current = min(current,i-s[tab[i]]+1);}
            s[tab[i]] = i+1;
        }
        max_cur = max(max_cur,current);
    }
    max_cur = max(max_cur,current);
    cout << max_cur << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}