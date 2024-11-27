#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node *head;
        Node *tail;

        Node* createNode(int data){
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;
            return newNode;
        };
    public:
        LinkedList(int data){
            head = createNode(data);
            tail = head;

        };
        ~LinkedList(){
            Node *current = head;
            while(current != nullptr){
                Node* nextNode = current->next;
            delete current;
            current = nextNode;
            }
        };

        void traverse(){
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
                throw "No item exist with the given data in list!";
            }
            return searchedNode;
        }

        void instertBack(int data){
            Node *newNode = createNode(data);
            tail->next = newNode;
            tail = newNode;
        }
        void insertStart(int data){
            Node *newNode = createNode(data);
            newNode->next = head;
            head = newNode;
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

        }
        void insertBefore(int item,int data){
             Node *listItem = searchNode(item);
             if(listItem == head){
                insertStart(data);
             }else{

             Node *newNode = createNode(data);
             Node *beforeListItem = head;
             while(beforeListItem->next != listItem){
                beforeListItem = beforeListItem->next;
             }
             beforeListItem->next = newNode;
             newNode->next = listItem;
             }

        }
        void deleteEnd(){
            Node *secoundLast= head;
            while(secoundLast->next != tail){
                secoundLast = secoundLast->next;
            }
            secoundLast->next = nullptr;
            delete tail;
            tail = secoundLast;
        }
        void deleteStart(){
            Node *newHead = head->next;
            delete head;
            head = newHead;

        }
        void deleteItem(int item){
            Node *listItem = searchNode(item);
            if(listItem == head){
                deleteStart();
             }else if(listItem == tail){
                deleteEnd();
             }else{
                Node *beforeListItem = head;
             while(beforeListItem->next != listItem){
                beforeListItem = beforeListItem->next;
             }
             beforeListItem->next = listItem->next;
             delete listItem;
             }
        }
        void deleteBefore(int item){
            Node *listItem = searchNode(item);
             if(listItem == head){
                 throw "No before Element item available";
             }else{
             Node *beforeListItem = head;
               while(beforeListItem->next != listItem){
                beforeListItem = beforeListItem->next;
             }
             deleteItem(beforeListItem->data);
             
             }
        }
        void deleteAfter(int item){
            Node *listItem = searchNode(item);
            if(listItem->next == nullptr){
                throw "No after Element item available";
            }
            Node *nextItem = listItem->next;
              deleteItem(nextItem->data);
            
        }
    
    
};

int main(){
    LinkedList list =  LinkedList(5);
    list.instertBack(10);
    list.instertBack(15);
    list.instertBack(20);
    list.instertBack(25);


    list.insertStart(0);

     cout << "List after performing Insert after on elment 5" << endl;
    list.insertAfter(5,6);
    list.traverse();

    cout << "List after performing Insert before on elment 5" << endl;
    list.insertBefore(5,4);
    list.traverse();

    cout << "List before Delete last element" << endl;
    list.traverse();


    cout << "List after Delete last element" << endl;
    list.deleteEnd();
    list.traverse();

    cout << "List after Delete first element" << endl;
    list.deleteStart();
    list.traverse();

      cout << "List after Delete before 10 element" << endl;
    list.deleteBefore(10);
    list.traverse();

      cout << "List after Delete after 10 element" << endl;
    list.deleteAfter(10);
    list.traverse();

   


    return 0;
}