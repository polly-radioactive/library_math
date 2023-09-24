#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(testing_abs) {
  for (int x = -781254872; x < 781254873; x = x + 5999)
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(testing_fabs) {
  for (double x = -781254872.925698256; x < 781254873; x = x + 578246.721846412)
    ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_eq(s21_fabs(S21_INF), fabs(S21_INF));
  ck_assert_ldouble_eq(s21_fabs(-S21_INF), fabs(-S21_INF));
  ck_assert_ldouble_eq(s21_fabs(S21_EPS), fabs(S21_EPS));
  ck_assert_ldouble_eq(s21_fabs(-S21_EPS), fabs(-S21_EPS));
}
END_TEST

START_TEST(testing_ceil) {
  for (double x = -781254872.925698256; x < 781254873; x = x + 578246.721846412)
    ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  ck_assert_ldouble_eq(s21_ceil(1234567890123456789.0 * 1000000),
                       ceil(1234567890123456789.0 * 1000000));
  ck_assert_ldouble_eq(s21_ceil(-1234567890123456789.0 * 1000000),
                       ceil(-1234567890123456789.0 * 1000000));
  ck_assert_ldouble_eq(s21_ceil(1234567890123.00000001),
                       ceil(1234567890123.00000001));
  ck_assert_ldouble_eq(s21_ceil(1234567890123456.00000001),
                       ceil(1234567890123456.00000001));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_eq(s21_ceil(S21_INF), ceil(S21_INF));
  ck_assert_ldouble_eq(s21_ceil(-S21_INF), ceil(-S21_INF));
  ck_assert_ldouble_eq(s21_ceil(S21_EPS), ceil(S21_EPS));
  ck_assert_ldouble_eq(s21_ceil(-S21_EPS), ceil(-S21_EPS));
}
END_TEST

START_TEST(testing_floor) {
  for (double x = -781254872.925698256; x < 781254873; x = x + 578246.721846412)
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
  ck_assert_ldouble_eq(s21_floor(1234567890123456789.0 * 1000000),
                       floor(1234567890123456789.0 * 1000000));
  ck_assert_ldouble_eq(s21_floor(-1234567890123456789.0 * 1000000),
                       floor(-1234567890123456789.0 * 1000000));
  ck_assert_ldouble_eq(s21_floor(-1234567890123.00000001),
                       floor(-1234567890123.00000001));
  ck_assert_ldouble_eq(s21_floor(-1234567890123456.00000001),
                       floor(-1234567890123456.00000001));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_eq(s21_floor(S21_INF), floor(S21_INF));
  ck_assert_ldouble_eq(s21_floor(-S21_INF), floor(-S21_INF));
  ck_assert_ldouble_eq(s21_floor(S21_EPS), floor(S21_EPS));
  ck_assert_ldouble_eq(s21_floor(-S21_EPS), floor(-S21_EPS));
}
END_TEST

START_TEST(testing_fmod) {
  for (double x = -781254872.925698256, y = -1230.123; x < 781254873;
       x = x + 578246.721846412, y = y + 12.3)
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq_tol(s21_fmod(123.123, S21_INF), fmod(123.123, S21_INF),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-123.123, S21_INF), fmod(-123.123, S21_INF),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(123.123, -S21_INF), fmod(123.123, -S21_INF),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-123.123, -S21_INF),
                           fmod(-123.123, -S21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(S21_EPS, S21_EPS), fmod(S21_EPS, S21_EPS),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-S21_EPS, -S21_EPS),
                           fmod(-S21_EPS, -S21_EPS), 1e-6);
}
END_TEST

START_TEST(testing_exp) {
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(3.45678901234567890),
                           exp(3.45678901234567890), 1e-6);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_eq(s21_exp(S21_INF), exp(S21_INF));
  ck_assert_ldouble_eq(s21_exp(-S21_INF), exp(-S21_INF));
  ck_assert_ldouble_eq_tol(s21_exp(S21_EPS), exp(S21_EPS), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-S21_EPS), exp(-S21_EPS), 1e-6);
}
END_TEST

START_TEST(testing_log) {
  ck_assert_ldouble_eq_tol(s21_log(0.0001), log(0.0001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(3.45678901234567890),
                           log(3.45678901234567890), 1e-6);
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_eq(s21_log(S21_INF), log(S21_INF));
  ck_assert_ldouble_eq(s21_log(0), log(0));

  ck_assert_ldouble_nan(s21_log(-S21_INF));
}
END_TEST

START_TEST(testing_sqrt) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(3.45678901234567890),
                           sqrt(3.45678901234567890), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-0.1));
  ck_assert_ldouble_eq(s21_sqrt(S21_INF), sqrt(S21_INF));
}
END_TEST

