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
    string u;
    cin >> u;
    multiset<char> s; 
    map<int,int> occ;
    for(int i =0;i<size(u);i++){
        s.insert(u[i]);
        occ[u[i]]++;
    }
    char s_res[size(u)+1];
    int i = 0;
    while(!s.empty()){
        auto el = s.begin();
        bool flag = false;
        int nb_max_occ = (size(u)-i+2)/2;
        for(int j = 0;j<26;j++){
            char cur = 'A' +j;
            if (occ[cur]>nb_max_occ){
                cout << "-1" << endl;
                return;
            }
            else if (occ[cur]==nb_max_occ){
                if (i != 0 && s_res[i-1] == cur){
                    cout << "-1" << endl;
                    return;
                }
                flag = true;
                auto eltosup = s.find(cur);
                s_res[i] = cur;
                occ[cur]--;
                i++;
                s.erase(eltosup);
            }
        }
        if (flag != true){
            if (i != 0 && s_res[i-1] == *el){
                auto x = s.upper_bound(*el);
                s_res[i]=*x;
                i++;
                occ[*x]--;
                s.erase(x);
            }
            else{
                s_res[i]=*el;
                s.erase(el);
                occ[*el]--;
                i++;
            }
    }
}
    s_res[i] = '\0';
    cout << s_res << endl;

}

int main()
{
    fastio();
    solve();
    return 0;
}