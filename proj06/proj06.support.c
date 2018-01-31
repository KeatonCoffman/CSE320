#define INFINITY  (__builtin_inff())
#define NAN       (__builtin_nanf (""))

#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

unsigned normalize(unsigned significand){
    if( significand >> 23 == 0 && significand >> 24 ==0){
      while (significand >> 23 == 0){
	significand = significand << 1;
	return significand;
      }
      if(significand >> 23 == 1 && significand >> 24 ==0){
        return significand;
      }
      if(significand >> 24 == 1){
	significand = significand >> 1;
	return significand;
      } 
    }
}


float add( float float_1, float float_2){
  union sp_item float_one;
  union sp_item float_two;
  signed sign_one, sign_two, exp_one, exp_two, fraction_one, fraction_two, shift;
  unsigned long result;
  unsigned significand_one;
  unsigned significand_two;
  unsigned final_result;
  signed final_significand, final_exponent, final_fraction, final_sign;
  

  // Assign float representation to the original float
  float_one.frep = float_1;
  float_two.frep = float_2;

  // Shift 31 bits to get sign of float
  sign_one = float_one.irep >> 31;
  sign_two = float_two.irep >> 31;
  
  if(float_one.frep > float_two.frep){
    final_sign = sign_one;
  }
  if(float_two.frep > float_one.frep){
    final_sign = sign_two;
  }
  if(float_two.frep == float_one.frep){
    final_sign = sign_one;
  }
    
  

  // Apply mask to retrieve exponent field
  exp_one = float_one.irep & 0x7f800000;
  exp_one = exp_one >> 23;
  exp_one = exp_one - 0x7f;


  // Apply mask to retrieve exponent field
  exp_two = float_two.irep & 0x7f800000;
  exp_two = exp_two >> 23;
  exp_two = exp_two - 0x7f;
  

  // Calculate final exponent
  final_exponent = (exp_one + exp_two);
  final_exponent = final_exponent + 127;
  
  
  
  // Apply mask to retrieve fraction field 
  fraction_one = float_one.irep & 0x007fffff;
  fraction_two = float_two.irep & 0x007fffff;


  // Masking the significand for leading bit
  significand_one = fraction_one | 0x00800000;
  significand_two = fraction_two | 0x00800000;
  
 
  
  
  // Check to see if the exponent makes the value denormal
  if(exp_one == -0x3FE){
    exp_one = 0;
    float_one.frep = 0;
  }
  
  // Check to see if the exponent makes the value denormal
  else if(exp_two == -0x3FE){
    exp_two = 0;
    float_two.frep = 0;
  }
  
  
  // If the float is Not a Number return NAN
  else if (float_one.irep == 0x7fc00000 || float_two.irep == 0x7fc00000 ){
      result = NAN ;
  }

  // If the float is INFINITY return INFINITY
  else if (float_one.irep == INFINITY  || float_two.irep == INFINITY ){
      result = INFINITY; 
  }
  
  
  // Calculations after checking values
  else{
    if(exp_one > exp_two){
      shift = exp_one - exp_two;
      significand_two = significand_two >> shift;
      final_significand = significand_one+significand_two;
      final_significand = normalize(final_significand);
      final_significand = final_significand - 0x00800000;
      final_result = (final_sign << 31  | final_exponent << 23 | final_significand) ;
      return final_result;
    }
      
    else if(exp_two > exp_one){
      shift = exp_two - exp_one;
      significand_one = significand_one >> shift;
      final_significand = significand_one+significand_two;
      final_significand = normalize(final_significand);
      final_significand = final_significand - 0x00800000;
      final_result.irep = (final_sign << 31  | final_exponent << 23 | final_significand) ;
      return final_result.frep;
    }
  }

};

