#include "IntStack.h"
#include <cassert>

IntStack::IntStack(int capacity) : cap{ capacity }, top_idx{ 0 } {
    assert(cap > 0);
    data = new int[cap];
}

IntStack::~IntStack() {
    delete[] data;
}

IntStack::IntStack(const IntStack& other)
    : cap{ other.cap }, top_idx{ other.top_idx } {
    data = new int[cap];
    for (int i = 0; i < top_idx; ++i) {
        data[i] = other.data[i];
    }
}

void IntStack::push(int x) {
    assert(top_idx < cap);
    data[top_idx++] = x;
}

int IntStack::pop() {
    assert(top_idx > 0);
    return data[--top_idx];
}

int IntStack::top() const {
    assert(top_idx > 0);
    return data[top_idx - 1];
}

bool IntStack::empty() const {
    return top_idx == 0;
}

int IntStack::size() const {
    return top_idx;
}