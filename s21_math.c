#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) x *= -1;
  return x;
}

long double s21_fabs(double x) {
  if (x == S21_INF || x != x) return x;
  if (x == -S21_INF) return -x;
  if (x < 0) x *= -1;
  return x;
}

long double s21_ceil(double x) {
  if (x == S21_INF || x == -S21_INF || x != x) return x;
  int i = 0;
  long double result;
  long long int xxx = x;
  double xx = x;
  if (x <= 0) {
    if (xxx < LONG_LONG_INT_MIN) {
      result = x;
    } else {
      result = xxx;
    }
  }
  if (x > 0) {
    if (xxx < LONG_LONG_INT_MIN) {
      result = x;
    } else {
      while (xx > 1) {
        xx = xx / 10;
        i++;
      }
      if (i > 15) {
        result = x;
      } else {
        xx = x - xxx;
        for (; 20 - i > 0; i++) xx = xx * 10;
        xxx = xx;
        if (xxx > 0) {
          xxx = x;
          result = xxx + 1;
        } else {
          xxx = x;
          result = xxx;
        }
      }
    }
  }
  return result;
}

long double s21_floor(double x) {
  if (x == S21_INF || x == -S21_INF || x != x) return x;
  int i = 0;
  long double result;
  long long int xxx = x;
  double xx = x;
  if (x >= 0) {
    if (xxx > LONG_LONG_INT_MIN) {
      result = xxx;
    } else {
      result = x;
    }
  }
  if (x < 0) {
    if (xxx > LONG_LONG_INT_MIN) {
      while (xx < -1) {
        xx = xx / 10;
        i++;
      }
      if (i > 15) {
        result = x;
      } else {
        xx = x + (-xxx);
        for (; 17 - i > 0; i++) xx = xx * 10;
        xxx = xx;
        if (xxx < 0) {
          xxx = x;
          result = xxx - 1;
        } else {
          xxx = x;
          result = xxx;
        }
      }
    } else {
      result = x;
    }
  }
  return result;
}

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (x != x || y != y) result = S21_NAN;
  if ((x == S21_INF) || (x == -S21_INF)) result = S21_NAN;
  if (s21_fabs(y) < S21_EPS) result = S21_NAN;
  if ((y == S21_INF) || (y == -S21_INF)) {
    result = x;
  } else {
    if (y < 0) y *= -1;
    if (x < 0) {
      x *= -1;
      result = -1 * (x - y * (s21_floor(x / y)));
    } else {
      result = x - y * (s21_floor(x / y));
    }
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1;
  long double temp = 1;
  long double i = 1;
  int flag = 0;
  if (x < 0) {
    x = -x;
    flag = 1;
  }
  while (s21_fabs(result) > S21_EPS) {
    result = result * x / i;
    temp = temp + result;
    if (temp > LONG_LONG_INT_MAX) {
      temp = S21_INF;
      break;
    }
    i++;
  }
  if (flag == 1) {
    if (temp > LONG_LONG_INT_MAX) {
      temp = 0;
    } else {
      temp = 1. / temp;
    }
  }
  if (temp > LONG_LONG_INT_MAX) {
    return S21_INF;
  }
  return temp;
}

long double s21_log(double x) {
  int ex_pow = 0;
  double result = 0;
  double compare = 0;
  if (x == S21_INF) {
    result = S21_INF;
  } else if (x == 0) {
    result = -S21_INF;
  } else if (x < 0) {
    result = S21_NAN;
  } else if (x == 1) {
    result = 0;
  } else {
    for (; x >= S21_EXP; ex_pow++) {
      x = x / S21_EXP;
    }
    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }
  return (result + ex_pow);
}

long double s21_sqrt(double x) {
  long double mid;
  if (x != x) {
    mid = S21_NAN;
  } else if (x == S21_INF) {
    mid = S21_INF;
  } else if (x < 0.0) {
    mid = S21_NAN;
  } else {
    long double left = 0.0;
    long double right;
    if (x > 1.0) {
      right = x;
    } else {
      right = 1.0;
    }
    mid = (left + right) / 2;
    while ((mid - left) > S21_EPS) {
      if (mid * mid > x) {
        right = mid;
      } else {
        left = mid;
      }
      mid = (left + right) / 2;
    }
  }
  return mid;
}

