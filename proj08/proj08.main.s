
/*************************
// Keaton Coffman
// CSE 320
// Project 8
*************************/

        .global main

        .text
main:   push    {lr}


        mov     r4, #0      @ Initialize character count
        mov     r5, #0      @ Initialize whitespace count (blanks,tabs and newlines)
        mov     r6, #0		@ Initialize newline count
        mov		r7, #0		@ Initialize octal digit count
        mov		r8, #0		@ Initialize decimal digit count
        mov		r9, #0		@ Initialize hexadecimal digit count
        mov		r10, #0		@ Initialize letter count
        
loop:   bl      getchar     @ Read one character (returned in r0)

        cmp     r0, #-1     @ Compare return value to EOF
        beq     end         @ When EOF found, exit loop
        
        add     r4, r4, #1  @ Increment character count
        
        

if1:    cmp     r0, #0x20   @ Compare return value to blank
        bne     endif1      @ If blank not found, skip increment
        
then1:  add     r5, r5, #1  @ Increment whitespace count

endif1:
        
        
        

if2:	cmp     r0, #0x0a   @ Compare return value to newline
		bne     endif2      @ If newline not found, skip increment

then2:	add		r6,r6, #1	@ Increment newline count
		add		r5,r5, #1	@ Increment whitespace count

endif2:




if3:	cmp     r0, #'0'    @ Compare character to '0'
        blt     endif3
        cmp     r0, #'9'    @ Compare character to '9'
        bgt     endif3
        
then3:	add     r8, r8, #1  @ Increment decimal count
        add		r9, r9, #1  @ Increment hexadecimal count
endif3:



if4:	cmp     r0, #'0'    @ Compare character to '0'
        blt     endif4
        cmp     r0, #'7'    @ Compare character to '7'
        bgt     endif4
        
then4:	add     r7, r7, #1  @ Increment octal count
       
endif4:



if5:	cmp     r0, #'A'   @ Compare character to 'A'
        blt     endif5
        cmp     r0, #'F'   @ Compare character to 'F'
        bgt     endif5
        
then5:	add     r9, r9, #1  @ Increment hexadecimal count
       
endif5:



if6:	cmp     r0, #'A'   @ Compare character to 'A'
        blt     endif6
        cmp     r0, #'Z'   @ Compare character to 'Z'
        bgt     endif6
        
then6:	add     r10, r10, #1@ Increment letters count
       
endif6:



if7:	cmp     r0, #'a'   @ Compare character to 'a'
        blt     endif7
        cmp     r0, #'z'   @ Compare character to 'z'
        bgt     endif7
        
then7:	add     r10, r10, #1 @ Increment letters count
       
endif7:



if8:	cmp     r0, #0x09   @ Compare character to tab
        bne		endif8		@ If tab not found, skip increment 
       
        
then8:	add     r5, r5, #1  @ Increment whitespace count
       
endif8:



if9:    cmp     r0, #'a'   @ Compare character to 'a'
        blt     endif9
        cmp     r0, #'f'   @ Compare character to 'f'
        bgt     endif9
        
then9:	add     r9, r9, #1 @ Increment hexadecimal count
       
endif9:


		bl		putchar
        b       loop        @ Branch to top of loop

end:    ldr     r0, =fmt2   @ First arg  -- address of format string
        mov     r1, r4      @ Second arg -- character count
        bl      printf      @ Display the count
        
        ldr     r0, =fmt3   @ First arg  -- address of format string
        mov     r1, r5      @ Second arg -- whitespace count
        bl      printf      @ Display the count
        
        ldr     r0, =fmt4   @ First arg  -- address of format string
        mov     r1, r6      @ Second arg -- newline count
        bl      printf      @ Display the count
        
        ldr     r0, =fmt5   @ First arg  -- address of format string
        mov     r1, r7      @ Second arg -- octal count
        bl      printf      @ Display the count
        
        ldr     r0, =fmt6   @ First arg  -- address of format string
        mov     r1, r8      @ Second arg -- decimal count
        bl      printf      @ Display the count
        
        ldr     r0, =fmt7   @ First arg  -- address of format string
        mov     r1, r9      @ Second arg -- hexadecimal count
        bl      printf      @ Display the count
        
        ldr     r0, =fmt8   @ First arg  -- address of format string
        mov     r1, r10     @ Second arg -- letter count
        bl      printf      @ Display the count

        pop     {lr}
        bx      lr

		.data
		
fmt2:   .asciz  "\nCharacter: %d\n"
fmt3:   .asciz  "\nWhitespace: %d \n"
fmt4:   .asciz  "\nNewline: %d \n"
fmt5:   .asciz  "\nOctal: %d \n"
fmt6:   .asciz  "\nDecimal: %d \n"
fmt7:   .asciz  "\nHexadecimal: %d \n"
fmt8:   .asciz  "\nLetter: %d \n"



