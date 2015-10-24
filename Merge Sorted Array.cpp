class Solution {
public:
//https://leetcode.com/problems/merge-sorted-array/
    void merge(vector<int>& nums1 , int m , vector<int>& nums2 , int n) {
        //假设是升序排列的了。
        int i=m-1,j=n-1;
        int k=m+n-1;//新的长度
        while(i>=0&&j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[k--]=nums1[i--];
            }else{
                nums1[k--]=nums2[j--];
            }
        }
        //i不为0 不要紧，反正就存在自己的数组里面。
        while(j>=0){
            nums1[k--]=nums2[j--];
        }
    }
};