#ifndef PIC32_VECSET_H_
#define PIC32_VECSET_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <libiberty.h>

/* helper macro that returns the next power of 2 */
#ifndef NEXTPOW2
#define NEXTPOW2(X) \
(__extension__ ({ \
  const uint32_t _x_np2 = (X); \
  (_x_np2 != 0U) ? 1U << (32 - __builtin_clz (_x_np2)) : 1U; \
}))
#endif

/******************************************************
 * abstract vector - on the lines of C++'s std::vector
 *****************************************************/

typedef struct vec_type {
  uint32_t size;
  uint32_t capacity;
  void     *data;
} vec_type;

#define VEC_NEW(T, N, ZERO_INIT) \
(__extension__ ({ \
  const size_t _elem_size = sizeof(T), _size = (N); \
  vec_type *_v = (vec_type *) xmalloc (sizeof (vec_type)); \
  _v->size     = _size; \
  _v->capacity = NEXTPOW2 (_size); \
  _v->data     = (ZERO_INIT) ? xcalloc (_v->capacity, _elem_size) \
                             : xmalloc (_v->capacity * _elem_size); \
  _v; \
}))

#define VEC_DELETE(V) \
(__extension__ ({ \
  vec_type *_v = (V); \
  if (_v) { \
    free (_v->data); \
    free (_v); \
  } \
}))

#define VEC_SIZE(V)       ((V)->size)
#define VEC_EMPTY(V)      (!(V)->size)
#define VEC_CAPACITY(V)   ((V)->capacity)
#define VEC(T, V, I)      (((T*)(V)->data)[(I)])
#define VEC_BEGIN(T, V)   ((T*)(V)->data)
#define VEC_END(T, V)     (VEC_BEGIN(T, V) + VEC_SIZE(V))

#define VEC_RESERVE(T, V, N) \
(__extension__ ({ \
  const size_t _elem_size = sizeof(T), _size = (N); \
  vec_type *_v = (V); \
  if (_size > _v->capacity) { \
    _v->capacity = NEXTPOW2 (_size); \
    _v->data = xrealloc (_v->data, _v->capacity * _elem_size); \
  } \
}))

#define VEC_RESIZE(T, V, N, ZERO_INIT) \
(__extension__ ({ \
  const size_t _elem_size = sizeof(T), _size = (N); \
  vec_type *_v = (V); \
  if (_size > _v->capacity) { \
    _v->capacity = NEXTPOW2 (_size); \
    _v->data = xrealloc (_v->data, _v->capacity * _elem_size); \
  } \
  if ((ZERO_INIT) && (_size > _v->size)) \
    memset (&VEC(T, V, _v->size), 0, (_size-_v->size) * sizeof(T)); \
  _v->size = _size; \
}))

#define VEC_PUSHBACK(T, V, X) \
(__extension__ ({ \
  const uint32_t _pos = VEC_SIZE (V); \
  VEC_RESIZE (T, V, _pos + 1, 0); \
  VEC(T, V, _pos) = (X); \
}))

#define VEC_BACK(T, V)    VEC(T, V, VEC_SIZE(V)-1)
#define VEC_POPBACK(T, V) VEC_RESIZE (T, V, VEC_SIZE(V)-1, 0)

#define VEC_INSERT(T, V, I, X) \
(__extension__ ({ \
  const uint32_t _N = VEC_SIZE (V), _IDX = (I); \
  VEC_RESIZE (T, V, _N + 1, 0); \
  if (_IDX != _N) \
    memmove (&VEC(T, V, _IDX+1), &VEC(T, V, _IDX), (_N-_IDX) * sizeof(T)); \
  VEC(T, V, _IDX) = (X); \
}))

#define VEC_ERASE(T, V, I) \
(__extension__ ({ \
  const uint32_t _N = VEC_SIZE (V), _IDX = (I); \
  if (_IDX + 1 != _N) \
    memmove (&VEC(T, V, _IDX), &VEC(T, V, _IDX+1), (_N-_IDX-1) * sizeof(T)); \
  VEC_RESIZE (T, V, _N - 1, 0); \
}))

/* returns the lower bound index */
#define VEC_LOWERBOUND(T, V, X) \
(__extension__ ({ \
  uint32_t _begin = 0, _end = VEC_SIZE (V); \
  while (_begin < _end) { \
    const uint32_t _mid = (_begin + _end) >> 1; \
    if (VEC (T, V, _mid) < (X)) \
      _begin = _mid + 1; \
    else \
      _end = _mid; \
  } \
  _begin; \
}))

