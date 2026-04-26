#pragma once
#include <vector>
#include <algorithm>

template<typename T>

void selection_sort(std::vector<T>& v)
{
    for (int i = 0; i < v.size() - 1 ; i++) {
        int min = i;
        for (int j=i+1; j <= v.size()-1; j++) {
            if (v[j]<v[min]) {
                min = j;
            }
        }
        std::swap(v[i], v[min]);
    }
}