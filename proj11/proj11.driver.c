
#include "/user/cse320/Projects/project11.support.h"
#include <string.h>
#include <stdio.h>

int main(){
	unsigned int PC = 0x00000000;
	unsigned int IR = 0x0b000003;
	unsigned int CPSR = 0x40000000;
	
	unsigned answer;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	///////////////////////////
	
	PC = 0x00000000;
	IR = 0x1b000003;
	CPSR = 0x0;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	//////////////////////////
	
	PC = 0x00000000;
	IR = 0x2b000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0x3b000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0x4b000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0x5b000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0x6b000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0x7b000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0x8b000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0x9b000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0xab000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0xbb000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0xcb000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0xdb000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0xeb000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0xfb000003;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0xfb00004d;
	CPSR = 0xa0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	
	/////////////////////////
	
	PC = 0x00000000;
	IR = 0xeafffff8;
	CPSR = 0xb0000000;
	
	answer = update(PC,IR,CPSR);
	printf("%x\n\n", answer);
	
	
	return 0;
}
