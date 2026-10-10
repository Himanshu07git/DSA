class Solution {
public:
    bool isHappy(int n) {
        int sum=0;
        while(n!=1){
          sum=0;
          while(n>0){
            int a= n%10;
            sum= sum+ a*a;
            n=n/10;
          }
          n=sum;
          if(n==4) 
            return false;
        }
       return true; 
    }
};