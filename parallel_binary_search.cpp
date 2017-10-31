#include<bits/stdc++.h>
#define rep(i,start,lim) for(lld i=start;i<lim;i++)
#define repd(i,start,lim) for(lld i=start;i>=lim;i--)
#define scan(x) scanf("%lld",&x)
#define print(x) printf("%lld ",x)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define br printf("\n")
#define sz(a) lld((a).size())
#define YES printf("YES\n")
#define NO printf("NO\n")
#define all(c) (c).begin(),(c).end()
using namespace std;
#define INF         1011111111
#define LLINF       1000111000111000111LL
#define EPS         (double)1e-10
#define MOD         1000000007
#define PI          3.14159265358979323
using namespace std;
typedef long double ldb;
typedef long long lld;
lld powm(lld base,lld exp,lld mod=MOD) {lld ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
typedef vector<lld> vlld;
typedef pair<lld,lld> plld;
typedef map<lld,lld> mlld;
typedef set<lld> slld;
#define N 300005
lld low[N],high[N],p[N],l[N],r[N],a[N];
vlld par[N],check[N];
struct fenTree{
  lld tree[N],sum;
  void init() {
    rep(i,0,N) tree[i]=0;
  }
  void update(lld i,lld value)
  {
    for(;i<=N;i+=(i&-i))
      tree[i]+=value;
  }
  lld query(lld i)
  {
    for(sum=0;i>0;i-=(i&-i))
      sum+=tree[i];
    return sum;
  }
} ft;
int main()
{
  lld n,m,x,k;
  scan(n),scan(m);
  rep(i,1,m+1) scan(x),par[x].pb(i);
  rep(i,1,n+1) scan(p[i]);
  scan(k);
  rep(i,1,k+1) scan(l[i]),scan(r[i]),scan(a[i]);
  rep(i,1,n+1) low[i]=1,high[i]=k+1;
  lld bound=log2(k);
  rep(i,0,bound+1) {
    ft.init();
    rep(i,1,n+1) if(low[i]!=high[i]) check[(low[i]+high[i])/2].pb(i);
    rep(i,1,k+1) {
      if(l[i]<=r[i]) ft.update(l[i],a[i]),ft.update(r[i]+1,-a[i]);
      else ft.update(1,a[i]),ft.update(r[i]+1,-a[i]),ft.update(l[i],a[i]);

      while(sz(check[i])) {
        lld curr=check[i].back();
        check[i].pop_back();
        lld curr_sum=0;
        for(auto j:par[curr]) {
          curr_sum+=ft.query(j);
          if(curr_sum>=p[curr]) break;
        }
        if(curr_sum>=p[curr]) high[curr]=i;
        else low[curr]=i+1;
      }
    } 
  }
  rep(i,1,n+1) {
    if(low[i]<=k) print(low[i]),br;
    else printf("NIE\n");
  }
  return 0;
}
