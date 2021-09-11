#include "edge_arr.h"

/*
// Edge array functions
err_t alloc_edge_arr(edge_arr_t &ptr, size_t n)
{
    if (n == 0)     return WRONG_ARR_SIZE;
    else if (ptr)   return  NOT_NULL_ALLOC;

    ptr = static_cast<edge_arr_t>(calloc(n, sizeof(edge_t)));
    if (!ptr)       return ALLOC_FAIL;

    return CORRECT_WORK;
}

void delete_edge_arr(edge_arr_t &ptr)
{
    free(ptr);
    ptr = nullptr;
}
*/

err_t arr_get_edge(edge_t &e, const edge_arr_t ptr, unsigned int i)
{
    if (!ptr)   return NULL_ARR;
    e = ptr[i];
    return CORRECT_WORK;
}
err_t arr_set_edge(edge_arr_t ptr, unsigned int i, const edge_t &e)
{
    if (!ptr)   return NULL_ARR;
    ptr[i] = e;
    return CORRECT_WORK;
}

///
/*
err_t fscan_edge_arr(FILE *f, edge_arr_t ptr, unsigned int n)
{
    err_t code = CORRECT_WORK;
    if (!f || !ptr)
        return WRONG_AGRS;

    for (unsigned int i = 0; code == CORRECT_WORK && i < n; i++)
        code = fscan_edge(f, ptr[i]);
    return code;
}
*/
