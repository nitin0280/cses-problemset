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

int t[800001];
void u(int idx,int s,int e,int i,int val){
    if(i>e) return;
    if(i<s) return;
    if(s==e){
        t[idx]=val;
        return;
    }
    int m=(s+e)/2;
    u(2*idx+1,s,m,i,val);
    u(2*idx+2,m+1,e,i,val);
    t[idx]=min(t[2*idx+1],t[2*idx+2]);
}
int q(int idx,int s,int e,int l,int r){
    if(l>e || r<s) return INT_MAX;
    if(s>=l && e<=r) return t[idx];
    int m=(s+e)/2;
    return min(q(2*idx+1,s,m,l,r),q(2*idx+2,m+1,e,l,r));
}
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        u(1,0,n-1,i,val);
    }
    dbg(q(1,0,n-1,0,n-1));
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int idx,val;
            cin>>idx>>val;
            --idx;
            u(1,0,n-1,idx,val);
        }else{
            int l,r;
            cin>>l>>r;
            --l;--r;
            cout<<q(1,0,n-1,l,r)<<endl;
        }
    }
}

int32_t main() {
    nitin;

    solve();
}