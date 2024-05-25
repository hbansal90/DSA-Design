// Task: To Implement the Binary Heaps
// What is Binary Heap: It is a complete Binary Tree which helps to store the data in some order, to get min or max Element based on its structure
// Binary Heaps: MinHeap or MaxHeap
// We will implement using an array or a vector, we will use array regardless
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
// Heaps
class Heaps
{
private:
    // using dynamic array
    int *arr;
    int capacity;
    int heapSize;
    bool minHeap;

    bool compare(const int &key1, const int &key2)
    {
        return minHeap? (key1 > key2): (key1 < key2);
    }
    int parent(int index)
    {
        return (index - 1) / 2;
    }
    
    int leftChild(int index)
    {
        return (2 * index + 1);
    }
    int rightChild(int index)
    {
        return (2 * index + 2);
    }
    // Bottom Up approach to maintain the heap property
    void percolate_up(int index)
    {
        while (index != 0 && compare(arr[parent(index)], arr[index]))
        {
            swap(arr[parent(index)], arr[index]);
            index = parent(index);
        }
    }
    // Top- down approach top maintain the heap property
    void heapify(int index)
    {
        int left = leftChild(index);
        int right = rightChild(index);
        int changed = index;
        if (left < heapSize && compare(arr[index], arr[left]))
        {
            changed = left;
        }
        if (right < heapSize && compare(arr[changed], arr[right]))
        {
            changed = right;
        }
        if (arr[changed] != arr[index])
        {
            swap(arr[index], arr[changed]);
            heapify(changed);
        }
    }

public:
// Constructor with defualt argumnets
    Heaps(int size = 10, bool type = true)
    {
        capacity = size;
        minHeap = type;
        arr = new int[size];
        heapSize = 0;
    }
    // destructor
    ~Heaps()
    {
        delete[] arr;
    }
    /****************
     * Operations to do:
     * 1. Insert()
     * 2. Delete()
     * 3. getMin() or getMax()
     * 4. extractMin() or extractMax()
     * 5. decreaseKey() or IncreaseKey()
     *****************/
    void insertKey(int key)
    {
        if (heapSize == capacity - 1)
        {
            cout << "\nHeap Overflow\n";
            return;
        }
        arr[heapSize++] = key;
        percolate_up(heapSize - 1);
    }

    void decreaseKey(int i, int newValue)
    {
        if (i > heapSize)
        {
            cout << "\nInvalid Inputs";
            return;
        }
        arr[i] = newValue;
        if (minHeap)
            percolate_up(i);
        else
            heapify(i);
    }
    void increaseKey(int i, int newValue){
        if(i>heapSize || i<0){
            cout<<"\nInvalid Inputs!!\n";
            return;
        }
        arr[i] = newValue;
        if(minHeap) heapify(i);
        else percolate_up(i);
    }
    int getTop()
    {
        if (heapSize == 0)
        {
            cout << "Heap empty";
            return -1;
        }
        return arr[0];
    }
    int extractTop()
    {
        if (heapSize == 0)
        {
            cout << "\nEmpty Heap\n";
            return -1;
        }
        if (heapSize == 1)
        {
            heapSize--;
            return arr[0];
        }
        int root = arr[0];
        swap(arr[heapSize - 1], arr[0]);
        // to maintain the heap property, we will heapify
        heapSize--;
        heapify(0);
        return root;
    }
    void deleteKey(int i)
    {
        if (i >= heapSize)
        {
            cout << "Invalid inputs\n";
            return;
        }
        if (minHeap)
            arr[i] = INT_MIN;
        else
            arr[i] = INT_MAX;
        percolate_up(i);
        extractTop();
    }
};
int main()
{
    Heaps h(11, true);
    cout << "Inserting keys: 3, 2, 15, 5, 4, 45" << endl;
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    cout << "Extract top (should be 2): " << h.extractTop() << endl;
    cout << "Get top (should be 3): " << h.getTop() << endl;

    cout << "Decrease key at index 2 to 1" << endl;
    h.decreaseKey(2, 1);
    cout << "Get top (should be 1): " << h.getTop() << endl;

    cout << "Deleting key at index 1" << endl;
    h.deleteKey(0);
    cout << "Get top (should be 3): " << h.getTop() << endl;

    cout << "Inserting more keys: 20, 30, 40, 50, 60" << endl;
    h.insertKey(20);
    h.insertKey(30);
    h.insertKey(40);
    h.insertKey(50);
    h.insertKey(60);

    cout << "Extract top multiple times: ";
    while (h.getTop() != -1)
    {
        cout << h.extractTop() << " ";
    }
    cout << endl;

    // Test edge case: insert into full heap
    Heaps h2(3, true);
    h2.insertKey(10);
    h2.insertKey(20);
    h2.insertKey(30);
    cout << "Attempting to insert into a full heap:" << endl;
    h2.insertKey(40); // Should show "Heap Overflow"

    // Test edge case: delete from empty heap
    cout << "Attempting to delete from an empty heap:" << endl;
    h.deleteKey(0); // Should show "Invalid Input"

    return 0;
}