#include <bits/stdc++.h>

typedef long double ld;
//#define int long long

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


//1-base
class fente {
public:
    int n;
    vector<int> tree;

    void init(int _n) {
        n = _n;
        tree.resize(n , 0);
    }

    void update(int idx, int inc) {
        if(idx==0)
            return;
        for (int i = idx; i <= n; i += i & -i)
            tree[i] += inc;
    }

    int query(int idx) {
        int sum = 0;
        assert(idx<=n);
        for (int i = idx; i >= 1; i -= i & -i)
            sum += tree[i];
        return sum;
    }
};


void solve() {
    int n,m;
    cin>>n>>m;
    int a[n];
    vector<int>u;
    for(int i=0;i<n;i++){
        cin>>a[i];
        u.pb(a[i]);
    }
    vector<int>q[m];
    for(int i=0;i<m;i++) {
        char c;
        cin >> c;
        if (c == '!') {
            int k, x;
            cin >> k >> x;
            q[i] = {1, k - 1, x};
            u.pb(x);
        } else {
            int k, x;
            cin >> k >> x;
            q[i] = {2, k, x};
            u.pb(k);
            u.pb(x);

        }
    }
    sort( u.begin(), u.end() );
    u.erase( unique( u.begin(), u.end() ), u.end() );
    map<int,int>F;
    int s=1;
    for(auto &c:u){
        F[c]=s++;
    }
    for(int i=0;i<n;i++){
        a[i]=F[a[i]];
    }
    for(auto &c:q){
        if(c[0]==1){
            c[2]=F[c[2]];
        }else{
            c[1]=F[c[1]];
            c[2]=F[c[2]];
        }
    }
    fente f;
    f.init(F.size()+5);
    for(int i=0;i<n;i++){
        f.update(a[i],1);
    }
    for(int i=0;i<m;i++){
        if(q[i][0]==1){
            f.update(a[q[i][1]],-1);
            a[q[i][1]]=q[i][2];
            f.update(a[q[i][1]],1);
        }else{
            cout<<f.query(q[i][2])-f.query(q[i][1]-1)<<endl;
        }
    }
}

int32_t main() {
    nitin;

    solve();
}