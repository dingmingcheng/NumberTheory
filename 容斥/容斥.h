/**
* 容斥 dfs
*
*/

void dfs(ll x, ll tot, ll sum)
{
	if (x == n)
	{
		if (tot == 0) return;
		if(sum>=m) {sum1++;}
		return;
	}
	dfs(x + 1, tot, sum);
	if (tot!=0)
	{
		dfs(x + 1, tot + 1, sum^a[x]);
	}
	else
	{
		dfs(x + 1, tot + 1, a[x]);
	}
}
dfs(0,0,0)