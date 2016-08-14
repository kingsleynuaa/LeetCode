class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int result = 0;
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0],nums[1]);
        
        vector<int> MAX(size,0);
        MAX[0] = nums[0];
        MAX[1] = max(nums[0],nums[1]);
        result = MAX[1];
        for(int i = 2; i < size; i++)
        {
            MAX[i] = max(MAX[i - 2] + nums[i], MAX[i - 1]);
            if(MAX[i] > result)
                result = MAX[i];
        }
        
        return result;
        
        
        
    }
};
