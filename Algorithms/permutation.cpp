class Solution {
public:
    void display(vector<int> nums)
    {
        for(auto itr : nums)
        {
            cout << itr << "\t";
        }
        cout << "\n";
        cout << "-------------------\n";
    }
    void helper(vector<int> nums, int left, int right, vector<vector<int>>& res)
    {
        if (left == right)
        {
            res.push_back(nums);
            //cout << "added below-";
            //display(nums);
            //cout << "\n";
            
        }
        for (int i = left; i < right; i++)
        {
            //cout << "before Swapping = " << left << " <-> " << right << "\n";
            //display(nums);
            std::swap(nums[left], nums[i]);
            
            //cout << "after Swapping\n";
           // display(nums);
            
            helper(nums, left+1, right, res);
            //cout << "before last Swapping = " << left << " <-> " << right << "\n";
            //display(nums);
            std::swap(nums[left], nums[i]);
            
            //cout << "after last Swapping\n";
            //display(nums);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, 0, nums.size(), res);
        return res;
    }
};
