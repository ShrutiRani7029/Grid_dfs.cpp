class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        //r2,c2   r3,c2    r2,c1
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        map<vector<int>,int>mp;
        for(int i=0;i<n;i++){
            mp[grid[i]]++; //row addition
        }
        
        for(int j=0;j<m;j++){
            vector<int>v; 
            for(int i=0;i<n;i++){
                v.push_back(grid[i][j]);
            }
            ans+=mp[v];
        }
        return ans;
        
        
    }
};


Time complexity: o(n*m * logn)
Space Complexity: o(n)
