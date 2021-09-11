#include "point_arr.h"

/*
// Point array CDIO
err_t alloc_point_arr(point_arr_t &ptr, size_t n)
{
    if (n == 0)     return WRONG_ARR_SIZE;
    else if (ptr)   return NOT_NULL_ALLOC;

    ptr = static_cast<point_arr_t>(calloc(n, sizeof(point_t)));
    if (!ptr)       return ALLOC_FAIL;

    return CORRECT_WORK;
}

void delete_point_arr(point_arr_t &ptr)
{
    free(ptr);
    ptr = nullptr;
}
*/

err_t arr_get_point(point_t &p, const point_arr_t ptr, unsigned int i)
{
    if (!ptr)   return NULL_ARR;
    p = ptr[i];
    return CORRECT_WORK;
}
err_t arr_set_point(point_arr_t ptr, unsigned int i, const point_t &p)
{
    if (!ptr)   return NULL_ARR;
    ptr[i] = p;
    return CORRECT_WORK;
}

///
/*
err_t move_point_arr(point_arr_t ptr, unsigned int n, const transform_t &trans)
{
    if (n == 0)     return WRONG_ARR_SIZE;
    if (!ptr)       return WRONG_AGRS;

    for (unsigned int i = 0; i < n; i++)
        move_point(ptr[i], trans.point);

    return CORRECT_WORK;
}

err_t scale_point_arr(point_arr_t ptr, unsigned int n, const transform_t &trans)
{
    if (n == 0)     return WRONG_ARR_SIZE;
    if (!ptr)       return WRONG_AGRS;

    for (unsigned int i = 0; i < n; i++)
        scale_point(ptr[i], trans.point, trans.scale);

    return CORRECT_WORK;
}

err_t rotate_point_arr(point_arr_t ptr, unsigned int n, const transform_t &trans)
{
    if (n == 0)     return WRONG_ARR_SIZE;
    if (!ptr)       return WRONG_AGRS;

    for (unsigned int i = 0; i < n; i++)
        rotate_point(ptr[i], trans.point, trans.angels);

    return CORRECT_WORK;
}


///
err_t fscan_point_arr(FILE *f, point_arr_t ptr, unsigned int n)
{
    if (!ptr)       return NULL_ARR;
    if (n == 0)     return WRONG_ARR_SIZE;
    err_t code = CORRECT_WORK;

    for (unsigned int i = 0; code == CORRECT_WORK && i < n; i++)
        code = fscan_point(f, ptr[i]);
    return code;
}
*/
///
