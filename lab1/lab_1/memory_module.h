#ifndef MEMORY_H
#define MEMORY_H

#include "edge_arr.h"
#include "point_arr.h"

point_arr_t alloc_point_arr(size_t size);
void free_point_arr(point_arr_t &ptr);

edge_arr_t alloc_edge_arr(size_t size);
void free_edge_arr(edge_arr_t &ptr);

#endif // MEMORY_H
