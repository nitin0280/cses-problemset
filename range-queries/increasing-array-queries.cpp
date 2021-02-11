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


//templates:- nitin0280/cp_template
class fente {
public:
    int n;
    vector<int> tree;

    void init(int _n) {
        n = _n;
        tree.resize(n + 5, 0);
    }

    void update(int idx, int inc) {
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
    int n;
    cin>>n;
    int a[n+2];
    int cont[n+2];
    int ans[n+2];
    int pref[n+2];
    mem0(cont);
    mem0(pref);
    mem0(ans);
    int q;
    cin>>q;
    vector<pair<int,int>>v[n+2];
    pref[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i+1];
        pref[i+1]=a[i+1]+pref[i];
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        v[l].pb({r,i});
    }
    a[n+1]=inf;
    deque<int>dq;
    dq.push_back(n+1);
    fente f;
    f.init(n+2);
    for(int i=n;i>=1;i--){
        while(a[i]>=a[dq.front()]){
            f.update(dq.front(),-cont[dq.front()]);
            cont[dq.front()]=0;
            dq.pop_front();
        }
        cont[i]=(dq.front()-i)*a[i]-(pref[dq.front()-1]-pref[i-1]);
        f.update(i,cont[i]);
        dq.push_front(i);
        for(auto c:v[i]){
            int r=dq.size();
            int l=0;
            while(l+1<r){
                int m=(l+r)/2;
                if(dq[m]<=c.f){
                    l=m;
                }else{
                    r=m;
                }
            }
            int pos=dq[l];
            int op1=f.query(pos);
            int x=(dq[l+1]-c.f-1)*a[pos];
            int y=(pref[dq[l+1]-1]-pref[c.f]);
            ans[c.s]=op1-(x-y);
        }
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int32_t main() {
    nitin;

    solve();
}