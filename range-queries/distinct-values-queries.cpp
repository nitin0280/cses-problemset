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

class fente{
public:
    vector<int>t;
    int n;

    explicit fente(int _n){
        n=_n;
        t.resize(n+1,0);
    }

    void upd(int x,int inc){
        for(int i=x;i<=n;i+=i&-i){
            t[i]+=inc;
        }
    }

    int qry(int x){
        int sum=0;
        for(int i=x;i>=1;i-=i&-i){
            sum+=t[i];
        }
        return sum;
    }
};
void solve() {
    int n,q;
    cin>>n>>q;
    map<int,int>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]=1;
    }
    int s=1;
    for(auto &c:m){
        c.s=s++;
    }
    for(int i=0;i<n;i++)
        a[i]=m[a[i]];
    vector<pair<int,int>>v[n+1];
    for(int i=0;i<q;i++){
        int c,d;
        cin>>c>>d;
        v[d].pb({c,i});
    }
    int ans[q];
    int last_visit[n+10];
    mem1(last_visit);
    fente f(n+1);
    for(int i=0;i<n;i++){
        if(last_visit[a[i]]==-1){
            f.upd(i+1,1);
        }else{
            f.upd(last_visit[a[i]]+1,-1);
            f.upd(i+1,1);
        }
        last_visit[a[i]]=i;
        for(auto c:v[i+1]){
            ans[c.s]=f.qry(i+1)-f.qry(c.f-1);
        }
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }


}

int32_t main() {
    nitin;

    solve();
}