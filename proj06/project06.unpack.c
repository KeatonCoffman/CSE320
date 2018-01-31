
/******************************************************************************

  Assume you have a 32-bit unsigned integer and you want to extract two 8-bit
  fields (bits 23:16 and 15:8) so that they can be processed as independent
  unsigned integer values.

  For example:  0x6789ABCD yields 0x00000089 and 0x000000AB

  There are three ways to extract those two 8-bit fields.

  <prompt> gcc -Wall project06.unpack.c
  <prompt> a.out

  value:   6789abcd
  field1:  00000089
  field2:  000000ab

  value:   6789abcd
  field1:  00000089
  field2:  000000ab

  value:   6789abcd
  field1:  00000089
  field2:  000000ab

******************************************************************************/

#include <stdio.h>

int main()
{
  unsigned int value = 0x6789ABCD;

  unsigned int field1;
  unsigned int field2;

  // Method #1:  mask, then shift

  field1 = (value & 0x00FF0000) >> 16;
  field2 = (value & 0x0000FF00) >> 8;

  printf( "value:   %08x\n", value );
  printf( "field1:  %08x\n", field1 );
  printf( "field2:  %08x\n", field2 );
  printf( "\n" );

  // Method #2:  shift, then mask

  field1 = (value >> 16) & 0x000000FF;
  field2 = (value >> 8)  & 0x000000FF;

  printf( "value:   %08x\n", value );
  printf( "field1:  %08x\n", field1 );
  printf( "field2:  %08x\n", field2 );
  printf( "\n" );

  // Method #3:  shift left, then shift right

  field1 = (value << 8) >> 24;
  field2 = (value << 16) >> 24;

  printf( "value:   %08x\n", value );
  printf( "field1:  %08x\n", field1 );
  printf( "field2:  %08x\n", field2 );
  printf( "\n" );

  return 0;
}