long double s21_pow(double x, double y) {
  long double result = 0;
  int bag = 0;
  if ((x == 0) && (y != y)) {
    result = S21_NAN;
    bag = 1;
  }
  if ((x == 0) && (y < 0)) {
    result = S21_INF;
    bag = 1;
  }
  if ((x == S21_INF) && (y < 0)) {
    result = 0;
    bag = 1;
  }
  if ((x == -1) && (y == -S21_INF)) {
    result = 1;
    bag = 1;
  }
  if (y == 0) {
    result = 1;
    bag = 1;
  }
  if (bag == 0) {
    if (x == 0) {
      result = 0;
    } else {
      if (x < 0) {
        result = s21_exp(y * s21_log(-x));
        if (s21_fmod(y, 2) != 0) {
          result = result * -1;
        }
      } else {
        result = s21_exp(y * s21_log(x));
      }
    }
  }
  return result;
}

long double s21_sin(double x) {
  long double result = 0.0;

  if (x == S21_INF || x != x) {
    result = S21_NAN;
  } else {
    if (s21_fabs(x) > 2.0 * S21_PI) {
      if (x > 0.0) x = s21_fmod(s21_fabs(x), 2.0 * S21_PI);
      if (x < 0.0) x = -1 * s21_fmod(s21_fabs(x), 2.0 * S21_PI);
    }

    int n = 0;
    long double series_count = x;
    result = series_count;

    if (x == 0.0) {
      result = 0.0;
    } else {
      while (s21_fabs(series_count) > S21_EPS) {
        series_count *= -1 * (x * x) / (4 * n * n + 10 * n + 6);
        n++;
        result += series_count;
      }
    }
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 1.0;

  if (x == S21_INF || x != x) {
    result = S21_NAN;
  } else {
    if (s21_fabs(x) > (2.0 * S21_PI)) {
      double q = s21_fmod(s21_fabs(x), 2.0 * S21_PI);
      if (x > 0.0) x = q;
      if (x < 0.0) x = -q;
    }

    int n = 1;
    long double series_count = 1.0;

    while (s21_fabs(series_count) > S21_EPS) {
      series_count *= -(x * x) / (4 * n * n - 2 * n);
      n++;
      result += series_count;
    }
  }

  return result;
}

long double s21_tan(double x) {
  long double result = 0.0;

  if (x == S21_INF || x != x) {
    result = S21_NAN;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }

  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  int sign, bag = 0;
  if (x != x) {
    result = x;
    bag = 1;
  }
  if (x == S21_INF || x == -S21_INF) {
    result = x < 0 ? -S21_PI_2 : S21_PI_2;
    bag = 1;
  }
  if (x == 1) {
    result = 0.7853981633974483L;
    bag = 1;
  }
  if (x == -1) {
    result = -0.7853981633974483L;
    bag = 1;
  }
  if (bag != 0) return result;
  if (x >= 0) {
    sign = 1;
  } else {
    x *= -1;
    sign = -1;
  }
  if (x < 1 && x > -1) {
    for (int i = 0; i < 5000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else {
    for (int i = 0; i < 5000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    result = S21_PI * s21_fabs(x) / (2 * x) - result;
  }
  return result * sign;
}

long double s21_asin(double x) {
  long double asin = S21_NAN;
  if (x > 1 || x < -1) return asin;
  if (x == 1 || x == -1) asin = S21_PI / (2 * x);
  if (x > -1 && x < 1) asin = S21_PI / 2 - s21_acos(x);
  return asin;
}

long double s21_acos(double x) {
  long double acos = S21_NAN;
  if (x < 1 && x >= 0) acos = s21_atan(s21_sqrt(1 - x * x) / x);
  if (x < 0 && x > -1) acos = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  if (x == 1) acos = 0;
  if (x == -1) acos = S21_PI;
  return acos;
}