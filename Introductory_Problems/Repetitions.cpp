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


int main()
{
    fastio();
    string s;
    cin >> s;
    int current = 1;
    int maxi = 0;
    for (int i=1;i<size(s);i++){    
        if (s[i] == s[i-1]){
            current+=1;
        }
        else{
            maxi = max(current,maxi);
            current = 1;
        }
    }
    cout << max(current,maxi) << endl;

    return 0;
}