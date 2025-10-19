#define ll long long
#include<bits/stdc++.h>
using namespace std;
bool vis[1001][1001];
char grid[1001][1001];
ll dx[4] = {-1,0,1,0};
ll dy[4] = {0,1,0,-1};
ll n,m;

bool isValid(int row,int col)
{
	return row < n and col < m and row >= 0 and col>=0 and !vis[row][col] and grid[row][col]!='#';
}
void dfs(ll row, ll col)
{
	vis[row][col] = true;
	
	for(int i=0;i<4;i++)
	{
		ll newRow = dx[i] + row;
		ll newCol = dy[i] + col;
		if(isValid(newRow,newCol))
		{
			dfs(newRow, newCol);
		} 
	}
}
void solve()
{
	cin>>n>>m;
	ll ans = 0;
	memset(vis,false,sizeof(vis));
	memset(grid,'#',sizeof(grid));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j] && grid[i][j]=='.')
			{
				
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	
	
	
	
	
}
int main()
{
	solve();
	return 0;
}
