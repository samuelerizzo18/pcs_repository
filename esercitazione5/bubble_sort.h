#pragma once
#include <vector>
#include <algorithm>

template<typename T>

void bubble_sort(std::vector<T>& v)
{
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = v.size() - 1; j > i; j--) {
            if (v[j] < v[j-1]){
                std::swap(v[j], v[j-1]);
            }
        }
    }

}