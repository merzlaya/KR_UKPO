#include "project1.h"

#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

int    is_expr(const char* s);
double _calc(const char* s, const char** p, enum err_expr* e);
double calculate(char* s, enum err_expr* err);

