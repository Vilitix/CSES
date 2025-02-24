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


void reci (vector<string> &res, vector<char> &current, vector<char> &trad, int t, map<char,int> &occ, int mini){
    if (t == (size(trad))){
        res.pb(string(current.begin(),current.end()));
    }
    else{
        for(int i = mini;i<size(current);i++){
            if (current[i] == '0'){
                current[i] = trad[t];
                occ[trad[t]]--;
                if (occ[trad[t]] != 0){
                    reci(res,current,trad,t,occ,i+1);
                }
                else{
                    reci(res,current,trad,t+1,occ,0); 
                }
                occ[trad[t]]++;
                current[i] = '0';
            }

        }
    }
}

void solve()
{ 
    string s;
    cin >> s;
    map<char,int> occ;
    vector<char> trad;
    for(int i=0;i<size(s);i++){
        if (!occ[s[i]])trad.pb(s[i]);
        occ[s[i]]++;
    }
    vector<char> current(size(s),'0');
    vector<string> res;
    reci(res,current,trad,0,occ,0); 
    cout << size(res) << endl;
    sort(res.begin(),res.end());
    for(auto x:res){
        cout << x << endl;
    }
}


int main()
{
    fastio();
    solve();
    return 0;
}