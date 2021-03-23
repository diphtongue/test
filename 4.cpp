#include <iostream>
#include <iterator>
#include <vector>
#include <functional>
 
template <class IT, class F>
void myapply(IT i1, IT i2, F f) {
    for (auto it = i1; it != i2; ++it) {
        f(*it);
    }
}

template <class IT, class F>
std::vector <std::reference_wrapper<typename IT::value_type>> myfilter2(IT i1, IT i2, F f) {

    std::vector <std::reference_wrapper<typename IT::value_type>> v;
    for (auto it = i1; it != i2; ++it) {
        if (f(*it)) {
            v.push_back(std::ref(*it));
        }
    }
    return v;
}


template <class T, class F>
void myapply(T *i1, T *i2, F f) {
    for (auto it = i1; it != i2; ++it) {
        f(*it);
    }
}

template <class T, class F>
std::vector <std::reference_wrapper<T>> myfilter2(T *i1, T *i2, F f) {

    std::vector <std::reference_wrapper<T>> v;
    for (auto it = i1; it != i2; ++it) {
        if (f(*it)) {
            v.push_back(std::ref(*it));
        }
    }
    return v;
}