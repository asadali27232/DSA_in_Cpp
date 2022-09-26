//
// Created by asada on 9/26/2022.
//

#ifndef LAB_2_STACK_H
#define LAB_2_STACK_H

template<typename T>
class Stack {
private:
    int TOP;
    int size;
    T *stack;
public:
    explicit Stack(int size);
    void print();
    void push(T value);
    T pop();
    bool isEmpty();
    bool isFull();
};

#endif //LAB_2_STACK_H
