#include<stdio.h>
#include <stdlib.h>
 typedef struct node 
 {
    int data;
    struct node * next;
 } s;
 s * head;
 
int length(s *head){
    int l =0;
    while(head != NULL){
        head = head->next;
        l++;
    }
    return l;
}

 void insert(int num) 
 {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = head;
    head = newNode;
    printf("Inserted Element : %d\n", num);
 }

int main() {
    insert(12);  
    insert(30); 
    insert(20); 
    insert(17);
    insert(19);
    printf("\nLinked List length\n");
    printf("The length is %d",length(head));
    return 0;
}