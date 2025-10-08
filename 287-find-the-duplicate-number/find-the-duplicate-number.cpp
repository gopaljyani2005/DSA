class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        bool firsttime = true;

        //first find the meeting point of slow and fast pointer 

        while(slow!=fast || firsttime){
            firsttime = false;
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        cout<<slow<<endl;
        int slow2 = 0;
        while(slow != slow2){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow2;
    }
};