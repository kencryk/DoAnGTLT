#include "Library.h" 
 string to_lower(string s) {
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
	return s;
}
 string to_upper(string s) {
	 for (int i = 0; i < s.length(); i++)
		 if (s[i] >= 'a' && s[i] <= 'z')
			 s[i] = s[i] - 32;
	 return s;
 }
 void SetColor(WORD color)
 {
	 HANDLE hConsoleOutput;
	 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	 CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	 GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	 WORD wAttributes = screen_buffer_info.wAttributes;
	 color &= 0x000f;
	 wAttributes &= 0xfff0;
	 wAttributes |= color;
	 SetConsoleTextAttribute(hConsoleOutput, wAttributes);
 }



