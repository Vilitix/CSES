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
struct tour{
    int nb;
    stack<int> s;
};

void hanoi(tour &a,tour &b,tour &c,int n,string &res, ll &count){
    if (n ==0) return;
    hanoi(a,c,b,n-1,res,count);
    int right = (a.s).top();
    count++;
    res += to_string(a.nb) + " " + to_string(c.nb) + "\n";
    (a.s).pop();
    (c.s).push(right);
    hanoi(b,a,c,n-1,res,count);
}

void solve()
{ 
    int n;
    cin >> n;
    stack<int> x;
    stack<int> y;
    stack<int> z;
    tour a = {1,x};
    tour b = {2,y};
    tour c = {3,z};
    for(int i = n-1;i>=0;i--){
        (a.s).push(i);
    }
    string res = "";
    ll count = 0;
    hanoi(a,b,c,n,res,count);
    cout << count << endl;
    cout << res << endl;
    


    
}



int main()
{
    fastio();
    solve();
    return 0;
}