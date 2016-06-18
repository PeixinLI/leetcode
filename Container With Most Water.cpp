class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if(size == 0)
            return 0;
        int i = 0; // start from the two lines have largest distance on the x-axis
        int j = size - 1;
        int water = 0;
        
        while(i < j){
            int h = min(height[i], height[j]);
            water = max(water, h * (j - i));
            while (h >= height[i]) i++;
            while (h >= height[j]) j--;
        }
        
        return water;
        
    }
};