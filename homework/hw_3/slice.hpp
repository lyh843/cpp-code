#include <memory>
#include <cstring>
#include <iostream>

struct SliceOutOfBoundError {};

class Slice {
private:
    std::shared_ptr<int> buf;
    size_t base;
    size_t length;
    size_t capacity;

    static void free_buf(int *buf) {
        delete[] buf;
    }

    static std::shared_ptr<int> allocate_buf(size_t size) {
        return std::shared_ptr<int>(new int[size], free_buf);
    }

public:
    Slice(size_t size, int initial = 0) {
        // TODO
        buf = allocate_buf(2 * size);
        base = 0;
        length = size;
        capacity = 2 * size;
        for(int i = 0; i < length; i++){
            buf.get()[base + i] = initial;
        }
    }

    Slice(const Slice &other) {
        // TODO
        buf = other.buf;
        base = other.base;
        length = other.length;
        capacity = other.capacity;
    }
    
    static Slice copy_from(const Slice &other) {
        // TODO
        Slice newone(other.length, 0);
        for(int i = 0; i < newone.length; i++){
            newone.buf.get()[newone.base + i] = other.buf.get()[other.base + i];
        }
        return newone;
    }

    void operator=(const Slice &other) {
        // TODO
        buf = other.buf;
        base = other.base;
        length = other.length;
        capacity = other.capacity;
    }

    void append(int x) {
        // TODO
        if(capacity <= base + length){
            Slice newone(capacity + 1, 0);
            newone.length = length;
            newone.base = 0;
            for(int i = 0; i < capacity; i++){
                newone.buf.get()[i] = buf.get()[i];
            }
            *this = newone;
        }
        buf.get()[base + length] = x;
        length++;
    }

    Slice operator[](std::pair<size_t, size_t> range) {
        // TODO
        if(range.first > range.second || base + range.second > capacity || base > range.first){
            SliceOutOfBoundError a;
            throw a;
        }
        Slice newone(*this);
        newone.base = base + range.first;
        newone.length = range.second - range.first;
        return newone;
    }

    int& operator[](size_t pos) {
        // TODO
        if(pos >= length){
            SliceOutOfBoundError a;
            throw a;
        }
        return buf.get()[base + pos];
    }

    void print() {
        for (int i = 0; i < length; ++i) {
            std::cout << buf.get()[base + i] << ' ';
        }
        std::cout << '\n';
    }

    size_t len() {
        return length;
    }
    
    size_t cap() {
        return capacity;
    }
};