#include <bits/stdc++.h>

typedef long double ld;
#define int long long

#define gcd            __gcd
//#define endl           "\n"
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

struct node{
    int ans,tot,suff,pef;
    //default value
    node()
    {
        ans=tot=suff=pef=0;
    }
};
class segte {
public:
    int n{};
    vector<node> tree;
    vector<int> a;
    node neutral;

    void init(int N) {
        n = N;
        tree.resize(4 * n + 1);
        //default values
        a.assign(n, 0);
    }

    void put(vector<int> &val) {
        a = val;
    }

    //merge function
    void merge(node &curr, node &left, node &right) {
        curr.tot=left.tot+right.tot;
        curr.pef=max(left.tot+right.pef,left.pef);
        curr.suff=max(right.suff,right.tot+left.suff);
        curr.ans=max({left.ans,right.ans,left.suff+right.pef});
    }

    //for leaf
    void single(node &curr, int idx) {
        curr.pef=max((int)0,a[idx]);
        curr.suff=max((int)0,a[idx]);
        curr.tot=a[idx];
        curr.ans=max((int)0,a[idx]);
    }

    void build(int index, int ss, int se) {
        if (ss == se) {
            single(tree[index], ss);
            return;
        }
        int mid = (ss + se) / 2;
        build(2 * index, ss, mid);
        build(2 * index + 1, mid + 1, se);
        merge(tree[index], tree[2 * index], tree[2 * index + 1]);
    }

    void build() {
        build(1, 0, n - 1);
    }

    node query(int index, int ss, int se, int qs, int qe) {
        if (qs > se || qe < ss) return neutral;
        if (qs <= ss && qe >= se) return tree[index];
        int mid = (ss + se) / 2;
        node left = query(2 * index, ss, mid, qs, qe);
        node right = query(2 * index + 1, mid + 1, se, qs, qe);
        node mer;
        merge(mer, left, right);
        return mer;
    }

    node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int index, int idx, int ss, int se) {
        if (idx < ss || idx > se)
            return;
        if (ss == se) {
            single(tree[index], ss);
            return;
        }
        int mid = (ss + se) / 2;
        update(2 * index, idx, ss, mid);
        update(2 * index + 1, idx, mid + 1, se);
        merge(tree[index], tree[2 * index], tree[2 * index + 1]);
    }

    void update(int idx) {
        update(1, idx, 0, n - 1);
    }
};

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    segte s;
    s.init(n);
    s.put(a);
    s.build();
    while(m--){
        int i,x;
        cin>>i>>x;
        --i;
        s.a[i]=x;
        s.update(i);
        cout<<s.tree[1].ans<<endl;
    }
}

int32_t main() {
    nitin;

    solve();
}