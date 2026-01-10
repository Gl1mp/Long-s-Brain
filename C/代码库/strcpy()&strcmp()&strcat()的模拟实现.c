char* m_strcpy_1(char* destination, const char* source) {
	char* h = destination;
	while (*source) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = *source;
	return h;
}
char* m_strcpy_2(char* dest, const char* src) {
	char* ret = dest;
	assert(dest && src);
	while ((*dest++ = *src++)) {
		;
	}
	return ret;
}
char* m_strcat_1(char* dest, const char* src) {
	assert(dest && src);
	char* ret = dest;
	while (*dest) dest++;
	while ((*dest++ = *src++)) {
		;
	}
	return ret;
}
int m_strcmp_1(const char* str1, const char* str2) {
	assert(str1 && str2);
	while (*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return (*(unsigned char*)str1 - *(unsigned char*)str2);
}