/****************************************************************
Keaton Coffman
CSE 320
Project 10
*****************************************************************/
	.global insert
	.global delete
	.global search
	.data
	memory: .skip 4
	
	.text
	
search:
		push {r4,r5,r6,r7,r8,r9,lr}
		
		mov	r4,r0
		mov	r5,r1
		ldrh	r8,[r0,#2]		@ Count of table
		ldr r7,[r0,#8]		@ Start of students
		mov	r9,#0			@ Initialize counter
		
loopsearch:	
		cmp	r8,r9
		beq notfound
		
		ldr	r6,[r7]			@ Access Student ID
		
		cmp	r6,r5
		beq	returntrue
		
		add	r7,r7,#40		@ Go to next student
		
		add	r9,r9,#1
		b	loopsearch
returntrue:
		mov r0,#1
		str	r7,[r2]
		b	endsearch

notfound:
		mov r0,#0
		
		b	endsearch
		
endsearch:
		
		pop	{r4,r5,r6,r7,r8,r9,lr}
		
		bx	lr
		
		

//************************************************************************		
		
insert:
		push {r4,r5,r6,r7,r8,r9,r10,r11,lr}
		mov	r4,r1	@ Move target ID
		mov	r5,r2	@ Move name of student
		mov	r11,r0	@ Table
		ldr r6,[r0,#8]		@ Start of students
		ldrh	r7,[r0,#2]		@ Count of table
		ldrh	r8,[r0]		@ Capacity of table
		
		cmp	r7,r8	@ Compare count to capacity
		beq	invalid_insert
		
		mov	r8,r3	@ Store the Exam 1
		
		bl search
		
		cmp	r0,#0	@ If not found insert
		beq	valid_insert
		
		cmp	r0,#1	@ If found terminate
		beq	invalid_insert
		
valid_insert:
		ldr	r10,[r6]	@ Load ID of student
		
		cmp	r10,r4		@ ID cannot be equal
		beq	invalid_insert
		
		cmp	r10,r4		@ Compare ID of current student to target ID
		bgt	move
		
		add	r6,r6,#40	@ Continue to next student
		
		sub	r7,r7,#1	@ Decrement count
		
		cmp	r7,#0		@ Compare count to zero
		beq	move
		
		b	valid_insert
move:	
		mov	r1,r6	@ Move src arg for memmove
		
		add	r0,r6,#40	@ Add 40 to src to get dest for memmove
		
		mov	r9,#40
		mul	r2,r9,r7	@ Multiply count by 40
		
		bl	memmove
		
		@ Calculate total points and percent
		@ Store all values in place
		
		
		str	r4,[r1,#0]	@ store ID
		str	r8,[r1,#30] 	@ Exam 1
		ldrh	r6,[sp,#36]	@ Exam 2 info
		strh	r6,[r1,#32]
		ldrh	r10,[sp,#40]	@ HW info
		strh	r10,[r1,#34]
		
		add	r8,r8,r6	@ Add exam 1 and 2
		add	r8,r8,r10	@ Add to get total
		str	r8,[r1,#36]	@ Store total
		
		mov	r6,#100		
		mul	r8,r8,r6	@ Total x 100
		ldrh	r9,[r11,#4]	@ Load available pts
		sdiv	r8,r8,r9
		strh	r8,[r1,#38]	@ Store Percentage
		
		
		mov	r2,#25
		add	r0,r1,#4
		mov	r1,r5
		bl	memmove		@ Calling memmove to move the name 
		
		
		ldr			r7, [r11, #2]	@ Load count
		add		    r7,r7,#1		@ increment count
		strh	    r7,[r11, #2]	@ store count
		
		mov	r0,#1
		b	endinsert
		
invalid_insert:
		mov	r0,#0
		
		b	endinsert
endinsert:		
		pop	{r4,r5,r6,r7,r8,r9,r10,r11,lr}
		
		bx	lr
				
//************************************************************************		
		
delete:		
		push {r4,r5,r6,r7,r8,r9,r10,lr}
		mov	r4,r0
		mov	r5,r1
		ldr r7,[r4,#8]		@ Start of students
		ldrh	r8,[r4,#2]		@ Count of table
		
		mov	r9,r8		@ Save number of students
		ldr	r2, =memory	@ Allocate memory 
		
		bl	search
		
		ldr	r10, [r2]	@ Store the address returned by search
			
		cmp	r0,#0
		beq	delete_failed
		
		cmp	r0,#1
		beq	delete_item
		
delete_item:
		
		mov r0,r10
		
		add	r10,r10,#40
		
		mov r1,r10
		
		mov	r6,#40		@ Initialize register for mult
		mul	r11,r9,r6	@ Number of students mult by 40
		sub	r11,r11,#40
		add	r11,r11,r7
		sub	r2,r11,r0
		
		
		bl	memmove
		
		sub	r8,r8,#1
		strh	r8,[r4,#2]
		mov	r0,#1
		
		b	end_delete
delete_failed:
		mov r0,#0
		
		b	end_delete
end_delete:
		pop	{r4,r5,r6,r7,r8,r9,r10,lr}
		
		bx	lr
		
		
//************************************************************************		
		
		
		
		
		
		
		
		
		
