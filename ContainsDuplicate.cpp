class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size_nums = nums.size();
        if(size_nums == 0) return false;
        set<int> s1;
        for(int i = 0; i < size_nums; i++)
        {
            s1.insert(nums[i]);
        }
        
        return s1.size() != size_nums;
        
    }
};
