#ifndef EDGES_DATA_H
#define EDGES_DATA_H

#include "edge_arr.h"

typedef struct
{
    edge_arr_t arr;
    unsigned int n;
} edata_t;

edata_t init_edata(void);
void delete_edata(edata_t &edata);

unsigned int get_edges_n(const edata_t &edata);
err_t get_edges_i(edge_t &p, const edata_t &edata, unsigned int i);

err_t fscan_edata(FILE *f, edata_t &edata);

#endif // EDGES_DATA_H
