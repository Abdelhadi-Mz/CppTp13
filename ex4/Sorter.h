#pragma once
#include <vector>
#include <functional>
#include <concepts>
#include <algorithm>

template<typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

template<Sortable T>
struct Asc {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

template<Sortable T>
struct Desc {
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

template<Sortable T, typename Comp = Asc<T>>
void quickSort(std::vector<T>& arr, Comp comp = Comp{}) {
    if (arr.size() <= 1) return;

    auto quickSortRec = [&](auto&& self, int low, int high) -> void {
        if (low >= high) return;
        T pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (comp(arr[j], pivot)) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int p = i + 1;
        self(self, low, p - 1);
        self(self, p + 1, high);
    };

    quickSortRec(quickSortRec, 0, arr.size() - 1);
}
