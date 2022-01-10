#pragma once


class FuncClass {
public:
	char* sdvig(char* iz) {
		int i = 0, j = 0;
		char* s = new char[16];
		if (iz[0] == '\0')
			return iz;
		while (iz[i++] != '\0') {
			if (iz[i] != ' ') {
				s[j] = iz[i];
				j++;
			}
		}
		iz = s;
		s[i] = '\0';
		return s;
	}
};
