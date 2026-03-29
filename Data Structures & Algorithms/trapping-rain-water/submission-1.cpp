class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
    int totalWater = 0;

    for (int i = 0; i < n; i++) {
        int leftMax = 0, rightMax = 0;

        // Find left max
        for (int j = 0; j <= i; j++) {
            leftMax = max(leftMax, height[j]);
        }

        // Find right max
        for (int j = i; j < n; j++) {
            rightMax = max(rightMax, height[j]);
        }

        // Add trapped water
        totalWater += min(leftMax, rightMax) - height[i];
    }

    return totalWater;
    }
};
