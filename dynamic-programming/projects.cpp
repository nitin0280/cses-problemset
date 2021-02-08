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


void solve() {
    int n;
    cin>>n;
    vector<vector<int>>v;
    vector<int>uniq;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        uniq.pb(a);
        uniq.pb(b);
        v.pb({a,b,c});
    }
    sort(all(uniq));
    uniq.erase(unique(all(uniq)),uniq.end());
    map<int,int>m;
    int s=1;
    for(auto &c:uniq)
        m[c]=s++;
    vector<pair<int,int>>idx[2*n+1];
    for(auto &c:v){
        c[0]=m[c[0]];
        c[1]=m[c[1]];
        idx[c[1]].pb({c[0],c[2]});
    }
    int dp[2*n+1];
    mem0(dp);
    int ans=0;
    for(int i=1;i<=2*n;i++){
        dp[i]=dp[i-1];
        for(auto c:idx[i]){
            dp[i]=max(dp[i],dp[c.f-1]+c.s);
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}

int32_t main() {
    nitin;

    solve();
}