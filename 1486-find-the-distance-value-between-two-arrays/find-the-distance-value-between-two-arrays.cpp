class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        int j=0;
        while(j<arr1.size()){
            bool flag=true;
            for(int i=0; i<arr2.size(); i++){
                if(abs(arr1[j]-arr2[i]) <= d){
                  flag=false;
                  break;
                }
            }
            if(flag==true)
               count++;
            j++;
        }
        return count;
    }
};