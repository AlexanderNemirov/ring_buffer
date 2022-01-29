#ifndef RINGBUFFERVEC
#define RINGBUFFERVEC

#include <vector>
#include <iostream>
#include <stdexcept>

template<class T>
class RingBuffVec {
    std::size_t capacity_;
    std::size_t size_;
    std::size_t head_;
    std::size_t tail_;
    std::vector<T> elements_;

    RingBuffVec();

    public:
    RingBuffVec(std::size_t buff_capacity)
        : capacity_(buff_capacity), size_(0), head_(0), tail_(0) {
            if (buff_capacity == 0)
                throw std::runtime_error("Error: attemt to create zero capacity buffer");
            elements_.reserve(buff_capacity);
        }

    void write(const T& value) {
        elements_[head_] = value;
        head_ = (head_ + 1) % capacity_;
        if (size_ != capacity_)
            ++size_;
        else
            tail_ = (tail_ + 1) % capacity_;
    }

    T read() {
        if (size_ == 0) return T();
        std::size_t val_index = tail_;
        tail_ = (tail_ + 1) % capacity_;
        --size_;
        return elements_[val_index];
    }

    void print() {
        std::cout << "size: " << size_ 
            << " capacity: " << capacity_ << std::endl;
        for(std::size_t i=0; i<size_; ++i)
            std::cout << elements_[(tail_ + i) % capacity_] << "; ";
        std::cout << std::endl;
    }
};

#endif
