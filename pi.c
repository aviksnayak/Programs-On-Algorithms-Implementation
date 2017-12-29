///////////////////////////////////////////////////////////////////////////////////////////////
//Avik Nayak
//CSC206 - Fall 2014, 
//Question :To use four numerical integration method to compute PI
////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

////////////////////////////////Variable Declaration//////////////////////////////////////
    int bi,cnt =0 ,j;
    double h=0,x=0,funci=0,pi=0,prevpi=0,temp=0,sum=0,lb=0, ub=1,xnext=0,pix, y= 0;


///////////////////Printing Actual Value of Pi ////////////////////////////////////////////////

printf("\nReal Value of Pi is = 3.141592653589793238462643383279502884197169399375105820974944592307816406286 \n");

////////////////////////////Calculating values of Pi using all the 4 Rules//////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Trapezoidal rule
//Value of Pi using Trapezoidal rule
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  /* Trapezoidal rule: Sum of [(xi-xi-1) * ((f(xi-1) + f(xi)) /2) ] where 1<=i<=n (no of intervals)
     PI: f(x) = 4 / (1+(x*x))
  */

     
while ((pi-prevpi)>=0)
     {
        cnt= cnt + 1; // Interval count
        prevpi=pi;
        pi=0;
        sum=0;
        j= 1;
        temp=(1.0/(1.0+(lb*lb)))+(1.0/(1.0+(ub*ub))); 
       while(j<=cnt-1)                     
        {
            x = ((((double)j) *((ub-lb)/cnt)) + lb  );
            sum= sum +(1.0 / ( ((x) * (x)) + 1.0 )) ;
            j++;
        }
        sum=sum*2;                      
        sum=sum + temp;                      
        pi= 2*sum*((ub-lb)/cnt);                 
      }

    printf("\nThe value of pi using Trapezoidal method is= %1.20lf\n",pi);
    printf("The number of intervals used is %d\n",cnt-1);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Mid point Rule 
//Value of Pi using Midpoint Rule 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Variable initaialisation / //
pi=0;temp=0;x=0;j=1;
    
    /* Midpoint rule: Sum of [(xi-xi-1) * f((xi-1 + xi)/2)] where 1<=i<=n (no of intervals)
     PI: f(x) = 4 / (1+(x*x))
     So, PI= h * 4 * [f((a + (a+h))/2) + f(((a+h) + (a+2h))/2) + .... + f(((a+(k-1)h) + (a+kh))/2)]
     */

    temp = ((ub-lb)/cnt);
    while(j<= cnt)
    {
        x = lb + (((double)j) * temp );
        xnext = lb + (((double)(j-1)) * temp );
        pi = pi + (1 / (1 + (((x+xnext)/2) * ((x + xnext)/2)))); 
        j = j + 1 ;
    }
    
   
     pi=pi*temp*4.0;
    
    printf("\nThe value of pi using Midpoint method is   = %1.20lf\n",pi);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Simpson rule 
//Value of Pi using Simpson rule 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //Initialisation of variables  
 x=0,xnext=0,pi=0, j = 1;

    /* Simpson's rule: Sum of [((xi-xi-1)/6) * (f(xi-1) + (4*f((xi-1+xi)/2)) + f(xi)) ] where 1<=i<=n (no of intervals)
     PI: f(x) = 4 / (1+(x*x)) So, PI= h * 4 * (1/6) * [f(a) + (2*f(a+h)) + (4*(f((a + (a+h))/2))) + (2*f(a+2h)) + .... + f(b)]
     = h * 2 * (1/3) * [f(a) + f(b) + (2* {f(a+h) + f(a+2h) + ....+f(a+(n-1)*h)}) + (4*[f((a + (a+h))/2) + f(((a+h) +
       (a+2h))/2) + .... + f(((a+(k-1)h) + (a+kh))/2)])]
     */
    
    pi=(1/(1+(lb*lb)))+(1/(1+(ub*ub)));                    
    

    
    while(j<=cnt)
    {       
        x = lb + (temp* ((double)j) );
        xnext = lb + (temp *((double)(j-1)));
        if(j<cnt) 
        {
           pi= pi + ((1 / (1 + (x * x)))*2);   
        }
       pi=pi + ( (1 / (1 + (((x+xnext)/2) * ((x+xnext)/2)))) * 4);
       j =  j++;

       
    }
      
     pi= ((pi*temp*2)/3);
    
    printf("\nThe value of pi using Simson's method is  = %1.20lf\n",pi);
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Monte Carlo Method 
//Value of Pi using Monte Carlo Method 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Initialisation////
 j = 0 ,pix = 100000000 , temp = 0,x=0 ,pi =0 ,xnext =0 ;
  
/*In order to compute the area of a complicated domain D, Monte Carlo method picks random points over some simple domain D’ which 
is a superset of  D, checks whether each point is within D, and estimates the area of D as the area of D’ multiplied by the fraction of
 points falling within D */

  srand ( time(NULL) );

   while(j < pix)
   {
        
        x = ((double) rand() / ((double)RAND_MAX + 1)); // random x=[0,1]
       
        y = ((double) rand() / ((double)RAND_MAX + 1) * 4.0); // random y=[0,4]
        
        xnext = (double)(4.0 / (1.0 + (x*x)));
       
       if(y <= xnext) 
        {
         temp = temp + 1; //To Check if the point falls in PI curve area .
        }

    j++;
    }

    
  pi = ( ((double)temp /(double)pix) * 4.0); // PI = (pt/total) * 4.0 where area of D' is 4.0
 printf("\nThe value of pi using Monte Carlo method with %.0f random points is: %1.20lf\n",pix, pi);

    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






return 0;

}




