#include <stddef.h>

class ArenaAllocator
{
public:
    ArenaAllocator(size_t _size);
    ~ArenaAllocator();
    void *Allocate(size_t _size);

    template <typename T>
    T *Allocate();

private:
    void *data = nullptr;
    size_t capacity = 0;
    size_t index = 0;
};

template <typename T>
inline T *ArenaAllocator::Allocate()
{
    return (T *)Allocate(sizeof(T));
}
