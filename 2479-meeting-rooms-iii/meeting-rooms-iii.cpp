class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int size = meetings.size();
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long , int>, vector<pair<long long ,int>>, greater<pair<long long , int>>> minheap1;
        priority_queue<int, vector<int>, greater<int>> minheap2;

        for(int i=0;i<n;i++){
            minheap2.push(i);
        }

        int i = 0;
        int ans = 0;
        int index = 0;
        vector<int> book(n,0);
        while(i<size){
            int start = meetings[i][0];
            int end = meetings[i][1];
            while(!minheap1.empty() && start>=minheap1.top().first){
                minheap2.push(minheap1.top().second);
                minheap1.pop();
            }

            int room;
            if(!minheap2.empty()){
                room = minheap2.top();
                minheap2.pop();
                minheap1.push({end,room});
            }
            else{
                room = minheap1.top().second;
                long long finishedtime = minheap1.top().first;
                minheap1.pop();
                minheap1.push({finishedtime+(end-start),room});
            }
            book[room]++;
            if(book[room]>ans){
                ans = book[room];
                index = room;
            }
            else if(book[room]==ans){
                index = min(index, room);
            }
            i++;
        }
        return index;
    }
};