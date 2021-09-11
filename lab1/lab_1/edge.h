#ifndef EDGE_C_H
#define EDGE_C_H

#include <stdio.h>
#include "defines.h"

typedef struct
{
    unsigned int p1, p2;
} edge_t;

edge_t create_edge(unsigned int p1, unsigned int p2);
unsigned int eget_p1(const edge_t &edge);
unsigned int eget_p2(const edge_t &edge);

err_t fscan_edge(edge_t &e, FILE *f);

#endif // EDGE_C_H
