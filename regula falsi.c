//Regula falsi method or method of false position
#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float);     //function declaration
float f(float x)    //function definition
{
    return pow(x,3)-5;
}
void regula (float *x, float x0, float x1, float fx0, float fx1, int *itr)
{
    *x = x0 - ((x1 - x0) / (fx1 - fx0))*fx0;
    ++(*itr);
    printf("\t\tIteration no.%d   X = %f \n", *itr, *x);
}
void main ()
{
	printf("\n\n\t\tANJALI CHHETRI");
    int itr = 0, m_itr;
    float x0,x1,x2,x3,e;
    printf("\n\t\tEnter the values of x0, x1:");
    scanf("%f %f", &x0, &x1);
    printf("\t\tallowed error: ");
    scanf("%f",&e);
    printf("\t\tenter maximum iterations:");
    scanf("%d",&m_itr);
    regula (&x2, x0, x1, f(x0), f(x1), &itr);
    do
    {
        if (f(x0)*f(x2) < 0)
            x1=x2;
        else
            x0=x2;
        regula (&x3, x0, x1, f(x0), f(x1), &itr);
        if (fabs(x3-x2) <e)
        {
            printf("\t\tAfter %d iterations,\n\t\tThe root of the given eqation is = %f\n", itr, x3);
            return 0;
        }
        x2=x3;
    }
    while (itr<m_itr);
    printf("\t\titerations not sufficient:\n");
    getch();
}
