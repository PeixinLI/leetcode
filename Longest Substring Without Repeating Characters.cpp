//abcdba   abcabcb
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int N = s.size();
        int max_len = 0;
        int cur_len = 0;
        int last_dup = 0; //
        map<char, int> last_letter_pos; // use this to record the last postion of character
        for(int i = 0 ; i < N; i++){
            if(last_letter_pos.find(s[i]) == last_letter_pos.end()){ // there doesn't exist the charactor before
                cur_len++;
                last_letter_pos.insert(pair<char, int> (s[i], i));
            }
            
            else if(last_letter_pos[s[i]] > last_dup) {//if the character is the last duplicate character
                last_dup = last_letter_pos[s[i]];
                last_letter_pos[s[i]] = i;
                cur_len = i - last_dup;
            }
            else {//if the character is not the last duplicate character
                last_letter_pos[s[i]] = i;
                cur_len = i - last_dup;
            }
            
            if(cur_len > max_len)
                max_len = cur_len;
        }
        
        return max_len;
        
    }
};