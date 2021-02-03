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

//can be done with pb_ds but i dont know them -_-
//fenwick tree from https://github.com/nitin0280/cp_template
class fente {
public:
    vector<int> tree;
    int n;

    fente(int _n) {
        n = _n;
        tree.resize(2 * n + 1, 0);
    }

    int query(int l) {
        int sum = 0;
        for (int i = l; i >= 1; i -= i & -i)
            sum += tree[i];
        return sum;
    }

    void update(int idx,int inc=-1) {
        for (int i = idx; i <= 2 * n; i+=i&-i) {
            tree[i] += inc;
        }
    }
};
void solve() {
    int n;
    cin>>n;
    fente f(n);
    for(int i=1;i<=2*n;i++){
        f.update(i,1);
    }
    int k;
    cin>>k;
    int cnt=n;
    int s=(k%n);
    while(true){
        cout<<s+1<<endl;
        cnt--;
        if(cnt==0)
            break;
        f.update(s+1);
        f.update(s+1+n);
        int l=s;
        int r=2*n+1;
        while(l+1<r){
            int m=(l+r)/2;
            dbg(f.query(m)-f.query(s+1));
            if(f.query(m)-f.query(s+1)<(k%cnt)+1){
                l=m;
            }else{
                r=m;
            }
        }
        if(l>=n){
            s=l-n;
        }else
        s=l;
    }

}

int32_t main() {
    nitin;

    solve();
}