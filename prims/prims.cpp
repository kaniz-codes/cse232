#include <stdio.h>
#include <limits.h>

int V;
int graph[100][100];

int minkey(int key[],bool mst[])
{
 	int min=INT_MAX,min_index;
 	for(int v=0;v<V;v++)
 	{	
 		if(mst[v]==false && key[v]<min)
 		{
 		 	min=key[v],min_index=v;
 		}
 		
 	}	
	return min_index;
}

void printmst(int parent[],int n)
{
 	printf("\nEdge Weight\n");
 	for(int i=1;i<V;i++)
 	{
 	 	printf("%d - %d  %d\n",parent[i]+1,i+1,graph[i][parent[i]]);
 	}
}


void prim()
{
 	int parent[V];
 	int key[V];
 	bool mst[V];
 	for(int i=0;i<V;i++)
 		key[i]=INT_MAX,mst[i]=false;
 	
 	key[0]=0;
 	parent[0]=-1;
    
    for(int count=0;count<V-1;count++)
 	{
 		int u=minkey(key,mst);
 		mst[u]=true;
 		for(int v=0;v<V;v++)	
 		if(graph[u][v] && mst[v] == false && graph[u][v]<key[v])
 			parent[v]=u,key[v]=graph[u][v];
 	}
printmst(parent,V);
}





int main()
{
 	printf("\nEnter number of vertices\n");
 	scanf("%d",&V);
 	
 	for(int i=0;i<V;i++)
 	{
 		for(int j=0;j<V;j++)
 	 	{
 	 	  	printf("\nEnter weigth of edge between %d and %d or enter '0' if no edge\n",i,j);
 		  	scanf("%d",&graph[i][j]);
 		}
 	}
 	prim();
 	return 0;
}		
