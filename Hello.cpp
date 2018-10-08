#include <iostream>
#include <vector>
using namespace std;
const int N =100;
const int MAXV = 1000;
const int INF = 1000000000;

int n,G[MAXV][MAXV];
bool vis[MAXV] = {false};
struct node
{
    int v,w;
    node(int _v,int _w) : v(_v),w(_w) {}//定义结构体构造函数
};

void DFS(int u ,int depth)
{
    vis[u] = true;
    for( int v = 0;v < n; v++)
        if(vis[v] == false && G[u][v] != INF)
    {
        DFS(v,depth + 1);
    }
}

vector<int> Adj[MAXV];
int n;
bool visL[MAXV] = {false};
void DFSL(int u, int depth)
{
    visL[u] = true;
    for(int i  = 0;i< Adj[u].size;i++)
    {
        int v = Adj[u][i]; //
        if(visL[v] == false)
        {
            DFSL(v,depth+1);
        }
    }
}
void DFSLTrave()
{
    for(int u = 0;u<n;u++)
    {
        if(visL[u] == false)
        {
            DFS(u,1);
        }
    }
}


void DFSTrave()
{
    for(int u = 0;u<n;u++)
        if(vis[u] == false)
    {
        DFS(u,1);
    }
}

int main()
{
    vector<node> Adj[N];
    Adj[1].push_back(node(3,4));
    //cout << "Hello world!" << endl;
    return 0;
}
