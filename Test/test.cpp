#include <bits/stdc++.h>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct cmp {
	int operator()(ListNode* a, ListNode* b) {
		return a->val < b->val;
	}
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *head = new ListNode(), *p = head;
		priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
		for (ListNode* l : lists)
			pq.push(l);
		while (!pq.empty()) {
			ListNode* node = pq.top();
			pq.pop();
			p->next = node;
			p = p->next;
			if (node->next)
				pq.push(node->next);
		}
		return head->next;
	}
};
int main() {



	return 0;
}