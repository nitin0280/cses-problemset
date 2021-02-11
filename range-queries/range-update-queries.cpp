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
int l[800001];
void prop(int idx,int s,int e) {
    t[idx] += l[idx];
    if (s != e) {
        l[2 * idx + 1] += l[idx];
        l[2 * idx + 2] += l[idx];
    }
    l[idx] = 0;
}
void u(int idx,int s,int e,int ll,int r,int val){
    prop(idx,s,e);
    if(ll>e) return;
    if(r<s) return;
    if(s>=ll && e<=r){
        l[idx]+=val;
        prop(idx,s,e);
        return;
    }
    int m=(s+e)/2;
    u(2*idx+1,s,m,ll,r,val);
    u(2*idx+2,m+1,e,ll,r,val);
    t[idx]=(t[2*idx+1]+t[2*idx+2]);
}
int q(int idx,int s,int e,int l,int r){
    prop(idx,s,e);
    if(l>e || r<s) return 0;
    if(s>=l && e<=r) return t[idx];
    int m=(s+e)/2;
    int val= (q(2*idx+1,s,m,l,r)+q(2*idx+2,m+1,e,l,r));
    t[idx]=(t[2*idx+1]+t[2*idx+2]);
    return val;
}
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        u(1,0,n-1,i,i,val);
    }
    dbg(q(1,0,n-1,0,n-1));
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int l,r,val;
            cin>>l>>r>>val;
            --l;--r;
            u(1,0,n-1,l,r,val);
        }else{
            int k;
            cin>>k;
            --k;
            cout<<q(1,0,n-1,k,k)<<endl;
        }
    }
}

int32_t main() {
    nitin;

    solve();
}