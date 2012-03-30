#using <mscorlib.dll>
#using <System.dll>
#include <iostream>
#include <stdlib.h>
#using "System.Xml.dll"

namespace GoofTwitter
{
	class myGoofTwitter
	{
	public:
		static _declspec(dllexport)  void UserNameDescription();
		//static _declspec(dllexport)  void UserNameDescription(String^);
	};
}