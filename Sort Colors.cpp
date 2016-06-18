/*class Solution {
public:
    void sortColors(vector<int>& nums) {
        multimap<int,int> c_obj;
        
        for(int i = 0; i < nums.size(); i++){
            c_obj.insert(pair<int, int>(nums[i], i));
        }
        
        multimap<int,int>::iterator it;
        
        int i = 0;
        for(it = c_obj.begin(); it != c_obj.end(); ++it){
            nums[i] = (*it)->second;
            i++;
        }
    }
};*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) red++;
            if(nums[i] == 1) white++;
            if(nums[i] == 2) blue++;
        }
        int i = 0;
        while(red--){
            nums[i] = 0;
            i++;
        }
        while(white--){
            nums[i] = 1;
            i++;
        }
        while(blue--){
            nums[i] = 2;
            i++;
        }
    }
};