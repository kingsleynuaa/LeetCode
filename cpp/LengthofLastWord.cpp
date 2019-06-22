class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;
        vector<int> nums;
        
        
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
               nums.push_back(count);
              // cout << count << " ";
               count = 0;
            }
            else count++;
        }
        nums.push_back(count);
        
        int result = 0;
       
       
        reverse(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) 
                continue;
            else 
            {
                result = nums[i];
                break;
            }
            //cout << endl << result ;
            //cout << nums[i];
        }
       
        
        
       
        return result;
        
        
    }
};
