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
string s;
bool visited[7][7];
vector<char> path(48);
int pas = 0;
int res = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

pair<int,int> next(pair<int,int> current,char direc){
    if (direc == 'L'){
        return mp(current.first,current.second-1);
    }
    if (direc == 'R'){
        return mp(current.first,current.second+1);
    }
    if (direc == 'D'){
        return mp(current.first+1,current.second);
    }
    if (direc == 'U'){
        return mp(current.first-1,current.second);
    }
    cout << "here" << direc << endl;
    cout << "error direc " << endl;
    return current;
}

inline bool valid(int i, int j){
    return (i >= 0) && (j >= 0) && (i < 7) && (j < 7);
}


void parcours(int i, int j,int oldi, int oldj){
    if (i == 6 && j == 0){
        if (pas == 48){
            res++;
        }
        return;
    }
    if (visited[i][j])return;
    if (((i + 1 == 7 || (visited[i - 1][j] && visited[i + 1][j])) && j - 1 >= 0 && j + 1 < 7 && !visited[i][j - 1] && !visited[i][j + 1]) ||
        ((j + 1 == 7 || (visited[i][j - 1] && visited[i][j + 1])) && i - 1 >= 0 && i + 1 < 7 && !visited[i - 1][j] && !visited[i + 1][j]) ||
        ((i == 0 || (visited[i + 1][j] && visited[i - 1][j])) && j - 1 >= 0 && j + 1 < 7 && !visited[i][j - 1] && !visited[i][j + 1]) ||
        ((j == 0 || (visited[i][j + 1] && visited[i][j - 1])) && i - 1 >= 0 && i + 1 < 7 && !visited[i - 1][j] && !visited[i + 1][j]))
        return;
    visited[i][j] = true;
    if (s[pas] == '?'){
        for(int k=0;k<4;k++){
            if (valid(i+dx[k],j+dy[k])){
                pas++;
                parcours(i+dx[k],j+dy[k],i,j);
                pas--;
        }
    }
    }
    else{
        pair<int,int> nxt = next(mp(i,j),s[pas]);
            if (valid(nxt.first,nxt.second)){
                pas++;
                parcours(nxt.first,nxt.second,i,j);
                pas--;
        }
    }
    visited[i][j] = false;
}



void solve()
{
    cin >> s;
    parcours(0,0,-1,-1);
    cout << res << endl; 


}

int main()
{
    fastio();
    solve();
    return 0;
}