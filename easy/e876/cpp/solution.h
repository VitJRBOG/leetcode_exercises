#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int8_t size = 1;

        ListNode* current = head->next;

        while (true) {
            if (current == nullptr) {
                break;
            }

            current = current->next;

            size++;
        }

        size /= 2;

        while (0 < size) {
            head = head->next;

            size--;
        }

        return head;
    }
};