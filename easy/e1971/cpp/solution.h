#include <iostream>
#include <vector>

struct Queue {
    int32_t val;
    Queue* next;
    Queue() : val(-1), next(nullptr) {};
    Queue(int32_t x) : val(x), next(nullptr) {};
    bool isExist(int32_t x) {
        Queue* q = this;

        while (q->next != nullptr) {
            if (q->val == x) {
                return true;
            }
            q = q->next;
        }

        return false;
    }
    void PushBack(int32_t x) {
        if (this->val == -1) {
            this->val = x;
            return;
        }

        Queue* q = this;

        while (q->next != nullptr) {
            q = q->next;
        }

        q->next = new Queue(x);
    };
    int32_t PopForehead() {
        int32_t val = this->val;

        if (this->next == nullptr) {
            this->val = -1;
            return val;
        };

        this->val = this->next->val;
        this->next = this->next->next;

        return val;
    };
};

class Solution {
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true;
        }

        if (edges.size() == 0) {
            return false;
        }

        Queue queueHead = Queue(source);
        int32_t beginning = 0;

        while (queueHead.val != -1) {
            for (int32_t i = beginning; i < edges.size(); i++) {
                if (edges[i][0] == queueHead.val) {
                    if (edges[i][1] == destination) {
                        return true;
                    }
                    queueHead.PushBack(edges[i][1]);

                    if (beginning != i) {
                        int32_t tmp1 = edges[i][0];
                        int32_t tmp2 = edges[i][1];
                        edges[i][0] = edges[beginning][0];
                        edges[i][1] = edges[beginning][1];
                        edges[beginning][0] = tmp1;
                        edges[beginning][1] = tmp2;
                    }

                    beginning++;
                } else if (edges[i][1] == queueHead.val) {
                    if (edges[i][0] == destination) {
                        return true;
                    }
                    queueHead.PushBack(edges[i][0]);

                    if (beginning != i) {
                        int32_t tmp1 = edges[i][0];
                        int32_t tmp2 = edges[i][1];
                        edges[i][0] = edges[beginning][0];
                        edges[i][1] = edges[beginning][1];
                        edges[beginning][0] = tmp1;
                        edges[beginning][1] = tmp2;
                    }

                    beginning++;
                }
            }
            queueHead.PopForehead();
        }

        return false;
    }
};