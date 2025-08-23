class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        int maxfreqele = nums[0];

        for(int i=0;i<size;i++){
            map1[nums[i]]++;
        }

        for(int i=0;i<size;i++){
            int ele = nums[i];
            map1[ele]--;
            map2[ele]++;
            if(map2[ele]>map2[maxfreqele]){
                maxfreqele = ele;
            }

            if(map2[maxfreqele]>(i+1)/2){
                if(map1[maxfreqele]>(size-i-1)/2){
                    return i;
                }
            }
        }
        
        return -1;
        
    }
};