#include<bits/stdc++.h>
using namespace std;
//

void dfs(int i,int j,int initial,int newcolor,vector<vector<int>>&img){
int n=img.size();
int m=img[0].size();

if(i<0 || j<0 || i>=n || j>=m || img[i][j]!=initial)return;
    img[i][j]=newcolor;

    dfs(i+1,j,initial,newcolor,img);
     dfs(i-1,j,initial,newcolor,img);
      dfs(i,j+1,initial,newcolor,img);
       dfs(i,j-1,initial,newcolor,img);



}


vector<vector<int>> floodFill(vector<vector<int>>&grid,int sr,int sc,int color){

    int initialcolor = grid[sr][sc];///initialcolor=1=grid[1][1]
    if(initialcolor!=color){
        dfs(sr,sc,initialcolor,color,grid);
    }
    return grid;



}

int main(){

int t;
cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int sr,sc,color;
    cin>>sr>>sc>>color;
    vector<vector<int>> ans=floodFill(grid,sr,sc,color);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }

}


}

