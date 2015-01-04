/**
 * @file stgs-private.h
 * @brief Declarations for Stgs class
 * @author 
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_STGS_PRIVATE_H_INCLUDE
#define GUARD_STGS_PRIVATE_H_INCLUDE

#include <stgs/stgs-config.h>

#if 0
#    define STGS_DEBUGM printf
#else
#    define STGS_DEBUGM black_hole
#endif

#if 0
#    define STGS_TRACE_ENTRY printf("STGS ENTRY %s in %s[%d]\n", __func__, __FILE__, __LINE__)
#else
#    define STGS_TRACE_ENTRY
#endif

#if 0
#    define STGS_TRACE_EXIT printf("STGS EXIT %s in %s[%d]\n", __func__, __FILE__, __LINE__)
#else
#    define STGS_TRACE_EXIT
#endif


static inline void black_hole (...)
{}

#endif // GUARD_STGS_PRIVATE_H_INCLUDE
