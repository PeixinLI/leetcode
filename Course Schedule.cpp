class Solution {
public:
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int prereq_num[numCourses];
        bool delete_c[numCourses];
        for(int i = 0; i < numCourses; i++){
            delete_c[i] = false;
        }
        for(int i = 0; i < prerequisites.size(); i++){
            prereq_num[prerequisites[i].first]++;
        }
        while(!prerequisites.empty()){
            for(int i = 0; i < numCourses; i++){
                if(prereq_num[i] == 0 && delete_c[i] = false){
                    flag = 1;
                    delete_c[i] = true;
                    for(int j = 0; j< prerequisites.size(); j++){
                        if(prerequisites[j].second == i){
                            prereq_num[prerequisites[j].first] --;
                            prerequisites.erase(prerequisites.begin()+j);
                            j--;
                        }
                    }
                }
                if(flag == 0) return false;
            }
        }
        
        return true;
        
    }
    
    void calculate_prereq_num(vector<pair<int, int>>& prerequisites){
        for(int i = 0; i < prerequisites.size(); i++){
            prereq_num[prerequisites[i].first]++;
        }
    }
};