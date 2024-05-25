#include <iostream>
#include <forward_list>

using namespace std;
// Implementation of stack using Arrrays
#define DEFAULT_SIZE 1000
template <typename T>
class Stack
{
private:
    int size;
    int topPointer;
    T *array;
    int maxSize;

public:
    Stack()
    {
        size = 0;
        topPointer = -1;
        maxSize = DEFAULT_SIZE;
        array = new T[DEFAULT_SIZE];
    }
    Stack(int inputSize)
    {
        size = 0;
        topPointer = -1;
        maxSize = inputSize;
        array = new T[inputSize];
    }

    // Function to push the element
    void push(T elem)
    {
        if (size == maxSize)
        {
            throw runtime_error("\nStack Overflow\n");
        }
        topPointer++;
        array[topPointer] = elem;
        size++;
    }
    // Function to pop the elements
    T pop()
    {
        if (size == 0)
        {
            throw runtime_error("Stack Underflow\n");
        }
        T elem = array[topPointer];
        topPointer--;
        size--;
        return elem;
    }
    // Function to peek the top element
    T top()
    {
        if (size == 0)
        {
            throw runtime_error("\nStack is Empty!!\n");
        }
        return array[topPointer];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool sizeOfStack()
    {
        return size;
    }
};
template <typename T>
class stack
{
private:
    int size = 0;
    forward_list<T> list;
public:
    stack()
    {
        size = 0;
    }
    void push(T elem)
    {
        list.push_front(elem);
        size++;
    }
    T pop()
    {
        if (list.begin() == list.end())
        {
            throw runtime_error("Stack Underflow\n");
        }
        T data = list.front();
        list.pop_front();
        size--;
        return data;
    }
    int sizeOfStack(){
        return size;
    }
    T top(){
        
        if (list.begin() == list.end())
        {
            throw runtime_error("Stack Underflow\n");
        }
        T data = list.front();
        return data;
    }
    bool isEmpty(){
        return size == 0 && list.begin() == list.end();
    }
    
};
void reverseTheStack(stack<int>&st){
    if(st.isEmpty()) return;
    stack<int> st2;
    int size = st.sizeOfStack();
    for(int i =0; i<size; i++){
        int top = st.pop();
        for(int j = 0; j< size-i-1; j++){
            st2.push(st.pop());
        }
        st.push(top);
        for(int j =0; j<size-i-1; j++){
            st.push(st2.pop());
        }
    }
}
void insertAtBottom(stack<int>&st, int x){
    if(st.isEmpty()){
        st.push(x);
        return;
    }
    int a = st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(a);
}
void reverseTheStackRecur(stack<int>&s){
    if(s.isEmpty()) return;
    int x = s.top();
    s.pop();
    reverseTheStackRecur(s);
    insertAtBottom(s, x);
}
int main()
{
    // Stack<int> st(100);
    // Stack<char> st2;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // cout << st.pop() << endl;
    // cout << st.pop() << endl;
    // cout << st.pop() << endl;
    // st2.push('h');
    // st2.push('a');
    // st2.push('r');
    // st2.push('s');
    // st2.push('h');

    // cout << st2.pop() << endl;
    // cout << st2.pop() << endl;
    // cout << st2.pop() << endl;
    // cout << st2.pop() << endl;
    // cout << st2.pop() << endl;

    // StackusingList<char> st3;

    // if(st3.isEmpty()) cout<<"\nEmpty List Stack Now\n";
    // st3.push('B');
    // st3.push('A');
    // st3.push('N');
    // st3.push('S');
    // st3.push('A');
    // st3.push('L');

    // cout<<"\nTop Element: "<<st3.top();
    // cout<<"\nSize of the stack: "<<st3.sizeOfStack()<<endl;

    // cout<<st3.pop()<<endl;
    // cout<<st3.pop()<<endl;
    // cout<<st3.pop()<<endl;
    // cout<<st3.pop()<<endl;
    // cout<<st3.pop()<<endl;
    // cout<<st3.pop()<<endl;
    // cout<<st3.pop()<<endl;
    // cout<<st3.pop()<<endl;


    // nTo test reverse fucntion
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseTheStack(st);
    while(!st.isEmpty()){
        cout<<st.pop()<<endl;
    }


    return 0;
}