#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <iterator>

class StackOverflow : public std::runtime_error {
public:
    StackOverflow() : std::runtime_error("Erreur : Depassement de la pile (Stack Overflow)") {}
};

class StackUnderflow : public std::runtime_error {
public:
    StackUnderflow() : std::runtime_error("Erreur : Pile vide (Stack Underflow)") {}
};

template <typename T>
class Stack {
private:
    std::unique_ptr<T[]> data;
    std::size_t capacity;
    std::size_t top;

public:
    explicit Stack(std::size_t cap = 10)
        : data(std::make_unique<T[]>(cap)), capacity(cap), top(0) {}

    template <typename InputIt>
    Stack(InputIt begin, InputIt end) {
        capacity = std::distance(begin, end);
        data = std::make_unique<T[]>(capacity);
        top = 0;
        for (auto it = begin; it != end; ++it)
            push(*it);
    }

    void push(const T& value) {
        if (top >= capacity)
            throw StackOverflow();
        data[top++] = value;
    }

    void pop() {
        if (empty())
            throw StackUnderflow();
        --top;
    }

    const T& peek() const {
        if (empty())
            throw StackUnderflow();
        return data[top - 1];
    }

    bool empty() const {
        return top == 0;
    }

    std::size_t size() const {
        return top;
    }

    std::size_t max_size() const {
        return capacity;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
        os << "[Sommet -> ";
        for (std::size_t i = stack.top; i > 0; --i) {
            os << stack.data[i - 1];
            if (i > 1) os << ", ";
        }
        os << "]";
        return os;
    }
};

#endif
