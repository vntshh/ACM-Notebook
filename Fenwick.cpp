Fenwick Tree
struct fenTree{
	lld tree[N],maxm;
	void construct(lld low,lld high,lld pos)
	{	
		rep(i,1,N+1) update(i,a[i]); 
	}
	void update(lld i,lld value)
	{
		for(;i<=N;i+=(i&-i))
			tree[i]=max(tree[i],value);
	}
	void update(lld x,lld y,lld val)
	{
		update(x,val),update(y+1,-val);
	}
	void findarrval(lld x)
	{
		for(sum=0;i>0;i-=(i&-i))
			sum+=tree[i];
		return sum+a[b];
	}
	lld query(lld i)
	{
		for(maxm=0;i>0;i-=(i&-i))
			maxm=max(maxm,tree[i]);
		return maxm;
	}
	lld query(lld x,lld y)
	{
		return query(y)-query(x-1);
	}
} ft;

