class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=0;i<n;i++) {
            for (int j=m;j>=0;j--) {
                if (j==0||(j==m&&nums2[i]>=nums1[j-1])||(nums1[j-1]<=nums2[i]&&nums2[i]<=nums1[j+1])) {
                    nums1[j]=nums2[i];
                    break;
                } else {
                    nums1[j]=nums1[j-1];
                }
            }
            m++;
        }
    }
};