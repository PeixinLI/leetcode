class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	map<string, vector<string> v> mp;

    	int size = strs.size();

    	for(int i = 0; i < size; i++){
    		string s1 = strs[i];
    		string t = s1;
    		sort(t.begin(), t.end());
    		if(mp.find(t) != mp.end()){
    			mp[t].push_back(s1; 
    		}
    		else{
    			vector<string> v;
    			v.push_back(s1);
    			map[t] = s1;
    		}
    	}
    	vector<vector<string>> res;
    	for(map<string, vector<string> v>::iterator it = mp.begin(); it != mp.end(); ++it )
    		res.push_back(it->second);

    	return res;
        
    }
};