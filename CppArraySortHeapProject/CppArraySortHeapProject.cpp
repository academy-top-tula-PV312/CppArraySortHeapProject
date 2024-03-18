#include <iostream>

void ArrayPrint(int* array, int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void Swap(int& a, int& b)
{
    int temp{ a };
    a = b;
    b = temp;
}

void Heapify(int* array, int size, int index)
{
    
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    int largest = (array[left] < array[right]) ? right : left;
    if (array[index] < array[largest])
    {
        Swap(array[index], array[largest]);
        if (largest < size / 2 - 1)
            Heapify(array, size, largest);
    }
}

void ArraySortHeap(int* array, int size)
{
    for (int i{ size / 2 - 1 }; i >= 0; i--)
        Heapify(array, size, i);
    ArrayPrint(array, size);

    for (int i{ size - 1 }; i >= 0; i--)
    {
        Swap(array[0], array[i]);
        ArrayPrint(array, size);
        Heapify(array, i, 0);
        ArrayPrint(array, size);
    }
    
}

int main()
{
    srand(time(nullptr));

    int size{ 7 };
    int* array = new int[size];

    for (int i{}; i < size; i++)
        array[i] = rand() % 100;
    ArrayPrint(array, size);

    ArraySortHeap(array, size);
    /*for (int i{ size / 2 - 1 }; i >= 0; i--)
        Heapify(array, size, i);*/

    ArrayPrint(array, size);
}
