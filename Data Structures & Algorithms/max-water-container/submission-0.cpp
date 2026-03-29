class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int height = min(nums[i], nums[j]);
                int width = j - i;
                int area = height * width;

                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};