#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <initializer_list>

using std::set;
using std::map;
using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::initializer_list;
using std::queue;

class Undirected_Graph{
      map<int,set<int>> m;
      int size=0;
      void breaadthFirst(int src, int dest,vector<int> &v){
            if((m[src].empty()))
                  return;
            else if(m[dest].empty())
                  return;
            else if(src==dest){
                  cout<<src;
                  return;
            }
            else{
                  queue<int> q;
                  q.push(src);
                  while(!q.empty()){
                        int node = q.front();
                        q.pop();
                        if(!v[node-1]){
                              v[node-1] = 1;
                              cout<<node<<std::endl;
                              if(node == dest){
                                    return;
                              }
                              for(auto i:m[node]){
                                    q.push(i);
                              }
                        }

                  }
            }
      }
public:
      Undirected_Graph();
      Undirected_Graph(initializer_list<pair<int,set<int>>> l){
            for(auto i: l){
                  // m[i.first] = i.second;
                  for(auto k: i.second)
                        m[i.first].insert(k);
                  for(auto j: i.second)
                        if(!m[j].empty())
                              continue;
                        else{
                              m[j].insert(i.first);
                        }
            }
      };
      void show(){
            for(auto i: m){
                  cout<< i.first<<" -{";
                  for(auto j:m[i.first])
                        cout<<" "<<j;
                  cout<<"}"<<std::endl;
            }
      };

      void BFS(int src,int dest){
            vector<int> v(m.size(),0);
            breaadthFirst(src,dest,v);
      }
};
#define Node pair<int,set<int>>
int main(int argc, char const *argv[])
{
      initializer_list<pair<int,set<int>>> l={ Node(1,{2,3}),Node(2,{4}),Node(3,{5}),Node(5,{2}),Node(6,{4})};
      Undirected_Graph g(l);
      g.show();
      std::cout<<"----------------------BFS for the given graph is ----------------------"<<std::endl;
      g.BFS(1,5);
      return 0;
}
