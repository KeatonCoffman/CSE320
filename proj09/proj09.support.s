/****************************************************************
Keaton Coffman
CSE 320
Project 09
*****************************************************************/

		.global negate
		.global absolute
		.global add
		.global sub
		.global mul
		.global divide
		.global remain
		.global power
		.global factorial
		

        .text
        

negate:
		push    {r4,lr}
		
		mov		r1,#-1
        bl		mul  		@ Multiply by negative 1 of the operand
        
		b		done

done:
        pop     {r4, lr}
        bx      lr

//************************************************************************

absolute:
        push    {r4,lr}

if:     
		cmp     r0, #0      @ Compare return value to 0
        bgt		done2	    @ Go to negative if less than zero

then:   
		mov		r1,#-1
		bl		mul			@ Negate the value
		bne		done2	
        
done2:
        pop     {r4,lr}
        bx      lr


//************************************************************************

add:
        push    {r4,r5,lr}

        mov     r4, r0      @ Save first argument
        mov     r5, r1      @ Save  argument
		
        adds    r0, r5, r4  @ Add the operands, set NZCV
		
		
		bvs		overflow	@ Check for overflow
		b		done3
overflow:
		mov		r0,#0x80000000

done3:
        pop     {r4,r5, lr}
        bx      lr



//************************************************************************

sub:
        push    {r4,r5,lr}

        mov     r4, r0      @ Save first argument
        mov     r5, r1      @ Save  argument
		
        subs    r0, r4, r5  @ Add the operands, set NZCV

		bvs		overflow2
		b 		done4
overflow2:
		mov		r0,#0x80000000

done4:
        pop     {r4,r5, lr}
        bx      lr


//************************************************************************

mul:
		push    {r6,r7,lr}
        
        
		smull   r7,r6,r0,r1

		cmp 	r7, #0x80000000	@ compare to overflow
		beq		overflow3	@ Send to overflow if equal
		
		mov		r0, r7		@ Move final number to r0
		b 		done5
		
overflow3:
		mov		r0,#0x80000000

done5:
        pop     {r6,r7, lr}
        bx      lr
        
    
//************************************************************************   
    
        
divide:
		push    {r4,r5,r6,lr}
		mov     r4, r0      @ Save first argument
        mov     r5, r1      @ Save second argument
        
        cmp		r5,#0		@ Compare divisor to 0
        beq		overflow4	@ Send to overflow if divisor is 0
        
		sdiv    r6,r0,r1	@ Divide
		mov		r0, r6
		
		bvs		overflow4
		b		done6
		
overflow4:
		mov		r0,#0x80000000
done6:
        pop     {r4,r5,r6, lr}
        bx      lr
        
//************************************************************************

remain:
		push    {r4,r5,r6,r7,r8, lr}
		mov     r4, r0      @ Save first argument
        mov     r5, r1      @ Save second argument
        
		sdiv	r6,r4,r5	@ Divide
		cmp		r5,#0		@ Compare result to 0
		beq		overflow10	@ Send to overflow if 0
		
		smull	r7,r8,r6,r5	@ Multiply

		cmp 	r8,#0x80000000 @ Compare to overflow value
		beq		overflow10	@ Send to overflow if overflow value
		b		sub1		
sub1:		
		subs	r0,r4,r7	@ Subtract
		
		bvs		overflow10	@ Check for overflow
		b 		done7
overflow10:
		mov		r0,#0x80000000
done7:
        pop     {r4,r5,r6,r7,r8, lr}
        bx      lr       
        


//************************************************************************
power:
		push    {r4,r5,r6,r7, lr}
		mov     r4, r0      @ Save first argument
        mov     r5, r1      @ Save second argument
        mov		r6, r0
        
        cmp		r5,#0		@ Compare second arg to 0
        beq		returnone	@ Send to returnone if 0
        
        cmp		r5,#0		@ Compare second arg to 0
        blt		returnzero	@ Send to overflow if less than 0
loop1:	

if5:	cmp		r5,#1
		beq		done8
		
then5:	smull	r6,r7,r6,r4
		
		cmp 	r7, #0x80000000	@ Compare rHi to overflow value
		beq		overflow5	@ Send to overflow if equal
		
		mov		r0,r6		@ Move multiplication to r0
		subs	r5,r5,#1	@ Decrement power
        
        
		b		loop1
		
overflow5:
		mov		r0,#0x80000000
		b		done8
		
returnone:
		mov		r0,#1
		b		done8
		
returnzero:
		mov		r0,#0

done8:
        pop     {r4,r5,r6,r7, lr}
        bx      lr 
	


//************************************************************************

factorial:
		push    {r4,r5,r6,r7,lr}
		mov     r4, r0      @ Save first argument
        mov     r5, r0      @ Save second argument
        
        cmp		r4,#0		@ Compare first arg to 0
        beq		return1		@ Send to return1 if equal
loop2:	

if7:	cmp		r5,#1		@ Compare second arg to 1
		beq		done9		@ Send to done9 if equal
		
then7:	sub		r5,r5,#1	@ Decrement r5
		smull	r6,r7,r4,r5	@ Multiply r4 and r5

		cmp 	r7, #0x80000000	@ Compare to overflow value	
		beq		overflow6	@ Send to overflow if equal
		
		mov		r4,r6		@ Move contents of r6 to r4
        
        
		b		loop2
overflow6:
		mov		r0,#0x80000000
return1:
		mov		r0,#1
		b		and
done9:
		mov		r0,r6
and:
        pop     {r4,r5,r6,r7, lr}
        bx      lr 
        

