#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


/**
 * Notice this function will write a newline and flush
 */
void printLinklist(ListNode* root) {
    while (root) {
        std::cout << std::hex << static_cast<void*>(root) << ": " << std::dec << root->val << std::endl;
        root = root->next;
    }
}