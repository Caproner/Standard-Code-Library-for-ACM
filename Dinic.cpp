struct Dinic
{
	struct edge
	{
		int u,v,f,c,next;
	};
	int n,src,sink,ans;
	int g[MAXN];
	int nume;
	edge e[MAXN*MAXN];
	void addedge(int u,int v,int c)
	{
		e[++nume].v=v;
		e[nume].u=u;
		e[nume].f=e[nume].c=c;
		e[nume].next=g[u];
		g[u]=nume;
		e[++nume].v=u;
		e[nume].u=v;
		e[nume].f=0;
		e[nume].c=c;
		e[nume].next=g[v];
		g[v]=nume;
	}
	void init()
	{
		memset(g,0,sizeof(g));
		nume=1;
	}
	queue<int> q;
	bool vis[MAXN];
	int dist[MAXN];
	void bfs()
	{
		memset(dist,0,sizeof(dist));
		while(!q.empty())q.pop();
		vis[src]=true;
		q.push(src);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=g[u];i;i=e[i].next)
				if(e[i].f&&!vis[e[i].v])
				{
					q.push(e[i].v);
					dist[e[i].v]=dist[u]+1;
					vis[e[i].v]=true;
				}
		}
	}
	int dfs(int u,int delta)
	{
		if(u==sink)return delta;
		int ret=0;
		for(int i=g[u];delta&&i;i=e[i].next)
			if(e[i].f&&dist[e[i].v]==dist[u]+1)
			{
				int dd=dfs(e[i].v,min(e[i].f,delta));
				e[i].f-=dd;
				e[i^1].f+=dd;
				delta-=dd;
				ret+=dd;
			}
		return ret;
	}
	void maxflow()
	{
		ans=0;
		while(1)
		{
			memset(vis,0,sizeof(vis));
			bfs();
			if(!vis[sink])break;
			ans+=dfs(src,INF);
		}
	}
}d;
