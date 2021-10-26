#include <bits/stdc++.h>

typedef long double ld;
#define int long long

#define gcd            __gcd
#define endl           "\n"
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define f              first
#define s              second
#define lb             lower_bound
#define ub             upper_bound
#define ins            insert
#define sz(x)          (int)(x).size()
#define mk             make_pair
#define deci(x, y)     fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PI             3.141592653589793238
#define mem0(x)        memset(x,0,sizeof x)
#define mem1(x)        memset(x,-1,sizeof x)
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.f << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NITIN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int tr[800005];
int lz[800005];
void prop(int i,int s,int e){
    tr[i]+=lz[i];
    if(s!=e){
        lz[2*i+2]+=lz[i];
        lz[2*i+1]+=lz[i];
    }
    lz[i]=0;
}
void u(int i,int s,int e,int l,int r,int inc) {
    prop(i,s,e);
    if (l > e || r < s)
        return;
    if (s >= l && e <= r) {
        lz[i] += inc;
        prop(i, s, e);
        return;
    }
    int m = (s + e) / 2;
    u(2 * i + 1, s, m, l, r, inc);
    u(2 * i + 2, m+1, e, l, r, inc);
    tr[i] = max(tr[2 * i + 1], tr[2 * i + 2]);
}
int qry(int i,int s,int e,int l,int r){
    prop(i,s,e);
    if(l>e || r<s)
        return LONG_LONG_MIN;
    if(s>=l && e<=r){
        return tr[i];
    }
    int m=(s+e)/2;
    int left=qry(2*i+1,s,m,l,r);
    int right=qry(2*i+2,m+1,e,l,r);
    tr[i]=max(tr[2*i+1],tr[2*i+2]);
    return max(left,right);
}
void solve() {
    int n, q;
    cin >> n >> q;
    int a[n];
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        u(0, 0, n - 1, i, i, s);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx, val;
            cin >> idx >> val;
            --idx;
            u(0, 0, n - 1, idx, n - 1, val - a[idx]);
            a[idx] = val;
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            dbg(qry(0, 0, n - 1, l, r));
            dbg(qry(0, 0, n - 1, l - 1, l - 1));
            cout << max((int) 0, qry(0, 0, n - 1, l, r) - (l >= 1 ? qry(0, 0, n - 1, l - 1, l - 1) : 0)) << endl;
        }
    }
}

int32_t main() {
    nitin;

    solve();
}