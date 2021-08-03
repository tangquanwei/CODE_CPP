#include <bits/stdc++.h>
struct Node {
	int data;
	struct Node* next;
};
int main() {
	int k, t;
	scanf("%d", &k);
	struct Node *head, *p;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	while (scanf("%d", &t) && t >= 0) {
		p = (struct Node*)malloc(sizeof(struct Node));
		p->data = t;
		p->next = head->next;
		head->next = p;
	}
	for (int i = 0; i < k; ++i)
		head = head->next;
	if (head)
		printf("%d", head->data);
	else
		printf("NULL");
	return 0;
}
