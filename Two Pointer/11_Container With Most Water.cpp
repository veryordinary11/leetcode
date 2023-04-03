class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int curr_area = 0;
        int max_area = 0;
        while(low < high){
            curr_area = (high - low) * min(height[low],height[high]);
            max_area = max(max_area, curr_area);

            if(height[low] < height[high]) low++;
            else if(height[low] > height[high])   high--;
            else{
                low++;
                high--;
            }
        }
        return max_area;
    }
};
