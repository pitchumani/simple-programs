digits are stored in list in reverse order
return list node for sum in reverse order
l1 = [2,4,3]
l2 = [1,2,3]
res = 342 + 321; => 663
l3 = [3,6,6]

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        uint64_t num1 = 0;
        uint64_t placeVal = 1;
        ListNode *node = l1;
        while(node) {
            num1 += (node->val * placeVal);
            placeVal *= 10;
            node = node->next;
        }
        //cout << "num1: " << num1 << "\n";
        placeVal = 1;
        uint64_t num2 = 0;
        node = l2;
        while(node) {
            num2 += (node->val * placeVal);
            placeVal *= 10;
            node = node->next;
        }
        //cout << "num2: " << num2 << "\n";
        uint64_t res = num1 + num2;
        //cout << "res: " << res << "\n";
        if (res == 0) return new ListNode(0);
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (res>0) {
            auto digit = res % 10;
            if (!head) {
                head = tail = new ListNode(digit);
            } else {
                tail->next = new ListNode(digit);
                tail = tail->next;
            }
            res /= 10;
        }
        return head;
    }

