#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LifoLinkedList{
    private:
        Node *head;
        Node *tail;
        const int capacity = 10;
        int length = 0;

        Node* createNode(int data){
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;
            return newNode;
        };
    public:
        LifoLinkedList(int data){
            head = createNode(data);
            tail = head;
            length++;

        };
        ~LifoLinkedList(){
            Node *current = head;
            while(current != nullptr){
                Node* nextNode = current->next;
            delete current;
            current = nextNode;
            }
        };

        void lifoHandler(){
            length++;
            if(length > capacity){
                deleteStart();                
            }
        }

        void traverse(){
            if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
                Node* current = head;
                while (current->next != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
                }
                cout << current->data << endl;
        };

        Node* searchNode(int data){
            
            Node *searchedNode = head;
            while (searchedNode->next != nullptr && searchedNode-> data != data){
                searchedNode = searchedNode->next;
            }
      

            if(searchedNode->data != data){
                cout << "No item exist with the given data in list!" << endl;       
                throw "No item exist with the given data in list!";
            }
            return searchedNode;
        }

        void push(int data){
            Node *newNode = createNode(data);
            tail->next = newNode;
            tail = newNode;
            
           lifoHandler();
            
        }       
        void insertAfter(int item,int data){
            Node *listItem = searchNode(item);
            Node *newNode = createNode(data);
            if(listItem->next == nullptr){
                listItem->next = newNode;
            }else{
                newNode->next = listItem->next;
                listItem->next = newNode;
            }
             lifoHandler();

        }
        void insertBefore(int item,int data){
             Node *listItem = searchNode(item);
             if(listItem == head){
                 Node *newNode = createNode(data);
            newNode->next = head;
            head = newNode;
             lifoHandler();
             }else{

             Node *newNode = createNode(data);
             Node *beforeListItem = head;
             while(beforeListItem->next != listItem){
                beforeListItem = beforeListItem->next;
             }
             beforeListItem->next = newNode;
             newNode->next = listItem;
             }
              lifoHandler();

        }
        void deleteEnd(){
            Node *secoundLast= head;
            while(secoundLast->next != tail){
                secoundLast = secoundLast->next;
            }
            secoundLast->next = nullptr;
            delete tail;
            tail = secoundLast;
            length--;
        }
        void deleteStart(){
            Node *newHead = head->next;
            delete head;
            head = newHead;
             length--;

        }
  
};



int main() {
    LifoLinkedList list(5);
    list.push(10);
    list.push(15);
    list.push(20);
    list.push(25);
    list.push(30);
    list.push(35);
    list.push(40);
    list.push(45);
    list.push(50);
    list.push(55);
    list.push(60);
    list.push(65);
    list.push(70);
    list.push(75);




    cout << "Initial List:" << endl;
    list.traverse();


    list.insertAfter(40, 6);
    cout << "After inserting 6 after 40:" << endl;
    list.traverse();

    list.insertBefore(40, 4);
    cout << "After inserting 4 before 40:" << endl;
    list.traverse();

    cout << "Before deleting the last element:" << endl;
    list.traverse();
    list.deleteEnd();
    cout << "After deleting the last element:" << endl;
    list.traverse();

    cout << "After deleting the first element:" << endl;
    list.deleteStart();
    list.traverse();

    return 0;
}