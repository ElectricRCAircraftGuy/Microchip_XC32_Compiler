#include <stdint.h>

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

typedef uint32_t spec_mask;

typedef struct smartio_suffix_
{
  const uint32_t mask;
  const char *suffix;
} smartio_suffix;

extern const uint32_t num_suffixes;
extern const uint32_t valid_suffixes;
EXTERNC uint32_t sio_map_char(char);
EXTERNC uint32_t sio_suffix_bit(uint32_t);
EXTERNC const smartio_suffix* get_suffix_info();
