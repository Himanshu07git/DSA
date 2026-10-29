class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int orig= money;
        sort(prices.begin(), prices.end());

        int val=money- (prices[0]+ prices[1]);
         
        if(val>=0)
           return val;
        else
           return orig;
    }
};