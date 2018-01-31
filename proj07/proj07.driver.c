
int main(){
	unsigned int bits = 0xe086500a;
	char loc[80];
	decode(bits,loc);
	printf("%s",loc);
	
  	unsigned int bits2 = 0xe086a007;
	char loc2[80];
	
	decode(bits2,loc2);
	printf("%s",loc2);

	unsigned int bits3 = 0xe096a007;
	char loc3[80];
	
	decode(bits3,loc3);
	printf("%s",loc3);

	unsigned int bits4 = 0xe1520003;
	char loc4[80];
	
	decode(bits4,loc4);
	printf("%s",loc4);

	unsigned int bits5 = 0xe1a01003;
	char loc5[80];
	
	decode(bits5,loc5);
	printf("%s",loc5);

	unsigned int bits6 = 0xe286a007;
	char loc6[80];
	
	decode(bits6,loc6);
	printf("%s",loc6);
	
	// orr r1, r6, r7
	unsigned int bits7 = 0xe1861007;
	char loc7[80];
	
	decode(bits7,loc7);
	printf("%s",loc7);

	//invalid
	unsigned int bits8 = 0xf286a007;
	char loc8[80];
	
	decode(bits8,loc8);
	printf("%s",loc8);
	
	// mov r0, r3
	unsigned int bits9 = 0xe1a00003;
	char loc9[80];
	
	decode(bits9,loc9);
	printf("%s",loc9);
	
	// orr r1, r6, r7
	unsigned int bits10 = 0xe1861007;
	char loc10[80];
	
	decode(bits10,loc10);
	printf("%s",loc10);
	
	return 0;
	
	
}
