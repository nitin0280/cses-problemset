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

struct node{
    int val;
    int type;
    node(){
        val=0;
        type=1;//add
    }
};
int t[800001];
node lz[800001];

void prop(int i,int s,int e){
    if(lz[i].type==1){
        t[i]+=lz[i].val*(e-s+1);
        if(s!=e){
            lz[2*i].val+=lz[i].val;
            lz[2*i+1].val+=lz[i].val;
        }
        lz[i].val=0;
    }else{
        t[i]=lz[i].val*(e-s+1);
        if(s!=e){
            lz[2*i].val=lz[i].val;
            lz[2*i+1].val=lz[i].val;
            lz[2*i].type=lz[2*i+1].type=2;
        }
        lz[i].type=1;
        lz[i].val=0;
    }
}
void u(int i,int s,int e,int l,int r,int type,int val){
    prop(i,s,e);
    if(l>e || r<s){
        return;
    }
    if(s>=l && e<=r){
        if(type==1){
            lz[i].type=1;
            lz[i].val=val;
        }else{
            lz[i].type=2;
            lz[i].val=val;
        }
        prop(i,s,e);
        return;
    }
    int m=(s+e)/2;
    u(2*i,s,m,l,r,type,val);
    u(2*i+1,m+1,e,l,r,type,val);
    t[i]=t[2*i]+t[2*i+1];
}
int q(int i,int s,int e,int l,int r){
    prop(i,s,e);
    if(e<l || s>r){
        return 0;
    }
    if(s>=l && e<=r){
        return t[i];
    }
    int m=(s+e)/2;
    int left=q(2*i,s,m,l,r);
    int right=q(2*i+1,m+1,e,l,r);
    t[i]=t[2*i]+t[2*i+1];
    return left+right;
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        u(1,0,n-1,i,i,1,val);
    }
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int a,b,x;
            cin>>a>>b>>x;
            --a;--b;
            u(1,0,n-1,a,b,1,x);
        }else if(type==2){
            int a,b,x;
            cin>>a>>b>>x;
            --a;--b;
            u(1,0,n-1,a,b,2,x);
        }else{
            int a,b;
            cin>>a>>b;
            --a;--b;
            cout<<q(1,0,n-1,a,b)<<endl;
        }
    }
}

int32_t main() {
    nitin;

    solve();
}