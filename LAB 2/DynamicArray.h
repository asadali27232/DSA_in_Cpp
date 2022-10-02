#ifndef LAB_2_DYNAMICARRAY_H
#define LAB_2_DYNAMICARRAY_H

template<typename T>
class DynamicArray {
private:
    int size{};
    int tSize;
    T *Array;

    void doubleArray();

public:
    DynamicArray();

    ~DynamicArray();

    int getSize();

    void printArray();

    void add(T element);

    void add(int index, T element);

    void removeAt(int index);

    void remove(T element);

    void sort();

    int search(T element);
};


#endif //LAB_2_DYNAMICARRAY_H
