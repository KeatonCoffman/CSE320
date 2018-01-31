
/******************************************************************************

  Assume you have two 16-bit unsigned integers that you want to pack into one
  32-bit unsigned integer.

  For example:  0x1234 and 0xABCD yields 0x1234ABCD

  <prompt> gcc -Wall project06.pack.c
  <prompt> a.out

  value1:  00001234
  value2:  0000abcd
  result:  1234abcd

******************************************************************************/

#include <stdio.h>

int main()
{
  unsigned int value1 = 0x1234;
  unsigned int value2 = 0xABCD;

  unsigned int result;

  result = (value1 << 16) | value2;

  printf( "value1:  %08x\n", value1 );
  printf( "value2:  %08x\n", value2 );
  printf( "result:  %08x\n", result );
  printf( "\n" );

  return 0;
}

