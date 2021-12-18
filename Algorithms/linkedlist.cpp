#include <bits/stdc++.h>

using namespace std;
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int v) : val(v), next(nullptr) {}
};
struct LinkedList {
	ListNode* reverse(ListNode* head) {
		if (!head->next)
			return head;
		ListNode* last = reverse(head->next);
		head->next->next = head;
		head->next = nullptr;
		return last;
	}
};
int main() {
	ListNode *list = new ListNode(1), *p;
	p = list;
	list->next = new ListNode(2);
	list->next->next = new ListNode(3);
	list->next->next->next = new ListNode(4);
	while (p) {
		cout << p->val << "-";
		p = p->next;
	}
	LinkedList* l = nullptr;
	list = l->reverse(list);
	p = list;
	while (p) {
		cout << p->val << "-";
		p = p->next;
	}

	return 0;
}