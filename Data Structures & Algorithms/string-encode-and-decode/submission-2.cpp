class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(string s : strs){
            res += to_string(s.length()) + "#" + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i < s.length()){
            // Step 1: Find '#'
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            // Step 2: Get length
            int len = stoi(s.substr(i, j - i));
            // Step 3: Extract string
            string word = s.substr(j + 1, len);
            result.push_back(word);
            // Step 4: Move pointer
            i = j + 1 + len;
        }

        return result;
    }
};