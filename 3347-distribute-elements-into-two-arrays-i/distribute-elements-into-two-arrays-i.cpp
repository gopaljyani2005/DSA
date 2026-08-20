class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> arr1;
        vector<int>arr2;

        int ptr1 = 0;
        int ptr2 = 0;
        int i = 2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        while(i<size){
            if(arr1[ptr1]>arr2[ptr2]){
                arr1.push_back(nums[i]);
                ptr1++;
            }
            else{
                arr2.push_back(nums[i]);
                ptr2++;
            }
            i++;
        }


        int j = 0;
        while(j<arr2.size()){
            arr1.push_back(arr2[j++]);
        }

        return arr1;

    }
};