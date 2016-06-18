class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        int prereq_num[numCourses];
        bool delete_c[numCourses];
        int count = 0;
        for(int i = 0; i < numCourses; i++){
            delete_c[i] = false;
            prereq_num[i] = 0;
        }
        for(int i = 0; i < prerequisites.size(); i++){
            prereq_num[prerequisites[i].first]++;
        }
        while(count != numCourses){
            int flag = 0;
            for(int i = 0; i < numCourses; i++){
                if(prereq_num[i] == 0 && delete_c[i] == false){
                    count++;
                    result.push_back(i);
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
            }
            if(flag == 0){
                return {};
            }
        }
        
        return result;
        
    }
    
};