class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> RtoI{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int size = s.size();
        int res = RtoI[s[0]];
        for(int i = 1; i < size; i++){
            if(RtoI[s[i-1]] < RtoI[s[i]])
                res += RtoI[s[i]] - 2* RtoI[s[i-1]];
            else
                res += RtoI[s[i]];
        }
        
        return res;
        
    }
};