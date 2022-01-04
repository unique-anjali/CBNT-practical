/* Program: Finding real roots using  Bisection Method*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (pow(x,2)-3)
void main()
{
	printf("\n\n\t\tANJALI CHHETRI\n");
	 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1;
	 start:
	 printf("\t\tEnter two initial guesses:");
	 scanf("%f%f",&x0,&x1);
	 printf("\t\tEnter tolerable error:");
	 scanf("%f", &e);
	  f0 = f(x0);
	  f1 = f(x1);
	 if( f0 * f1 > 0)
	 {
		  printf("Incorrect Initial Guesses.\n");
		  goto start;
	 }
   
	 printf("\n\t\tStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do
	 {
		  x2 = (x0 + x1)/2;
		  f2 = f(x2);
		
		  printf("\t\t%d\t\t%f\t%f\t%f\t%f\n",step, x0, x1, x2, f2);
		
		  if( f0 * f2 < 0)
		  {
			   x1 = x2;
			   f1 = f2;
		  }
		  else
		  {
			   x0 = x2;
			   f0 = f2;
		  }
		  step = step + 1;
	 }while(fabs(f2)>e);
	 printf("\t\tRoot of given function is : %f", x2);
	 getch();
}
