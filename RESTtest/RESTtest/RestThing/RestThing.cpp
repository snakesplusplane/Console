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
		string tmp;
		cout << "Enter Twitter Username: ";

		getline(cin,tmp);
		String^ username = gcnew String(tmp.c_str());
		Stream^ myStream;

		HttpWebResponse^ HttpReq;
		HttpWebRequest^ HttpResp;

		String^ urlWithoutScreenName ="https://api.twitter.com/1/users/lookup.xml?screen_name=";//snakesplusplane&include_entities=true";
		String^ longUrl = urlWithoutScreenName + username;
		String^ urlExtra = "&include_entities=true";
		longUrl += urlExtra;
		try
		{
			HttpResp = dynamic_cast<HttpWebRequest^>(WebRequest::Create(longUrl));
			HttpResp->Method = "GET";
			HttpReq = dynamic_cast<HttpWebResponse^>(HttpResp->GetResponse());
			myStream = HttpReq->GetResponseStream();
		}

		catch(WebException^ except)
		{
			Console::WriteLine("404: User doesn't exist");
			return;
		}

		Encoding^ mEncode = System::Text::Encoding::GetEncoding( "utf-8" );
		StreamReader^ readStream = gcnew StreamReader(myStream,mEncode);
		String^ resString = readStream->ReadToEnd();
		StringBuilder^ output = gcnew StringBuilder();
		String^ result;
		StringBuilder^ tweettweet = gcnew StringBuilder();;

		XmlReader^ reader = XmlReader::Create(gcnew StringReader(resString));


		if(reader->ReadToFollowing("name"))
			output->AppendLine("Username... ");
			output->AppendLine(reader->ReadElementContentAsString());

		if (reader->ReadToFollowing("description"))
		{
			output->AppendLine("Description... ");
			output->AppendLine(reader->ReadElementContentAsString());
		}
				if (reader->ReadToFollowing("text"))
		{
			output->AppendLine("TweetTweet!.. ");
			output->AppendLine(reader->ReadElementContentAsString());
		}
		result = output->ToString();
		Console::Write(result);
		//result = tweettweet->ToString();
		//Console::Write(result);
		HttpReq->Close();
		readStream->Close();
	}

		void  myGoofTwitter::UserNameDescription(std::string userName)
	{
		
				Stream^ myStream;
		HttpWebResponse^ HttpReq;
		HttpWebRequest^ HttpResp;
		String^ username = gcnew String(userName.c_str());

				String^ urlWithoutScreenName ="https://api.twitter.com/1/users/lookup.xml?screen_name=";//snakesplusplane&include_entities=true";
		String^ longUrl = urlWithoutScreenName + username;
		String^ urlExtra = "&include_entities=true";
		longUrl += urlExtra;
		try
		{
			HttpResp = dynamic_cast<HttpWebRequest^>(WebRequest::Create(longUrl));
			HttpResp->Method = "GET";
			HttpReq = dynamic_cast<HttpWebResponse^>(HttpResp->GetResponse());
			myStream = HttpReq->GetResponseStream();
		}

		catch(WebException^ except)
		{
			Console::WriteLine("404: User doesn't exist");
			return;
		}

		Encoding^ mEncode = System::Text::Encoding::GetEncoding( "utf-8" );
		StreamReader^ readStream = gcnew StreamReader(myStream,mEncode);
		String^ resString = readStream->ReadToEnd();
		StringBuilder^ output = gcnew StringBuilder();
		String^ result;
		StringBuilder^ tweettweet = gcnew StringBuilder();;

		XmlReader^ reader = XmlReader::Create(gcnew StringReader(resString));


		if(reader->ReadToFollowing("name"))
			output->AppendLine("Username... ");
			output->AppendLine(reader->ReadElementContentAsString());

		if (reader->ReadToFollowing("description"))
		{
			output->AppendLine("Description... ");
			output->AppendLine(reader->ReadElementContentAsString());
		}
				if (reader->ReadToFollowing("text"))
		{
			output->AppendLine("TweetTweet!.. ");
			output->AppendLine(reader->ReadElementContentAsString());
		}
		result = output->ToString();
		Console::Write(result);
		//result = tweettweet->ToString();
		//Console::Write(result);
		HttpReq->Close();
		readStream->Close();
	}
}