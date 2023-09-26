#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
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
    p->data=data;
    p->next=head;
    p->prev=NULL;
    if (head!=NULL){
        head->prev = p;
    }else{
        return p;
    }
    return p;
}

node insertInMiddle(node head , int data , int index){
    node ptr = (node)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (head == NULL){
        return ptr;
    }
    node p = head;
    for (int i = 0; i < index-1 && p!=NULL ; i++){
        p=p->next;
    }
    ptr->next=p->next;
    ptr->prev=p;
    if(p->next!=NULL){
        p->next->prev=ptr;
    }
    p->next=ptr;
    return head;
}

node insertAtEnd(node head , int data){
    node ptr = (node)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    if (head==NULL){
        return ptr;
    }
    node p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->prev=p;
    p->next=ptr;
    return head;
}

node deleteFromStart(node head ){
    node p = head;
    head = head->next;
    if (head != NULL){
        head->prev = NULL;
    }else {
        return NULL;
    }
    free (p);
    return head;
}

node deleteFromMiddle(node head , int index){
    node p = head;
    node q = head->next;
    for (int i = 0; i < index - 1 && q!=NULL; i++){
        p=p->next;
        q=q->next;
    }
    if (q->next!=NULL){
        p->next = q->next;
        q->next->prev= p;
    }
    free(q);
    return head;
}

node deleteFromEnd(node head){
    if (head == NULL){
        return NULL;
    }
    node p = head;
    while (p->next != NULL){
        p=p->next;
    }
    p->prev->next=NULL;
    free(p);
    return head;
}
void reverse(node head){
    node ptr = head;
    while (ptr->next!=NULL){
        ptr=ptr->next;
    }
    node rev = ptr;
    while (rev!=NULL){
        printf("%d ",rev->data);
        rev=rev->prev;
    }
}
node concatenate(node head,node head2){
    if(head == NULL){
        return head2;
    }
    node ptr = head;
    while (ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next=head2;
    if(head2 != NULL){
        head2->prev = ptr;
    }
    return head;
}
int search(node head,int key){
    node ptr = head;
    int c=0;
    while (ptr->next!=NULL){
        c++;
        if(ptr->data==key){
            return c;
        }
        ptr=ptr->next;
    }
    return -1;
}

node sort(node head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    int swapped ;
    do{
        swapped = 0;
        node ptr = head;
        node prev = head;
        while(ptr->next!=NULL){
            if(ptr->data > ptr->next->data){
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            prev = ptr;
            ptr=ptr->next;
        }
    }while(swapped);
    return head;
}

int main(){
    node head, second, third, fourth, fifth, sixth, seventh=NULL;
    head = (node)malloc(sizeof(struct Node));
    second = (node)malloc(sizeof(struct Node));
    third = (node)malloc(sizeof(struct Node));
    fourth = (node)malloc(sizeof(struct Node));
    sixth = (node)malloc(sizeof(struct Node));
    seventh = (node)malloc(sizeof(struct Node));
    fifth = (node)malloc(sizeof(struct Node));

    head->prev=NULL;
    head->data = 7;
    head->next = second;
   
    second->prev= head;
    second->data = 11;
    second->next = third;
    
    third->prev = second;
    third->data = 41;
    third->next = fourth;

    fourth->prev=third;
    fourth->data = 66;
    fourth->next = fifth;

    fifth->prev=fourth;
    fifth->data = 76;
    fifth->next = sixth;

    sixth->prev=fifth;
    sixth->data = 56;
    sixth->next = seventh;

    seventh->prev=sixth;
    seventh->data = 91;
    seventh->next = NULL;

    printf("LINKED LIST:\n");
    traversal(head);

    int ch ,d,index;

    while (1){
        printf("\nMENU\n");
        printf("1 - Insert at the beginning\n");
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
        printf("Enter the choice:");
        scanf("%d", &ch);
        switch (ch){
        case 1:{
            // INSERT AT BEGINNING
            printf("\nINSERT AT BEGINNING\n");
            printf("Enter data:");
            scanf("%d", &d);
            head = insertAtStart(head, d);
            traversal(head);
            break;
        }
        case 2:{
            // INSERT IN MIDDLE
            printf("\nINSERT IN THE MIDDLE\n");
            printf("Enter data:");
            scanf("%d", &d);
            printf("Enter index:");
            scanf("%d", &index);
            head = insertInMiddle(head, index, d);
            traversal(head);
            break;
        }
        case 3:{
            // INSERT AT END
            printf("\nINSERT AT THE END\n");
            printf("Enter data:");
            scanf("%d", &d);
            head = insertAtEnd(head, d);
            traversal(head);
            break;
        }
        case 4:{
            // DELETE FROM START
            printf("\nDELETE FROM THE BEGINNING\n");
            head = deleteFromStart(head);
            traversal(head);
            break;
        }
        case 5:{
            // DELETE FROM MIDDLE
            printf("\nDELETE FROM THE MIDDLE\n");
            printf("Enter index:");
            scanf("%d", &index);
            head = deleteFromMiddle(head, index);
            traversal(head);
            break;
        }
        case 6:{
            // DELETE FROM END
            printf("\nDELETE FROM THE END\n");
            head = deleteFromEnd(head);
            traversal(head);
            break;
        }
        case 7:{
            // REVERSE
            printf("\nREVERSED LINKED LIST\n");
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
            head2->prev = NULL;
            head2->next = f;

            f->data = 45;
            f->prev = head2;
            f->next = s;

            s->data = 60;
            s->prev = f;
            s->next = t;

            t->data = 77;
            t->prev = s;
            t->next = NULL;

            head = concatenate(head, head2);
            traversal(head);
            break;
        }
        case 9:{
            // SEARCH
            printf("\nSEARCH FOR A KEY ELEMENT\n");
            int key;
            printf("enter the key to be searched = ");
            scanf("%d", &key);
            int a = search(head, key);
            if (a == -1){
                printf("Element not found in linked list\n");
            }else{
                printf("Element found at position %d \n", a);
            }
            break;
        }
        case 10:{
            // SORT
            printf("\nSORTED LIST\n");
            head = sort(head);
            // node ptr = head;
            // while (ptr!=NULL){
            //     printf("%d ",ptr->data);
            //     ptr=ptr->next;
            // }
            traversal(head);
            break;
        }
        case 11:{
            exit(0);
        }
        default:{
            printf("wrong choice");
            break;
        }
        }
    }
    return 0;
}