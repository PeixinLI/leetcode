class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dig_to_let = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int N = digits.size();
        vector<string> res;
        if(N == 0) return res;
        res.push_back("");
        
        for(int i = 0; i < N; i++){
            int L = res.size();
            string dig = dig_to_let[digits[i]-'1'];
            for(int j = 0; j < L; j++){
                for(int k = 0; k < dig.size(); k++){
                    string s = res[j];
                    s += dig[k];
                    res.push_back(s);
                }
            }
            res.erase(res.begin(), res.begin()+L);
        }
        return res;
    }
};