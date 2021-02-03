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
int sf=0,ss=0;
multiset<int>f,s;

void corr(multiset<int>&a,multiset<int>&b){
    int k=sz(a)+sz(b);
        while(a.size()>b.size()+(k&1)){
            b.ins(*a.rbegin());
            ss+=*a.rbegin();
            sf-=*a.rbegin();
            a.erase(a.find(*a.rbegin()));
        }
        while(a.size()+(k&1)<b.size()+(k&1)){
            a.ins(*b.begin());
            sf+=*b.cbegin();
            ss-=*b.cbegin();
            b.erase(b.find(*b.begin()));
        }
}
int n,k;
void p(){
    if(k&1){
        cout<<ss-sf+*f.rbegin()<<" ";
    }else{
        cout<<ss-sf<<" ";
    }
}
void solve() {
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(k==1){
        for(int i=0;i<n;i++)
            cout<<0<<" ";
        cout<<endl;
        exit(0);
    }
    for(int i=0;i<k;i++){
        s.ins(a[i]);
        ss+=a[i];
    }
    corr(f,s);
    p();
    for(int i=k;i<n;i++){
        if(f.count(a[i-k])){
            f.erase(f.find(a[i-k]));
            sf-=a[i-k];
        }else{
            s.erase(s.find(a[i-k]));
            ss-=a[i-k];
        }
        corr(f,s);
        if(a[i]>*f.rbegin())
        {
            s.ins(a[i]);
            ss+=a[i];
        }
        else
        {
            f.ins(a[i]);
            sf+=a[i];
        }
        corr(f,s);
        p();
    }


}

int32_t main() {
    nitin;

    solve();
}