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
    int n,m;
    cin>>n>>m;
    int dp[n+1][m+2];
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    mem0(dp);
    int sum=0;
    if(a[1]==0){
        for(int i=1;i<=m;i++)
        dp[1][i]=1;
    }else{
        dp[1][a[1]]=1;
    }
    for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++) {
                if(a[i]==0 || j==a[i])
                (dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] + dp[i-1][j]) %= mod;
            }
        }
    for(int i=1;i<=m;i++)
    {
        (sum+=dp[n][i])%=mod;
    }
    cout<<sum<<endl;
}

int32_t main() {
    nitin;

    solve();
}