START_TEST(testing_pow) {
  ck_assert_ldouble_eq_tol(s21_pow(0.12, 2.2), pow(0.12, 2.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(15, 2.5), pow(15, 2.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(8239751.123456789012345, 0.0001),
                           pow(8239751.123456789012345, 0.0001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0.0001), pow(0, 0.0001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 2), pow(-2, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 3), pow(-2, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -2), pow(-2, -2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -3), pow(-2, -3), 1e-6);
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq(s21_pow(123.123, S21_INF), pow(123.123, S21_INF));
  ck_assert_ldouble_eq(s21_pow(S21_INF, -1), pow(S21_INF, -1));
  ck_assert_ldouble_eq(s21_pow(123.123, -S21_INF), pow(123.123, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(-123.123, -S21_INF), pow(-123.123, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(-1, -S21_INF), pow(-1, -S21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(S21_EPS, S21_EPS), pow(S21_EPS, S21_EPS),
                           1e-6);
  ck_assert_ldouble_eq(s21_pow(0, 0), pow(0, 0));
  ck_assert_ldouble_eq(s21_pow(0, 1), pow(0, 1));
  ck_assert_ldouble_eq(s21_pow(0, -1), pow(0, -1));

  ck_assert_ldouble_nan(s21_pow(0, S21_NAN));
}
END_TEST

START_TEST(testing_sin) {
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(3.45678901234567890),
                           sin(3.45678901234567890), 1e-6);
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_nan(s21_sin(-S21_INF));
}
END_TEST

START_TEST(testing_cos) {
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(3.45678901234567890),
                           cos(3.45678901234567890), 1e-6);
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_INF));
  ck_assert_ldouble_nan(s21_cos(-S21_INF));
}
END_TEST

START_TEST(testing_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(3.45678901234567890),
                           tan(3.45678901234567890), 1e-6);
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_ldouble_nan(s21_tan(-S21_INF));
}
END_TEST

START_TEST(testing_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.0001), atan(0.0001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-17.3206), atan(-17.3206), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(3.45678901234567890),
                           atan(3.45678901234567890), 1e-6);
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF), atan(S21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-S21_INF), atan(-S21_INF), 1e-6);
}
END_TEST

START_TEST(testing_asin) {
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.0001), asin(0.0001), 1e-6);
  ck_assert_ldouble_nan(s21_asin(-17.3206));
  ck_assert_ldouble_nan(s21_asin(3.45678901234567890));
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_INF));
  ck_assert_ldouble_nan(s21_asin(-S21_INF));
}
END_TEST

START_TEST(testing_acos) {
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.0001), acos(0.0001), 1e-6);
  ck_assert_ldouble_nan(s21_acos(-17.3206));
  ck_assert_ldouble_nan(s21_acos(3.45678901234567890));
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(s21_acos(S21_INF));
  ck_assert_ldouble_nan(s21_acos(-S21_INF));
}
END_TEST

Suite *test_suite(void) {
  Suite *s;
  TCase *tc_test_abs;
  TCase *tc_test_fabs;
  TCase *tc_test_ceil;
  TCase *tc_test_floor;
  TCase *tc_test_fmod;
  TCase *tc_test_exp;
  TCase *tc_test_log;
  TCase *tc_test_sqrt;
  TCase *tc_test_pow;
  TCase *tc_test_sin;
  TCase *tc_test_cos;
  TCase *tc_test_tan;
  TCase *tc_test_atan;
  TCase *tc_test_asin;
  TCase *tc_test_acos;

  s = suite_create("Library tests");

  tc_test_abs = tcase_create("abs\n");
  tcase_add_test(tc_test_abs, testing_abs);
  suite_add_tcase(s, tc_test_abs);

  tc_test_fabs = tcase_create("fabs\n");
  tcase_add_test(tc_test_fabs, testing_fabs);
  suite_add_tcase(s, tc_test_fabs);

  tc_test_ceil = tcase_create("ceil\n");
  tcase_add_test(tc_test_ceil, testing_ceil);
  suite_add_tcase(s, tc_test_ceil);

  tc_test_floor = tcase_create("floor\n");
  tcase_add_test(tc_test_floor, testing_floor);
  suite_add_tcase(s, tc_test_floor);

  tc_test_fmod = tcase_create("fmod\n");
  tcase_add_test(tc_test_fmod, testing_fmod);
  suite_add_tcase(s, tc_test_fmod);

  tc_test_exp = tcase_create("exp\n");
  tcase_add_test(tc_test_exp, testing_exp);
  suite_add_tcase(s, tc_test_exp);

  tc_test_log = tcase_create("log\n");
  tcase_add_test(tc_test_log, testing_log);
  suite_add_tcase(s, tc_test_log);

  tc_test_sqrt = tcase_create("sqrt\n");
  tcase_add_test(tc_test_sqrt, testing_sqrt);
  suite_add_tcase(s, tc_test_sqrt);

  tc_test_pow = tcase_create("pow\n");
  tcase_add_test(tc_test_pow, testing_pow);
  suite_add_tcase(s, tc_test_pow);

  tc_test_sin = tcase_create("sin\n");
  tcase_add_test(tc_test_sin, testing_sin);
  suite_add_tcase(s, tc_test_sin);

  tc_test_cos = tcase_create("cos\n");
  tcase_add_test(tc_test_cos, testing_cos);
  suite_add_tcase(s, tc_test_cos);

  tc_test_tan = tcase_create("tan\n");
  tcase_add_test(tc_test_tan, testing_tan);
  suite_add_tcase(s, tc_test_tan);

  tc_test_atan = tcase_create("atan\n");
  tcase_add_test(tc_test_atan, testing_atan);
  suite_add_tcase(s, tc_test_atan);

  tc_test_asin = tcase_create("asin\n");
  tcase_add_test(tc_test_asin, testing_asin);
  suite_add_tcase(s, tc_test_asin);

  tc_test_acos = tcase_create("acos\n");
  tcase_add_test(tc_test_acos, testing_acos);
  suite_add_tcase(s, tc_test_acos);

  return s;
}

int main() {
  int sucsess = 0;
  Suite *s;
  SRunner *runner;
  s = test_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  sucsess = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (sucsess == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}