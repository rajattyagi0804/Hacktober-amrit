#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
void push(node** head, int l_data){
    node* temp = new node();
    temp->data = l_data;
    temp->next=NULL;
    if(*head == NULL){
        *head = temp;
        return;
    }
    node*n = *head;
    while(n->next!=NULL)
        n = n->next;
    n->next=temp;
}
void findMiddleElement(node* curr, node**first, node**second){
    node* slow= curr;
    node* fast = curr->next;
    while(fast!=NULL){
        fast=fast->next;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }

    *first = curr;
    *second = slow->next;
    slow->next=NULL;
}

node* mergeBoth(node* first, node* second){
    node* answer = NULL;
    if(!first)
        return second;
    if(!second)
        return first;

    if(first->data <= second->data){
        answer = first;
        answer->next = mergeBoth(first->next, second);
    }else{
        answer = second;
        answer->next = mergeBoth(first, second->next);
    }
    return answer;
}

void  MergeSorting(node**head){
    node* curr= *head;
    node* first;
    node* second;
    if(!curr || !curr->next) return;

    findMiddleElement(curr, &first, &second);

    MergeSorting(&first);
    MergeSorting(&second);
    *head = mergeBoth(first, second);
}
node* mergeSort(node* head){
    MergeSorting(&head);
    return head;
}
void print(node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<"\n";
}
int main(){
    node* head = NULL;
    int n, ele;
    cout<<"\n Enter the size of the llist : ";
    cin>>n;
    cout<<"\n Enter elements to be entered in linked list: ";
    for(int i=0; i<n; i++){
        cin>>ele;
        push(&head, ele);
    }
    cout<<"\n The llist 1 is: ";
    print(head);
    head = mergeSort(head);
    cout<<"\n merge sort of ll: ";
    
    print(head);
}
