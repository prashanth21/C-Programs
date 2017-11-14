#include<cstdio>
#include<list>
#include<queue>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Graph{

private:
    int V;
    list<int> *adj;

public:
    Graph(int v);
    void addEdge(int u, int v);
    void topo_sort();

};

void Graph::topo_sort(){

    //int in_degree[] = new int[V];
    vector<int> in_degree(V,0);   
 
    for(int i=0; i < V; i++)
         in_degree[i] = 0;

    for(int u=0; u<V; u++){
        list<int>::iterator it;
        for(it = adj[u].begin(); it!= adj[u].end(); it++){
            in_degree[*it]++;
        }
    }

    queue<int> q;
    int count = 0;
    vector<int> ans;

    for(int i=0; i < V; i++){
        if(in_degree[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        
        int elem = q.front();
        q.pop();
        ans.push_back(elem);

        list<int>::iterator it;
        for(it=adj[elem].begin(); it!=adj[elem].end(); it++){
                
            in_degree[*it]--;
            if(in_degree[*it]==0)
                q.push(*it);
        }
        count++;
    }
    
    if(count != V){
        cout << "top_sort not possible on given graph" << endl;
        return;
    }

    vector<int>::iterator it;
    for(it=ans.begin();it!=ans.end();it++){
        cout << *it << " ";
    }
    
    return;

}


Graph::Graph(int v){

    this->V = v;
    this->adj = new list<int>[V];

}

void Graph::addEdge(int u, int v){
   adj[u].push_back(v);
}


int main(){

    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topo_sort();
    
    return 0;

}
