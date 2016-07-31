class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        set<int> set2;
        vector<int> result;
        
        if(nums1.size() == 0 || nums2.size() == 0)
            return result;
        
        int i = 0, j = 0;
        vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
        
        for(; it1 != nums1.end(); it1++)
        {
            set1.insert(*it1);
        }
        for(; j < nums2.size(); j++)
        {
           set2.insert(nums2[j]);
        }
       
        set<int>eg3;
        set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),insert_iterator<set<int> >(eg3,eg3.begin()));
        
        set<int>::iterator set_iter=eg3.begin();
        for(;set_iter!=eg3.end();set_iter++)
            result.push_back(*set_iter);
            
        return result;
        
        
    }
};
