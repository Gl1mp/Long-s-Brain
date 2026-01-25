#include <stdio.h>

int m_strlen_1(const char* str) {
	int count = 0;
	while (*str) {
		count++;
		str++;
	}
	return count;
}

int m_strlen_2(const char* str) {
	const char* h = str;
	while(*str) str++;
	return str - h;
}

int m_strlen_3(const char* str) {
	if (*str) {
		return 1 + m_strlen_3(str+1);
	}
	return 0;
}

int main() {
	int len = m_strlen_3("teststr");
	printf("%d", len);
}