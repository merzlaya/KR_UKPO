#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef KP_UKPO_H //LIBAPP_CALC_HPP
#define KP_UKPO_H //LIBAPP_CALC_HPP

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;

//коды ошибок
enum err_expr {
	ERR_SUCCESS,      //нет ошибки
	ERR_NONE_STR,     //строка пуста
	ERR_DIV_BYZERO,   //деление на ноль
	ERR_PARSE_NUMBER, //ошибка при парсировании выражения
	ERR_EXPR          //другие ошибки: скобки, иные символы...
};

int    is_expr(const char* s);
double _calc(const char* s, const char** p, enum err_expr* e);

//вычисление мат-выражений из строки
double calculate(char* s, enum err_expr* err) {
	char* a, *b;
	enum  err_expr e = ERR_SUCCESS;
	const char*    p = NULL;
	double         n = 0.0;

	if (*s && is_expr(s)) {
		a = s;
		while (*a && !isspace(*a))
			++a;
		for (b = a; *a; *a = *(++b)) {
			if (!isspace(*b))
				++a;
		}

		if (*s)
			n = _calc(s, &p, &e);
		else
			e = ERR_NONE_STR;
	}
	else
		e = (*s) ? ERR_EXPR : ERR_NONE_STR;

	if (err != NULL)
		*err = e;
	return n;
}

//проверка скобок на правильность расстоновки
int is_expr(const char* s) {
	int n = 0;
	for (; *s; ++s) {
		if (*s == '(')
			++n;
		else if (*s == ')') {
			if (--n < 0)
				break;
		}
	}
	return (n == 0);
}

// рекурсивное вычисление мат-выражений из строки
double  _calc(const char* s, const char** p, enum err_expr* e) {
	int    neg;
	char   c, c1;
	char*  i;
	const char* o;
	double k, v, n = 0.0;

	if ((*s == '(') || (*s == '-' && *(s + 1) == '(')) {
		neg = (*s == '-');
		n = _calc(s + (1 + neg), &o, e);
		if (*e != ERR_SUCCESS)
			return 0.0;
		s = o;
		if (neg)
			n = 0.0 - n;
	}
	else {
		n = strtod(s, &i);
		if (s == i) {
			*e = ERR_PARSE_NUMBER;
			return 0.0;
		}
		s = i;
	}

	while (*s && (*s != ')')) {
		c = *s++;
		if (!*s) {
			*e = ERR_EXPR;
			return 0.0;
		}

		if (*s == '(') {
			k = _calc(s + 1, &o, e);
			if (*e != ERR_SUCCESS)
				return 0.0;
			s = o;
		}
		else {
			k = strtod(s, &i);
			if (s == i) {
				*e = ERR_PARSE_NUMBER;
				return 0.0;
			}
			s = i;
		}

		switch (c) {
		case '*':
			n *= k;
			break;
		case '/':
			if (k == 0.0) {
				*e = ERR_DIV_BYZERO;
				return 0.0;
			}
			n /= k;
			break;
		case '+':
		case '-':

			if ((*s == '*') || (*s == '/')) {
				v = k;
				while (*s && (*s != ')')) {

					c1 = *s;
					if ((c1 == '+') || (c1 == '-'))
						break;

					++s;
					if (*s == '(') {
						k = _calc(s + 1, &o, e);
						if (*e != ERR_SUCCESS)
							return 0.0;
						s = o;
					}
					else {
						k = strtod(s, &i);
						if (s == i) {
							*e = ERR_PARSE_NUMBER;
							return 0.0;
						}
						s = i;
					}

					if (c1 == '/') {
						if (k == 0.0) {
							*e = ERR_DIV_BYZERO;
							return 0.0;
						}
						v /= k;
					}
					else if (c1 == '*')
						v *= k;
				}
				k = v;
			}

			if (c == '+')
				n += k;
			else if (c == '-')
				n -= k;

			if (*s == ')') {
				*p = s + 1;
				return n;
			}
			break;
		}
	}

	if (*s == ')')
		*p = s + 1;
	return n;
}

double convert(int chisloV10SS) {
	double razrjadChislaV2SS = 0;//Разряд двоичного числа
	double chisloV2SS = 0;//Искомое число в двоичной CC
	if (chisloV10SS < 0) return -1;
	else {
		while (chisloV10SS > 1)
		{
			chisloV2SS += (chisloV10SS % 2)*pow(10, razrjadChislaV2SS);//Присваиваем i-тому разряду остаток от деления
			chisloV10SS /= 2;
			razrjadChislaV2SS++;
		}

		chisloV2SS += chisloV10SS * pow(10, razrjadChislaV2SS);
		return chisloV2SS;
	}
}

#endif
