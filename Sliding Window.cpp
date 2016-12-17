Sliding Window  //For getting the maximum of every consecutive k elements of the array O(N) approach
deque<pair<int,int> > window;
rep(i,1,m+1)
{
	while(!window.empty() and window.back().f<=arr[i]) window.pop_back();
	window.pb(mp(arr[i],j));
	while(window.front().s<=i-b) window.pop_front();
	if(i>=b) final[i][i-b+1]=window.front().f;
}

