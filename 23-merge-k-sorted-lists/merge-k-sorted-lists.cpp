class Solution {
    public:

        struct compare {
                bool operator()(ListNode* a, ListNode* b) {
                            return a->val > b->val;
                                    }
                                        };

                                            ListNode* mergeKLists(vector<ListNode*>& lists) {

                                                    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

                                                            // Add first node of every list
                                                                    for (ListNode* node : lists) {
                                                                                if (node != nullptr) {
                                                                                                pq.push(node);
                                                                                                            }
                                                                                                                    }

                                                                                                                            ListNode dummy(0);
                                                                                                                                    ListNode* tail = &dummy;

                                                                                                                                            while (!pq.empty()) {

                                                                                                                                                        // Get smallest node
                                                                                                                                                                    ListNode* curr = pq.top();
                                                                                                                                                                                pq.pop();

                                                                                                                                                                                            // Attach smallest node
                                                                                                                                                                                                        tail->next = curr;
                                                                                                                                                                                                                    tail = curr;

                                                                                                                                                                                                                                // Add next node from the same list
                                                                                                                                                                                                                                            if (curr->next != nullptr) {
                                                                                                                                                                                                                                                            pq.push(curr->next);
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                        return dummy.next;
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                            };