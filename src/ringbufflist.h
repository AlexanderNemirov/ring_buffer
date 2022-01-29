#ifndef RINGBUFFERLIST
#define RINGBUFFERLIST

#include <list>
#include <iostream>
#include <stdexcept>

template<class T>
class RingBuffList {
    std::size_t capacity_;
    std::size_t size_;
    std::list<T> elements_;

    RingBuffList();

    public:
    RingBuffList(std::size_t buff_capacity)
        : capacity_(buff_capacity), size_(0) {
            if (buff_capacity == 0)
                throw std::runtime_error("Error: attemt to create zero capacity buffer");
        }

    void write(const T& value) {
        if (size_ == capacity_) {
            elements_.pop_front();
            --size_;
        }
        elements_.push_back(value);
        ++size_;
    }

    T read() {
        if (size_ == 0) return T();
        --size_;
        T value = *elements_.begin();
        elements_.pop_front();
        return value;
    }

    void print() {
        std::cout << "size: " << size_ 
            << " capacity: " << capacity_ << std::endl;
        for(auto & el : elements_)
            std::cout << el << "; ";
        std::cout << std::endl;
    }
};

#endif
