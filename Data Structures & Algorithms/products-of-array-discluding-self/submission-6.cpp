class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int prefix = 1;
        int suffix = 1;
        for(int i = 1;i < n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix *=nums[i+1];
            ans[i]*=suffix;
        }
        return ans;
    }
};

// Create an array ans of size n and fill it with 1

// Set prefix = 1

// Loop from left to right (i = 0 to n-1):

// Set ans[i] = prefix

// Update prefix = prefix * nums[i]

// Set suffix = 1

// Loop from right to left (i = n-1 to 0):

// Multiply ans[i] = ans[i] * suffix

// Update suffix = suffix * nums[i]

// Return ans