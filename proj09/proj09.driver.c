#include <stdio.h>
#include "/user/cse320/Projects/project09.support.h"

int main(){
	printf("TESTING MULT FUNCTION \n");
	
	int A = 2;
	int CD = 2;
	int B = mul(A,CD);
	printf("The mul of %d and %d is %d \n",A,CD,B);
	
	A = -8;
	CD = -7;
	B = mul(A,CD);
	printf("The mul of %d and %d is %d \n",A,CD,B);
	
	A = -2;
	CD = 2;
	B = mul(A,CD);
	printf("The mul of %d and %d is %d \n",A,CD,B);
	
	
	printf("\n");
//************************************************************************
	printf("TESTING NEGATE FUNCTION \n");
	
	A=-14;
	B = negate(A);
	printf("The negation of %0d is %0d \n",A,B);
	
	A= 14;
	B = negate(A);
	printf("The negation of %0d is %0d \n",A,B);
	
	printf("\n");
//************************************************************************	
	printf("TESTING ABS VAL FUNCTION \n");

	A=-14;
	B = absolute(A);
	printf("The absolute value of %0d is %0d \n",A,B);
	
	
	A= 14;
	B = absolute(A);
	printf("The absolute value of %0d is %0d \n",A,B);
	
	printf("\n");
//************************************************************************
	printf("TESTING ADD FUNCTION \n");
	
	int C = 16;
	int D = 25;
	int E = add(D,C);
	printf("The addition of %d and %d is %d \n",C,D,E);

	C = -16;
	D = 25;
	E = add(D,C);
	printf("The addition of %d and %d is %d \n",C,D,E);
	
	C = -16;
	D = -25;
	E = add(D,C);
	printf("The addition of %d and %d is %d \n",C,D,E);
	
	C = 16;
	D = -25;
	E = add(D,C);
	printf("The addition of %d and %d is %d \n",C,D,E);
	
	printf("\n");
//************************************************************************	
	printf("TESTING SUBTRACTION FUNCTION \n");
	
	C = 25;
	D = 16;
	E = sub(C,D);
	printf("The subtraction of %d - %d is %d \n",C,D,E);
	
	C = -25;
	D = 16;
	E = sub(C,D);
	printf("The subtraction of %d - %d is %d \n",C,D,E);
	
	C = 25;
	D = -16;
	E = sub(C,D);
	printf("The subtraction of %d - %d is %d \n",C,D,E);
	
	C = -25;
	D = -16;
	E = sub(C,D);
	printf("The subtraction of %d - %d is %d \n",C,D,E);
	
	printf("\n");
//************************************************************************	
	printf("TESTING DIVIDE FUNCTION \n");
	
	A = 10;
	CD = 2;
	B = divide(A,CD);
	printf("The division of %d and %d is %d \n",A,CD,B);
	
	A = -10;
	CD = 2;
	B = divide(A,CD);
	printf("The division of %d and %d is %d \n",A,CD,B);
	
	A = 10;
	CD = -2;
	B = divide(A,CD);
	printf("The division of %d and %d is %d \n",A,CD,B);
	
	A = -10;
	CD = -2;
	B = divide(A,CD);
	printf("The division of %d and %d is %d \n",A,CD,B);
	
	A = -10;
	CD = 0;
	B = divide(A,CD);
	printf("The division of %d and %d is %d \n",A,CD,B);
	
	printf("\n");
//************************************************************************
	printf("TESTING REMAINDER FUNCTION \n");

	A = 10;
	B = 51;
	C = remain(B,A);
	printf("The remainder of %d divided by %d is %d \n",B,A,C);
	
	A = -52;
	B = 10;
	C = remain(A,B);
	printf("The remainder of %d divided by %d is %d \n",A,B,C);
	
	A = 53;
	B = -10;
	C = remain(A,B);
	printf("The remainder of %d divided by %d is %d \n",A,B,C);
	
	A = -54;
	B = -10;
	C = remain(A,B);
	printf("The remainder of %d divided by %d is %d \n",A,B,C);

	printf("\n");
//************************************************************************
	printf("TESTING POWER FUNCTION \n");

	A = 2;
	B = 3;
	C = power(A,B);
	printf("The power of %d to the %d power is %d \n",A,B,C);
	
	A = -2;
	B = 3;
	C = power(A,B);
	printf("The power of %d to the %d power is %d \n",A,B,C);
	
	
	A = 2;
	B = -3;
	C = power(A,B);
	printf("The power of %d to the %d power is %d \n",A,B,C);
	
	A = -2;
	B = -3;
	C = power(A,B);
	printf("The power of %d to the %d power is %d \n",A,B,C);

	A = 2;
	B = 0;
	C = power(A,B);
	printf("The power of %d to the %d power is %d \n",A,B,C);
	
	printf("\n");
//************************************************************************
	printf("TESTING FACTORIAL FUNCTION \n");

	A = 5;
	C = factorial(A);
	printf("The factorial of %d is %d \n",A,C);
	
	A = 2;
	C = factorial(A);
	printf("The factorial of %d is %d \n",A,C);
	
	A = 3;
	C = factorial(A);
	printf("The factorial of %d is %d \n",A,C);
	
	A = 4;
	C = factorial(A);
	printf("The factorial of %d is %d \n",A,C);
	
	A = 0;
	C = factorial(A);
	printf("The factorial of %d is %d \n",A,C);
	return 0;
};
