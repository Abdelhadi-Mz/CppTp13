#ifndef ARRAYDYN_H
#define ARRAYDYN_H

#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayDyn {
private:
    T* data;
    std::size_t taille;
    std::size_t capacite;

public:
    class Iterator {
    private:
        T* ptr;
    public:
        Iterator(T* p = nullptr) : ptr(p) {}
        T& operator*() const { return *ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        Iterator& operator--() { --ptr; return *this; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    ArrayDyn(std::size_t cap = 4) : taille(0), capacite(cap) {
        data = new T[capacite];
    }

    ArrayDyn(const ArrayDyn& other) : taille(other.taille), capacite(other.capacite) {
        data = new T[capacite];
        for (std::size_t i = 0; i < taille; ++i)
            data[i] = other.data[i];
    }

    ArrayDyn& operator=(const ArrayDyn& other) {
        if (this != &other) {
            delete[] data;
            capacite = other.capacite;
            taille = other.taille;
            data = new T[capacite];
            for (std::size_t i = 0; i < taille; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    ~ArrayDyn() { delete[] data; }

    void push_back(const T& value) {
        if (taille == capacite) {
            capacite *= 2;
            T* newData = new T[capacite];
            for (std::size_t i = 0; i < taille; ++i)
                newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        data[taille++] = value;
    }

    void pop_back() {
        if (taille > 0) taille--;
    }

    T& operator[](std::size_t index) {
        if (index >= taille) throw std::out_of_range("Index hors limites");
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= taille) throw std::out_of_range("Index hors limites");
        return data[index];
    }

    std::size_t size() const { return taille; }
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + taille); }
};

#endif