/* returns the lower bound index; CMP function variant (similar to bsearch's one) */
#define VEC_LOWERBOUND_CMP(T, V, X, CMP) \
(__extension__ ({ \
  T const _x = (X); \
  uint32_t _begin = 0, _end = VEC_SIZE (V); \
  while (_begin < _end) { \
    const uint32_t _mid = (_begin + _end) >> 1; \
    if ((CMP) (&VEC (T, V, _mid), &_x) < 0) \
      _begin = _mid + 1; \
    else \
      _end = _mid; \
  } \
  _begin; \
}))

/* returns the address of the vector element with value X; CMP function variant */
#define VEC_BSEARCH_CMP(T, V, X, CMP) \
(__extension__ ({ \
  T const _x = (X); \
  const uint32_t _idx = VEC_LOWERBOUND_CMP (T, V, _x, (CMP)); \
  _idx != VEC_SIZE(V) ? __extension__ ({ \
    T *const _ptr = &VEC(T, V, _idx); \
    !(CMP) (_ptr, &_x) ? _ptr : NULL; \
  }) : NULL; \
}))



/******************************************************
 * a set as an ordered vector
 *****************************************************/

typedef vec_type set_type; /* for convenience as it's basically the same type */

#define SET_NEW(T)              VEC_NEW(T,0,0)
#define SET_DELETE(SET)         VEC_DELETE(SET)
#define SET_SIZE(SET)           VEC_SIZE(SET)
#define SET_EMPTY(SET)          VEC_EMPTY(SET)
#define SET_LOWERBOUND(T,SET,X) VEC_LOWERBOUND(T,SET,X)

/* inserts X in SET; returns != 0 if really inserted, 0 if already existing */
#define SET_INSERT(T, SET, X) \
(__extension__ ({ \
  T const __x = (X); \
  const uint32_t _idx = VEC_LOWERBOUND (T, SET, __x); \
  int _rc = 0; \
  if (_idx == VEC_SIZE (SET) || VEC (T, SET, _idx) != __x) { \
    VEC_INSERT (T, SET, _idx, __x); \
    _rc = 1; \
  } \
  _rc; \
}))

/* SET_INSERT with compare function (similar to bsearch's one) */
#define SET_INSERT_CMP(T, SET, X, CMP) \
(__extension__ ({ \
  T const __x = (X); \
  const uint32_t _idx = VEC_LOWERBOUND_CMP (T, SET, __x, (CMP)); \
  int _rc = 0; \
  if (_idx == VEC_SIZE (SET) || (CMP) (&VEC (T, SET, _idx), &__x)) { \
    VEC_INSERT (T, SET, _idx, __x); \
    _rc = 1; \
  } \
  _rc; \
}))

/* returns != 0 if SET contains X */
#define SET_CONTAINS(T, SET, X) \
(__extension__ ({ \
  T const __x = (X); \
  const uint32_t _idx = VEC_LOWERBOUND (T, SET, __x); \
  _idx != VEC_SIZE (SET) && VEC(T, SET, _idx) == __x; \
}))

/* SET_CONTAINS with compare function */
#define SET_CONTAINS_CMP(T, SET, X, CMP) \
(__extension__ ({ \
  T const __x = (X); \
  const uint32_t _idx = VEC_LOWERBOUND_CMP (T, SET, __x, (CMP)); \
  _idx != VEC_SIZE (SET) && !(CMP) (&VEC (T, SET, _idx), &__x); \
}))

/* erases X from SET; returns != 0 if really erased, 0 if not there */
#define SET_ERASE(T, SET, X) \
(__extension__ ({ \
  T const __x = (X); \
  const uint32_t _idx = VEC_LOWERBOUND (T, SET, __x); \
  int _rc = 0; \
  if (_idx != VEC_SIZE (SET) && VEC(T, SET, _idx) == __x) { \
    VEC_ERASE (T, SET, _idx); \
    _rc = 1; \
  } \
  _rc; \
}))

/* SET_ERASE with compare function */
#define SET_ERASE_CMP(T, SET, X, CMP) \
(__extension__ ({ \
  T const __x = (X); \
  const uint32_t _idx = VEC_LOWERBOUND_CMP (T, SET, __x, (CMP)); \
  int _rc = 0; \
  if (_idx != VEC_SIZE (SET) && !(CMP) (&VEC (T, SET, _idx), &__x)) { \
    VEC_ERASE (T, SET, _idx); \
    _rc = 1; \
  } \
  _rc; \
}))

#endif /* PIC32_VECSET_H_ */
