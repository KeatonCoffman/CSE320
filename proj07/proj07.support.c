#include <stdio.h>
#include <stdlib.h>

void decode( unsigned int Bits, char buffer[] ){
	// split "Bits" into 4's and analyze each string of 4 
	unsigned int Front = Bits >> 26;
	unsigned int i_bit = (Bits << 6) >> 31;
	unsigned int opcode = (Bits << 7) >> 28;
	unsigned int s_bit = (Bits << 11) >> 31 ;
	unsigned int R_n = (Bits << 12) >> 28;
	unsigned int R_d = (Bits << 16) >> 28;
	unsigned int imm_val;
	unsigned int R_m;
	
	if (i_bit == 1){
		 imm_val = (Bits << 24) >> 24;
	}
	if (i_bit == 0){
		 R_m = (Bits << 28) >> 28;
	}
	

	
	if(Front == 0x38){
	
	
	if ( opcode == 0 ){
		if (s_bit == 1 ){
		    sprintf(buffer, "%s ", "ands");
			sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
			
		}
		else{
			sprintf(buffer, "and ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}
	}
	if ( opcode == 1 ){
		if (s_bit == 1 ){
			sprintf(buffer, "%s ","eors");
			sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n ",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n ",R_m);
			}
			
		}
		else{
			sprintf(buffer, "eor ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d  \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}

	}
	
	if ( opcode == 2 ){
		if (s_bit == 1 ){
			sprintf(buffer, "subs ");
			sprintf(strlen(buffer)+buffer,"r%d",R_d);
		        sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d ",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
			
		}
		else{
			sprintf(buffer, "sub ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}
	}
	
	if ( opcode == 3 ){
		if (s_bit == 1 ){
			sprintf(buffer, "rsbs ");
			sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n ",R_m);
			}
			
		}
		else{
			sprintf(buffer, "rsb ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}

	}

	if ( opcode == 4 ){
		if (s_bit == 1 ){
			sprintf(buffer, "adds ");
			sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"r%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
			
		}
		else{
			sprintf(buffer, "add ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}

	}

	if ( opcode == 5 ){
		if (s_bit == 1 ){
			sprintf(buffer, "adcs ");
			sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
			
		}
		else{
			sprintf(buffer, "adc ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}

	}

	if ( opcode == 6 ){
		if (s_bit == 1 ){
			sprintf(buffer, "sbcs ");
			sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
			
		}
		else{
			sprintf(buffer, "sbc ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}

	}
	
	if ( opcode == 7 ){
		if (s_bit == 1 ){
		    sprintf(buffer, "rscs " );
			sprintf(strlen(buffer)+buffer,"rd",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d ",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d ",R_m);
			}
			
		}
		else{
			sprintf(buffer, "rsc ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}
		
	}
	
	
	if ( opcode == 8 ){
		//tst
		if (s_bit == 1 ){
			sprintf(buffer, "tst ");
			sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
			
		}
		else{
			sprintf(buffer, "tst ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}
	
}

	
	
	if ( opcode == 9 ){
		//teq
	    sprintf(buffer, "teq ");
		sprintf(strlen(buffer)+buffer,"r%d",R_d);
		sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
		if (i_bit == 1){
		    sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
		}
		else{
		    sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
		}
	}
	if ( opcode == 10 ){
		//cmp
		if(R_d != 0){
			sprintf(buffer,"This is not machine code.");
		}
		else{
	    sprintf(buffer, "cmp ");
		sprintf(strlen(buffer)+buffer,"r%d, ",R_n);
		if (i_bit == 1){
		    sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
		}
		else{
		    sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
		}
	}
	}
	if ( opcode == 11 ){
		//cmn
		if(R_d != 0){
			sprintf(buffer,"This is not machine code.");
		}
		else{
	    sprintf(buffer, "cmn ");
		sprintf(strlen(buffer)+buffer,"r%d, ",R_n);
		if (i_bit == 1){
		    sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
		}
		else{
		    sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
		}
	}
	}
	if ( opcode == 12 ){
		if (s_bit == 1 ){
			sprintf(buffer, "orrs ");
			sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
			
		}
		else{
			sprintf(buffer, "orr ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}
	
	}
	
	if ( opcode == 13 ){
		//mov
		if(R_n != 0){
			sprintf(buffer,"This is not machine code.");
		}
		else{
	    sprintf(buffer, "teq ");
		sprintf(strlen(buffer)+buffer,"r%d, ",R_d);
		if (i_bit == 1){
		    sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
		}
		else{
		    sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
		}
		}
	}
	
	if ( opcode == 14 ){
		if (s_bit == 1 ){
			sprintf(buffer, "bics ");
			sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
			
		}
		else{
			sprintf(buffer, "bic ");
		    sprintf(strlen(buffer)+buffer,"r%d",R_d);
			sprintf(strlen(buffer)+buffer,", r%d, ",R_n);
			if (i_bit == 1){
			  sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
			}
			else{
			  sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
			}
		}

	}
	
	if ( opcode == 15 ){
		//mvn
		if(R_n != 0){
			sprintf(buffer,"This is not machine code. \n");
		}
		else{
	    sprintf(buffer, "mvn ");
		sprintf(strlen(buffer)+buffer,"r%d, ",R_d);
		if (i_bit == 1){
		    sprintf(strlen(buffer)+buffer,"#0x%d \n",imm_val);
		}
		else{
		    sprintf(strlen(buffer)+buffer,"r%d \n",R_m);
		}
	}
	}
	
}
else{
	sprintf(buffer,"This is not machine code. \n");
}

};
