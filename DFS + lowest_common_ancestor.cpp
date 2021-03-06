#include <iostream>
#include <vector>
using namespace std;

/*dfs using vector

input:
7 3                       
0 1 2
1 3 4
4 5 6

O/P: 0 1 3 4 5 6 2

TREE:

                    0
                   / \
                  1   2
                 / \
                3   4
                   / \
                  5   6
*/


bool visited[1000];
vector<vector<int>> adj(1000);

void dfs(int node){
    
    if(visited[node]==false){
        visited[node]=true;
        cout<<node<<" ";
        for(int i=0;i<adj[node].size();i++){
            dfs(adj[node][i]);
        }
        
    }
}

void print(int num_of_nodes){
    dfs(0);
}

int lca(int root,int x,int y){
    if(adj[root].size()==0){
        if(root == x || root ==y){
            return root;
        }
        else{
            return 0;
        }
    }
    if(root==x || root==y){
        return root; 
    }
    int left,right;
    left = lca(adj[root][0],x,y);
    right = lca(adj[root][1],x,y);
    if(left == 0 && right ==0){
        return 0;
    }
    else if(right!=0 && left != 0){
        return root;
    }
    if(left!=0){
        return left;
    }
    else{
        return right;
    }
}

int main() {
    
    int num_of_nodes,lines;
    cin>>num_of_nodes;
    cin>>lines;
    
    for(int i=0;i<num_of_nodes;i++){
        visited[i]=false;
    }
	
	int line = lines;
	
	while(line){
	    int a,b,c;
	    vector<int> temp;
	    cin>>a;
	    cin>>b;
	    cin>>c;
	    temp.push_back(b);
	    temp.push_back(c);
	    adj[a]=temp;
	    line--;
	}
	int x,y;
	cin>>x>>y;
	
	cout<<lca(0,x,y);
	
	//print(num_of_nodes);
	
	
	
	return 0;
}