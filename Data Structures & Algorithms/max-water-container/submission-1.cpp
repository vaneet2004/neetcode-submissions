class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int maxWater = 0;
        int left = 0 , right = n-1;
        while(left<right){
            int width = right - left;
            int ht = min(nums[left],nums[right]);
            int area = width * ht;
            maxWater = max(maxWater,area);
            nums[left]<nums[right] ? left++ : right--;
        }

        return maxWater;
    }
};