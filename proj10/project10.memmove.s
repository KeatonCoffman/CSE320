
/******************************************************************************
  Given two 12-byte records, use "memmove" to copy one record over the top
  of the other record, then display that area of memory.

  Translation:

    gcc /user/cse320/Projects/project10.memmove.s /user/cse320/lib/memlib.o
******************************************************************************/

        .global main
 
        .text
        .balign 4
main:
        push    {lr}
 
        ldr     r0, =pointA
        mov     r1, #24
        mov     r2, #12
        bl      display
 
        ldr     r0, =pointA
        ldr     r1, =pointB
        mov     r2, #12   
        bl      memmove
 
        ldr     r0, =pointA
        mov     r1, #24
        mov     r2, #12
        bl      display
 
        pop     {lr}
        bx      lr
 
        .data
        .balign 4
pointA:
        .byte   'A'
        .balign 4
        .word   12, 16
pointB:
        .byte   'B'
        .balign 4
        .word   19, 14
 
