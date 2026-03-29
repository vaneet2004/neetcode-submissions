class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit = 0;
        int mini = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            int cost = nums[i]-mini;
            profit = max(profit,cost);
            mini = min(mini,nums[i]);
        }
        return profit;
    }
};