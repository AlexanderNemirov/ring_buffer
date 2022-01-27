#ifndef RINGBUFFERVEC
#define RINGBUFFERVEC

#include <vector>
#include <iostream>

template<class T>
class RingBuffVec {
    std::size_t capacity_;
    std::size_t size_;
    std::size_t head_;
    std::size_t tail_;
    std::vector<T> elements_;

    public:
    RingBuffVec(std::size_t buff_capacity)
        : capacity_(buff_capacity), size_(0), head_(0), tail_(0) {
            elements_.reserve(buff_capacity);
        }
    void put(T value) {
        elements_[head_] = value;
        head_ = (head_ + 1) % capacity_;
        size_ = (size_ == capacity_) ? (size_) : (size_ + 1);
    }
    T get() {
        if (size_ == 0) return T();
        std::size_t val_index = tail_;
        tail_ = (tail_ + 1) % capacity_;
        --size_;
        return elements_[val_index];
    }
    void print() {
        for(std::size_t i=tail_; i<size_; ++i)
            std::cout << elements_[i % capacity_] << "; ";
        std::cout << std::endl;
    }

};

#endif
