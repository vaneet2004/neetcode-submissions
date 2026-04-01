class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            // Avoid overflow using: mid = low + (high - low) / 2 because in worst cases low and high was int_max if we do low+high overflow occurs 

            int mid = (high+low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};
