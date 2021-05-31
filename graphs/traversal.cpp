#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
	map<int,vector<int>> adjList;
	bool biDirectional;

private:
	void _dfsHelper(int v, map<int,bool>& visited){
		cout << v << ' ';
		visited[v] = true;
		for(int i : adjList[v]){
			if(!visited[i]){
				_dfsHelper(i,visited);
			}
		}
	}

	bool _pathDFSHelper(int src, int target, map<int,bool>& visited , vector<int>& path){
		visited[src] = true;
		path.push_back(src);
		if(src == target){
			return true;
		}

		for(int i : adjList[src]){
			if(!visited[i]){
				return _pathDFSHelper(i,target,visited,path);
			}
		}
		return false;
	}

	bool _pathBFSHelper(int src, int target, vector<int> &path){
		queue<int> temp;
		map<int,bool> visited;
		temp.push(src);
		int current;
		visited[current] = 1;

		while(!temp.empty()){
			current = temp.front();
			temp.pop();
			path.push_back(current);

			if(current == target){
				return true;
			}
			
			for(int i : adjList[current]){
				if(!visited[i]){
					visited[i] = 1;
					temp.push(i);
				}
			}

		}

		// can clear the path array
		return false;
	}

	void _cycleDFSHelper(int v, map<int,bool>& visited, bool &cyclePresent){
		visited[v] = 1;
		for(int i : adjList[v]){
			if(!visited[i]){
				_cycleDFSHelper(i,visited,cyclePresent);
				visited[i] = false;
			}
			else{
				cyclePresent = true;
				
			}
		}
	}

public:

	Graph(bool biDirectional = false){
		this->biDirectional = biDirectional;
	}

	void addEdge(int u, int v){
		adjList[u].push_back(v);
		if(biDirectional)
			adjList[v].push_back(u);
	}

	void bfs(int v){
		queue<int> Q;
		map<int,bool> visited;

		Q.push(v);
		visited[v] = 1;

		while(!Q.empty()){
			v = Q.front();
			Q.pop();
			cout << v << ' ';
			for(int i : adjList[v]){
				if(!visited[i]){
					visited[i] = 1;
					Q.push(i);
				}
			}
		}
		cout << '\n';
	}

	void dfs(int v){
		map<int,bool> visited;
		_dfsHelper(v,visited);
		cout << '\n';
	}

	void pathUsingDFS(int src, int target){
		map<int,bool> visited;
		vector<int> path;
		bool found = _pathDFSHelper(src,target,visited,path);
		if(found){
			for(int i : path)
				cout << i << ' ';
			cout << '\n';
		}
		else
			cout << "No path exists\n" ;		
	}

	void pathUsingBFS(int src, int target){
		vector<int> path;
		if(_pathBFSHelper(src,target,path)){
			for(int i : path)
				cout << i << ' ';
			cout << '\n';
		}
		else{
			cout << "Path does not exist\n";
		}
	}

	void printGraph(){
		map<int,vector<int>>::iterator itr;
		for(itr = adjList.begin();itr != adjList.end();itr++){
			cout << itr->first << " : ";
			for(int i : itr->second){
				cout << i << ' ';
			}
			cout << '\n';
		}
	}

	bool detectCycleDirectedDFS(){
		map<int,vector<int>>::iterator itr;
		bool cyclePresent = false;
		for(itr = adjList.begin();itr != adjList.end();itr++){
			int key = itr->first;
			map<int,bool>visited;
			_cycleDFSHelper(key,visited,cyclePresent);
			if(cyclePresent)
				return true;
		}
		return cyclePresent;
	}



};


int main(){
	Graph g(false);
    g.addEdge(1, 2);
	g.addEdge(5, 1);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(4, 5);
	
	
	cout << g.detectCycleDirectedDFS() << '\n';

}
