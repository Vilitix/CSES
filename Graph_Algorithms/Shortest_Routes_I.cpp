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
    vector<vector<pair<ll,ll>>> g(n+1,vector<pair<ll,ll>>());
    for(int i = 0;i<m;i++){
        int a,b,p; 
        cin >> a >> b >> p;
        g[a].pb(mp(b,p));
    }
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
	vector<ll> distTo(n+1,LLONG_MAX); 
    vector<bool> visited(n+1,false);	 
	
	distTo[1] = 0;
	pq.push(make_pair(0,1));	
	while( !pq.empty() ){
	    ll prev = pq.top().second;
		pq.pop();	
        if(visited[prev])continue;
        visited[prev] = true;
		vector<pair<ll,ll> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			ll next = it->first;
			if( distTo[next] > distTo[prev] + it->second){
				distTo[next] = distTo[prev] + it->second;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
    for(int i = 1;i<=n;i++){
        cout << distTo[i] << " \n"[i==n];
    }



}

int main()
{
    fastio();
    solve();

    return 0;
}