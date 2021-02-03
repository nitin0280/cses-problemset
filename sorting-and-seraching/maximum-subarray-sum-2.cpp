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
    int n,a,b;
    cin>>n>>a>>b;
    int v[n+1],s[n+1];
    v[0]=s[0]=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s[i]=v[i];
        s[i]+=s[i-1];
        dbg(s[i]);
    }
    int ans=s[a];
    map<int,int>m;
    m[0]++;
    for(int i=a+1;i<=n;i++){
        m[s[i-a]]++;
        if(i-b>0){
            m[s[i-b-1]]--;
            if(m[s[i-b-1]]==0)
                m.erase(s[i-b-1]);
        }
        dbg(m);
        ans=max(ans,s[i]-m.begin()->first);
    }
    cout<<ans<<endl;

}

int32_t main() {
    nitin;

    solve();
}