class Solution {
public:
    bool linearSearch(vector<int>& nums, int target) {
        for (int num : nums) {
            if (num == target) return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int longest = 1;

        for (int i = 0; i < n; i++) {
            int count = 1;
            int x = nums[i];

            while (linearSearch(nums, x + 1)) {
                x = x + 1;
                count++;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};