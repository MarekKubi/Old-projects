#pragma once

#include"ode_solver.h"
#include <cmath>

matrix ff0T(matrix, matrix = NAN, matrix = NAN);
matrix ff1T(matrix, matrix = NAN, matrix = NAN);
matrix ff2T(matrix, matrix = NAN, matrix = NAN);
matrix ff3TW(matrix, matrix = NAN, matrix = NAN);
matrix ff3TZ(matrix, matrix = NAN, matrix = NAN);
matrix ff4T(matrix, matrix = NAN, matrix = NAN);
matrix ff6T(matrix, matrix = NAN, matrix = NAN);
matrix ff4Tscal(matrix, matrix = NAN, matrix = NAN);
matrix Gf4T(matrix, matrix = NAN, matrix = NAN);
matrix Gf4spa(matrix, matrix = NAN, matrix = NAN);
matrix Gf4spr(matrix, matrix = NAN, matrix = NAN);
matrix reset(matrix, matrix = NAN, matrix = NAN);
matrix Gf4N(matrix, matrix = NAN, matrix = NAN);
matrix Hf4T(matrix, matrix = NAN, matrix = NAN);
matrix ff0R(matrix, matrix = NAN, matrix = NAN);
matrix ff1R(matrix, matrix = NAN, matrix = NAN);
matrix ff2R(matrix, matrix = NAN, matrix = NAN);
matrix ff3R(matrix, matrix = NAN, matrix = NAN);
matrix ff4Rgrad(matrix, matrix = NAN, matrix = NAN);
matrix ff4Rh0(matrix, matrix = NAN, matrix = NAN);
matrix ff4RJ(matrix, matrix = NAN, matrix = NAN);
matrix fR6(matrix, matrix = NAN, matrix = NAN);
matrix df0(double, matrix, matrix = NAN, matrix = NAN);
matrix df1(double, matrix, matrix = NAN, matrix = NAN);
matrix df2(double, matrix, matrix = NAN, matrix = NAN);
matrix df3(double, matrix, matrix = NAN, matrix = NAN);
matrix df6(double, matrix, matrix = NAN, matrix = NAN);

