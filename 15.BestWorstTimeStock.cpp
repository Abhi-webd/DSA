 class Solution {
public:
    int maxProfit(vector<int>& prices) {
        map<int,int> m1;
        for(int i = 0 ; i < prices.size()-1; i++){
            if(i == 0){
                if(prices[i] < prices[i+1]){
                    m1[prices[i]] = 1;
                    cout<<prices[i]<<" "<<i<<" ";
                }
            }
            else{
                if(prices[i] <= prices[i-1] && prices[i] <= prices[i+1] && !m1[prices[i]]){
                      m1[prices[i]] = i;
                }
            }
        }
        map<int,int> m2;
        for(int i = 1; i < prices.size(); i++){
            if( i == prices.size()-1){
                if(prices[i] > prices[i-1]){
                    m2[prices[i]] = i;
                }
            }
            else{
                if(prices[i] >= prices[i-1] && prices[i] >= prices[i+1]){
                    m2[prices[i]]= i;
                }
            }
        }
        int max_profit = INT_MIN;
        int profit;
        for(auto i: m2){
            for(auto j:m1){
                if(i.second >= j.second ){
                    profit = i.first - j.first;
                    max_profit = max(profit,max_profit);
                }
            }
        }
        if(max_profit == INT_MIN){
            return 0;
        }
        return max_profit;
    }
};
