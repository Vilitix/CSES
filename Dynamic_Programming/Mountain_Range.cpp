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


template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;

    SegmentTree() : n(0) {}

    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info()) {
        init(std::vector<Info>(n_, v_));
    }

    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        int sz = (1 << (std::__lg(n - 1) + 1));
        info.assign(sz * 2, Info());
        std::function<void(int, int, int)> build = [&](int v, int l, int r) {
            if (l == r) {
                info[v] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(v + v, l, m);
            build(v + v + 1, m + 1, r);
            info[v] = info[v + v] + info[v + v + 1];
        };
        build(1, 0, n - 1);
    }

    Info rangeQuery(int v, int l, int r, int tl, int tr) {
        if (r < tl || l > tr) {
            return Info();
        }
        if (l >= tl && r <= tr) {
            return info[v];
        }
        int m = (l + r) / 2;
        return rangeQuery(v + v, l, m, tl, tr) + rangeQuery(v + v + 1, m + 1, r, tl, tr);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }

    void modify(int v, int l, int r, int i, const Info &x) {
        if (l == r) {
            info[v] = x;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) {
            modify(v + v, l, m, i, x);
        } else {
            modify(v + v + 1, m + 1, r, i, x);
        }
        info[v] = info[v + v] + info[v + v + 1];
    }

    void modify(int i, const Info &x) {
        modify(1, 0, n - 1, i, x);
    }

    Info query(int v, int l, int r, int i) {
        if (l == r) {
            return info[v];
        }
        int m = (l + r) / 2;
        if (i <= m) {
            return query(v + v, l, m, i);
        } else {
            return query(v + v + 1, m + 1, r, i);
        }
    }

    Info query(int i) {
        return query(1, 0, n - 1, i);
    }
};

const int INF = 1E9;

struct Info {
    int max;

    Info() : max(0) {}

    Info(int x) : max(x) {}
};

Info operator+(const Info &a, const Info &b) {
    return (a.max<b.max?b:a);
}

void solve()
{ 
    int n;
    cin >> n;
    vector<int> tab(n) ;
    vector<pair<int,int>> cp(n);
    for(int i=0;i<n;i++) cin>> tab[i], cp[i] = mp(tab[i],i);
    vector<int> lind(n,-1);
    vector<int> rind(n,n);
    stack<int> monostack;
    
    for(int i = 0;i<n;i++){
        while(!monostack.empty() && tab[monostack.top()] < tab[i]) {
            int idx = monostack.top();
            monostack.pop(); 
        }
        lind[i] = (monostack.empty() ? -1 : monostack.top());
        monostack.push(i);
    }
    stack<int> monostack2;
    for(int i = n-1;i>=0;i--){
        while(!monostack2.empty() && tab[monostack2.top()] < tab[i]) {
            int idx = monostack2.top();
            monostack2.pop(); 
        }
        rind[i] = (monostack2.empty() ? n : monostack2.top());
        monostack2.push(i);
    }
    vector<int> dp(n,0);
    SegmentTree<Info> dptree(n, Info(0));
    sort(cp.begin(),cp.end());
    int res = 0;
    for(int j = 0;j<n;j++){
        int i = cp[j].second;
        dp[i] = 1 + dptree.rangeQuery(lind[i]+1,rind[i]-1).max;
        dptree.modify(i,Info(dp[i]));
        res=max(res,dp[i]);
    }
    
    cout << res << endl;
    
    

}

int main()
{
    fastio();
    solve();
    return 0;
}