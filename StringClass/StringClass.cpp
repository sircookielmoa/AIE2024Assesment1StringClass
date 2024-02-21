#include "string.h"

#include <iostream>



int main()
	{
		//std::string s = ";
	//boom
		//std::cout << s << std::endl;
	String s = "POOPy bumhole";
	String s2 = s;

	s.WriteToConsole();
	s.ToLower();
	s.WriteToConsole();
	//s.Append(" again. ");

	std::cout << s.CharacterAt(1) << std::endl;
	std::cout << s.CStr() << std::endl;
	}
