#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

class graph final{
    std::vector< std::unordered_map<size_t, size_t> > node;
    friend std::ostream& operator<<(std::ostream& os, const graph& g);

    public:
        graph(size_t node_number = 0): node(node_number){ }
        ~graph(){ }

        void resize(size_t new_size){
            if (new_size < node.size())
                for(auto i = node.begin(); i != node.end(); ++i)
                    for(auto j = new_size; j < node.size(); ++j)
                        i->erase(j);
            node.resize(new_size);
        }

        void connect(size_t node1_num, size_t node2_num, size_t len = 0){
            // check if node2_num < node_number
            node.at(node2_num);
            node.at(node1_num)[node2_num] = len;
        }

        size_t length() const {return node.size();}

        std::vector<size_t> bfs(size_t start_node){
            // check if start_node is within range
            node.at(start_node);
            std::vector<bool> visited( length(), false );
            std::vector<size_t> order;

            std::queue<size_t> q;
            q.push(start_node);
            visited[start_node] = true;

            start_node = 0;
            while(!q.empty()){
                const auto& head_node = q.front();
                q.pop();
                order.push_back(head_node);

                for(auto i = node[head_node].begin(); i != node[head_node].end(); ++i){
                    const auto& next_node = i->first;
                    if (!visited[next_node]){
                        q.push(next_node);
                        visited[next_node] = true;
                    }
                }
            }
            return order;
        }

        std::vector<size_t> dfs(size_t start_node){
            // check if start_node is within range
            node.at(start_node);
            std::vector<bool> visited( length(), false );
            std::vector<size_t> order;

            std::stack<size_t> s;
            s.push(start_node);
            visited[start_node] = true;

            start_node = 0;
            while(!s.empty()){
                const auto& head_node = s.top();
                s.pop();
                order.push_back(head_node);

                for(auto i = node[head_node].begin(); i != node[head_node].end(); ++i){
                    const auto& next_node = i->first;
                    if (!visited[next_node]){
                        s.push(next_node);
                        visited[next_node] = true;
                    }
                }
            }
            return order;
        }

        size_t dijkstra(size_t node1, size_t node2){

            std::unordered_map<size_t, size_t> dist(node.at(node1));
            dist[node1] = 0;

            for(size_t i = 0; i < length(); ++i){
                if ( dist.find(i) == dist.end() )
                    break;
                for(auto j = node[i].begin(); j != node[i].end(); ++j){
                    auto alt = dist[i] + j->second;
                    if(dist.find(j->first) == dist.end() || alt < dist[j->first])
                        dist[j->first] = alt;
                }
            }

            if (dist.find(node2) == dist.end() ) throw std::runtime_error("two nodes are not connected");
            return dist[node2];
        }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    for(auto i = v.begin(); i != v.end(); ++i)
        os << *i << ' ';
    return os;
}

#endif // GRAPH_HPP
