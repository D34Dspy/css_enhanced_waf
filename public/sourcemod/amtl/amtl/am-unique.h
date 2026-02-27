#pragma once 

#include <memory>
#include <type_traits>
#include <utility>

namespace std {
    // 1. For single objects (non-arrays)
    template <typename T, typename... Args>
    typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type
    make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    // 2. For arrays of unknown bound (e.g., T = char[])
    template <typename T>
    typename std::enable_if<std::is_array<T>::value && std::extent<T>::value == 0, std::unique_ptr<T>>::type
    make_unique(size_t size) {
        typedef typename std::remove_extent<T>::type ElementType;
        return std::unique_ptr<T>(new ElementType[size]());
    }

    // 3. For arrays of known bound (e.g., T = char[10]) - Disallowed by C++14/17
    template <typename T, typename... Args>
    typename std::enable_if<std::extent<T>::value != 0, void>::type
    make_unique(Args&&...) = delete;
}
