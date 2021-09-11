#ifndef EDGE_ARR_H
#define EDGE_ARR_H

#include "edge.h"
typedef edge_t* edge_arr_t;

err_t alloc_edge_arr(edge_arr_t &ptr, size_t n);
void delete_edge_arr(edge_arr_t &ptr);

err_t arr_get_edge(edge_t &e, const edge_arr_t ptr, unsigned int i);
err_t arr_set_edge(edge_arr_t ptr, unsigned int i, const edge_t &e);

err_t fscan_edge_arr(FILE *f, edge_arr_t ptr, unsigned int n);
#endif // EDGE_ARR_H
