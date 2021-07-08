#include <iostream>
#include <fstream>
#include "graph.hpp"
using namespace std;

void read(std::string filename){
    graph g(100);
    ifstream f1(filename);
    size_t node1, node2, length;
    while (f1 >> node1 >> node2 >> length){
        g.connect(node1,node2,length);
        //cout << node1 << endl;
    }

    cout << filename << ':' << endl;
    cout << "Breadth-first search: " << g.bfs(0) << endl;
    cout << "Depth-first search: " << g.dfs(0) << endl;
    cout << "Shortest path of 0-th and 4-th node: " << g.dijkstra(0,4) << endl << endl;
}

int main()
{
    read("graph1.txt");
    read("graph2.txt");
    read("graph3.txt");
    read("graph4.txt");
    read("graph5.txt");

    return 0;
}
