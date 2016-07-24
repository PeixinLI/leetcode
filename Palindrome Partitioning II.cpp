// using recurtion time out 
// using dp time out
class Solution {
public:
    int minCut(string s) {
        int size = s.size();

        if(size == 0 || size == 1)
        	return 0;

        vector<int> min_cut(size, size - 1);
        vector<vector<bool>> pal(size, vector<bool>(size, false));

        min_cut[0] = 0; // if the size of the string is 1


        for(int i = 1; i < size; i++){// calculate min_cut[i]
           cout << i<< endl;
        	min_cut[i] = i;
        	for(int j = 0; j <= i; j++){//  the length of sub string is i-j
        	   // cout << j <<endl;
        		if(s[j] == s[i] && (i == j || i == j+1 || i == j+2|| pal[j+1][i-1])){
        		  //  cout << i << j<< endl;
        			pal[j][i] = true;
        			if(j == 0)
        				min_cut[i] = 0;
        			else if(min_cut[j-1] + 1 < min_cut[i])
        				min_cut[i] = min_cut[j-1] + 1;
        		}
        	}
        }

        return min_cut[size - 1];
    }

};