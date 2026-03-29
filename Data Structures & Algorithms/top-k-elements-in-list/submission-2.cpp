class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // Step 1: Count frequency
        for(int num : nums){
            freq[num]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);

        for(auto it : freq){
            int number = it.first;
            int count = it.second;

            bucket[count].push_back(number);
        }

        // Step 3: Traverse buckets
        vector<int> result;

        for(int i = bucket.size() - 1; i >= 0; i--){

            for(int num : bucket[i]){
                result.push_back(num);

                if(result.size() == k)
                    return result;
            }
        }

        return result;
    }
};

// FUNCTION TopKFrequent(nums, k)

//     CREATE hashmap freq

//     FOR each num in nums
//         freq[num]++
//     END FOR

//     CREATE bucket array of size (length(nums) + 1)

//     FOR each (num, count) in freq
//         bucket[count].append(num)
//     END FOR

//     CREATE empty list result

//     FOR i from length(bucket)-1 DOWNTO 0
//         FOR each num in bucket[i]
//             result.append(num)

//             IF size(result) == k
//                 RETURN result
//             END IF
//         END FOR
//     END FOR

//     RETURN result

// END FUNCTION