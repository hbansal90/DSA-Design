#include<iostream>
#include<vector>
using namespace std;

class QueueUsingArrays{
    private:
        int* arr;
        int rear;
        int front;
        int currSize;
        int maxSize;
    public:
        QueueUsingArrays(){
            arr = new int[16];
            maxSize = 16;
            currSize = 0;
            front = -1;
            rear = -1;
        }
        QueueUsingArrays(int maxSize){
            this->maxSize = maxSize;
            arr = new int[maxSize];
            currSize = 0;
            front = -1;
            rear = -1;
        }
        void enqueue(int data){
            if(currSize == maxSize){
                throw runtime_error("Maximum Size Exceeded\n");
            }
            if(rear == -1){
                front = 0;
                rear = 0;
            }
            else rear = (rear+1)%(maxSize);
            arr[rear] = data;
            currSize++;
        }
        int dequeue(){
            if(currSize == 0){
               throw runtime_error("Empty Queue\n");
            }
            int deleElem = arr[front];
                front = (front+1)%maxSize;
            currSize--;
            if(currSize == 0){
                rear = front = -1;
            }
            return deleElem;
        }
        int top(){
            if(front == -1){
                cout<<"\nEmpty Queue\n";
            }
            return arr[front];
        }
        int size(){
            return currSize;
        }
        void print(){
            int temp = front;
            while(temp !=rear){
                cout<<arr[temp]<<" ";
                temp = (temp +1)%maxSize;
            }
            cout<<arr[temp];
            cout<<endl;
        }

};
int main(){
    QueueUsingArrays q(4);
    q.enqueue(1);
    cout<<q.top()<<endl;
    q.print();
    q.enqueue(2);
    q.print();
    q.enqueue(3);
    q.print();
    q.enqueue(4);
   
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(4);
    q.print();
    cout<<q.top()<<" "<<q.size()<<endl;
    q.enqueue(5);
    return 0;
}