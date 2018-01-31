/****************************************************************
Keaton Coffman
CSE 320
Project 11
*****************************************************************/
#include "/user/cse320/Projects/project11.support.h"

unsigned sign_extend(int simmbit){
	int first_val = simmbit>>25;
	if(first_val == 1){
		simmbit = simmbit | 0xfc000000;
	}
	return simmbit;
}






unsigned update( unsigned PC, unsigned IR, unsigned CPSR ){
	
	unsigned int instruction = ((IR<<4)>>30);
	unsigned int condition = IR>>28;
	unsigned int Lvalue = ((IR<<6)>>30);
	int simmbit = ((IR<<8)>>8);
	
	// Error Checking //
	if(instruction == 3){
		PC = 0;
		return PC;
	}
	if(condition == 15){
		PC = 0;
		return PC;
	}
	if((Lvalue>>1)!=1){
		PC = 0;
		return PC;
	}
	////////////////////
	
	// NZCV Bits //
	unsigned int Nbit = (CPSR>>31);
	unsigned int Zbit = (CPSR<<1)>>31;
	unsigned int Cbit = (CPSR<<2)>>31;
	unsigned int Vbit = (CPSR<<3)>>31;
 	
	
	
	// Reading condition fields //
	if(instruction == 2){
		// equal: z set
		if(condition == 0){
			if(Zbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// not equal: z clear
		if(condition == 1){
			if(!Zbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// carry: c set
		if(condition == 2){
			if(Cbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// not carry: c clear
		if(condition == 3){
			if(!Cbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// negative: n set
		if(condition == 4){
			if(Nbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// not negative: n clear
		if(condition == 5){
			if(!Nbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// overflow: v set
		if(condition == 6){
			if(Vbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// not overflow: v clear
		if(condition == 7){
			if(!Vbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// unsigned greater than: c set and z clear
		if(condition == 8){
			if(Cbit && !Zbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// unsigned less than or equal to: c clear and z set
		if(condition == 9){
			if(!Cbit || Zbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// signed greater than or equal to: N == V
		if(condition == 10){
			if(Nbit == Vbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// signed less than: N != V
		if(condition == 11){
			if(Nbit != Vbit){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// signed greater than: z clear and N == V
		if(condition == 12){
			if(!Zbit && (Nbit == Vbit)){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// signed less than or equal to: z set or N != V
		if(condition == 13){
			if(Zbit || (Nbit != Vbit)){
				PC = PC +  sign_extend(simmbit<<2);
			}
			else{
				PC += 4;
			}
		}
		// always: irrelevant
		if(condition == 14){
			PC = PC +  sign_extend(simmbit<<2);
		}
		return PC;
	}
	else{
		PC+=4;
		return PC;
	}
}

