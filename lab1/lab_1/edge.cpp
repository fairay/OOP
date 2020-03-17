#include <stdlib.h>
#include "edge.h"

// Edge functions
edge_t create_edge(unsigned int p1, unsigned int p2)
{
    edge_t e;
    e.p1 = p1;
    e.p2 = p2;
    return e;
}

unsigned int eget_p1(const edge_t &edge)
{
    return edge.p1;
}
unsigned int eget_p2(const edge_t &edge)
{
    return edge.p2;
}

err_t fscan_edge(FILE *f, edge_t &e)
{
    int sc;
    unsigned int i1, i2;

    if (!f)         return INCORRECT_FILE;

    sc = fscanf(f, "%u%u", &i1, &i2);
    if (sc != 2)    return INCORRECT_FILE;

    e = create_edge(i1, i2);
    return CORRECT_WORK;
}
