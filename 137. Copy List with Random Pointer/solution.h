#include <cstddef>
#include <unordered_map>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        std::unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode preHead(0);
        for (RandomListNode *next = &preHead; head; next = next->next, head = head->next) {
            if (map[head] == NULL) {
                RandomListNode* node = new RandomListNode(head->label);
                map[head] = node;
            }
            next->next = map[head];
            if (head->random && map[head->random] == NULL) {
                RandomListNode* node = new RandomListNode(head->random->label);
                map[head->random] = node;
            }
            map[head]->random = map[head->random];
        }
        return preHead.next;
    }
};
