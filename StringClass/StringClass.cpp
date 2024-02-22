#include "string.h"

#include <iostream>



int main()
	{
		//std::string s = ";
	//boom
		//std::cout << s << std::endl;
	
	String s = "POOP";
	String s2 = "POOP";
	String pageBreak = "_______________________";

	s.WriteToConsole();
	s2.WriteToConsole();
	//s.ToUpper();
	//s2.ToLower();

	//std::cout << pageBreak.CStr() << std::endl;

	std::cout << std::boolalpha;
	std::cout << s.EqualTo(s2) << std::endl;

	//std::cout << s.CharacterAt(20) << std::endl;
	//std::cout << s.CStr() << std::endl;
	//std::cout << s2.CStr() << std::endl;
	}
