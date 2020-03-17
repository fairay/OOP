#include "points_data.h"
#include "memory_module.h"

pdata_t init_pdata(void)
{
    pdata_t pdata;
    pdata.n = 0;
    pdata.arr = nullptr;
    return pdata;
}

err_t alloc_pdata(pdata_t &pdata, const unsigned int n)
{
    if (pdata.arr)  return NOT_NULL_ALLOC;
    pdata.arr = alloc_point_arr(n);
    if (!pdata.arr)
        return ALLOC_FAIL;
    else
    {
        pdata.n = n;
        return CORRECT_WORK;
    }
}

void delete_pdata(pdata_t &pdata)
{
    if (!pdata.n)   return;

    free_point_arr(pdata.arr);
    pdata.n = 0;
}

//
unsigned int get_points_n(const pdata_t &pdata)
{
    return pdata.n;
}

err_t get_points_i(point_t &p, const pdata_t &pdata, unsigned int i)
{
    if (pdata.n > i)    return WRONG_AGRS;
    return arr_get_point(p, pdata.arr, i);
}

pedge_t get_points_pedge(const pdata_t &pdata, const edge_t &edge)
{
    point_t p1, p2;
    arr_get_point(p1, pdata.arr, eget_p1(edge));
    arr_get_point(p2, pdata.arr, eget_p2(edge));
    return create_pedge(p1, p2);
}


//
err_t move_points(pdata_t &pdata, const transform_t &trans)
{
    if (pdata.n == 0)     return WRONG_ARR_SIZE;
    if (!pdata.arr)       return WRONG_AGRS;

    err_t code = CORRECT_WORK;
    point_t p;

    for (unsigned int i = 0; (!code) && i < pdata.n; i++)
    {
        arr_get_point(p, pdata.arr, i);
        move_point(p, trans.point);
        arr_set_point(pdata.arr, i, p);
    }
    return code;

}
err_t scale_points(pdata_t &pdata, const transform_t &trans)
{
    if (pdata.n == 0)     return WRONG_ARR_SIZE;
    if (!pdata.arr)       return WRONG_AGRS;

    err_t code = CORRECT_WORK;
    point_t p;

    for (unsigned int i = 0; (!code) && i < pdata.n; i++)
    {
        arr_get_point(p, pdata.arr, i);
        scale_point(p, trans.point, trans.scale);
        arr_set_point(pdata.arr, i, p);
    }
    return code;
}
err_t rotate_points(pdata_t &pdata, const transform_t &trans)
{
    if (pdata.n == 0)     return WRONG_ARR_SIZE;
    if (!pdata.arr)       return WRONG_AGRS;

    err_t code = CORRECT_WORK;
    point_t p;

    for (unsigned int i = 0; (!code) && i < pdata.n; i++)
    {
        arr_get_point(p, pdata.arr, i);
        rotate_point(p, trans.point, trans.angels);
        arr_set_point(pdata.arr, i, p);
    }
    return code;
}

//
err_t draw_points(draw_t &draw, const pdata_t &pdata, const proj_params_t &view_par)
{
    point_t p;
    err_t code = CORRECT_WORK;

    for (unsigned int i = 0; (!code) && i < pdata.n; i++)
    {
        code = arr_get_point(p, pdata.arr, i);
        if (!code)  p = trans_point(code, p, view_par);
        if (!code)  code = draw_point(draw, p);
    }
    return code;
}

//
err_t fscan_point_n(unsigned int &n, FILE *f)
{
    if (!f) return INCORRECT_FILE;
    int sc;
    unsigned int new_n;

    sc = fscanf(f, "%ud", &new_n);
    if (sc != 1 || !new_n)  return WRONG_ARR_SIZE;

    n = new_n;
    return CORRECT_WORK;
}

err_t fscan_points(pdata_t &pdata, FILE *f)
{
    if (!pdata.n)       return WRONG_ARR_SIZE;
    err_t code = CORRECT_WORK;
    point_t p;

    for (unsigned int i = 0; (!code) && i < pdata.n; i++)
    {
        code = fscan_point(p, f);
        if (!code)
            code = arr_set_point(pdata.arr, i, p);
    }
    return code;
}

err_t fscan_pdata(pdata_t &pdata_old, FILE *f)
{
    err_t code;
    pdata_t pdata = init_pdata();
    unsigned int n;

    code = fscan_point_n(n, f);
    if (code)  return code;

    code = alloc_pdata(pdata, n);
    if (code)  return code;

    code = fscan_points(pdata, f);

    if (code)
    {
        delete_pdata(pdata);
    }
    else
    {
        delete_pdata(pdata_old);
        pdata_old = pdata;
    }
    return code;
}
