#define ll long long
#include<bits/stdc++.h>
using namespace std;
ll n,m;
vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> parent;
void bfs()
{
	queue<ll> q;
	ll mini = 0;
	q.push(0);
	vis[0ll] = true;
	bool ok = false;
	while(!q.empty())
	{
		int size = q.size();
		if(ok) break;
		for(int i=0;i<size;i++)
		{
			ll node = q.front();
			q.pop();
			if(node == n-1)
			{
				ok = true;
				break;
			}
			for(auto it : adj[node])
			{
				if(!vis[it])
				{
					q.push(it);
					vis[it] = true;
					parent[it] = node;
				}
			}
		}
		mini++;
	}
	if(!vis[n-1])
	{
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	cout<<mini<<endl;
	ll last = n-1;
	vector<ll> ans;
	while(last!=-1)
	{
		ans.push_back(last);
		last = parent[last];
	}
	reverse(ans.begin(),ans.end());
	for(auto it : ans) cout<<it+1<<" ";
	cout<<endl;
	return;
	
	
	
}
void solve()
{
	cin>>n>>m;
	adj.clear();
	vis.clear();
	parent.clear();
	adj.resize(n);
	vis.resize(n,false);
	parent.resize(n,-1);
	for(int i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs();
	return;
	
	
}
int main()
{
	solve();
	return 0;
}
