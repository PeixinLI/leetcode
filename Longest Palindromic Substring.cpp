//first come up with Reverse S and become S’. the longest common substring method fails when there exists a reversed copy of a non-palindromic substring in some other part of S.

//we can use dynamic programming to solve this problem O(n^2)
// if S[i][j] is a palindrome and S[i-1] == S[j+1]then S[i+1][j+1]..
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        if(N == 0 || N ==1) return s;
        int max_len = 1;
        int max_i = 0;
        bool P[1000][1000];
        
        for(int i = 0; i < N; i++){  //initialization
            for(int j = 0; j < N; j++)
                P[i][j] = false;
        }
        
        for(int i = 0; i < N; i++)
            P[i][i] = true;// a single character is definely a palindrome
        
        for(int i = 0; i < N -1; i++){
            if(s[i] == s[i+1]){
                P[i][i+1] = true;
                max_len = 2;
                max_i = i;
            }
        }
        
        for(int i = 2; i < N; i++){
            for(int j = 0; j < N - i; j++ ){
                if(s[j] == s[j+i]){
                    P[j][j+i] = P[j+1][j+i-1];
                    if(P[j][j+i] && ((i + 1) > max_len)){
                        max_len = i+1;
                        max_i = j;
                    }
                }
            }
        }
        string res = s.substr(max_i, max_len);
        
        return res;
        
    }
};