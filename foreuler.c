/* ----------------------------------------------------------------------------
 * 
 * A standalone C routine for computing the numerical approximation of a first-
 * order ordinary differential equation using forward Euler's method. 
 *
 * with code from Rosetta Code for C
 * 
 * CSE 380 
 * ----------------------------------------------------------------------------
 *
 *  foreuler.c
 * ---------------------------------------------------------------------------- */
#include <stdio.h>
#include <math.h>

/* Declare an arbitrary function as a pointer */
typedef double (*deriv_f) (double, double);

/* defines a term to print width and precision of output results
* to a tabular format */
#define FMT " %7.3f"

/* Define initial value problem (IVP) with Euler solution */
void ivp_euler(deriv_f f, double y, int step, int end_t)
/* deriv_f f is a pointer to an arbitrary function that is passed later. Here, 
 * it is the cooling() function defined below */
{
	int t = 0;

	printf(" Step %2d: ", (int)step); /* (int)step is an example of type casting */
	do {
		if (t % 10 == 0) printf(FMT, y);
		y += step * f(t, y);
	} while ((t+=step) <= end_t);
	printf("\n");
}

/* Define a function to return the analytic solution at time t */
void analytic()
{
	double t;
	printf(" Time: ");
	for (t = 0; t <= 100; t += 10) printf(" %7g", t);
	printf("\nAnalytic: ");

	for (t = 0; t <= 100; t+= 10)
		printf(FMT, 20 + 80 * exp(-0.07 * t));
	printf("\n");
}

/* define the function to compute the derivative */
double cooling(double t, double temp)
{
	return -0.07 * (temp - 20);
}

