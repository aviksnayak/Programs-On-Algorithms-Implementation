///Name : Avik S nayak
///Question:Use the power series expansion method to implement sqrt(x).
///Course : CSC206
///Fall 2017

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{ //////Declaration of variables /////
   double x, n=0, m ,z,cnt = 0,mysqrt = 1,x1 = 1, temp=1.0,diff=0;// Accuracy of how close to the answer from Sqrt function
   int i = 1, flag = 0;
  ///////Asking User for Input/////////
   printf("\nEnter a number.(0 to exit) :");
   scanf("%lf",&n);
   if(n <= 0 )  // Exit the program if Input is Zero 
   { exit(0);}
    x = n;
    m = n;

   if(n>1)
    { // Divide by 4 until n < 1
        while (n > 1)
       	{  n = n/4;
  	   temp = temp * 2;
 	}
     }
   else
    { 
      while(n<=0.25)
       {  n = n*4;
          temp = temp / 2;
       }
    } 
/////////Value of x displayed/////////////
     printf("\n x = %lf ,", n);
///////////////////////////////////////////
   // Power series to estimate sqare root, the Taylor Series
   // sqrt(x) = 1 + 1/2(x-1) - 1/4(x-1)^2/2! + 3/8(x-1)^3/3! - 15/16(x-1)^4/4!
   // sqrt(1-x) = 1 - x/2 + 1/4(x-1)^2/2! - 3/8(x-1)^3/3! + 15/16(x-1)^4/4!
   // sqrt(1-x) = 1 - x/2 - x^2/4 - ... -{1*3*5...(2n-3)x^n/2*n*n!
///////////////Talor Series Calculation ////////////////////////////////////
while( flag == 0 ) 
   {
        x1 = ( x1 * (((2 * i) - 3) * (1-n)) / (2 * i));
        mysqrt = mysqrt + x1;
        i= i+1; 
    	 diff = x1; // Difference between successive terms items

        if(diff <0)   //makes diff positive if it is negetive
            diff= x1 * -1;
 	 if(diff <= 0.00000000000001)            // checks for accuracy , Exits the loop if the accuracy has been reached.
 	 {flag =1;}
  }
///////////////////////Printing Results////////////////////////////////////
printf("n = %d\n\n",i);
   printf("Using Library function :the square root of %.3lf is = %.15lf\n", x, sqrt(m));
   printf("Using Talor Series     :the square root of %.3lf is = %.15lf\n", x, (mysqrt * temp));
   return 0;
}
