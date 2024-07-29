Program04: Write and execute a menu driven program to print all the nodes reachable from a given starting node in a graph to arrange nodes in topological order using DFS method and source removal technique.

#include <stdio.h>
#include <stdlib.h>

int s[100], count, res[100];

//-------------------------------------------------------------------------------------
void dfs(int n, int a[100][100], int source) 
{
  int i;
  s[source] = 1;
  for (i = 1; i <= n; i++) {
  if (a[source][i] == 1 && s[i] == 0) 
  dfs(n, a, i);
  }
  count = count + 1;
  res[count] = source;
}
//-------------------------------------------------------------------------------------
void topologicalDFS(int n, int a[100][100]) {
  int i, j;
  for (i = 1; i <= n; i++) 
{
    s[i] = 0;
  }
  count = 0;
  for (j = 1; j <= n; j++) 
{
    if (s[j] == 0) 
{
      dfs(n, a, j);
    }
  }
  for (i = n; i >= 1; i--) 
{
    printf("--> %d ", res[i]);
  }
  printf("\n");
}


void topologicalSourceRemoval(int n, int a[100][100], int sc[100]) {
  int i, j;
  for (i = 1; i <= n; i++) {
    if (sc[i] == 0) {
      printf("%d\t", i);
      sc[i] = -1;
      for (j = 1; j <= n; j++) {
	if (a[i][j] == 1) {
	  sc[j] = sc[j] - 1;
	}
      }
      i = 0;
    }
  }
  printf("\n");
}


//---------------------------------------------------------------------------------------
int main()
{
  int a[100][100], n, i, j, sc[100],ch;

  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix:\n");
  for (i = 1; i <= n; i++)
  for (j = 1; j <= n; j++)
  scanf("%d", &a[i][j]);

  printf("1:Topological order using DFS 2: Source Removal method:\n");
  scanf("%d",&ch);

  switch(ch)
  {
  case 1: printf("Topological order using DFS:\n");
	  topologicalDFS(n, a);
	  break;

  case 2: for (i = 1; i <= n; i++)
	  sc[i] = 0;

	  for (i = 1; i <= n; i++)
	  for (j = 1; j <= n; j++)
	  if(a[i][j] == 1)
	  {
	  sc[j] = sc[j] + 1;
	  }
	  printf("Topological order using Source Removal:\n");
	  topologicalSourceRemoval(n, a, sc);
	  break;

  default: exit(0);
}
}


Program 06: Write and execute a program for matrix chain multiplication for the given sequence of Matrices {A1, A2 . . . . . An}.

#include <stdio.h>
#include <conio.h>
	
//Function for matrix chain multiplication  
	int MCM(long int p[], long int n)
	{
	long int m[10][10];
	long int i,j,k,L,q;

	for (i = 1; i < n; i++)
	m[i][i] = 0;

	for (L=2; L<=n; L++)
	{
	for (i=1; i<=n-L+1; i++)
	{
	j = i+L-1;
	m[i][j] = 30000;
		for (k=i; k<=j-1; k++)
		{
		q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
		if (q < m[i][j])
		m[i][j] = q;
		}
	}
	}
	printf("-------------------------------------------\n");
	for (i = 1; i < n; i++)
	{
	for (j = 1; j < n; j++)
	if(i<j)
	printf("%ld\t", m[i][j]);
	else  if( i== j)
	printf("0\t");
	else
	printf("--\t");
	printf("\n");
	}
	}
         int main()
{
long int arr[10],n,i;
clrscr();

printf("Enter the numbre of matrices\n");
scanf("%ld", &n);

printf("Enter the sizes of matrices (p0,p1....)\n");
for(i=0;i<=n;i++)
scanf("%ld", &arr[i]);
printf("Minimum number of multiplications is :\n");
MCM(arr, n+1);
}




Program 07: Write and execute a program to find a longest-common-subsequence of X and Y using   
                 dynamic programming for given two sequences X = {x1 ,x2 . . . . . xm }; Y = {y1 y2 . . . . .yn }

#include<stdio.h>
#include<string.h>

