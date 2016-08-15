struct MincoStFlow
{
	struct Edge
	{
		int u,v,f,w,next;
		Edge(){}
		Edge(int uu,int vv,int ff,int ww,int nn):u(uu),v(vv),f(ff),w(ww),next(nn){}
	};
	int n,lmt,ans;
	int g[MAXN];
	Edge e[MAXN*MAXN];
	int nume;
	int src,sink;
	void init()
	{
		nume=1;
		memset(g,0,sizeof(g));
	}
	void addedge(int u,int v,int c,int w)
	{
		e[++nume]=Edge(u,v,c,w,g[u]);
		g[u]=nume;
		e[++nume]=Edge(v,u,0,-w,g[v]);
		g[v]=nume;
	}
	queue<int> q;
	bool inQue[MAXN];
	int dist[MAXN];
	int prev[MAXN],pree[MAXN];
	bool findPath()
	{
		while(!q.empty())q.pop();
		q.push(src);
		for(int i=0;i<MAXN;i++)dist[i]=INF;
		dist[src]=0;
		inQue[src]=true;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=g[u];i;i=e[i].next)
			{
				if(e[i].f>0&&dist[u]+e[i].w<dist[e[i].v])
				{
					dist[e[i].v]=dist[u]+e[i].w;
					prev[e[i].v]=u;
					pree[e[i].v]=i;
					if(!inQue[e[i].v])
					{
						inQue[e[i].v]=true;
						q.push(e[i].v);
					}
				}
			}
			inQue[u]=false;
		}
		return dist[sink]<INF;
	}
	int augment()
	{
		int u=sink;
		int delta=INF;
		while(u!=src)
		{
			if(e[pree[u]].f<delta)delta=e[pree[u]].f;
			u=prev[u];
		}
		u=sink;
		while(u!=src)
		{
			e[pree[u]].f-=delta;
			e[pree[u]^1].f+=delta;
			u=prev[u];
		}
		return dist[sink]*delta;
	}
	void solve()
	{
		int cur=0;
		ans=0;
		while(findPath())
		{
			cur+=augment();
			if(cur>ans)ans=cur;
		}
	}
}D;
