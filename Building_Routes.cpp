#define ll long long 
#define vei vector<ll>
#define veb vector<bool>
#define VAI vector<vei>
#define VAB vector<veb>
#include<bits/stdc++.h>
using namespace std;
ll n,m;
VAI adj;
veb vis;
void dfs(ll node)
{
	vis[node] = true;
	for(auto it : adj[node])
	{
		if(!vis[it])
		{
			dfs(it);
		}
	}
}

void solve()
{
	adj.clear();
	vis.clear();
	cin>>n>>m;
	adj.resize(n);
	vis.resize(n,false);
	for(int i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<ll> ans;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			ans.push_back(i);
		}
	}
	if(ans.size() == 1)
	{
		cout<<0<<endl;
	}
	else{
		cout<<ans.size()-1<<endl;
	ll size = ans.size();
	for(int i=0;i<size-1;i++) cout<<ans[i]+1ll<<" "<<ans[i+1]+1ll<<endl;
	}
	
	
	
	
}
int main()
{
	solve();
	return 0;
}
