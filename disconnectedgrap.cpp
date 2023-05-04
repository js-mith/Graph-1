#include<iostream>
#include<queue>
using namespace std;

void print_dfs(int **edges , int n , int sv , bool *visited){
    cout << sv << endl;
    visited[sv] = true;

    for(int i =0 ; i<n ; i++){
        if(i == sv){
            continue;
        }

        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }

            print_dfs(edges , n , i , visited);
        }
    }
}

void print_bfs(int **edges , int n , int sv , bool * visited){
    queue<int> pendingvertex;
    

    pendingvertex.push(sv);
    visited[sv] = true;

    while(!pendingvertex.empty()){
        int currentvertex = pendingvertex.front();
        pendingvertex.pop();

        cout << currentvertex << endl;

        for(int i =0 ; i< n ; i++){
            if(i == currentvertex){
                continue;
            }

            if(edges[currentvertex][i] == 1 && !visited[i]){
                pendingvertex.push(i);
                visited[i] = true;
            }
        }
    }

    

}

void bfs(int **edges , int n){
    bool *visited = new bool[n];
    for(int i =0 ; i<n ; i++){
        visited[i] = false;
    }

    for(int i =0 ; i<n ; i++){
        if(!visited[i]){
            print_bfs(edges,n ,i ,visited);
        }
    }
    delete []visited;
}

void dfs(int **edges , int n){
    bool *visited = new bool[n];
    for(int i =0 ; i<n ; i++){
        visited[i] = false;
    }

    for(int i =0 ; i<n ; i++){
        if(!visited[i]){
            print_dfs(edges,n ,i ,visited);
        }
    }
    delete []visited;

}

int main() {
     int n;
     int e;
     cin>>n>>e;

     int **edges = new int *[n];
     for(int i =0 ; i<n ; i++){
        edges[i] = new int[n];
        for(int j =0 ; j<n ; j++){
            edges[i][j] = 0;
        }
     }

     for(int i =0 ; i< e ; i++){
        int f,s;
        cin>>f>>s;

        edges[f][s] = 1;
        edges[s][f] = 1;
     }

     bool * visited = new bool[n];
     for(int i =0 ; i <n ; i++){
        visited[i] = false;
     }
      
      cout << "======= DFS ======" << endl;
     dfs(edges , n );

     cout << "======= BFS =======" <<endl;
     bfs(edges,n);
     return 0;
}