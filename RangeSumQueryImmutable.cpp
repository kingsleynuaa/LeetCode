class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            Nums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if(i > 0) return Nums[j] - Nums[i-1];
        return Nums[j];
    }
private:
    vector<int> Nums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
