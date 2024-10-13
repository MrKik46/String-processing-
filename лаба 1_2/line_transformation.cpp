#include <iostream>
int line_transformation(char* line, int line_length) {
	char letter;
	if ((line_length - 1) % 2 == 0) {
		for (int i = 0; i < line_length / 2; i++) {
			letter = line[i];
			line[i] = line[line_length - i - 2];
			line[line_length - i - 2] = letter;
		}
	}

	for (int i = 0; i < line_length - 1; i++) {
		if (line[i] == '+' or line[i] == '-') {
			for (int j = line_length; j > i; j--) {
				line[j + 1] = char(line[j]);
			}
			if (line[i] == '+')
				line[i + 1] = '+';
			else
				line[i + 1] = '-';
			i++;
			line_length++;
		}

		if (int(line[i]) > 47 and int(line[i]) < 58) {
			for (int j = i; j < line_length - 1; j++) {
				line[j] = line[j + 1];
			}
			line_length--;
			i--;
			line[line_length - 1] = '\0';
		}
	}

	return line_length;
}

void show_line(char* line, int line_length) {
	for (int i = 0; i < line_length; i++) {
		std::cout << line[i];
	}
	std::cout << std::endl;
}
