#include <iostream>
#include <vector>
using namespace std;

void adjustHeap(vector<int> &data, int parent, int size)
{
    int max = parent;

    for(int i = parent * 2 + 1; i <= size; i = (parent + 1) * 2 - 1)
    {
        if(i + 1 <= size && data[i + 1] > data[i])
        {
            max = i + 1;
        }
        else
        {
            max = i;
        }
        if(data[parent] < data[max])
        {
            swap(data[parent], data[max]);
        }
        parent = max;
    }
}

void createHeap(vector<int> &data, int size)
{
    for(int i = size / 2; i >= 0; --i)
    {
        adjustHeap(data, i, size);
    }
}

void heapSort(vector<int> &data, int length)
{
    if(length == 0)
    {
        cout << "input length of data is 0" << endl;
        return;
    }

    int size = length - 1;
    createHeap(data, size);

    for(int i = size; i >= 0; --i)
    {
        swap(data[0], data[i]);
        adjustHeap(data, 0, i - 1);
    }
}


int main()
{
    int a[] = {3, 1, 5, 7, 8, 2, 4, 6};
   
    vector<int> data(a, a + 8);

    heapSort(data, data.size());

    for(unsigned long i = 0; i < data.size(); ++i)
    {
        cout << data[i] << "    ";
    }
    cout << endl;

    return 0;
}

