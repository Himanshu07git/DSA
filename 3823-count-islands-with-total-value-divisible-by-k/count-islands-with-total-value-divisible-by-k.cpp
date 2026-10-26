class Solution {
public:
    int n,m;

    long long dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return 0;

        int val= grid[i][j];
        grid[i][j]=0;
        long long sum= val;
        
        // calling dfs for all four direction
        sum=sum+ dfs(grid, i+1, j);
        sum=sum+ dfs(grid, i-1, j);
        sum=sum+ dfs(grid, i, j+1);
        sum=sum+ dfs(grid, i, j-1);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n= grid.size();
        m= grid[0].size();
            
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0){
                  long long sum= dfs(grid, i,j);
                  if(sum%k==0)
                    cnt++;
                }
            }
        }
        return cnt;
    }
};