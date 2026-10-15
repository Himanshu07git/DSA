class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        int sum=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                st.insert(nums[j]);
                int cnt= st.size();
                sum=sum+ cnt*cnt;
            }
            st.clear();
        }
        return sum;
    }
};