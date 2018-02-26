#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ld(a) while(a--)
#define tci(v,i) for(auto i=v.begin();i!=v.end();i++)
#define tcf(v,i) for(auto i : v)
#define all(v) v.begin(),v.end()
#define rep(i,start,lim) for(long long (i)=(start);i<(lim);i++)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define osit ostream_iterator
#define INF         0x3f3f3f3f
#define LLINF       1000111000111000111LL
#define PI          3.14159265358979323
#define endl '\n'
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
const int N=1000006;
typedef long long lld;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef tuple<int,int,int> iii;
typedef set<int> si;
typedef complex<double> pnt;
typedef vector<pnt> vpnt;
typedef priority_queue<ii,vii,greater<ii> > spq;
const ll MOD=1000000007LL;
template<typename T> T gcd(T a,T b){if(a==0) return b; return gcd(b%a,a);}
template<typename T> T power(T x,T y,ll m=MOD){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}
lld mulmod(lld a,lld b,lld m) {
    lld ret = 0;
    lld c = a;
    while(b) {
        if(b&1) {
            ret = (ret + c);
            if(ret>=m) ret-=m;
        }
        b>>=1;
        c = (c + c);
        if(c>=m) c-=m;
    }
    return ret;
}
struct node{
    lld cnt = 0;
    node *left;
    node *right;
    node(lld cnt,node* left,node* right) :
        cnt(cnt),left(left),right(right) {}
    node* update(lld l,lld r,lld idx,lld val); 
};
node* root;
node* null = new node(0,NULL,NULL);
node* node::update(lld l,lld r,lld idx,lld val) {
    // cout<<l<<" "<<r<<endl;
    if(l<=idx and idx<=r) {
        if(l==r) return new node(this->cnt + val,null,null);
        lld m = (l + r)/2;
        return new node(this->cnt + val, this->left->update(l,m,idx,val), this->right->update(m+1,r,idx,val));
    }
    return this;
}
lld query(lld l,lld r,lld qs,lld qe,node* curr) {
    if(curr == null) return 0LL;
    if(r<l) return 0LL;
    if(l>qe or r<qs) return 0LL;
    if(l>=qs and r<=qe) return curr->cnt;
    lld mid = (l + r)/2;
    return query(l,mid,qs,qe,curr->left) + query(mid+1,r,qs,qe,curr->right);
}
void solve() {
    lld n,q,x;
    null -> left = null;
    null -> right = null;
    root = null;
    cin>>n>>q;
    rep(i,1,n+1) {
        cin>>x;
        root = root->update(0,LLINF,x,1);
    }   
    lld p = 0,a,b,c,d,type;
    while(q--) {
        cin>>type>>a>>b>>c>>d;
        a%=d, b%=d, c%=d;
        lld curr = mulmod(a,p,d);
        curr = mulmod(b,curr,d);
        curr = (curr + c);
        if(curr>=d) curr-=d;
        // lld curr;
        // cin>>type>>curr;
        if(type == 1) root = root->update(0,LLINF,curr,1);
        else if(type == 2) {
            lld findd = query(0,LLINF,curr,curr,root);
            if(findd) root = root->update(0,LLINF,curr,-1);
        }
        else {
            lld ans = query(0,LLINF,0,curr-1,root);
            cout<<ans<<endl;
            p = ans;
        }
    }
}
int32_t main(){
    //sync;
    lld t;
    //cin>>t;
    t=1;
    while(t--) {
        solve();
    }
}