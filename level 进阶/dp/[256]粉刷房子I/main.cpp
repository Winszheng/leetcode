#include <vector>
using namespace std;

// define d[i]为[0-i]上的最优解, 由题意知，每个状态只与上一个状态有关。
// 当前状态仅仅与前一个状态有关

// @lc code=start
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = costs[0][0], dp[0][1]=costs[0][1], dp[0][2]=costs[0][2];
        for(int i=1; i<n; i++){
            dp[i][0] = costs[i][0]+min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1]+min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }
        int re = min(dp[n-1][0], dp[n-1][1]);
        return min(re, dp[n-1][2]);
    }
};
// @lc code=end