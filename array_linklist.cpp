#include <iostream>
using namespace std;
template <class ArrType>

class CustomArr{
    private:
        ArrType* arr;
        int  size;
        int capacity;

         void resize(){
            capacity = capacity * 2;
            ArrType* newArr = new ArrType[capacity];
            for(int i = 0; i < size; i++){
                newArr[i] =  arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        
    public:
        CustomArr(){
            capacity = 2;
            size = 0;
            arr  = new ArrType[capacity];
        }
        ~CustomArr(){
            delete[] arr;
        }
        int getSize(){
            return size;
        }
        int getCapacity(){
            return capacity;
        }
         void traverse(){
           
            cout << "[";
             for(int i = 0; i < size; i++){
                cout << arr[i] << ",";
            }
            cout << "]" << "\n";

        }
        void traverse(int index){
            if(index >= size){
                throw "the given index is not exist in the Array!";
            }
            cout << "[";
             for(int i = 0; i <= index; i++){
                cout << arr[i] << ",";
            }
            cout << "]" << "\n";

        }

       void insertEnd(ArrType x){
            if(size == capacity){
                resize();
            }
            arr[size] = x;
            size++;
        }
       void insertStart(ArrType x){
        size++;
         if(size == capacity){
                resize();
            }
            for(int i = size; i > 0; i--){
                arr[i] = arr[i-1];
            }
            arr[0] = x;
       }

       void insertAt(ArrType x, int index){
         if(index >= size){
                throw "the given index is not exist in the Array!";
            }
        size++;
        if(size == capacity){
                resize();
            }
             for(int i = size; i > index; i--){
                arr[i] = arr[i-1];
            }
            arr[index] = x;
       }
       
       int searchIndex(ArrType x){
        for(int i =0; i < size; i++){
            if(arr[i] == x){
                return i;
            }
        }
        return -1;
       }
       void insertBefore(ArrType x, ArrType item){
        int itemIndex = searchIndex(item);
        if(itemIndex == -1){
            cout << "before Item not exist in Array!";
        }else{
           insertAt(x,itemIndex);

        }
       }
       void insertAfter(ArrType x, ArrType item){
        int itemIndex = searchIndex(item);
        if(itemIndex == -1){
            cout << "before Item not exist in Array!";
        }else{
           insertAt(x,itemIndex + 1);

        }
       }

       void deleteAt(int index){
        for (int i = index; i < size-1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;

       }
       void deleteFirst(){
        deleteAt(0);
       }
       void deleteLast(){
        deleteAt(size-1);
       }
       void deleteValue(ArrType value){
        int index = searchIndex(value);
        deleteAt(index);
       }
       void replaceAt(ArrType x, int  index){
        arr[index] = x;
       }
       void replaceStart(ArrType x){
            replaceAt(x,0);
       }
       void replaceLast(ArrType x){
            replaceAt(x,size -1);
       }
       void replaceValue(ArrType x, ArrType item){
            int index = searchIndex(item);
        replaceAt(x,index);
       }
       
       
 };
       

int main(){
    CustomArr<int> dataArray;

  // Insert elements at the end
    dataArray.insertEnd(10);
    dataArray.insertEnd(20);
    dataArray.insertEnd(30);
    dataArray.traverse();  // [10,20,30,]

     // Insert element at the start
    dataArray.insertStart(5);
    dataArray.traverse();  // [5,10,20,30,]

    // Insert element at index
    dataArray.insertAt(15, 2);
    dataArray.traverse();  // [5,10,15,20,30,]

    // find element index
    cout << dataArray.searchIndex(10) << endl; // 1

    // insert Before
    dataArray.insertBefore(25,15);
    dataArray.traverse();  // [5,10,25,15,20,30,]

    // Insert After
    dataArray.insertAfter(30,15);
    dataArray.traverse();  // 5,10,25,15,30,20,30,]

   // Delete index
    dataArray.deleteAt(4);
    dataArray.traverse();  // [5,10,25,15,20,30,]


    // Delete first and last
    dataArray.deleteFirst();
    dataArray.traverse();  // [10,25,15,20,30,]

    dataArray.deleteLast();
    dataArray.traverse();  // [10,25,15,20,]

    // Delete specific value
    dataArray.deleteValue(25);
    dataArray.traverse();  // [10,15,20,]


   // Replace index
    dataArray.replaceAt(45,1);
    dataArray.traverse();  // [10,45,20,]


    // Delete first and last
    dataArray.replaceStart(40);
    dataArray.traverse();  // [40,45,20,]

    dataArray.replaceLast(50);
    dataArray.traverse();  // [40,45,50,]

    // Delete specific value
    dataArray.replaceValue(35,45);
    dataArray.traverse();  // [40,35,50,]

    
    return 0;
}