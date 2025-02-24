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
    vector<int> tab(n+1) ;
    for(int k=1;k<=n;k++){
        cin >> tab[k];
    }
    stack<int> s;
    for(int i = 1;i<=n;i++){
        while(!s.empty() && tab[s.top()]>=tab[i]) s.pop();
        if (s.empty()){cout << 0 << " ";}
        else{
            cout << s.top() << " ";
        }
        s.push(i);
    }
    cout << endl;
    

}

int main()
{
    fastio();
    solve();
    return 0;
}