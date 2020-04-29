class Solution {
public:
    static const int MAX = 1e5;
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        if(!n)return {};
        vector<int>bucket[2*MAX + 7];
        int sz=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<(int)nums[i].size();j++){
                int id = i+j;
                sz = max(sz,id);
                bucket[id].push_back(nums[i][j]);
            }
        }
        vector<int>res;
        for(int i=0;i<=sz;i++){
                res.insert(res.end(),bucket[i].rbegin(),bucket[i].rend());
        }
        return res;
    }
};
