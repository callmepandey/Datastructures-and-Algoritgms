#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
	public:
		int n;
		vector < vector <int> > edges;
		Graph(int size) {
			edges.resize(size + 1);
			n = size;
		};
		
		void addDirectedEdge(int u, int v) {
			edges[u].push_back(v);
		}
		
		void addUndirectedEdge(int u, int v) {
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		
		void bfs(int u , vector <bool> &vis) {
			queue <int> Q;
			Q.push(u);
			vis[u] = true;

			while(!Q.empty()) {
				int currentVertex = Q.front();

				cout << currentVertex << " " ;
				Q.pop();
				for(int connectedVertex : edges[currentVertex]) {
					if(vis[connectedVertex]) {
						continue;
					}
					vis[connectedVertex] = true;
					Q.push(connectedVertex);
				}
			}
		}
		
		void bfs() {
			
			cout << "BFS Order is as follow -> " ;
			vector <bool> vis(n + 1 , 0);
			for(int i = 1;i<=n;i++) {
				if(!vis[i]) {
					bfs(i , vis);
				}
			}
			cout << "\n" ;
		}
		
		void dfs(int currentVertex, vector <bool> &vis) {
			cout << currentVertex << " " ;
			for(int connectedVertex : edges[currentVertex]) {
				if(vis[connectedVertex]) {
					continue;
				}
				vis[connectedVertex] = true;
				dfs(connectedVertex , vis);
			}
		}
		
		void dfs() {

			cout << "DFS Order is as follow -> " ;
			vector <bool> vis(n + 1 , 0);
			for(int i = 1;i<=n;i++) {
				if(!vis[i]) {
					vis[i] = true;
					dfs(i , vis);
				}
			}
			cout << "\n" ;
		}
};

int main() {
	Graph Object(5);
	Object.addDirectedEdge(1 , 2);
	Object.addDirectedEdge(2 , 3);
	Object.addDirectedEdge(1 , 4);
	Object.addDirectedEdge(5 , 1);
	Object.bfs();
	Object.dfs();
	return 0;
}
