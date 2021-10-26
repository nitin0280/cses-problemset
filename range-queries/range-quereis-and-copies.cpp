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

const int N=200001;
int t[120*N],lc[120*N],rc[120*N];
int ptr=1;
int a[N];
int build(int l,int r){
    int new_node=ptr++;
    if(l==r){
        t[new_node]=a[l];
        return new_node;
    }
    int mid=(l+r)/2;
    lc[new_node]=build(l,mid);
    rc[new_node]=build(mid+1,r);
    t[new_node]=t[lc[new_node]]+t[rc[new_node]];
    return  new_node;
}
vector<int>versions;
int which_version[N];
int upd(int i,int s,int e,int index,int value){
    if(index<s || index>e){
        return i;
    }
    int new_node=ptr++;
    if(s==e){
        t[new_node]=value;
        return new_node;
    }
    int mid=(s+e)/2;
    lc[new_node]=upd(lc[i],s,mid,index,value);
    rc[new_node]=upd(rc[i],mid+1,e,index,value);
    t[new_node]=t[lc[new_node]]+t[rc[new_node]];
    return new_node;
}
int qry(int i,int s,int e,int l,int r){
    if(e<l || s>r)
        return 0;
    if(s>=l && e<=r)
        return t[i];
    int  m=(s+e)/2;
    return qry(lc[i],s,m,l,r)+qry(rc[i],m+1,e,l,r);
}
void solve() {
    mem1(which_version);
    int n;
    cin>>n;
    int q;
    cin>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    versions.pb(build(0,n-1));
    int which_array=2;
    which_version[1]=versions.back();
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int array,index,to;
            cin>>array>>index>>to;
            versions.pb(upd(which_version[array],0,n-1,index-1,to));
            which_version[array]=versions.back();
        }else if(type==2){
            int array,l,r;
            cin>>array>>l>>r;
            --l;--r;
            cout<<qry(which_version[array],0,n-1,l,r)<<endl;
        }else{
            int k;
            cin>>k;
            versions.push_back(which_version[k]);
            which_version[which_array++]=versions.back();
        }
    }
}

int32_t main() {
    nitin;

    solve();
}