//DSU结构体的内置方法：
//void init(int n)：初始化一个大小为n的并查集
//int find(int x)：查找点x的祖先，并返回 
//bool unite(int x,int y) ：合并点x和点y。若点x和点y本身已在同一集合中则返回false，否则返回true。 

struct DSU
{
	int prt[MAXN];
	int rank[MAXN];
	
	void init(int n=0)
	{
		for(int i=0;i<=n;i++)
		{
			prt[i]=i;
			rank[i]=0;
		}
	}
	
	int find(int x)
	{
		if(prt[x]==x)return x;
		return prt[x]=find(prt[x]);
	}
	
	bool unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y)return false;
		if(rank[x]<rank[y])prt[x]=y;
		else
		{
			prt[y]=x;
			if(rank[x]==rank[y])rank[x]++;
		}
		return true;
	}
};
