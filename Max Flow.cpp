Max Flow
vector<lld> adj[N];
lld a[N],cap[N][N];
class prioritize{
	public:
		bool operator ()(pair<lld,lld>& p1,pair<lld,lld> &p2)
		{
			return p1.second<p2.second;
		}
};
struct maxFlow{
	lld path,result=0,source,sink,from[N],vis[N],curr,tmp;
	lld max_flow()
	{
		while(bfs()) 
		{
			path=INF;
			for(lld v=sink;v!=source;v=from[v]) path=min(path,cap[from[v]][v]);
			for(lld v=sink;v!=source;v=from[v]) cap[from[v]][v]-=path,cap[v][from[v]]+=path;
			result+=path;
		}
		return result; 
	}
	void addedge(lld a,lld b,lld capacity)
	{
		adj[a].pb(b),cap[a][b]=capacity;
		adj[b].pb(a);
	}
	bool bfs()
	{
		rep(i,0,N) vis[i]=0;
 		priority_queue<pair<lld,lld> ,vector<pair<lld,lld> >,prioritize> q;
		q.push({source,0}),vis[source]=1,from[source]=-1;
		while(!q.empty()) 
		{
			curr=q.top().first,q.pop(),tmp=sz(adj[curr]);
			rep(i,0,tmp)
				if(!vis[adj[curr][i]] and cap[curr][adj[curr][i]])
				{
					q.push({adj[curr][i],cap[curr][adj[curr][i]]}),from[adj[curr][i]]=curr,vis[adj[curr][i]]=1;
					if(adj[curr][i]==sink) return true;
				}
		}
		return false;
	}
} flow[105];
