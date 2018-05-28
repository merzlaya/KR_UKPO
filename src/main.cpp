#include <iostream>
#include "project1.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(void) {

		setlocale(LC_CTYPE, ".1251");

		enum err_expr e;
		char          s[256];
		double        res, res_2;

		cout << "Введите арифметическое выражение" << endl;
		cin >> s;
		res = calculate(s, &e);
		res_2 = convert(res);
		switch (e) {
		case ERR_SUCCESS:
			printf("%lg\n\n", res);
			if (res_2 != (-1))
				printf("%lg\n\n", res_2);
			else
				puts("Ошибка конвертации!");
			break;
		case ERR_NONE_STR:
			puts("Строка пуста!");
			break;
		case ERR_DIV_BYZERO:
			puts("Деление на ноль!");
			break;
		case ERR_PARSE_NUMBER:
			puts("Ошибка при парсировании выражения.");
			break;
		case ERR_EXPR:
			puts("Арифметически не корректное выражение! ");
			break;
		}

		getchar();
		system("pause");
		return 0;
}
