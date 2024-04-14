#ifndef data_h
#define data_h
#include <iostream>
#include <string>
using std::string;
class Data
{
	private :
		string AgentId,Contact,PropertySize,RoomType,Location,SellingPrice;
	public :
		Data():AgentId(),Contact(), PropertySize(),RoomType(),Location(),SellingPrice(){}//default constructor
		Data(string AgentId, string Contact, string PropertySize, string RoomType, string Location, string SellingPrice);// parametrized constructor
		void setAgentId(string x){this->AgentId=x;}
		void setContact(string x){this->Contact=x;}
		void setPropertySize(string x){this->PropertySize=x;}
		void setRoomType(string x){this->RoomType=x;}
		void setLocation(string x){this->Location=x;}
		void setSellingPrice(string x){this->SellingPrice=x;}
		string getAgentId() const{return this->AgentId;}
		string getContact()const{return this->Contact;}
		// string getContact()const{return this->Contact;}
		string getPropertySize()const{return this->PropertySize;}
		string getRoomType()const{return this->RoomType;}
		string getLocation()const{return this->Location;}
		string getSellingPrice()const{return this->SellingPrice;}
		bool operator>(Data a);
		bool operator<(Data a);
};
Data::Data(string AgentId, string Contact, string PropertySize, string RoomType, string Location, string SellingPrice)
{
	
	this->AgentId=AgentId;
	this->Contact=Contact;
	this->PropertySize=PropertySize;
	this->RoomType=RoomType;
	this->Location=Location;
	this->SellingPrice=SellingPrice;
}
bool Data::operator>(Data a)
{
	if(SellingPrice>a.getSellingPrice())
	{
		return(true);
	}else{
		return(false);
	}
}
bool Data::operator<(Data a)
{
	if(SellingPrice<a.getSellingPrice())
	{
		return(true);
	}else{
		return(false);
	}
}
#endif
