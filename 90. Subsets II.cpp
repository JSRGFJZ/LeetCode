class Solution {
public:
    vector<vector<int>>res;
    vector<int>tem;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        res.push_back(vector<int>());
        subsetsHelper(0,nums);
        return res;
    }
    
    void subsetsHelper(int start,vector<int>&nums){
        if(start==nums.size())
            return;
        
        for(int i=start;i<nums.size();i++){
            if(i>start&&nums[i]==nums[i-1])// attention
                continue;
            tem.push_back(nums[i]);
            res.push_back(tem);
            subsetsHelper(i+1,nums);
            tem.pop_back();
        }
    }
};
// 还行啊，就是一开始插入一个空的不太会了
// 测试的时候心里很紧张啊
// 还不错，小心谨慎啊
