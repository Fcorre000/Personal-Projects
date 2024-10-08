#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void add_node(Node **head, int data){
    //Create a new Node
    Node *new_node = new Node();
    new_node -> data = data;
    new_node -> next = NULL;

    //if the list is empty, set the head as the
    //new node
    if(*head == NULL){
        *head = new_node;
    }else{
        //traverse to the end of the list
        Node *temp = *head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        //add new node at the end
        temp -> next = new_node;
    }
}

int main(){
    Node *head = NULL;

     // Add nodes to the list
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);

    // Print the list
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}