#include "Library.h" 
 string to_lower(string s) {
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
	return s;
}

