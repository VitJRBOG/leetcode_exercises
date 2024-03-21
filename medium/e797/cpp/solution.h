#include <iostream>
#include <vector>

struct Stack {
    int8_t val;
    Stack* prev;
    Stack() : val(-1), prev(nullptr) {};
    Stack(int8_t val) : val(val), prev(nullptr) {};
    Stack(int8_t val, Stack* prev) : val(val), prev(prev) {};
    void Push(int8_t x) {
        if (this->val == -1) {
            this->val = x;
            return;
        }

        Stack* s = new Stack(this->val, this->prev);
        this->val = x;
        this->prev = s;
    };
    int8_t Pop() {
        int8_t x;

        if (this->prev == nullptr) {
            x = this->val;
            this->val = -1;
            return x;
        }

        x = this->val;
        this->val = this->prev->val;
        this->prev = this->prev->prev;

        return x;
    };
};

void deepFirstSearch(std::vector<std::vector<int>>& graph, int8_t i, Stack* s, Stack* paths) {
    if (i == graph.size() - 1) {
        Stack c = *s;

        while (c.val != -1) {
            paths->Push(c.Pop());
        }
        return;
    }

    if (graph[i].size() == 0) {
        return;
    }

    for (int8_t j = 0; j < graph[i].size(); j++) {
        s->Push(graph[i][j]);
        deepFirstSearch(graph, graph[i][j], s, paths);
        s->Pop();
    }
}

class Solution {
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        std::vector<std::vector<int>> result = {};

        Stack s = Stack(0);
        Stack paths = Stack();

        for (int8_t i = 0; i < graph[0].size(); i++) {
            s.Push(graph[0][i]);
            deepFirstSearch(graph, graph[0][i], &s, &paths);
            s.Pop();
        }

        while (paths.val != -1) {
            if (paths.val == 0) {
                result.push_back({});
            }
            result[result.size() - 1].push_back(paths.Pop());
        }

        return result;
    }
};