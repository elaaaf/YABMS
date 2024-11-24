/* naive.c
 *
 * Author:
 * Date  :
 *
 *  Description
 */

/* Standard C includes */
#include <stdlib.h>

/* Include common headers */
#include "common/macros.h"
#include "common/types.h"

/* Include application-specific headers */
#include "include/types.h"

/* Naive Implementation */
#pragma GCC push_options
#pragma GCC optimize ("O1")
void* impl_scalar_naive(void* args)
{
/*
  args_t* parsed_args = (args_t*)args;

  register int* dest = (int*)(parsed_args->output);
  register const int* src0 = (const int*)(parsed_args->output);
  register const int* src1 = (const int*)(parsed_args->input0);
  register size_t size = parsed_args->size/4;
*/

// as a start, start with hardcoded inputs and make sure it works
    register int const m = 3;
    register int const p = 3;
    register int const n = 3;

   int src0[9] = {
      0, 1, 2,
      3, 4, 5,
      6, 7, 8
    };

    int src1[9] = {
      1, 0, 0,
      0, 1, 0,
      0, 0, 1
    };

    int dest[9] = {0,0,0,0,0,0,0,0,0};

    for(register int j = 0; j < 3; j++) {
       for(register int k = 0; k < 3; k++) {
          for(register int i = 0; i < 3; i++) {
              dest[i * m + j] += src0[i * p + k] * src1[k * m + j];
          }
       }
    }
/*
    // Perform matrix multiplication
    for(register int i = 0; i < 3; i++) {
        for(register int j = 0; j < 3; j++) {
            dest[i][j] = 0;
            for(register int k = 0; k < 3; k++) {
                dest[i][j] += src0[i][k] * src1[k][j];
            }
        }
    }
*/
    return NULL;
  
}
#pragma GCC pop_options
