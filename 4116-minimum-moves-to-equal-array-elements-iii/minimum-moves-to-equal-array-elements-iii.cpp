class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long mx=nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i]>mx)
              mx= nums[i];
        }
        long long ans=0;
        for(int i=0; i<nums.size(); i++){
            ans= ans+ (mx-nums[i]);
        }
        return ans;
    }
};