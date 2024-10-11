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
    
    // 創建一個新的 Node，存儲傳入的值。
    // 將新節點的 next 指向當前的頂部。
    // 更新 top 指向新節點，使其成為新的頂部。

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
    
    // 首先檢查堆疊是否為空。
    // 如果不為空，保存頂部節點的值。
    // 將 top 移到下一個節點。
    // 刪除原頂部節點以釋放內存。
    // 返回保存的值。

    int peek() {
        if (isEmpty()) {
            std::cout << "堆疊為空" << std::endl;
            return -1;
        }
        return top->data;
    }

    // 檢查堆疊是否為空。
    // 如果不為空，返回頂部元素的值，但不改變堆疊。


    bool isEmpty() {
        return top == nullptr;
    }
};

// 新的測試程式
int main() {
    IntStack stack;

    // 放入10個整數
    std::cout << "放入10個整數：" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        stack.push(i);
        std::cout << "放入: " << i << std::endl;
    }

    std::cout << "\n嘗試取出11個整數：" << std::endl;
    // 嘗試取出11個整數
    for (int i = 1; i <= 11; ++i) { 
        int value = stack.pop();
        if (value != -1) {
            std::cout << "取出: " << value << std::endl;
        }
    }

    return 0;
}