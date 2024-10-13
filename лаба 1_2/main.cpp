#define _CRT_SECURE_NO_WARNINGS
#include "line_transformation.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

int task1() {
	char line[100];
	char letter1;
	int line_length = 0;

	while (true) {
		letter1 = getchar();
		if (letter1 == EOF) {
			break;
		}
		line[line_length] = letter1;
		line_length++;
	}

	line_length = line_transformation(line, line_length);
	show_line(line, line_length);

	return 0;
}

int task2() {
	char line[100];
	int line_length = 0;

	fgets(line, 100, stdin);
	line_length = strlen(line);

	line_length = line_transformation(line, line_length);
	show_line(line, line_length);

	return 0;
}

int task3() {
	char line[100] = {};
	int line_length = 0;

	FILE* file = fopen("myline.txt", "r");
	
	if (file) {
		fgets(line, 100, file);
		line_length = strlen(line);
	}

	else {std::cout << "File is corrupted" << std::endl;}
	
	line_transformation(line, line_length);
	fclose(file);

	FILE* file2 = fopen("myline.txt", "w");
	fputs(line, file2);
	fclose(file2);

	return 0;
}


int  main() {
	task1();
	task2();
    task3();
}