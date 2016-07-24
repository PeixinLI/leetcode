class Solution {
public:
	vector<vector<string>> res;
    vector<vector<string>> partition(string s) {  	
    	int size = s.size();
    	if(size == 0)
    		return res;

    	vector<string> v;
    	dfs(v, s, 0, size);

    	return res;

    }

    void dfs(vector<string>& v, string s, int begin, int end){
        //cout <<begin <<" "<< end<<endl;
    	if(begin == end){
    	    res.push_back(v);
    		return;
    	}

    	for(int i = 1; i <= end-begin; i++){
    		string tps = s.substr(begin, i);
    		if(isPalindrome(tps)){
    			v.push_back(tps);
    			dfs(v, s, begin + i , end);
    			v.pop_back();
    		}
    	}

    	return;
    }

    bool isPalindrome(string s){
        int j = s.size()-1;
        int i = 0;
    	while(i <= j){
    		if(s[i] != s[j])
    			return false;
    		i++;
    		j--;
       	}
       	return true;
    }
};