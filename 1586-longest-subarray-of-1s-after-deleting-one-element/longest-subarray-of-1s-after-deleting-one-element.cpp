class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // define required variable here ;
        int size = nums.size();
        int ans = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        int lastlen = 0;
        int currentlen = 0;

// tracking the answer according to the given condition of question ;
        while(ptr2<size){
            if(nums[ptr2] == 1){
                ptr2++;
            }
            else{
                currentlen = ptr2 - ptr1;
                ans = max(ans, lastlen+currentlen);
                lastlen = currentlen;
                ptr2++;
                ptr1 = ptr2;
            }
        }

// here is write last case of subarray ;
        if(nums[size-1] != 0){
            currentlen = ptr2 - ptr1;
            ans = max(ans, lastlen+currentlen);
        }

// one element from the nums should delete ;
        if(ans == size){
            return ans-1;
        }
        else{
            return ans;
        }
    }
};