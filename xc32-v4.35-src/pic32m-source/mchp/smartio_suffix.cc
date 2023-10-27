/* 
  This file uses the template metaprogramming technique to generate the 
  suffix_info table. The suffix_info table contains a list of pairs 
  {mask, smartio-suffix}.
  
  Basically for each smartio-suffix we have a mask associated with. E.g for 
  smartio-suffix 'axX' we have an associated mask 
    1 << 'a' - 'a' | 1 << 'x' - 'a' | 1 << 'X' - 'A' 
  
  Using template metaprogramming we do compute these masks at build time.
*/

#include "smartio_suffix.h"

EXTERNC uint32_t
sio_map_char (char c)
{
  return (c >= 'a') ? (c - 'a') : (c - 'A');
}

EXTERNC uint32_t
sio_suffix_bit (uint32_t c)
{
  return 1 << c;
}

template <uint32_t N, uint32_t IDX> struct Helper
{
  static constexpr uint32_t
  find_mask (const char (&S)[N])
  {
    return sio_suffix_bit (sio_map_char (S[IDX]))
           | Helper<N, IDX - 1>::find_mask (S);
  }
};

template <uint32_t N> struct Helper<N, 0>
{
  static constexpr uint32_t
  find_mask (const char (&S)[N])
  {
    return sio_suffix_bit (sio_map_char (S[0]));
  }
};

template <uint32_t N>
static constexpr uint32_t
sio_mask (const char (&S)[N])
{
  return Helper<N, N - 2>::find_mask (S);
}

#undef E
#define E(x) { sio_mask (#x), #x },

const smartio_suffix suffix_info[] = 
{
	#include "smart-io.esfx"
};

#undef E
#define E(x) sio_mask (#x) |

const uint32_t valid_suffixes = 
(
	#include "smart-io.esfx"
 	0
);

const uint32_t num_suffixes = sizeof (suffix_info) / sizeof (suffix_info[0]);

EXTERNC const smartio_suffix *
get_suffix_info ()
{
  return suffix_info;
}
