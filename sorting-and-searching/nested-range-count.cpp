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
//from:- nitin0280/cp_template ^_^
class fente{
public:
    int n;
    vector<int>t;
    void init(int _n){
        n=_n;
        t.resize(2*n+1,0);
    }
    int q(int l){
        int sum=0;
        for(int i=l;i>=1;i-=i&-i)
            sum+=t[i];
        return sum;
    }
    void u(int l,int inc){
        for(int i=l;i<=2*n;i+=i&-i)
            t[i]+=inc;
    }

};
bool cmp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    map<int,int>m;
    for(int i=0;i<n;i++){
        cin>>v[i][1]>>v[i][0];
        v[i][2]=i;
        m[v[i][0]]=m[v[i][1]]=1;
    }
    int start=1;
    for(auto &c:m)
        c.s=start++;
    for(auto &c:v){
        c[0]=m[c[0]];
        c[1]=m[c[1]];
    }
    int cnt1[n],cnt2[n];
    for(auto &c:cnt1)
        c=0;
    for(auto &c:cnt2)
        c=0;
    fente f;
    f.init(n);
    sort(all(v),cmp);
    for(auto &c:v){
        cnt1[c[2]]=f.q(c[0])-f.q(c[1]-1);
        f.u(c[1],1);
    }
    fente s;
    s.init(n);
    for(int i=n-1;i>=0;i--){
        cnt2[v[i][2]]=s.q(v[i][1]);
        s.u(v[i][1],1);
    }
    for(int i=0;i<n;i++)
        cout<<cnt1[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<cnt2[i]<<" ";
    cout<<endl;
}

int32_t main() {
    nitin;

    solve();
}