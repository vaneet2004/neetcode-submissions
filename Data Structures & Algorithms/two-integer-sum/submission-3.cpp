class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        map<int,int> mpp;
        for(int i = 0; i < size; i++){
            int a = nums[i];
            int required = target - a;
            if(mpp.find(required) != mpp.end()){
                return {mpp[required], i};
            }

            mpp[a] = i;
        }
        return {-1,-1};
    }
};