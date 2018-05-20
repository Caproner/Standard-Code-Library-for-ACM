//Hungary结构体的部分变量：
//ans： 最大匹配数
//mx：mx[i]表示与左边编号为i的点匹配的右边的点的编号
//	例如说mx[1]=2表示左边的1和右边的2匹配 
//
//Hungary结构体的内置方法：
//void clear(int nn)：清空结构体的参数，重置为左边与右边点数均为nn的空二分图
//void AddEdge(int u,int v)：向结构体的图中添加一条连接左边的点u和右边的点v的边
//void matching()：对当前二分图跑最大匹配，并更新ans和mx的值 

struct Hungary
{
	vector<int> g[MAXN];
	int from[MAXN],mx[MAXN],ans;
	bool use[MAXN];
	int n;
	
	bool match(int x)
	{
		for(int i=0;i<g[x].size();i++)
		{
			if(!use[g[x][i]])
			{
				use[g[x][i]]=true;
				if(from[g[x][i]]==-1||match(from[g[x][i]]))
				{
					from[g[x][i]]=x;
					mx[x]=g[x][i];
					return true;
				}
			}
		}
		return false;
	}
	
	void matching()
	{
		ans=0;
		memset(from,-1,sizeof(from));
		memset(mx,0,sizeof(mx));
		for(int i=1;i<=n;i++)
		{
			memset(use,0,sizeof(use));
			if(match(i))ans++;
		}
	}
	
	void AddEdge(int u,int v)
	{
		g[u].push_back(v);
	} 
	
	void clear(int nn)
	{
		n=nn;
		for(int i=1;i<=n;i++)
			g[i].clear();
	}
};
