
/******************************************************************************

  Assume you need to process a 32-bit floating point value as an unsigned
  integer (so that you can use bitwise operators).

  For example:  extract the biased exponent field and the true exponent.

  <prompt> gcc -Wall project06.union.c
  <prompt> a.out

  Real: 24.500000  Hex integer: 41c40000  True exponent: 4 

  Real: -0.250000  Hex integer: be800000  True exponent: -2 

******************************************************************************/

#include <stdio.h>

union sp_item
{
  float frep;
  unsigned irep;
};

int main()
{
  union sp_item num;
  signed true_exp;

  num.frep = 24.5;

  printf( "Real: %f  Hex integer: %08x  ", num.frep, num.irep );

  true_exp = ((num.irep >> 23) & 0xff) - 0x7f;

  printf( "True exponent: %d \n\n", true_exp );


  num.frep = -0.25;

  printf( "Real: %f  Hex integer: %08x  ", num.frep, num.irep );

  true_exp = ((num.irep >> 23) & 0xff) - 0x7f;

  printf( "True exponent: %d \n\n", true_exp );

  return 0;
}

