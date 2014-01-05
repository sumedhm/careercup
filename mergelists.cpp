/*
*http://www.careercup.com/question?id=6284997057052672
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct list_{
	int val;
	struct list_ *next;
} list;

void printandfree(list *head){
	list *temp = head;
	while(temp!=NULL){
		cout << head->val << "->";
		head = head->next;
		free(temp);
		temp = head;
	}
	cout << "NULL";
	return;
}

void enqueue(int val, list **head, list **tail){
	if(*head==NULL){
		*head = (list *) malloc (sizeof(list));
		*tail = *head;
	} else {
		(*tail)->next = (list *) malloc (sizeof(list));
		*tail = (*tail)->next;
	}
	(*tail)->val = val;
	(*tail)->next = NULL;
	return;
}

int dequeue(list *head){
	list *temp = head;
	head = head->next;
	int ans = temp->val;
	free(temp);
	return ans;
}

list *mergeandsort(list *head1, list *head2){
	list *head, *tail;
	//Initialization.
	if(head1!=NULL && head2!=NULL){
		if(head1->val < head2->val){
			head = head1;
			head1 = head1->next;
		}
		else{
			head = head2;
			head2 = head2->next;
		}
	}
	else if(head1==NULL && head2==NULL) return NULL;
	else if(head1==NULL){
		head = head2;
		head2 = head2->next;
	}
	else if(head2==NULL){
		head = head1;
		head1 = head1->next;
	}
	tail = head;
	//Merging
	while(head1!=NULL && head2!=NULL){
		if(head1->val < head2->val){
			tail->next = head1; tail = tail->next; head1 = head1->next;
		} else {
			tail->next = head2; tail = tail->next; head2 = head2->next;
		}
	}
	while(head1!=NULL){
		tail->next = head1; tail = tail->next; head1 = head1->next;
	}
	while(head2!=NULL){
		tail->next = head2; tail = tail->next; head2 = head2->next;
	}
	tail->next = NULL;
	return head;
}

int main(){
	list *head1=NULL, *tail1, *head2=NULL, *tail2, *head=NULL, *tail;
	int n,m;
	cout << "\nEnter number of elements in the two lists respectively: ";
	cin >> n >> m;
	cout << "\n\nEnter all elements of list 1 :\n";
	int i = 0, j;
	while(i<n){
		cin >> j; enqueue(j, &head1, &tail1); i++;
	}
	i = 0;
	cout << "\n\nEnter all elements of list 2 :\n";
	while(i<m){
		cin >> j; enqueue(j, &head2, &tail2); i++;
	}
	head = mergeandsort(head1, head2);	//Returns head of sorted list in O(n) time and O(1) extra space.
	cout << "\n\nThis is the final list:\n";
	printandfree(head);
	cout << "\n\n";

	return 0;
}
