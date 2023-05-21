#include<bits/stdc++.h>
using namespace std;


    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m,int &count)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
        {
            return 0;
        }
        //count++;
        grid[i][j]=0;

            if(dfs(grid,i+1,j,n,m,count))count++;;
             if(dfs(grid,i-1,j,n,m,count))count++;
              if(dfs(grid,i,j+1,n,m,count))count++;
               if(dfs(grid,i,j-1,n,m,count))count++;

        return 1;


    }
    int misland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int count=1;
                dfs(grid,i,j,n,m,count);
                ans=max(ans,count);
                }
            }
        }
        return ans;
    }


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>grid(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }
        int ans=misland(grid);
        cout<<ans<<endl;
    }
}
