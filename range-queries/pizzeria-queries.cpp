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


class segte_sub{
public:
    vector<int>t;
    int n ;
    void init(int _n){
        n=_n;
        t.resize(4*n+1,0);
    }
    void u(int i,int s,int e,int idx,int val){
        if(idx>e || idx<s){
            return;
        }
        if(s==e){
            t[i]=val-idx;
            return;
        }
        int m=(s+e)/2;
        u(2*i,s,m,idx,val);
        u(2*i+1,m+1,e,idx,val);
        t[i]=min(t[2*i],t[2*i+1]);
    }
    int qry(int i,int s,int e,int l,int r){
        if(l>e || r<s)
            return INT_MAX;
        if(s>=l && e<=r){
            return t[i];
        }
        int m=(s+e)/2;
        return min(qry(2*i,s,m,l,r),qry(2*i+1,m+1,e,l,r));
    }
};
class segte_sum{
public:
    vector<int>t;
    int n ;
    void init(int _n){
        n=_n;
        t.resize(4*n+1,0);
    }
    void u(int i,int s,int e,int idx,int val){
        if(idx>e || idx<s){
            return;
        }
        if(s==e){
            t[i]=val+idx;
            return;
        }
        int m=(s+e)/2;
        u(2*i,s,m,idx,val);
        u(2*i+1,m+1,e,idx,val);
        t[i]=min(t[2*i],t[2*i+1]);
    }
    int qry(int i,int s,int e,int l,int r){
        if(l>e || r<s)
            return INT_MAX;
        if(s>=l && e<=r){
            return t[i];
        }
        int m=(s+e)/2;
        return min(qry(2*i,s,m,l,r),qry(2*i+1,m+1,e,l,r));
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    int a[n];
    segte_sub s_sub;
    segte_sum s_sum;
    s_sub.init(n);
    s_sum.init(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        s_sub.u(1,0,n-1,i,a[i]);
        s_sum.u(1,0,n-1,i,a[i]);
    }
    while(q--){
        int t ;
        cin>>t;
        if(t==1){
            int k,x;
            cin>>k>>x;
            k--;
            a[k]=x;
            s_sub.u(1,0,n-1,k,a[k]);
            s_sum.u(1,0,n-1,k,a[k]);
        }else{
            int k;
            cin>>k;
            --k;
            int op1=s_sub.qry(1,0,n-1,0,k-1)+k;
            int op2=s_sum.qry(1,0,n-1,k+1,n-1)-k;
            int op3=a[k];
            cout<<min({op1,op2,op3})<<endl;
        }
    }

}

int32_t main() {
    nitin;

    solve();
}