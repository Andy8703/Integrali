/** \file main.c
	\brief Numeric integration of a polynomial
	\author Andrea Rivano

	first version of this software; all the functions are in this file
*/

/*! \mainpage
 *
 * \section intro_sec Introduction
 *
 * This is a software in C language for calculating numerical integration by adopting different techniques
 *
 * \section install_sec Installation
 *
 *
 *
 * etc...
 */

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "mathf.h"

 /*! \brief the main function

	 here we define the polynomial, set the integration range and set the number of equally spaced intervals in which the range should be divided
	 the points delimiting the intervals are defined and then the integration is finalized

 */
int main() {
	srand(time(NULL));
	/* setting all the parameters */
	float fcoeff[4] = { -10.0,1.0,0.0,2.0 };	/* the polynomial (-10 + x + 2x^3) */

	float integ1, integ2;

	for (int j = 0; j < 10; j++)
	{
		float xmin = rand()%100; 						/* the integration range */
		float xmax = rand()%100 + 100;
		int intervals = rand() % 1000000;
		int i;
		float in = xmin;
		float gap = (xmax - xmin) / (float)intervals;
		float* fvalues = NULL;

		/* this array will store the (steps+1) values of the polynomial that are delimiting the equally spaced intervals*/
		fvalues = (float*)malloc(sizeof(float) * (intervals + 1));
		if (fvalues == NULL) {
			printf("\nERROR: cannot allocate memory\n");
			exit(-1);
		}

		/* to get the value of the polynomial at the different points that are delimiting the intervals */
		for (i = 0; i <= intervals; i++) {
			fvalues[i] = Polynomial(fcoeff, 4, in);
			in += gap;
		}

		integ1 = 0.;
		integ2 = 0.;

		/* to compute the integral according to the rectangular rule */
		Rectangular(fvalues, intervals + 1, gap, &integ1, &integ2);
		printf("\nRectangular rule - The integral between %f and %f is in the interval: [%f,%f]\n", xmin, xmax, integ1, integ2);

		/* to compute the integral according to the trapezoidal rule */
		integ1 = Trapezoidal(fvalues, intervals + 1, gap);
		printf("\nTrapezoidal rule - The integral between %f and %f is : %f\n", xmin, xmax, integ1);

		printf("%i\n", intervals);

		/* deallocation */
		if (fvalues != NULL)
			free(fvalues);
	}	

	return 0;
}