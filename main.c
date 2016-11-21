#include <stdio.h>
#include <math.h>
#include "foreuler.h"

int main()
{
	analytic();
	ivp_euler(cooling, 100, 2, 100);
	ivp_euler(cooling, 100, 5, 100);
	ivp_euler(cooling, 100, 10, 100);
 
	return 0;
}
