/*class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        Generate(n, res);
        return res;
    }
    
    void Generate(int n, vector<string>& res){
        if(n == 0) return;
        if(n == 1){
            string p = "()";
            res.push_back(p);
            return;
        }
        
        Generate(n-1, res);
        int cur_size = res.size();
        for(int i = 0; i < cur_size; i++){
            string tmp = res[i];
            string tmp_ = tmp;
            tmp_.insert(tmp_.begin(), '(');
            tmp_.insert(tmp_.end(),')');
            res.push_back(tmp_);
            tmp_ = tmp;
            tmp_ += "()";
            res.push_back(tmp_);
            if( i != cur_size -1){
                tmp_ = tmp;
                tmp_.insert(tmp_.begin(),')');
                tmp_.insert(tmp_.begin(),'(');
                res.push_back(tmp_);
            }
            
        }
        
        res.erase(res.begin(), res.begin()+cur_size);
        return;
    }
    
};*/

// leftnum > rightnum
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        Generate(res, s, n, n);
        return res;
    }
    
    void Generate(vector<string>& res, string s, int leftnum, int rightnum){
        if(leftnum == 0 && rightnum ==0){
            res.push_back(s);
            return;
        }
        if(leftnum > 0) Generate(res, s+'(', leftnum-1, rightnum);
        if(rightnum > leftnum && rightnum > 0) Generate(res, s+')', leftnum, rightnum -1);
        return;
    }
};














