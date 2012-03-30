#using <mscorlib.dll>
#using <System.dll>
#include <iostream>
#include <stdlib.h>
#using "System.Xml.dll"
#include <string>

namespace GoofTwitter
{
	class myGoofTwitter
	{
	public:
		static _declspec(dllexport)  void UserNameDescription();
		static _declspec(dllexport)  void UserNameDescription(std::string);
	};
}