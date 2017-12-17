#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
    void dfs(UndirectedGraphNode *node) {
        if (map.find(node) != map.end()) return;
        map[node] = new UndirectedGraphNode(node->label);
        for (UndirectedGraphNode *neighbor : node->neighbors) {
            dfs(neighbor);
            map[node]->neighbors.push_back(map[neighbor]);
        }
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        dfs(node);
        return map[node];
    }
};