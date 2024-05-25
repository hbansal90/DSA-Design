#include <iostream>
#include <limits>    // For INT_MIN
#include <stdexcept> // For runtime_error
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(): data(-1e9),next(NULL){};
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class LinkedList
{
public:
    Node *head ;
    int sizeOfList;
    LinkedList(): head(NULL), sizeOfList(0){}

    void insertAtHead(int data)
    {
        sizeOfList++;
        if (head == NULL)
        {
            Node *new_node = new Node(data);
            head = new_node;
            return;
        }
        Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    // Insert At Tail
    void insertAtTail(int data)
    {
        Node *new_node = new Node(data);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *iterator = head;
        while (iterator->next)
            iterator = iterator->next;
        iterator->next = new_node;
        sizeOfList++;
    }
    // Insert at position x
    void insertAtX(int position, int data)
    {
        Node *new_node = new Node(data);
        if (position <= 0)
        {
            cout << "Error!\n";
            return;
        }
        if (head == NULL)
            return insertAtHead(data);
        if (position == 1)
            return insertAtHead(data);
        if (position >= sizeOfList)
            return insertAtTail(data);

        int jumps = 1;
        Node *temp = head;
        while (jumps < position - 1)
        {
            temp = temp->next;
            jumps++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        sizeOfList++;
    }
    // delete at head

    void deleteAtHead()
    {
        if (head == NULL)
        {
            throw runtime_error("Empty List\n");
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        sizeOfList--;
    }

    // delete at tail
    void deleteAtTail()
    {
        if (head == NULL)
        {
            throw runtime_error("Empty List\n");
        }
        Node *temp = head;
        Node *prev = NULL;

        while (temp->next)
        {
            prev = temp;
            temp = temp->next;
        }
        // Single Node
        if (prev == NULL)
            head = NULL;
        else
        {
            prev->next = NULL;
        }

        delete temp;
        sizeOfList--;
    }

    // delete at position p

    void deleteAtPosition(int &position)
    {
        if (head == NULL)
        {
            throw runtime_error("Empty List\n");
        }
        if (position <= 0)
        {
            throw runtime_error("Index cannot be negative");
        }
        if (position == 1)
            return deleteAtHead();
        if (position >= sizeOfList)
            return deleteAtTail();

        int jumps = 1;
        Node *temp = head;
        while (jumps < position)
        {
            jumps++;
            if (temp->next)
                temp = temp->next;
        }

        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        sizeOfList--;
    }

    // delete the node by value
    void deleteByValue(int value)
    {
        if (head == NULL)
        {
            throw runtime_error("Empty List\n");
        }

        if (head->data == value)
            return deleteAtHead();

        Node *prev = NULL, *curr = head;

        while (curr && curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        // If key not found
        if (curr == NULL)
        {
            cout << "Value Not Found!\nTry Again! \n";
            return;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        sizeOfList--;
    }
    // Recursively
    void deleteByValueRecursively(int value, Node *Dhead)
    {
        if (Dhead == NULL)
        {
            cout << "The key is not found!\n";
            return;
        }
        if (Dhead->data == value)
        {
            Node *target = Dhead;
            target = target->next;
            delete target;
            sizeOfList--;
        }
        return deleteByValueRecursively(value, Dhead->next);
    }
    // Searching in a linked list
    int search(int data)
    {
        if (head == NULL)
        {
            throw runtime_error("!!- Empty List: Insert some nodes first!\n!");
        }
        int position = 0;
        Node *iterator = head;

        while (iterator && iterator->data != data)
        {
            iterator = iterator->next;
            position++;
        }
        if (iterator == NULL)
        {
            position = -1;
            cout << "\n No Such key Found!\n";
        }
        return position;
    }
    // get size
    int getSize()
    {
        return sizeOfList;
    }
    // Print the list
    public:
    void printTheList()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "\nEmpty List\n";
            return;
        }
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
        return;
    }
    static void printTheList(Node* temp)
    {
        if (temp== NULL)
        {
            cout << "\nEmpty List\n";
            return;
        }
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
        return;
    }
    // Take inputs from user
    public:
    Node *input()
    {   int n;
        cout << "\nEnter the size of the List: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int data;
            cout << "\nEnter the value of Node " << i + 1 << " : ";
            cin >> data;
            insertAtTail(data);
        }
        return head;
    }
    // Operator overloading for >>
    // We will use operator cascading for multiple cins. For e.g.: cin>>list1>>list2;
    friend istream& operator>>(istream &in,  LinkedList& head1)
    {
        head1.input();
        return in;
    }
    friend ostream& operator<<(ostream &out, LinkedList& head1)
    {
        head1.printTheList();
        return out;
    }
    //Reverse the List- Iterative
    void reverseTheList(){
        //Corner Case
        if(head == NULL){
            throw runtime_error("\n!Empty List\n");
        }
        Node* prev = NULL, *curr = head, *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Remember we need three pointers
        head = prev;
    }
    // reverse the list recursively
    void reverseTheListRecur(){
        head = reverseTheListRecur(head);
    }
    Node* reverseTheListRecur(Node*head){
        if(head == NULL || head->next == NULL) return head;
        Node* nhead = reverseTheListRecur(head->next);
        head->next->next = head;
        head->next = NULL;
        return nhead;
    }

    // To find the mid Element of a linkedList
    static Node* middleNode(Node* head ){
        if(head == NULL || head->next == NULL){
            return head;
        }
        // Using the Hare and Totrtoise Algorithm
        Node* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow ->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node * firstNode(){
        return head;
    }
    Node * lastNode(){
        if(head == NULL) return head;
        Node* last = head;
        while(last->next) last = last->next;
        return last;
    }
    // To find the Kth Node from the end
    Node * kLastNode(int k){
        if(head == NULL) {
            throw runtime_error("\n The List is Empty!\n");
        }
        if( k > sizeOfList){
            cout<<"\nInvalid input of k!\n";
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;

        // 1-based indexing
        for(int i=0; i<k-1; i++){
            fast = fast->next;
            if(fast == NULL){
                cout<<"\nThe Value is K is greater than the size of List\n";
                return NULL;
            }
        }
        while(fast && fast->next){
            slow = slow ->next;
            fast = fast->next;
        }
        return slow;
    }
    // merging two sorted linkled lists
    static Node* mergeTheTwoSortedList(Node* temp1, Node* temp2){
        if(temp1 == NULL) return temp2;
        if(temp2 == NULL) return temp1;
        // taking an new node
        Node* newTemp = NULL;
        if(temp1->data <= temp2->data){
            newTemp = temp1;
            newTemp->next = mergeTheTwoSortedList(temp1->next, temp2);
        }
        else{
            newTemp = temp2;
            newTemp->next = mergeTheTwoSortedList(temp1, temp2->next);
        }
        return newTemp;
    }
    // Sorting a linked list using merge sort
    static Node* sort(Node* list1){
        if(list1 == NULL || list1->next == NULL){
            return list1;
        }
        Node* midNode = middleNode(list1);
        Node* firstList = list1;
        Node* nextList = midNode->next;
        midNode->next = NULL;
        firstList= sort(firstList);
        nextList = sort(nextList);
        return mergeTheTwoSortedList(firstList, nextList);
    }
    
};

int main(){
    
    LinkedList l1,l2;
     cin>>l1;
     cout<<l1;
     l1.head = LinkedList::sort(l1.head);
     cout<<l1;
     
     
     //cout<<"The value is"<<l1.kLastNode(2)->data<<endl;
    return 0;
}