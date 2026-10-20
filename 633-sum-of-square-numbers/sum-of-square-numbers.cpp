class Solution {
public:
    bool judgeSquareSum(int c) {
        // if(c==2) return true;

        long long n= sqrt(c);
        long long i=0;
        while(i<=n){
            long long sum= i*i + n*n;
            if(sum==c)
              return true;
            else{
               if(sum <c)
                  i++;
               else
                  n--;
            }
        }
        return false;
    }
};