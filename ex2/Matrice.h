#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <iomanip>

template <typename T, std::size_t N, std::size_t M>
class Matrice {
private:
    T data[N][M];

public:

    Matrice() {
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < M; ++j)
                data[i][j] = T{};
    }

    Matrice(std::initializer_list<std::initializer_list<T>> init) {
        std::size_t i = 0;
        for (auto &row : init) {
            std::size_t j = 0;
            for (auto &val : row) {
                if (i < N && j < M)
                    data[i][j] = val;
                ++j;
            }
            ++i;
        }
    }

    T& operator()(std::size_t i, std::size_t j) {
        if (i >= N || j >= M)
            throw std::out_of_range("Index hors limites");
        return data[i][j];
    }

    const T& operator()(std::size_t i, std::size_t j) const {
        if (i >= N || j >= M)
            throw std::out_of_range("Index hors limites");
        return data[i][j];
    }

    Matrice operator+(const Matrice &other) const {
        Matrice result;
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < M; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrice operator-(const Matrice &other) const {
        Matrice result;
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < M; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    template <std::size_t P>
    Matrice<T, N, P> operator*(const Matrice<T, M, P> &other) const {
        Matrice<T, N, P> result;
        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < P; ++j) {
                result(i, j) = T{};
                for (std::size_t k = 0; k < M; ++k)
                    result(i, j) += data[i][k] * other(k, j);
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream &os, const Matrice &mat) {
        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < M; ++j)
                os << std::setw(8) << mat.data[i][j] << " ";
            os << "\n";
        }
        return os;
    }
};

#endif
