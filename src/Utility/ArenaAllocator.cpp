#include "Utility/ArenaAllocator.hpp"
#include <malloc.h>
#include <cassert>
#include <iostream>

ArenaAllocator::ArenaAllocator(size_t _capacity)
{
    capacity = _capacity;
    data = malloc(capacity);
}
ArenaAllocator::~ArenaAllocator()
{
    if (data != nullptr)
        free(data);
}
void *ArenaAllocator::Allocate(size_t _size)
{
    std::cout << "Allocating " << _size << " bytes.\n";
    void *ptr = (char *)data + index;
    index += _size;
    assert(index < capacity);
    return ptr;
}