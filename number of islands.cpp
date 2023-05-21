#include<bits/stdc++.h>
using namespace std;


void dfs(int i,int j,vector<vector<char>>&grid,int vis[][600],int n,int m)
{
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0')return;
    if(!vis[i][j]){

        vis[i][j]=1;
        dfs(i+1,j,grid,vis,n,m);
        dfs(i-1,j,grid,vis,n,m);
        dfs(i,j-1,grid,vis,n,m);
        dfs(i,j+1,grid,vis,n,m);
    }
}

int nisland(vector<vector<char>>&grid){
int n=grid.size();
int m=grid[0].size();
int count=0;

int vis[600][600];

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        vis[i][j]=0;
    }
}

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]!='0' && !vis[i][j])
        {
            dfs(i,j,grid,vis,n,m);
            count++;
        }
    }
}
return count;

}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>>grid(n,vector<char>(m,'#'));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }
        int ans=nisland(grid);
        cout<<ans<<endl;
    }
}
