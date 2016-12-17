Persistent Segment Tree
struct node
{
	int count;
	node *left, *right;
	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}
	node* insert(int l, int r, int w);
};
node *null = new node(0, NULL, NULL); 
node * node::insert(int l, int r, int w)
{
	if(l <= w && w < r)
	{
		if(l+1 == r)
		{
			return new node(this->count+1, null, null);
		}
		int m = (l+r)>>1;
		return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
	}
	return this;
}
node *root[N];
null->left = null->right = null;
