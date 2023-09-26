#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node *node;

void traversal(node head){
    printf("-------------------------------\n");
    node ptr = head;
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

node insertAtStart(node head, int data){
    node p = (node)malloc(sizeof(struct Node));
    p->data = data;
    p->next = head;
    return p;
}

node insertInMiddle(node head , int data , int index){
    node ptr = (node)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL){
        return ptr;
    }
    node p = head;
    for (int i = 0; i < index-1 && p != NULL; i++){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

node insertAtEnd(node head , int data){
    node ptr = (node)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        return ptr;
    }
    node p = head;
    while (p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    return head;
}

node deleteFromStart(node head ){
    if (head == NULL) {
        return NULL;
    }
    node p = head;
    head = head->next;
    free(p);
    return head;
}

node deleteFromMiddle(node head , int index){
    if (head == NULL) {
        return NULL;
    }
    node p = head ;
    node q = head->next; //next node address
    for (int i =0; i< index -1 && q != NULL; i++){
        p= p->next;
        q=q->next;
    }
    p ->next = q->next;
    free(q);
    return head;
}

node deleteFromEnd(node head){
    if (head == NULL) {
        return NULL;
    }
    node p = head;
    node q = head->next;
    while (q->next !=NULL){
        p = p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

node concatenate(node head, node head2) {
    if (head == NULL) {
        return head2;
    }
    node ptr = head;
    while (ptr->next != NULL) {//last tak jao
        ptr = ptr->next;
    }
    ptr->next = head2;
    return head;
}

node sort(node head) {
    if (head == NULL || head->next == NULL) {
        return head; // Already sorted or empty list
    }
    int swapped;
    do {
        swapped = 0;
        node ptr = head;
        node prev = NULL;
        while (ptr->next != NULL) {//traverse
            if (ptr->data > ptr->next->data) {
                // Swap data values
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    } while (swapped);//continues as long as swapped is 1
    return head;
}

int search(node head, int key) {
    int i = 1;
    node ptr = head;
    while (ptr != NULL) {
        if (ptr->data == key) {
            return i;
        }
        ptr = ptr->next;
        i++;
    }
    return -1; // Value not found
}

void reverse(node head){
    node prev = NULL;
    node ptr= head;
    node nextNode = NULL;
    while (ptr != NULL) {
        nextNode = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = nextNode;
    }
    printf("\nREVERSED LINKED LIST\n");
    traversal(prev);
}
node create(node head,int n){
	int i,data;
	node newnode,ptr;
	if (head == NULL || n<=0){
		printf("List empty");
		return head;
	}
	
	printf("Input value of node 1 = ");
	scanf("%d",&data);
	head->data=data;
	head->next=NULL;
	ptr=head;
	for(i=2;i<=n;i++){
		newnode = (node)malloc(sizeof(node));
		printf("Input value of node %d = ",i);
	    scanf("%d",&data);
	    newnode->data=data;
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	return head;	
}



int main(){
    int ch, d ,n , index;
    node head=NULL;
    head = (node)malloc(sizeof(struct Node));

	printf("Enter number of nodes = ");
	scanf("%d",&n);
	head=create(head,n);
    printf("LINKED LIST:\n");
    traversal(head);    

    
    while (1) {
        printf("\n1 - Insert at the beginning\n");
        printf("2 - Insert in the middle\n");
        printf("3 - Insert at the end\n");
        printf("4 - Delete from the beginning\n");
        printf("5 - Delete from the middle\n");
        printf("6 - Delete from the end\n");
        printf("7 - Reverse the linked list\n");
        printf("8 - Concatenate two lists\n");
        printf("9 - Search for a key element\n");
        printf("10 - Sort the list\n");
        printf("11 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:{
                //INSERT AT BEGINNING
                printf("\nINSERT AT BEGINNING\n");
                printf("Enter data:");
                scanf("%d",&d);
                head = insertAtStart(head,d);
                traversal(head);
                break;
            }
            case 2:{
                //INSERT IN MIDDLE
                printf("\nINSERT IN THE MIDDLE\n");
                printf("Enter data:");scanf("%d",&d);
                printf("Enter index:");scanf("%d",&index);
                head = insertInMiddle(head,index,d);
                traversal(head);
                break;
            }
            case 3:{
                //INSERT AT END
                printf("\nINSERT AT THE END\n");
                printf("Enter data:");scanf("%d",&d);
                head = insertAtEnd(head,d);
                traversal(head);
                break;
            }
            case 4:{
                //DELETE FROM START
                printf("\nDELETE FROM THE BEGINNING\n");
                head = deleteFromStart(head);
                traversal(head);
                break;
            }
            case 5:{
                //DELETE FROM MIDDLE
                printf("\nDELETE FROM THE MIDDLE\n");
                printf("Enter index:");scanf("%d",&index);
                head = deleteFromMiddle(head,index);
                traversal(head);
                break;
            }
            case 6:{
                //DELETE FROM END
                printf("\nDELETE FROM THE END\n");
                head = deleteFromEnd(head);
                traversal(head);
                break;
            }
            case 7:{
                //REVERSE
                reverse(head);
                break;
            }
            case 8:{
                // CONCATENATE
                printf("\nCONCATENATE TWO LISTS\n");
                node head2 = NULL;
                node f, s, t;

                head2 = (node)malloc(sizeof(node));
                f = (node)malloc(sizeof(node));
                s = (node)malloc(sizeof(node));
                t = (node)malloc(sizeof(node));

                head2->data = 34;
                head2->next = f;

                f->data = 45;
                f->next = s;

                s->data = 60;
                s->next = t;

                t->data = 77;
                t->next = NULL;

                head = concatenate(head, head2);
                traversal(head);
                break;
            }
            
            case 9:{
                //SEARCH
                printf("\nSEARCH FOR A KEY ELEMENT\n");
                int key;
                printf("Enter the key to be searched = ");
                scanf("%d",&key);
                int a = search(head,key);
                if (a==-1){
                    printf("Element not found in linked list\n");
                }else{
                    printf("Element found at position %d in the linked list\n",a);
                }
                break;
            }
            case 10:{
                //SORT
                printf("\nSORTED LIST\n");
                head = sort(head);
                break;
            }
            case 11:{
                //EXIT
                exit(0);
            }
            default:{
                printf("Invalid choice\n");
                break;
            }
        }
    }
    
    return 0;
}
