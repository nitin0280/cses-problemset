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

struct lnode{
    int a{},d{};
    lnode(){
        a=0;
        d=0;
    }
};
int t[800001];
lnode l[800001];
bool p[800001];
int a[200001];
void prop(int i,int s,int e){
    if(!p[i])
        return;
    int len=(e-s+1);
//    dbg(l[i].a,l[i].d);
    t[i]+=(len*(2*l[i].a+(len-1)*l[i].d))/2;
    if(s!=e){
        int mid=(s+e)/2;
        l[2*i].a+=l[i].a;
        l[2*i+1].a+=l[i].a+(mid-s+1)*l[i].d;
        l[2*i].d+=l[i].d;
        l[2*i+1].d+=l[i].d;
        p[2*i]=true;
        p[2*i+1]=true;
    }
    l[i].a=l[i].d=0;
    p[i]=false;
}
void build(int i,int s,int e){
    if(s==e)
    {
        t[i]=a[s];
        return;
    }
    int m=(s+e)/2;
    build(2*i,s,m);
    build(2*i+1,m+1,e);
    t[i]=t[2*i]+t[2*i+1];
}
void u(int i,int s,int e,int left,int right){
    prop(i,s,e);
    if(left>e || right<s){
        return;
    }
    if(s>=left && e<=right){
        l[i].a+=(s-left+1);
        l[i].d+=1;
        p[i]=true;
        prop(i,s,e);
        return;
    }
    int m=(s+e)/2;
    u(2*i,s,m,left,right);
    u(2*i+1,m+1,e,left,right);
    t[i]=t[2*i]+t[2*i+1];
}
int q(int i,int s,int e,int left,int right){
    prop(i,s,e);
    if(left>e || right<s)
        return 0;
    if(s>=left && e<=right)
        return t[i];
    int m=(s+e)/2;
    int x=q(2*i,s,m,left,right);
    int y=q(2*i+1,m+1,e,left,right);
    t[i]=t[2*i]+t[2*i+1];
    return x+y;
}
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    build(1,0,n-1);
//    for(int i=0;i<300;i++){
//        cout<<l[i].a<<" "<<l[i].d<<endl;
//    }
//    for(int i=0;i<n;i++){
//        cout<<q(1,0,n-1,i,i)<<" ";
//    }
//    cout<<endl;
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int l,r;
            cin>>l>>r;
            --l;--r;
            u(1,0,n-1,l,r);
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