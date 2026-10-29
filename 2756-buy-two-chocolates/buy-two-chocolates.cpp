class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int orig= money;
        sort(prices.begin(), prices.end());

        for(int i=0; i<=1; i++){
           money=money-prices[i];
        }
         
        if(money>=0)
           return money;
        else
           return orig;
    }
};