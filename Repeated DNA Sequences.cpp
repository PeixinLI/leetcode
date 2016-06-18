class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int N = s.size();
        vector<string> res;
        if( N < 10) return res;
        map<string, int>::iterator it;
        map<string, int> dna_seq;
        
        // each time
        for(int i = 0; i < N -9; i++){
            string t = t.substr(i, 10);
            it = dna_seq.find(t);
            if(it == dna_seq.end())
                dna_seq.insert(pair<string, int> (t, 1));
            else
                dna_seq[t]++;
        }
        
        for(it = dna_seq.begin(); it != dna_seq.end(); ++it){
            if(it->second > 1)
                res.push_back(it->first);
        }
        
        return res;
        
    }
};