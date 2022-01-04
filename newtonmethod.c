#include<stdio.h>
#include<math.h>
float f(float x)
{
    return 3*x-cos(x)-1;
}
float df (float x)
{
    return 3+sin(x);
}
void main()
{
	printf("\n\n\t\tANJALI CHHETRI");
    int itr, m_itr;
    float h, x0, x1, allerr;
    printf("\n\t\tEnter the value of x0:"); 
    scanf("%f", &x0);
    printf("\t\tenter allowed error:");
    scanf("%f",&allerr);
    printf("\t\tenter maximum iteration:");
    scanf("%d",&m_itr);
	    for (itr=1; itr<=m_itr; itr++)
    {
        h=f(x0)/df(x0);
        x1=x0-h;
        printf("\t\tIteration no.%d, x = %.4f\n", itr, x1);
        if (fabs(h) < allerr)
        {
            printf("\t\tAfter %d iterations, \n\t\tThe root of the given equation is = %.4f\n", itr, x1);
            return 0;
        }
        x0=x1;
    }
    printf("\t\t The required solution does not converge or iterations are insufficient\n");
    return 1;
}
