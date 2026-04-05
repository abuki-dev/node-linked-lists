#include <iostream>
#include <unistd.h>
using namespace std;
void loading()
{
    cout << "Processing: [";
    for (int i = 0; i < 10; i++)
    {
        usleep(50000); // Small 1s delay
        cout << "#";
    }
    cout << "] Done!\n";
}
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    // constractor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class singlelinkedlist
{
public:
    Node *head; // pointer to head of the linked list
    // constructor
    singlelinkedlist()
    {
        this->head = NULL; // initially head is null or our starting point of the linked list
    }
    void Insertfront(int x)
    {
        Node *temp = new Node(x);
        if (head == NULL) // cheking if the list is empty or not
        {
            head = temp;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to Front.\n";
        }
        else
        {
            temp->next = head; // pointing the next of temp to head which contains the rest of the linked list
            head = temp;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to Front.\n"; // pointing head to temp which is the new node we just created
        }
    }
    void Insertend(int x)
    {
        Node *temp = new Node(x);
        if (head == NULL)
        {
            head = temp;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to End.\n";
        }
        else
        {
            Node *tail = head; // finding the tail of the linked list
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = temp;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to End.\n";
        }
    }
    void Insertleft(int x, int y)
    { // y for location x is actual data
        Node *left = new Node(x);
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else
        {
            Node *list = head;
            Node *prevus = NULL;
            while (list != NULL && list->data != y)
            {
                prevus = list;
                list = list->next;
            }
            if (list == NULL) // if the list reaches its end and the data is not found
            {
                cout << "ERROR\t" << y << "\t is not in the lsit try agan\n";
                delete left;
            }
            // the data is founded at first node
            else if (prevus == NULL)
            {
                Insertfront(x);
            }
            else
            {
                left->next = list;
                prevus->next = left;
                loading();
                cout << ">> SUCCESS: [" << x << "] added to the left of [" << y << "].\n";
            }
        }
    }
    void Insertright(int x, int y)
    { // y for location x is actual data
        Node *right = new Node(x);
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else
        {
            Node *list = head;
            while (list != NULL && list->data != y)
            {
                list = list->next;
            }
            if (list == NULL)
            {
                cout << "ERROR\t" << y << "\t is not in the lsit try agan\n";
                delete right;
            }
            else
            {
                right->next = list->next; // fist let us add the rigiht or the rest of the linked list to the new node
                list->next = right;
                loading();
                cout << ">> SUCCESS: [" << x << "] added to the right of [" << y << "].\n";
            }
        }
    }
    void Deletefront()
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else
        {
            Node *Oldhead = head;
            head = head->next;
            delete Oldhead;
            loading();
            cout << ">> SUCCESS: Node at Front deleted.\n";
        }
    }
    void DeleteEnd()
    {
        if (head == NULL)
        {
            cout << "list is emty \n";
        }
        else
        {
            Node *tail = head;
            Node *previus = NULL;
            while (tail->next != NULL)
            {
                previus = tail;
                tail = tail->next;
            }
            if (previus == NULL)
            {
                head = NULL;
                delete tail;
                loading();
                cout << ">> SUCCESS: Node at End deleted.\n";
            }
            else
            {
                previus->next = NULL;
                delete tail;
                loading();
                cout << ">> SUCCESS: Node at End deleted.\n";
            }
        }
    }
    void DeleteByposition(int x)
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else if (x == 1)
        {
            Deletefront();
        }
        else
        {
            int count = 1;
            Node *list = head;
            Node *previus = NULL;
            while (list != NULL && count < x)
            {
                previus = list;
                list = list->next;
                count++;
            }
            if (list == NULL)
            {
                cout << "ERROR\t" << x << "\t is not in the list try agan\n";
            }
            else
            {
                previus->next = list->next;
                delete list;
                loading();
                cout << ">> SUCCESS: Node at position [" << x << "] deleted.\n";
            }
        }
    }
    void Display()
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
            return;
        }
        loading();
        Node *list = head;
        cout << "single list: head->";
        while (list != NULL)
        {
            cout << "[" << list->data << "]->";
            list = list->next;
        }
        cout << "NULL\n";
    }
};
class Doublelinkedlist
{
public:
    Node *head;
    Node *tail;
    Doublelinkedlist()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void Insertfront(int x)
    {
        Node *front = new Node(x);
        if (head == NULL)
        {
            loading();
            cout << ">> SUCCESS: [" << x << "] added to Front (List was empty).\n";
            head = tail = front;
        }
        else
        {

            head->prev = front;
            front->next = head;
            head = front;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to Front.\n";
        }
    }
    void Insertend(int x)
    {
        Node *end = new Node(x);
        if (head == NULL)
        {
            head = tail = end;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to End (List was empty).\n";
        }
        else
        {
            tail->next = end;
            end->prev = tail;
            tail = end;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to End.\n";
        }
    }
    void Insertleft(int x, int y)
    {
        Node *left = new Node(x);
        if (head == NULL)
        {
            cout << "list is empty\n";
            delete left;
        }
        else
        {
            Node *location = NULL;
            Node *list = head;
            while (list != NULL && list->data != y)
            {
                location = list;
                list = list->next;
            }
            if (list == NULL)
            {
                cout << "ERROR\t" << y << "\t is not in the lsit try agan\n";
                delete left;
            }
            else if (location == NULL)
            {
                left->next = head;
                head->prev = left;
                head = left;
                loading();
                cout << ">> SUCCESS: [" << x << "] added to the left of [" << y << "].\n";
            }
            else
            {
                left->next = list; // rest of the list
                left->prev = location;
                list->prev = left;
                location->next = left;
                loading();
                cout << ">> SUCCESS: [" << x << "] added to the left of [" << y << "].\n";
            }
        }
    }
    void Insertright(int x, int y)
    {
        Node *right = new Node(x);
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else
        {
            Node *list = head;
            while (list != NULL && list->data != y)
            {
                list = list->next;
            }
            if (list == NULL)
            {
                cout << "ERROR\t" << y << "\t is not in the lsit try agan\n";
                delete right;
            }
            else
            {
                right->prev = list;       // pointing the previous of the new node to the location node
                right->next = list->next; // pointing the next of the new node to the rest of the list
                if (list == tail)
                {
                    list->next = right;
                    tail = right;
                }
                else
                {
                    list->next->prev = right; // the previous of the old next of the location node should point to the new node
                    list->next = right;
                }
                loading();
                cout << ">> SUCCESS: [" << x << "] added to the right of [" << y << "].\n";
            }
        }
    }
    void Deletefront()
    {
        if (head == NULL)
        {
            cout << "the list is empty try agan\n";
        }
        else if (head == tail)
        { // Only one node in the list
            delete head;
            head = tail = NULL;
            loading();
            cout << ">> SUCCESS: Node at Front deleted (List is now empty).\n";
        }
        else
        {
            Node *oldhead = head;
            head = head->next;
            head->prev = NULL;
            delete oldhead;
            loading();
            cout << ">> SUCCESS: Node at Front deleted.\n";
        }
    }
    void DeleteEnd()
    {
        if (head == NULL)
        {
            cout << "lsit is empty\n";
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
            loading();
            cout << ">> SUCCESS: Node at End deleted (List is now empty).\n";
        }
        else
        {
            Node *oldtail = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete oldtail;
            loading();
            cout << ">> SUCCESS: Node at End deleted.\n";
        }
    }
    void DeleteByposition(int x)
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else if (x == 1)
        {
            Deletefront();
        }
        else
        {
            Node *list = head;
            int count = 1;
            while (list != NULL && count < x)
            {
                list = list->next;
                count++;
            }
            if (list == NULL)
            {
                cout << "ERROR: Position " << x << " is out of bounds\n";
            }
            else if (list == tail)
            {
                DeleteEnd();
            }

            else
            {
                list->prev->next = list->next;
                list->next->prev = list->prev;
                delete list;
                loading();
                cout << ">> SUCCESS: Node at position " << x << " deleted.\n";
            }
        }
    }
    void DisplayForward()
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else
        {

            Node *list = head;
            loading();
            cout << "[head]" << "<-";
            while (list != NULL)
            {
                cout << "[" << list->data << "]";
                if (list->next != NULL)
                    cout << "<->";
                list = list->next;
            }
            cout << " -> [tail]\n";
        }
    }
    void DisplayBackward()
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else
        {
            loading();
            Node *list = tail;
            cout << "[tail]" << "<-";
            while (list != NULL)
            {
                cout << "[" << list->data << "]";
                if (list->prev != NULL)
                    cout << "<->";

                list = list->prev;
            }
            cout << " -> [head]\n";
        }
    }
};
class Circularlinkelist
{
public:
    Node *head;
    // constractor
    Circularlinkelist()
    {
        this->head = NULL;
    }
    void Insertfront(int x)
    {
        Node *front = new Node(x);

        if (head == NULL)
        {
            head = front;
            front->next = head;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to Front (List was empty).\n";
        }
        else
        {
            Node *tail = head;
            while (tail->next != head)
            {
                tail = tail->next;
            }
            front->next = head;
            tail->next = front;
            head = front;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to Front.\n";
        }
    }
    void InsertEnd(int x)
    {
        Node *end = new Node(x);

        if (head == NULL)
        {
            head = end;
            end->next = end;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to End (List was empty).\n";
        }
        else
        {
            Node *list = head;
            while (list->next != head)
            {
                list = list->next;
            }
            list->next = end;
            end->next = head;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to End.\n";
        }
    }
    void Insertleft(int x, int y)
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else if (head->data == y)
        {
            Insertfront(x);
        }
        else
        {
            Node *curr = head->next;
            Node *left = new Node(x);
            Node *prev = head;
            while (curr != head && curr->data != y)
            {
                prev = curr;
                curr = curr->next;
            }
            if (curr == head)
            {
                cout << "ERROR\t" << y << "\t is not in the lsit try agan\n";
                delete left;
            }
            else
            {
                left->next = curr;
                prev->next = left;
                loading();
                cout << ">> SUCCESS: [" << x << "] added to the left of " << y << ".\n";
            }
        }
    }
    void Insertright(int x, int y)
    {
        if (head == NULL)
        {
            cout << "List is empty, cannot find " << y << endl;
        }

        else if (head->data == y)
        {
            Node *right = new Node(x);
            right->next = head->next;
            head->next = right;
            loading();
            cout << ">> SUCCESS: [" << x << "] added to the right of " << y << ".\n";
        }
        else
        {
            Node *right = new Node(x);
            Node *list = head->next;
            while (list != head && list->data != y)
            {
                list = list->next;
            }
            if (list == head)
            {
                cout << "ERROR\t" << y << "\t is not in the ist\n";
            }
            else
            {
                right->next = list->next;
                list->next = right;
                loading();
                cout << ">> SUCCESS: [" << x << "] added to the right of " << y << ".\n";
            }
        }
    }
    void Deletefront()
    {
        if (head == NULL)
        {
            cout << "your list is empty\n";
        }
        else if (head->next == head)
        {
            delete head;
            head = NULL;
            loading();
            cout << ">> SUCCESS: Node at Front deleted (List is now empty).\n";
        }
        else
        {
            Node *list = head;
            while (list->next != head)
            {
                list = list->next;
            }
            Node *oldhead = head;
            head = head->next;
            list->next = head;
            delete oldhead;
            loading();
            cout << ">> SUCCESS: Node at Front deleted.\n";
        }
    }
    void DeleteEnd()
    {
        if (head == NULL)
        {
            cout << "list is empty try agan\n";
        }
        else if (head->next == head)
        {
            delete head;
            head = NULL;
        }

        else
        {
            Node *tail = head;
            Node *curr = NULL;
            while (tail->next != head)
            {
                curr = tail;
                tail = tail->next;
            }
            curr->next = head;
            delete tail;
            loading();
            cout << ">> SUCCESS: Node at End deleted.\n";
        }
    }
    void DeleteByposition(int x)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (x == 1)
        {
            Deletefront();
            return;
        }

        Node *curr = head;
        Node *prev = NULL;
        int count = 1;

        // move until we hit the position OR we are back  to head
        while (count < x)
        {
            prev = curr;
            curr = curr->next;
            count++;

            // If we hit head again before reaching x, the position is too large
            if (curr == head)
            {
                cout << "ERROR: Position " << x << " is out of bounds\n";
                return;
            }
        }
        // Now curr is exactly at position x, and prev is at x-1
        prev->next = curr->next;
        delete curr;
        loading();
        cout << "Node at position " << x << " deleted successfully\n";
    }
    void Display()
    {
        if (head == NULL)
        {
            cout << "list is empty \n";
            return;
        }
        cout << "--------------circular list-----------\n";
        loading();

        Node *curr = head;
        cout << "[head]->";
        do
        {
            cout << "[" << curr->data << "]->";
            curr = curr->next;
        } while (curr != head);
        cout << "[back to head (" << head->data << ")]" << endl;
    }
};
int getValidInt()
{
    int value;
    while (!(cin >> value))
    {
        cout << "Invalid input! Please enter a number: ";
        cin.clear();           // Clear the error flag
        cin.ignore(123, '\n'); // Discard the bad input up to the next newline
    }
    return value;
}
int main()
{
    int mainChoice, subChoice, data, target, position;

    singlelinkedlist sList;
    Doublelinkedlist dList;
    Circularlinkelist cList;

    while (true)
    {
        cout << "\n===============================" << endl;
        cout << "   MAIN LINKED LIST MENU" << endl;
        cout << "===============================" << endl;
        cout << "1. Singly Linked List" << endl;
        cout << "2. Doubly Linked List" << endl;
        cout << "3. Circular Linked List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        mainChoice = getValidInt();

        if (mainChoice == 4)
            break;

        switch (mainChoice)
        {
        case 1: // --- Singly ---
            do
            {
                cout << "\n--- Singly List Options ---\n1. Insert Front  2. Insert End\n3. Insert Left   4. Insert Right\n5. Delete Front  6. Delete End\n7. Delete Pos    8. Display\n9. BACK\nChoice: ";
                subChoice = getValidInt();

                if (subChoice == 1)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    sList.Insertfront(data);
                }
                else if (subChoice == 2)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    sList.Insertend(data);
                }
                else if (subChoice == 3)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    cout << "Left of: ";
                    target = getValidInt();
                    sList.Insertleft(data, target);
                }
                else if (subChoice == 4)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    cout << "Right of: ";
                    target = getValidInt();
                    sList.Insertright(data, target);
                }
                else if (subChoice == 5)
                    sList.Deletefront();
                else if (subChoice == 6)
                    sList.DeleteEnd();
                else if (subChoice == 7)
                {
                    cout << "Position: ";
                    position = getValidInt();
                    sList.DeleteByposition(position);
                }
                else if (subChoice == 8)
                    sList.Display();
            } while (subChoice != 9);
            break;

        case 2: // --- Doubly ---
            do
            {
                cout << "\n--- Doubly List Options ---\n1. Insert Front  2. Insert End\n3. Insert Left   4. Insert Right\n5. Delete Front  6. Delete End\n7. Delete Pos    8. Display FWD\n9. Display BWD   10. BACK\nChoice: ";
                subChoice = getValidInt();

                if (subChoice == 1)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    dList.Insertfront(data);
                }
                else if (subChoice == 2)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    dList.Insertend(data);
                }
                else if (subChoice == 3)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    cout << "left of: ";
                    target = getValidInt();
                    dList.Insertleft(data, target);
                }
                else if (subChoice == 4)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    cout << "right of: ";
                    target = getValidInt();
                    dList.Insertright(data, target);
                }
                else if (subChoice == 5)
                    dList.Deletefront();
                else if (subChoice == 6)
                    dList.DeleteEnd();
                else if (subChoice == 7)
                {
                    cout << "Position: ";
                    position = getValidInt();
                    dList.DeleteByposition(position);
                }
                else if (subChoice == 8)
                    dList.DisplayForward();
                else if (subChoice == 9)
                    dList.DisplayBackward();
                // ... Add other dList calls here ...
            } while (subChoice != 10);
            break;

        case 3: // --- Circular ---
            do
            {
                cout << "\n--- Circular List Options ---\n1. Insert Front  2. Insert End\n3. Insert Left   4. Insert Right\n5. Delete Front  6. Delete End\n7. Delete Pos    8. Display\n9. BACK\nChoice: ";
                subChoice = getValidInt();

                if (subChoice == 1)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    cList.Insertfront(data);
                }
                else if (subChoice == 2)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    cList.InsertEnd(data);
                }
                else if (subChoice == 3)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    cout << "Left of: ";
                    target = getValidInt();
                    cList.Insertleft(data, target);
                }
                else if (subChoice == 4)
                {
                    cout << "Enter data: ";
                    data = getValidInt();
                    cout << "Right of: ";
                    target = getValidInt();
                    cList.Insertright(data, target);
                }
                else if (subChoice == 5)
                {
                    cList.Deletefront();
                }
                else if (subChoice == 6)
                {
                    cList.DeleteEnd();
                }
                else if (subChoice == 7)
                {
                    cout << "Position: ";
                    position = getValidInt();
                    cList.DeleteByposition(position);
                }
                else if (subChoice == 8)
                {
                    cList.Display();
                }
            } while (subChoice != 9);
            break;

        default:
            cout << "Choice out of range!" << endl;
        }
    }
    cout << "\nexiting.....!" << endl;
    return 0;
}
