#include "memory_module.h"
#include <stdlib.h>

point_arr_t alloc_point_arr(size_t size)
{
    if (!size) return nullptr;
    point_arr_t ptr = static_cast<point_arr_t>(calloc(size, sizeof(point_t)));
    return ptr;
}
void free_point_arr(point_arr_t &ptr)
{
    free(ptr);
    ptr = nullptr;
}

edge_arr_t alloc_edge_arr(size_t size)
{
    if (!size) return nullptr;
    edge_arr_t ptr = static_cast<edge_arr_t>(calloc(size, sizeof(edge_t)));
    return ptr;
}
void free_edge_arr(edge_arr_t &ptr)
{
    free(ptr);
    ptr = nullptr;
}

