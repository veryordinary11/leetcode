class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,0);
        unordered_set<int> travelDays;
        for(auto day : days){
            travelDays.insert(day);
        }
        for(int i = 1; i <= 365; i++){
            if(travelDays.find(i) == travelDays.end()){
                dp[i] = dp[i-1];
            }
            else{
                dp[i] = min(dp[i-1] + costs[0], min(dp[max(0,i-7)] + costs[1], dp[max(0,i-30)] + costs[2]));
            }
        }
        return dp[365];
    }
};

/*The idea behind the dynamic programming approach is to build up the solution incrementally, starting from smaller subproblems and working our way up to larger subproblems.

In this case, we start by considering the minimum cost to travel up to day 1, which is simply costs[0] if day 1 is in the days array, or 0 if it is not. We then consider the minimum cost to travel up to day 2, which can be computed by considering the minimum cost of buying a one-day ticket on day 2, a seven-day ticket valid from day 1 to day 7, or a thirty-day ticket valid from day 1 to day 30. We can then use this information to compute the minimum cost to travel up to day 3, and so on.

By iteratively building up the minimum cost to travel up to each day, we eventually arrive at the minimum cost to travel up to the largest day in the days array, which is our final solution.*/
