class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         if(n == 0) return;
         if(n != 0 && m == 0)  
         {
             nums1 = nums2;
             return;
         }
         //cout << nums1.size();
         int index = m + n - 1;
         int index1 = m - 1, index2 = n - 1;
         
         
         
         while(index1 >= 0 && index2 >= 0)
         {
             //cout << " " << index;
             if(nums2[index2] > nums1[index1])
                nums1[index--] = nums2[index2--];
             else 
                nums1[index--] = nums1[index1--];
            cout << nums1[index+1];
         }
         
         while(index1 >= 0)
            nums1[index--] = nums1[index1--];
         while(index2 >= 0)
         {
            nums1[index--] = nums2[index2--];
         }
        
        
    }
};
