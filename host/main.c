/*
 * main.c
 *
 *  Created on: Jun 12, 2024
 *      Author: athul-muralidhar
 */


#include <stdio.h>

int main() {

	float num1, num2, num3,avg;

	printf("please enter num1:");
	scanf("%f", &num1);

	printf("\nplease enter num2:");
	scanf("%f", &num2);

	printf("\nplease enter num3:");
	scanf("%f", &num3);

	avg = (num1 + num2 + num3) / 3;

	printf("\nresult: %f", avg);

	return 0;
}
