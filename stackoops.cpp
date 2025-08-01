class Stack {
private:
    int top, arr[100];

public:
    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int x) {
        if (!isFull()) arr[++top] = x;
    }

    int pop() {
        if (!isEmpty()) return arr[top--];
        return -1;
    }

    int peek() {
        return (isEmpty()) ? -1 : arr[top];
    }
};
