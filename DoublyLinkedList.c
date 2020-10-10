#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start = NULL;
int count = 0;

struct node *create_new_node(int data)
{
    count++;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    return new_node;
}

struct node *insert_beginning(struct node *start, int data)
{
    struct node *new_node = create_new_node(data);
    if(start == NULL){
        start = new_node;
    }
    else{
        new_node -> next = start;
        start -> prev = new_node;
        start = new_node;
    }
    return start;
}

struct node *insert_end(struct node *start, int data)
{

    struct node *new_node = create_new_node(data);
    if(start == NULL){
        start = new_node;
    }
    else{
        struct node *ptr = start;
        while(ptr -> next != NULL){
            ptr = ptr -> next;
        }
        ptr -> next = new_node;
        new_node -> prev = ptr;
    }
    return start;
}

struct node *insert_middle(struct node *start, int data, int pos)
{
    struct node *ptr = start;
    struct node *preptr = ptr;
    int c = 1;
    if(pos == 1)
        return insert_beginning(start, data);
    else if(pos == count + 1)
        return insert_end(start, data);
    else{
        struct node *new_node = create_new_node(data);
        while(c != pos){
            c++;
            preptr = ptr;
            ptr = ptr -> next;
        }
        new_node -> next = ptr;
        new_node -> prev = preptr;
        preptr -> next = new_node;
        ptr -> prev = new_node;
        return start;
    }
}

struct node *create_linked_list(struct node *start)
{
    int data;
    printf("\n Enter -1 to exit.");
    printf("\n Enter the data for the first node: ");
    scanf("%d", &data);
    while(data != -1){
        start = insert_end(start, data);
        printf(" Enter the data for the next node: ");
        scanf("%d", &data);
    }
    return start;
}

struct node *delete_beginning(struct node *start)
{
    struct node *ptr = NULL;
    if(start == NULL){
        printf("\n No elements in the linked list...!!");
    }
    else if(start -> next == NULL){
        ptr = start;
        start = start -> next;
        free(ptr);  count--;
    }
    else{
        ptr = start;
        start = start -> next;
        start -> prev = NULL;
        free(ptr);  count--;
    }
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr = start;
    struct node *preptr = ptr;
    if(start == NULL){
        printf("\n No elements in the linked list...!!");
    }
    else if(start -> next == NULL){
        start = start -> next;
        free(ptr);  count--;
    }
    else{
        while(ptr -> next != NULL){
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = NULL;
        free(ptr);  count--;
    }
    return start;
}

struct node *delete_middle(struct node *start, int pos)
{
    struct node *ptr = start;
    struct node *preptr = ptr;
    if(pos == 1){
        return delete_beginning(start);
    }
    else if(pos == count){
        return delete_end(start);
    }
    else{
        int c = 1;
        while(c != pos){
            c++;
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = ptr -> next;
        ptr -> next -> prev = preptr;
        free(ptr);  count--;
        return start;
    }
}

struct node *delete_linked_list(struct node *start)
{
    struct node *ptr = start;
    struct node *preptr = ptr;
    if(start == NULL)
        return start;
    else{
        while(ptr != NULL){
            preptr = ptr;
            ptr = ptr -> next;
            free(preptr);   count--;
        }
        start = NULL;
        return start;
    }
}

struct node *reverse_linked_list(struct node *start)
{
    struct node *temp = NULL;
    struct node *current = start;
    while(current != NULL){
        temp = current -> prev;
        current -> prev = current -> next;
        current -> next = temp;
        current = current -> prev;
    }
    if(temp != NULL)
        start = temp -> prev;
    return start;
}

void display_linked_list(struct node *start)
{
    struct node *ptr = start;
    if(start == NULL)
        printf("\n No elements in the linked list...!!");
    else{
        printf("\n The contents of the linked list are: ");
        while(ptr != NULL){
            printf("%d ", ptr -> data);
            ptr = ptr -> next;
        }
    }
}
int search_linked_list(struct node *start, int data)
{
    int c = 1;
    struct node *ptr = start;
    while(ptr != NULL && ptr -> data != data){
        c++;
        ptr = ptr -> next;
    }
    if(ptr != NULL)
        return c;
    else
        return -1;
}

int main()
{
    int ch, data, pos;
    while(1){
        printf("\n\n--------------------------------------------------");
        printf("\n 1.Create linked list");
        printf("\n 2.Insert node at the beginning");
        printf("\n 3.Insert node at the middle");
        printf("\n 4.Insert node at the end");
        printf("\n 5.Delete node at the beginning");
        printf("\n 6.Delete node at the middle");
        printf("\n 7.Delete node at the end");
        printf("\n 8.Search for an element in the linked list");
        printf("\n 9.Display the linked list");
        printf("\n 10.Count of nodes in the linked list");
        printf("\n 11.Reverse the linked list");
        printf("\n 12.Delete the linked list");
        printf("\n 13.Exit");
        printf("\n--------------------------------------------------");
        printf("\n\n Enter your choice: "); scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            start = create_linked_list(start);
            break;
        case 2:
            printf("\n Enter the data to be inserted at the beginning: ");
            scanf("%d", &data);
            start = insert_beginning(start, data);
            break;
        case 3:
            printf("\n Enter the data to be inserted at the middle: ");
            scanf("%d", &data);
            printf("\n Enter the position at which the data is to be inserted: ");
            scanf("%d", &pos);
            if(pos > count + 1 || pos < 1)
                printf("\n Data cannot be inserted at the given position..!!");
            else
                start = insert_middle(start, data, pos);
            break;
        case 4:
            printf("\n Enter the data to be inserted at the end: ");
            scanf("%d", &data);
            start = insert_end(start, data);
            break;
        case 5:
            start = delete_beginning(start);
            break;
        case 6:
            printf("\n Enter the position at which the data is to be deleted: ");
            scanf("%d", &pos);
            if(pos > count || pos < 1)
                printf("\n Data cannot be deleted at the given position..!!");
            else
                start = delete_middle(start, pos);
            break;
        case 7:
            start = delete_end(start);
            break;
        case 8:
            printf("\n Enter the element to be searched in the linked list: ");
            scanf("%d", &data);
            pos = search_linked_list(start, data);
            if(pos == -1)
                printf("\n No such element in the linked list..!!");
            else
                printf("\n Element found at position: %d", pos);
            break;
        case 9:
            display_linked_list(start);
            break;
        case 10:
            printf("\n Count of nodes in the linked list: %d", count);
            break;
        case 11:
            start = reverse_linked_list(start);
            break;
        case 12:
            start = delete_linked_list(start);
            break;
        case 13:
            start = delete_linked_list(start);
            exit(0);
        }
    }
    return 0;
}

