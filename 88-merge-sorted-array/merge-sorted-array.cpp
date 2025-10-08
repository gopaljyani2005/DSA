class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m-1;i>=0;i--){
            nums1[i+n] = nums1[i];
        }

        int ptr1 = n;
        int ptr2 =0;
        int index = 0;

        while(ptr1<m+n && ptr2<n){
            if(nums1[ptr1]<=nums2[ptr2]){
                nums1[index] = nums1[ptr1];
                index++;
                ptr1++;
            }
            else{
                nums1[index] = nums2[ptr2];
                index++;
                ptr2++;
            }
        }

        if(ptr1==m+n){
            for(int i=ptr2;i<n;i++){
                nums1[index] = nums2[i];
                index++;
            }
        }
        return ;
        
    }
};