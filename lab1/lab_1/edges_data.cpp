#include "edges_data.h"
#include "memory_module.h"

edata_t init_edata(void)
{
    edata_t edata;
    edata.n = 0;
    edata.arr = nullptr;
    return edata;
}

err_t alloc_edata(edata_t &edata, const unsigned int n)
{
    if (edata.arr)  return NOT_NULL_ALLOC;
    edata.arr = alloc_edge_arr(n);
    if (!edata.arr)
        return ALLOC_FAIL;
    else
    {
        edata.n = n;
        return CORRECT_WORK;
    }
}

void delete_edata(edata_t &edata)
{
    if (!edata.n)   return;

    // delete_edge_arr(edata.arr);
    free_edge_arr(edata.arr);
    edata.n = 0;
}


//
unsigned int get_edges_n(const edata_t &edata)
{
    return edata.n;
}

err_t get_edges_i(edge_t &e, const edata_t &edata, unsigned int i)
{
    if (edata.n <= i)    return WRONG_AGRS;
    return arr_get_edge(e, edata.arr, i);
}

//
err_t fscan_edge_n(unsigned int &n, FILE *f)
{
    if (!f) return INCORRECT_FILE;
    int sc;
    unsigned int new_n;

    sc = fscanf(f, "%ud", &new_n);
    if (sc != 1 || !new_n)  return WRONG_ARR_SIZE;

    n = new_n;
    return CORRECT_WORK;
}

err_t fscan_edges(edata_t &edata, FILE *f)
{
    if (!edata.n)       return WRONG_ARR_SIZE;
    err_t code = CORRECT_WORK;
    edge_t e;

    for (unsigned int i = 0; (!code) && i < edata.n; i++)
    {
        code = fscan_edge(e, f);
        if (!code)
            code = arr_set_edge(edata.arr, i, e);
    }
    return code;
}

err_t fscan_edata(edata_t &edata_old, FILE *f)
{
    err_t code;
    edata_t edata = init_edata();
    unsigned int n;

    code = fscan_edge_n(n, f);
    if (code)  return code;

    code = alloc_edata(edata, n);
    if (code)  return code;

    code = fscan_edges(edata, f);

    if (code)
    {
        delete_edata(edata);
    }
    else
    {
        delete_edata(edata_old);
        edata_old = edata;
    }
    return code;
}
