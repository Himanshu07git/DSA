class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n= nums.size();
        long long sumofsquare=0;
        for(int i=1; i<=n; i++){
            if(n%i==0)
              sumofsquare+=(nums[i-1]*nums[i-1]);
        }
        return sumofsquare;
    }
};