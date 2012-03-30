// Managed extensions for C++
#using <mscorlib.dll>
#using <System.dll>
#include <iostream>
#include <stdlib.h>

#include <string>
#using "System.Xml.dll"
#include "RestThing.h"
//#include "RestThing.dll"

using namespace System;
using namespace System::Net;
using namespace System;
using namespace System::Net;
using namespace std;
using namespace System::Text;
using namespace System::IO;
using namespace System::Xml;


//using namespace System::System::Net;

int main(array<System::String ^> ^args)
{
	
	//System::Net::HttpWebRequest^ myRequest = dynamic_cast<HttpWebRequest^>(WebRequest::Create( "http://graphical.weather.gov/xml/sample_products/browser_interface/ndfdXMLclient.php?whichClient=NDFDgen&lat=38.99&lon=-77.01&listLatLon=&lat1=&lon1=&lat2=&lon2=&resolutionSub=&listLat1=&listLon1=&listLat2=&listLon2=&resolutionList=&endPoint1Lat=&endPoint1Lon=&endPoint2Lat=&endPoint2Lon=&listEndPoint1Lat=&listEndPoint1Lon=&listEndPoint2Lat=&listEndPoint2Lon=&zipCodeList=&listZipCodeList=&centerPointLat=&centerPointLon=&distanceLat=&distanceLon=&resolutionSquare=&listCenterPointLat=&listCenterPointLon=&listDistanceLat=&listDistanceLon=&listResolutionSquare=&citiesLevel=&listCitiesLevel=&sector=&gmlListLatLon=&featureType=&requestedTime=&startTime=&endTime=&compType=&propertyName=&product=time-series&begin=2004-01-01T00%3A00%3A00&end=2016-01-20T00%3A00%3A00&Unit=e&maxt=maxt&Submit=Submit" ));
	//System::Net::WebResponse^ myResponse = myRequest->GetResponse();
	GoofTwitter::myGoofTwitter::UserNameDescription();
	cin.get();

	return 0;
}
