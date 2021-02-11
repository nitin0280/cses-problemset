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


//templates on github:- nitin0280/cp_template
class segte2d{
public:
    int n,m;
    vector<vector<int>>tr;
    vector<vector<int>>a;
    segte2d(int _n,int _m,vector<vector<int>>&_a){
        a=_a;
        n=_n;
        m=_m;
        tr.resize(4*n+1,vector<int>(4*m+1,0));

    }
    void build_y(int vx,int vy,int sx,int ex,int sy,int ey){
        if(sy==ey){
            tr[vx][vy] = sx == ex ? a[sx][sy] : tr[2 * vx + 1][vy] + tr[2 * vx + 2][vy];
            return;
        }
        int my=(sy+ey)/2;
        build_y(vx,2*vy+1,sx,ex,sy,my);
        build_y(vx,2*vy+2,sx,ex,my+1,ey);
        tr[vx][vy]=tr[vx][2*vy+1]+tr[vx][2*vy+2];
    }
    void build_x(int vx,int sx,int ex){
        if(sx!=ex){
            int mx=(sx+ex)/2;
            build_x(2*vx+1,sx,mx);
            build_x(2*vx+2,mx+1,ex);
        }
        build_y(vx,1,sx,ex,0,m-1);
    }
    void build(){
        build_x(1,0,n-1);
    }
    void update_y(int vx,int vy,int sx,int ex,int sy,int ey,int x,int y,int val){
        if(sy==ey){
            if(sx==ex){
                tr[vx][vy]=val;
            }else{
                tr[vx][vy]=tr[2*vx+1][vy]+tr[2*vx+2][vy];
            }
            return;
        }
        int mid=(sy+ey)/2;
        if(y<=mid)
            update_y(vx,2*vy+1,sx,ex,sy,mid,x,y,val);
        else
            update_y(vx,2*vy+2,sx,ex,mid+1,ey,x,y,val);
        tr[vx][vy]=tr[vx][2*vy+1]+tr[vx][2*vy+2];
    }
    void update_x(int vx,int sx,int ex,int x,int y,int val){
        if(sx!=ex){
            int mid=(sx+ex)/2;
            if(x<=mid){
                update_x(2*vx+1,sx,mid,x,y,val);
            }else{
                update_x(2*vx+2,mid+1,ex,x,y,val);
            }
        }
        update_y(vx,1,sx,ex,0,m-1,x,y,val);
    }
    void update(int x,int y,int val){
        update_x(1,0,n-1,x,y,val);
    }
    int query_y(int vx,int vy,int sy,int ey,int qsy,int qey){
        if(qey<sy || qsy>ey){
            return 0;
        }
        if(sy>=qsy && ey<=qey){
            return tr[vx][vy];
        }
        int my=(sy+ey)/2;
        int A=query_y(vx,2*vy+1,sy,my,qsy,qey);
        int B=query_y(vx,2*vy+2,my+1,ey,qsy,qey);
        return A+B;
    }
    int query_x(int vx,int qsx,int qex,int qsy,int qey,int sx,int ex){
        if(qsx>ex || qex<sx)
            return 0;
        if(sx>=qsx && ex<=qex){
            return query_y(vx,1,0,m-1,qsy,qey);
        }
        int mx=(sx+ex)/2;
        int A=query_x(2*vx+1,qsx,qex,qsy,qey,sx,mx) ;
        int B=query_x(2*vx+2,qsx,qex,qsy,qey,mx+1,ex);
        return A+B;
    }
    int query(int sx,int ex,int sy,int ey){
        return query_x(1,sx,ex,sy,ey,0,n-1);
    }
};

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            v[i][j]=c=='*';
        }
    }
    segte2d s(n,n,v);
    s.build();
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            --x;--y;
            v[x][y]=!v[x][y];
            s.a[x][y]=v[x][y];
            s.update(x,y,v[x][y]);
        }else{
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            --a;--b;--c;--d;
            cout<<s.query(a,c,b,d)<<endl;
        }
    }

}

int32_t main() {
    nitin;

    solve();
}