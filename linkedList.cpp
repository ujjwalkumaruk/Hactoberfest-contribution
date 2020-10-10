#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

node *get_node(int val) {
    node *newnode = new node;
    newnode -> data = val;
    newnode -> next = NULL;
    return newnode;
}

node *reverse (node *head) {
    if (head == NULL or head -> next == NULL) {
        return head;
    }
    node *f = NULL, *s = head, *t;
    while (s != NULL) {
        t = s -> next;
        s -> next = f;
        f = s;
        s = t;
    }
    head = f;
    return head;
}

void reverse_util(node **head, node *current, node *prev) {
    if (current -> next == NULL) {
        *head = current;
        current -> next = prev;
        return;
    }
    node *temp = current -> next;
    current -> next = prev;
    reverse_util(head, temp, current);

}

void reverse_recursive (node **head) {
    if (*head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    reverse_util(head, *head, NULL);
}

int length(node *head) {
    if (head == NULL)
        return 0;
    int counter = 1;
    node *fast = head, *slow = head;
    while (fast != NULL and fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        counter++;
    }
    return fast == NULL ? 2 * counter : 2 * counter - 1;
    // return counter;
}

node *insert_beg(node *head, int val) {
    node *newnode = get_node(val);
    if (head == NULL)
        return newnode;
    newnode -> next = head;
    return newnode;
}

node *insert_end(node *head, int val) {
    node *newnode = get_node(val);
    if (head == NULL)
        return newnode;
    node *iter = head;;
    while (iter -> next != NULL) {
        iter = iter -> next;
    }
    iter -> next = newnode;
    return head;
}

void print (node *head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
}

int main() {
    node *head = NULL;
    int choice, val;
    while (true) {
        cout << "1. Print\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at end\n";
        cout << "4. Reverse Iteratively\n";
        cout << "5. Reverse Recursively\n";
        cout << "6. Length\n";
        cin >> choice;
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            print (head);
        } else if (choice == 2) {
            cin >> val;
            head = insert_beg (head, val);
        } else if (choice == 3) {
            cin >> val;
            head = insert_end (head, val);
        } else if (choice == 4) {
            head = reverse(head);
        } else if (choice == 5) {
            reverse_recursive(&head);
        } else if (choice == 6) {
            cout << length(head) << "\n";
        } else {
            return 0;
        }
    }
    return 0;
}
