
#include "string.h"

#include <iostream>
#include "Windows.h"



int main()
	{
		SetConsoleTitleA("Ghost House");
		//std::string s = "";
		//std::cout << s << std::endl;
	

		String s1 = "";
		String s2 = "";
		
		s1.ReadFromConsole();
		s2.ReadFromConsole();
		
		//s1.Replace(s1, s2);
		//s1.ToLower();
		
		s1.Append(s2).CStr();
		

		//s1.ReadFromConsole();

		//s1.WriteToConsole();
		//s2.WriteToConsole();
		//s1.ToUpper();

		//std::cout << pageBreak.CStr() << std::endl;

		std::cout << std::boolalpha;
		std::cout << s1.EqualTo(s2) << std::endl;

		std::cout << s1.CharacterAt(20) << std::endl;
		std::cout << s1.CStr() << std::endl;
		std::cout << s2.CStr() << std::endl;



	}
