#ifndef STRUCTS_H
#define STRUCTS_H

#define PI                  3.1415
#define EPS                 1e-6

typedef const char* file_arg_t;


typedef enum {
    CORRECT_WORK = 0,
    WRONG_AGRS,
    ALLOC_FAIL,
    NOT_NULL_ALLOC,
    WRONG_ARR_SIZE,
    UNREAD_FILE,
    INCORRECT_FILE,
    NO_SCENE,
    WRONG_DRAW,
    INVALID_VIEW,
    WRONG_ACTION,
    NULL_ARR,
    INCORRECT_VIEW,
    INVISIBLE_POINT
} err_t;

#endif // STRUCTS_H
