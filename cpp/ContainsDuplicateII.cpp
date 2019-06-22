class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size_nums = nums.size();
        if(size_nums <= 1) return false;
        
        unordered_map<int, int> mp1;
        for (int i = 0; i < nums.size(); ++i) {
            //扫描一遍数组，如果首次出现，将元素和位序加入map
            //如果找到了（即重复出现），比较当前位序与该元素上次出现时的位序，若差不大于k，返回true
            //若不满足，将map中该重复数字的值更新为当前位序
            //算法时间复杂度：O(n)，其中map的find函数为O(logn)
            if (mp1.find(nums[i]) != mp1.end() && i - mp1[nums[i]] <= k) 
            {
                cout << i << " " << mp1[nums[i]] << endl;
                return true;
            }
            else mp1[nums[i]] = i;
        }
        return false;
        
        
    }
};
