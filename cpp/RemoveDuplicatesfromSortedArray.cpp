class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length <= 0) return 0;
        int i = 0, j = 1;
        for(; i < length, j < length;)
        {
            if(nums.at(i) != nums.at(j))
            {
                nums[++i] = nums[j];
            }
            else
            {
                j++;
            }
            
        }
        
        for(int m = 0; m < (j-i); m++)
            nums.pop_back();
            
        return i+1;
        
    }
};
