#pragma once
#include <vector>
#include <algorithm>

template<typename T>

void insertion_sort(std::vector<T>& v)
{
    for (int i = 1; i < v.size(); i++) {
        T key = v[i];
        int j = i-1;
        while (j >=0 && v[j]>key) {
            v[j+1] = v[j];
            j  = j-1;
        }
        v[j+1] = key;
    }
}