// RestThing.cpp : Defines the exported functions for the DLL application.
//
#using <mscorlib.dll>
#include "stdafx.h"
#include <string>
#using "System.Xml.dll"
#include "RestThing.h"

using namespace System;
using namespace System::Net;
using namespace System;
using namespace System::Net;
using namespace std;
using namespace System::Text;
using namespace System::IO;
using namespace System::Xml;


namespace GoofTwitter
{
	void  myGoofTwitter::UserNameDescription()
	{
		string usr;
		cout << "enter a name" << endl;
		getline(cin,usr);
		String^ username = gcnew String(usr.c_str());
		Stream^ myStream;
		HttpWebResponse^ HttpReq;
		HttpWebRequest^ HttpResp;
		String^ urlWithoutScreenName ="https://api.twitter.com/1/statuses/user_timeline.xml?include_entities=true&include_rts=true&screen_name=";
		String^ longUrl = urlWithoutScreenName + username;
		try
		{
			HttpResp = dynamic_cast<HttpWebRequest^>(WebRequest::Create(longUrl));
			HttpResp->ServicePoint->Expect100Continue = false;
			HttpResp->Method = "GET";
			HttpReq = dynamic_cast<HttpWebResponse^>(HttpResp->GetResponse());
			myStream = HttpReq->GetResponseStream();
		}
		catch(WebException^ except)
		{
			Console::WriteLine("404: User doesn't exist");
			return;
		}
		Encoding^ encode = System::Text::Encoding::GetEncoding( "utf-8" );
		StreamReader^ readStream = gcnew StreamReader(myStream,encode);
		String^ resString = readStream->ReadToEnd();
		StringBuilder^ output = gcnew StringBuilder();
		String^ result;
		XmlReader^ reader = XmlReader::Create(gcnew StringReader(resString));

		if(reader->ReadToFollowing("name"))
			output->AppendLine(reader->ReadElementContentAsString());

		if (reader->ReadToFollowing("description"))
		{
			output->AppendLine(reader->ReadElementContentAsString());
		}
		result = output->ToString();
		Console::Write(result);
		HttpReq->Close();
		readStream->Close();
	}
}