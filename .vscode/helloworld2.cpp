#include <iostream>

class IntStack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* top;

public:
    IntStack() : top(nullptr) {}

    ~IntStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "堆疊為空，無法彈出元素" << std::endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "堆疊為空" << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// 測試程式
int main() {
    IntStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "頂部元素: " << stack.peek() << std::endl;
    std::cout << "彈出: " << stack.pop() << std::endl;
    std::cout << "彈出: " << stack.pop() << std::endl;

    stack.push(4);
    std::cout << "頂部元素: " << stack.peek() << std::endl;

    return 0;
}