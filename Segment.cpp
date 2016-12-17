Segment Tree
struct segTree{
	lld tree[4*N],x,y;
	void construct(lld low,lld high,lld pos)
	{	
		if(low==high)
		{
			tree[pos]=a[low];
			return;
		}
		lld mid=(high+low)/2;
		construct(low,mid,2*pos+1),construct(mid+1,high,2*pos+2);
		tree[pos]=max(tree[2*pos+1],tree[2*pos+2]);
	}
	lld query(lld low,lld high,lld pos)
	{
		if(x<=low && y>=high)
			return tree[pos];
		if(x>high||y<low)
			return 0;
		lld mid=(high+low)/2;
		return max(query(low,mid,2*pos+1),query(mid+1,high,2*pos+2));
	}
	void update(lld low,lld high,lld pos)
	{
		if(x<low||x>high) return;
		if(low==high)
		{
			tree[pos]=val;
			return;
		}
		lld mid=(low+high)/2;
		update(low,mid,2*pos+1),update(mid+1,high,2*pos+2);
		tree[pos]=max(tree[2*pos+1],tree[2*pos+2]);
	}
} st;