void main()
	{
	char x[100],y[100],lc[10];
	int m,n,len,i,j;

	printf(" Enter the first string \n");
	gets(x);

	printf(" Enter the second string \n");
	gets(y);

	m=strlen(x);
	n=strlen(y);

	lcs(x,y,m,n);
	}
//-------------------------------------------------------------------------------------------------------
	lcs(char x[100], char y[100], int m,int n)
	{
	int len,i,j,L[100][100];
	char lc[100];
	for(i=0;i<=m;i++)
	{
	for(j=0;j<=n;j++)
	if(i==0 || j==0)
	L[i][j]=0;
	else
	if(x[i-1] == y[j-1])
	L[i][j] = L[i-1][j-1]+1;
	else
	L[i][j] = max(L[i-1][j],L[i][j-1]);
	}

	printf(" LCS length is %d \n", L[m][n]);

	len =L[m][n];
	lc[len]='\0';
	i=m; 
	j=n;

	while( i > 0 && j>0)
	{ 
	if(x[i-1] == y[j-1])                             
	{
	lc[len-1] = x[i-1];
	i--;
	j--;
	len--;
	}
	else
	if(L[i-1][j] > L[i][j-1])
	i--;
	else
	j--;
	}
     //	printf(": THE LCS is  %s \n",lc);
	}
            max( int a, int b)
	{
	if(a>b)
	return a;
	else
	return b;
	}

Program 08: Write and execute a program to find Minimum Spanning Tree using Prim’s method.

#include<stdio.h>
#include<conio.h>

