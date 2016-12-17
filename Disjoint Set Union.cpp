Sliding Window
struct DSU{
	lld sze[N],arr[N];
	void init()
	{
		rep(i,1,N) arr[i]=i,sze[i]=1;
	}
	void get_union(lld a,lld b)
	{
		lld root_a=root(a),root_b=root(b);
		if(sze[root_a]<sze[root_b])
			arr[root_a]=arr[root_b],sze[root_b]+=sze[root_a];
		else
			arr[root_b]=arr[root_a],sze[root_a]+=sze[root_b];
	}
	lld root(lld x)
	{
		while(arr[x]!=x) arr[x]=arr[arr[x]],x=arr[x];
		return x;
	} 
} dsu;
