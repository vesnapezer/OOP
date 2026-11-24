#pragma once
#pragma once

class IntStack {
private:
    int* data;
    int cap;
    int top_idx;

public:
    IntStack(int capacity);
    ~IntStack();                         // Destruktor (RAII)
    IntStack(const IntStack& other);     // Copy konstruktor (duboka kopija)

    void push(int x);
    int pop();
    int top() const;
    bool empty() const;
    int size() const;
};
