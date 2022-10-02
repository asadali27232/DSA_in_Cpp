#ifndef LAB_2_DYNAMICARRAY_H
#define LAB_2_DYNAMICARRAY_H

template<typename T>
class DynamicArray {
private:
    int size;
    int tSize;
    T *Array;
public:
    DynamicArray();
    void printArray();
};


#endif //LAB_2_DYNAMICARRAY_H
