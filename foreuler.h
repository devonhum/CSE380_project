typedef double (*deriv_f)(double, double);
void ivp_euler(deriv_f f, double y, int step, int end_t);
void analytic();
double cooling(double t, double temp);
