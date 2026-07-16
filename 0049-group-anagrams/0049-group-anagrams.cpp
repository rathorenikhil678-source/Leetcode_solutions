class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ye basical store kare ga ek word se related sare word
        unordered_map<string, vector<string>> anagramMap;

        for (string word : strs) {
            string sortedWord =
                word; // copy bana li word taki original me koi change na ho
            sort(sortedWord.begin(), sortedWord.end());

            // Sorted word ko key banakar original word ko push kar diya
            anagramMap[sortedWord].push_back(word);
        }

        // Map se values nikal kar answer mein dal do
        vector<vector<string>> ans;
        for (auto it : anagramMap) {
            ans.push_back(it.second);
        }

        return ans;
    }
};