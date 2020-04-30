// https://leetcode.com/problems/next-greater-element-i/
// i feel dumb , i could've used stack instead of deque
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        if(!n)return {};
        unordered_map<int,int>M;
        deque<int>d;
        d.push_back(nums2[0]);
        for(int i=1;i<n;i++){
            while(!d.empty()&& nums2[i]>d.back() ){
                M[d.back()]=nums2[i];
                d.pop_back();
            }
            d.push_back(nums2[i]);
        }
        while(!d.empty()){
            M[d.back()]=-1;
            d.pop_back();
        }
        vector<int>V;
        for(auto x:nums1)V.push_back(M[x]);
        return V;
    }
};
