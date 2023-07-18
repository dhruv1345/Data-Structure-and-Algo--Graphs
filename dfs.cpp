#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    private:
    void dfsOfGraph(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfsOfGraph(it, adj, vis, ls); 
            }
        }
    }
    public:
    vector<int> dfs(int node, vector<int> adj[]){
        int vis[node] = {0};
        int start = 0;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfsOfGraph(start, adj, vis, ls); 
        return ls; 
    }
};

void makegraph(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printdfs(vector<int> &ans){
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int n = 5;
    vector<int> adj[n+1];

    makegraph(adj, 0,1);
    makegraph(adj, 0,2);
    makegraph(adj, 2,4);
    makegraph(adj, 0,3);

    Solution obj;
    vector<int> ans = obj.dfs(5, adj);

    printdfs(ans);

    return 0;

}