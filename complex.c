/* 
 * created wykys 2015
 * Library for computing with complex numbers in C.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <math.h>

typedef struct
{
	double re;
	double im;
} complex;

double comp_abs(complex a)
{
	return sqrt(a.re*a.re + a.im*a.im);
}

double comp_alpha(complex a)
{
	return asin(a.im/comp_abs(a));
}

complex comp_add(complex a, complex b)
{
	complex y;
	y.re = a.re + b.re;
	y.im = a.im + b.im;
	return y;
}

complex comp_mul(complex a, complex b)
{
	double z1 = comp_abs(a);
	double z2 = comp_abs(b);
	double alpha1 = comp_alpha(a);
	double alpha2 = comp_alpha(b);
	double z = z1*z2;
	double alpha = alpha1+alpha2;
	complex y;
	y.re = z * cos(alpha);
	y.im = z * sin(alpha);
	return y;
}

complex comp_div(complex a, complex b)
{
	double z1 = comp_abs(a);
	double z2 = comp_abs(b);
	double alpha1 = comp_alpha(a);
	double alpha2 = comp_alpha(b);
	double z = z1/z2;
	double alpha = alpha1-alpha2;
	complex y;
	y.re = z * cos(alpha);
	y.im = z * sin(alpha);
	return y;
}

void comp_print(complex a)
{
	printf("\nre = %f\nim = %f\n", a.re, a.im);
}

void comp_print_alg(complex a)
{
	printf("%.3f + %.3fj\n", a.re, a.im);
}

void comp_print_geo(complex a)
{
	double z, alpha;
	z = comp_abs(a);
	alpha = comp_alpha(a);
	alpha = (alpha * 180.0) / M_PI;
	printf("%.3f * [cos(%.0f°) + sin(%.0f°)j]\n", z, alpha, alpha);
}

int main(void)
{
	complex a = { 1, 2 };
	complex b = { 3, 4 };

	comp_print_alg(a);
	comp_print_geo(a);
	comp_print_alg(b);
	comp_print_geo(b);
	printf("==============================\n");

	comp_print_alg(comp_add(a, b));
	comp_print_geo(comp_add(a, b));

	comp_print_alg(comp_mul(a, b));
	comp_print_geo(comp_mul(a, b));

	comp_print_alg(comp_div(a, b));
	comp_print_geo(comp_div(a, b));


	return 0;
}