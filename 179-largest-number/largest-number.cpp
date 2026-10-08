class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        // Apply bubble sort
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i-1; j++){
               if(to_string(nums[j])+to_string(nums[j+1]) < to_string(nums[j+1])+to_string(nums[j]))
                  swap(nums[j], nums[j+1]);
            }
        }

        if(nums[0]==0)
          return "0";

        string ans;
        for(int i=0; i<n; i++){
           ans= ans+ to_string(nums[i]);
        }
        return ans;
    }
};