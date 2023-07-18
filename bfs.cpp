#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution{
    public:

    vector<int> bfs(int node, vector<int> adj[]){
        int vis[node] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        
        vector<int> bfsvec;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            bfsvec.push_back(v);
            for(auto i : adj[v]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        return bfsvec;
    }

};

void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans){
    for(int i = 0 ; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int n = 5;
    vector<int> adj[n+1];
    addEdge(adj, 0,1);
    addEdge(adj, 1,2);
    addEdge(adj, 1,3);
    addEdge(adj, 0,4);

    Solution obj;
    vector<int> ans = obj.bfs(5, adj);
    printAns(ans);

    return 0;

}