void main()
	{
	int n,a[10][10] i ,j, source, mstcost;

	printf(" Enter the Number of Nodes \n");
	scanf("%d",&n);

	printf(" Enter the Adjacency Matrix \n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);

	printf(" Enter the Source Node \n");
	scanf("%d",&source);

	mstcost =  prims(n,a,source);

	printf(" The cost of minimum spanning Tree is %d \n",mstcost);
	}
//-----------------------------------------------------------------------------------
	prims(int n, int a[10][10], int source)
	{
	int d[100],s[10],i,j,u,v,minval,sum=0;

	for(i=1;i<=n;i++)
	{
	s[i]=0;
	d[i]=a[source][i];
	}

	s[source]=1;

	for(i=1;i<=n-1;i++)
	{
	minval = 999;

			for(j=1;j<=n;j++)
			if(s[j]==0) if(d[j] < minval)
			{
			minval = d[j];
			u=j;
			}
			s[u]=1;
			sum=sum+d[u];

			for(v=1;v<=n;v++)
			if(s[v]==0 && d[v]>a[u][v])
			d[v]=a[u][v];
	   }

	   return sum;
	   }
Program 9: Write and execute a program to find Minimum Spanning Tree using Kruskal’s method
include<stdio.h>
#include<conio.h>


int parent[20]={0},min,mincost=0,ne=1,n,cost[20][20];
int a,b,i,j,u,v;
void kruskal(void);

void main()
{
 clrscr();

 printf("Enter the number of  nodes:");
 scanf("%d",&n);

 printf("Enter the cost matrix:");
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
 {
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=999;
 }
 kruskal();
 getch();
}

void kruskal()
{
 while(ne<n)
 {
  for(i=1,min=999;i<=n;i++)
  for(j=1;j<=n;j++)
  if(cost[i][j]<min)
  {
    min=cost[i][j];
    a=u=i;
    b=v=j;
  }
  while(parent[u])
  u=parent[u];
  while(parent[v])
  v=parent[v];
  if(u!=v)
  {
   printf("%d\tedge\t(%d,%d)=%d\n",ne++,a,b,min);
   mincost+=min;
   parent[v]=u;
  }
  cost[a][b]=cost[b][a]=999;
 }
 printf("The minimum cost=%d\n",mincost);
}

Program 10: Write and execute a program to find shortest path to all other nodes in weighted graph using Dijkstra’s strategy

#include<stdio.h>
#include<conio.h>

void main()
{
int n,a[10][10],i,j,source,mstcost;

printf(" Enter the Number of Nodes \n");
scanf("%d",&n);

printf(" Enter the Adjacency Matrix \n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);

printf(" Enter the Source Node \n");
scanf("%d",&source);

Dijkstra(n,a,source);

}
	
Dijkstra(int n, int a[10][10], int source)
	{
	int d[100],s[10],i,j,u,v,minval,sum=0;

	for(i=1;i<=n;i++)
	{
	s[i]=0;
	d[i]=a[source][i];
	}

	s[source]=1;

	for(i=1;i<=n;i++)
	{
	minval = 999;

			for(j=1;j<=n;j++)
			if(s[j]==0) if(d[j] < minval)
			{
			minval = d[j];
			u=j;
			}

			s[u]=1;
			sum=sum+d[u];

			for(v=1;v<=n;v++)
			if(s[v]==0 && d[v] > d[u]+a[u][v])
			d[v]=d[u]+a[u][v];
	   }
for(i=1;i<=n;i++)
printf("The shortest distance from %d to %d is %d \n",source,i,d[i]);
	   }




Program 11: Write and execute a program to find a subset of a given set S = {s1, s2,.....,s n } of n positive integers whose sum is equal to a given positive integer d. For example, if S= {1,2, 5, 6, 8} and d = 9 there are two solutions {1, 2, 6} and {1, 8}. A suitable message isto be displayed if the given problem instance doesn’t have a solution.

#include <stdio.h>
	
int s[10], x[10], d, flag=0;


void sumofsub(int,int,int);

int main()
{
	int i,n,sum=0;

	printf("Enter maximum no\n");
	scanf("%d",&n);

	printf("Enter the set in increasing order\n");
	for(i=1;i<=n;i++)
	scanf("%d",&s[i]);

	printf("Enter the maximum subset value:");
	scanf("%d",&d);
	for(i=1;i<=n;i++)
	sum+=s[i];

	if(sum<d || s[1]>d)
	{
	printf("No subset possible\n");
	flag=1;
	}

	sumofsub(0,1,sum);

	if(flag==0)
	printf("no subset possible\n");
	return 0;
}

 void sumofsub(int m,int k,int r)
{
int i;
x[k]=1;
	if((m+s[k])==d)
	{
	printf("{");
	for(i=1;i<=k;i++)
	if(x[i]==1)
	{
	printf(" %d ",s[i]);
	flag=1;
	}
	printf("}");
	printf("\n");
	}

else
	{
	if(m+s[k]+s[k+1]<=d)
	sumofsub(m+s[k],k+1,r-s[k]);
	if((m+r-s[k]>=d) && (m+s[k+1]<=d))
	{
	x[k]=0;
	sumofsub(m,k+1,r-s[k]);
	}
	}
}

Program 12: Write and execute a program to find solution to n- queens problem

#include<stdio.h>
#include<math.h>

	void main()
		{
		int n;
		clrscr();

		printf(" Enter the Number of Queens \n");
		scanf("%d", &n);

		if(n == 1 || n==2 || n==3)
		printf(" Solution is not posible \n");
		else
		nqueen(n);
		}

	// Function for nqueens

		nqueen(int n)
		{
		int x[10],k=1,i,count = 0;
		x[k]=0;

		while(k!= 0)
		{
			x[k] = x[k] + 1;

			while( x[k] <= n && place(x,k) == 0)
			x[k] = x[k] + 1;

			if(x[k] <= n)
			{

			if( k == n)
			{
			count++;
			printf(" \n Solution %d is \n", count);
			for(i=1;i<=n;i++)
			printf("%d \t", x[i]);
			}

			else

			{
			k = k + 1;
			x[k] = 0;
			}
			}
			else
			k--;
			}
			}
// Function for placing Queen
			
place(int x[10], int k)
		{
		int i;

		for( i = 1; i<=k-1; i++)
		{
		if(x[k] == x[i]) return 0;
		if(abs(x[k] -x[i]) == abs(i-k) ) return 0;
		}
		return 1;
		}

Program 3: Write and execute a menu driven program to print all the nodes reachable from a given starting node in a graph using DFS and BFS method.

#include<stdio.h>
#include<conio.h>

void main()
	{
	int n,a[10][10],i,j,source,s[10],ch;

	clrscr();
	printf("Enter the Number of Nodes \n");
	scanf("%d",&n);

	printf("Enter the Adjacency Matrix \n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);

	printf("Enter the Source Node \n");
	scanf("%d",&source);

	for(i=1;i<=n;i++)
	s[i]=0;

	printf("1: Depth first Traversal 2:Breadth first Traversal \n");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1:	printf("The DFS order is \n");
		Dfs(n,a,source,s);
		break;

	case 2: printf("The BFS order is \n");
		Bfs(n,a,source,s);
		break;

	default: exit(0);
	}
	}

//---------------------------------------------------------------
	Dfs(int n, int a[10][10], int source, int s[10])
	{
	int i;

	printf("%d\t", source);
	s[source]=1;

	for(i=1;i<=n;i++)
	if( s[i] == 0 && a[source][i] == 1)
	Dfs(n,a,i,s);
	}

//---------------------------------------------------------------
	Bfs(int n, int a[10][10], int source, int s[10])
	{
	int q[10], f=1, r=1, i, u, v;

	printf("%d\t", source);
	s[source]=1;

	q[r] = source;

	while ( f <= r )
	{
	u = q[f];
	f = f + 1;

	for(i=1;i<=n;i++)
	if( s[i] == 0 && a[u][i] == 1)
	{
	printf("%d\t", i);
	s[i] = 1;
	r = r+1;
	q[r] = i;
	}

	}
	}

/* OutPut

Enter the Number of Nodes
5
Enter the Adjacency Matrix
0 0 0 1 0
1 0 1 0 0
1 0 0 1 1
0 1 0 0 0
0 0 0 0 0
Enter the Source Node
1
The DFS order is
1       4       2       3       5


Enter the Number of Nodes
5
Enter the Adjacency Matrix
0 0 0 1 0
1 0 1 0 0
1 0 0 1 1
0 1 0 0 0                                                                       
0 0 0 0 0                                                                       
Enter the Source Node                                                           
1                                                                               
1: Depth first Traversal 2:Breadth first Traversal                              
2                                                                               
The BFS order is                                                                
1       4       2       3    
// Program 5: Write and execute a program to search for the given pattern string in given text string
// using Horspool String Matching algorithm.

#include<stdio.h>
#include<string.h>

// Horspool Function
int horspool(char T[100], char P[100], int n, int m) {
    char ST[200];
    int i, j;
    for(i = 0; i < n; i++)
        ST[T[i]] = m;
    for(i = 0; i < m - 1; i++)
        ST[P[i]] = m - 1 - i;
    i = m - 1;
    while(i < n) {
        j = 0;
        while(j < m && (P[m - 1 - j] == T[i - j]))
            j = j + 1;
        if(j == m)
            return (i - m + 1);
        else
            i = i + ST[T[i]];
    }
    return -1;
}

// Main Function
int main() {
    char T[100], P[100];
    int i, j, n, m, flag;
    printf("Enter the text string:\n");
    gets(T);
    printf("Enter the pattern string:\n");
    gets(P);

    n = strlen(T);
    m = strlen(P);

    flag = horspool(T, P, n, m);
    if(flag == -1)
        printf("String not found!\n");
    else
        printf("String found from index %d.", flag);
}

// Program 1: Write and execute a program to sort a given set of elements using the Quick sort method.

#include<stdio.h>

// Partition Function
int partition(int a[100], int low, int high) {
    int key, i, j, temp;
    key = a[low];
    i = low + 1;
    j = high;
    while(1) {
        while (key >= a[i])
            i++;
        while (key < a[j])
            j--;
        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else {
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
            return j;
        }
    }
}

// Quicksort Function
void quicksort(int a[100], int low, int high) {
    int j;
    if(low < high) {
        j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

// Main Program
int main() {
    int n, a[100], i;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("Enter the %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);
    quicksort(a, 0, n - 1);
    printf("The sorted elements are:\n");
    for(i = 0; i < n; i++)
        printf("%d\t",a[i]);
}
   


                                                                              
                                       
 
                                                                
                                                                               
                                                                                   
                                                                





























