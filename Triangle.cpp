// pay attention to intialize to the vector


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> min_step;
        int row = triangle.size();
        if(row == 1) return triangle[0][0];
        min_step.push_back(triangle[0]);
        for(int i = 1 ; i< row; i++){
            min_step[i][0] = min_step[i-1][0] + triangle[i][0];
            for(int j = 1; j < triangle[i].size(); j++){
                min_step[i][j]
                = min((min_step[i][j] + triangle[i][j]), (min_step[i-1][j] + triangle[i-1][j]) );
                cout<<i << " "<<j<<" "<<min_step[i][j];
            }
        }
        
        int min_path = 9999999;
        for(int j = 0; j < triangle[row -1].size(); j++)
            if(min_step[row-1][j] < min_path)
                min_path = min_step[row-1][j];
    }
    
    int min(int a, int b){
        return (a < b) ? a:b;
    }
};