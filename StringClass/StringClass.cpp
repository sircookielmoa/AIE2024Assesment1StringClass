#include "string.h"

#include <iostream>



int main()
	{
		//std::string s = ";
	//boom
		//std::cout << s << std::endl;
	
	String s1 = "";
	String s2 = "";
	
	s1.ReadFromConsole();
	s2.ReadFromConsole();

	s1.Append(s2);
	s1.ToLower();
	
	s1.WriteToConsole();

	std::cout << s1.CharacterAt(12) << std::endl;

	//std::size_t everyonePos = s1.Find(0, "stinky");
	//s2.ToLower();
	//s1.Append(s2);

	//std::cout << s1.CStr() << std::endl;
	//std::cout << everyonePos << std::endl;

	//s.ReadFromConsole();

	//s.WriteToConsole();
	//s2.WriteToConsole();
	//s.ToUpper();

	//std::cout << pageBreak.CStr() << std::endl;

	//std::cout << std::boolalpha;
	//std::cout << s.EqualTo(s2) << std::endl;

	//std::cout << s.CharacterAt(20) << std::endl;
	//std::cout << s.CStr() << std::endl;
	//std::cout << s2.CStr() << std::endl;
	}
