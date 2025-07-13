class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int p = players.size();
        int t = trainers.size();
        int pc = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(ptr1<p && ptr2<t){
            if(players[ptr1]<=trainers[ptr2]){
                ptr1++;
                ptr2++;
                pc++;
            }
            else{
                ptr2++;
            }
        }
        return pc;
    }
};