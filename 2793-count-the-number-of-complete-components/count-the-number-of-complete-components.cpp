void dfs(unordered_map<int,vector<int>> & graph, int node, vector<int> & visited, vector<int> & nodes){
    if(visited[node]){
        return ;
    }
    else{
        visited[node] = true;
        nodes.push_back(node);
        vector<int> adj = graph[node];
        for(int i=0;i<adj.size();i++){
            dfs(graph, adj[i], visited,nodes);
        }
        return; 
    }
}

bool funct(unordered_map<int,vector<int>> & graph, int node, vector<int> & visited, vector<int> & degree){
    vector<int> nodes;
    dfs(graph, node, visited, nodes);
    int m = nodes.size();
    for(int i=0;i<m;i++){
        if(degree[nodes[i]]!=m-1){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // construct the graph
        vector<int> degree(n,0);
        int e = edges.size();
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<e;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            degree[u]++;
            degree[v]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> visited(n,false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                bool check = funct(graph, i, visited, degree);
                if(check){
                    ans++;
                }
            }
        }
        return ans;
    }
};