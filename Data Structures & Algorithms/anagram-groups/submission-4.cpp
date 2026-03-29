#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string word : strs){

            int count[26] = {0};

            // count character frequencies
            for(char c : word){
                count[c - 'a']++;
            }

            // create key from frequency
            string key = "";
            for(int i = 0; i < 26; i++){
                key += to_string(count[i]) + "#";
            }

            mp[key].push_back(word);
        }

        vector<vector<string>> result;

        for(auto &it : mp){
            result.push_back(it.second);
        }

        return result;
    }
};