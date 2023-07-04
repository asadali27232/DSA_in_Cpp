#ifndef LAB_3_STACK_H
#define LAB_3_STACK_H

template<typename T>
class Stack {
private:
    int TOP{};
    int size{};
    T *stack;
public:
    explicit Stack(int size);

    ~Stack();

    int getTOP();

    void print();

    void push(T element);

    T pop();

    bool isEmpty();

    bool isFull();
};

#endif //LAB_3_STACK_H
