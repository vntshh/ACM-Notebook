Finding Just Smaller Element on Left Side for each element of the array
sta.push(-1);
rep(i,0,n) 
{
	while(sta.top()>=0 && a[i]>=a[sta.top()])
		sta.pop();
	result.push_back(sta.top()+1);
	sta.push(i);
}
Finding just Smaller element on Right Side for each element of the array
sta.push(n);
repd(i,n-1,0)
{
	while(sta.top()<n && a[i]>a[sta.top()])
		sta.pop();
	result.push_back(sta.top());
	sta.push(i);
}
