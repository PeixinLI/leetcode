class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> skyline;
        priority_queue <pair<int,int>> BD; //in the order of height
        int L = buildings.size();
        int cur_X = 0, cur_Y = -1, cur_B = 0;
        while(cur_B < L || !BD.empty()){
            cur_X = BD.empty()? buildings[cur_B][0]:BD.top().second;
            if(cur_B >= L || buildings[cur_B][0] > cur_X){
                while((cur_X >= BD.top().second) && !BD.empty() )
                    BD.pop();
            }
            else{
                cur_X = buildings[cur_B][0];
                while(cur_B < L &&  cur_X == buildings[cur_B][0]){
                    BD.push(pair<int, int>(buildings[cur_B][2], buildings[cur_B][1]));
                    cur_B ++;
                }
            }
            
            cur_Y = BD.empty()? 0: BD.top().first;
            
            if(skyline.empty() || skyline.back().second != cur_Y) skyline.push_back(pair<int, int> (cur_X, cur_Y));
            
            
        }
        
        
        return skyline;
        
    }
    
};