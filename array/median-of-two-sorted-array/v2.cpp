class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,prev,cur=0;
        int total_length=nums1.size()+nums2.size();
        int count=(total_length/2)+1;
        while(count--){
            prev=cur;
            if(i<nums1.size() && (j>=nums2.size() || nums1[i]<nums2[j])){
                cur=nums1[i];
                i++;
            }
            else{
                cur=nums2[j];
                j++;
            }
        }
        if(total_length%2==1) return cur;
        else return (prev+cur)/2.0;
    }
};