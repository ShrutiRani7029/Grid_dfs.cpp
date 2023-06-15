///no. of enclaves,
#include<bits/stdc++.h>
using namespace std;


void dfs(int i,int j,int n,int m, vector<vector<int>>&grid){
    
    if(i<0 || j<0 || i>=n-1 || j>=m-1 || grid[i][j]==0)return;
    grid[i][j]=0;
    dfs(i,j+1,n,m,grid);
         dfs(i+1,j,n,m,grid);
          dfs(i-1,j,n,m,grid);
           dfs(i,j-1,n,m,grid);
}

int enclaves(vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ///we convert all 1's to 0's those are connected to boundaries,
            if((i==0 || j==0 || i== n-1 || j==m-1)&& grid[i][j]==1)
            {
                dfs(i,j,n,m,grid);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)ans++;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>grid(n,vector<int>(m));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }
        cout<<enclaves(grid)<<endl;
        
    }
}
