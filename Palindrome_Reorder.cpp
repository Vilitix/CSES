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
    string s;
    cin >> s;
    map<char,int> occ;
    int n = size(s);
    for(auto x:s) occ[x]++;
    string new_s = s;
    bool seen_imp = false;
    int i = 0;
    for (auto [c,oc]:occ){
        if(oc&1){
            if ((size(s)&1)&&!seen_imp){
                seen_imp = true;
                new_s[n/2] = c;
                oc--;
            }
            else{
            cout << "NO SOLUTION" << endl;
            return;
            }
        }
        while(oc != 0){
        new_s[i] = c;
        new_s[n-i-1] = c;
        i++;
        oc-=2;
        }
    }
    cout << new_s << endl;
    
}

int main()
{
    fastio();
    solve();
    return 0;
}