#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdio.h>

#define LONG_LONG_INT_MIN -9223372036854775800
#define LONG_LONG_INT_MAX 9223372036854775800
#define S21_PI 3.14159265358979323846264338327950288
#define S21_EXP 2.7182818284590452353602874713526624
#define S21_PI_2 1.57079632679489661923132169163975144
#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_EPS 1e-7

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_pow(double x, double y);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);

#endif  // S21_MATH_H