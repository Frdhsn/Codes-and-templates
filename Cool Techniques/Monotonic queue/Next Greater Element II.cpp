// https://leetcode.com/problems/next-greater-element-ii/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(!n)return {};
        vector<int>M(n);
        deque<int>d;
        d.push_back(0);
        for(int i=1;i<n;i++){
            while(!d.empty()&& nums[i]>nums[d.back()] ){
                M[d.back()]=nums[i];
                d.pop_back();
            }
            d.push_back(i);
        }
        for(int i=0;i<n;i++){
            while(!d.empty()&& nums[i]>nums[d.back()] ){
                M[d.back()]=nums[i];
                d.pop_back();
            }
        }
        
        while(!d.empty()){
            M[d.back()]=-1;
            d.pop_back();
        }
        vector<int>V;
        for(int i=0;i<n;i++)V.push_back(M[i]);
        return V;
    }
};
