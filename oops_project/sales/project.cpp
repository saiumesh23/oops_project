#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Data.h"
#include "Property.h"
#include <list>
#include"Agent.h"
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::vector;
using namespace std;
void addProperty(std::list<Data> &propertyList)
{
    Data propertyData;
    string agentId, contact, size, roomType, location, sellingPrice;
    cout << "Welcome to the property adding menu" << endl;

    cout << "Please insert your Agent ID: " << endl;
    cin >> agentId;
    propertyData.setAgentId(agentId);

    cout << "Please insert your Contact: " << endl;
    cin >> contact;
    propertyData.setContact(contact);

    cout << "Please insert your Property Size: " << endl;
    cin >> size;
    propertyData.setPropertySize(size);

    cout << "Please insert your Room Type: " << endl;
    cin >> roomType;
    propertyData.setRoomType(roomType);

    cout << "Please insert your Location: " << endl;
    cin >> location;
    propertyData.setLocation(location);

    cout << "Please insert your Selling Price: " << endl;
    cin >> sellingPrice;
    propertyData.setSellingPrice(sellingPrice);
    ofstream outFile("data.in", ios::app);
    if (outFile.is_open()) {
        // Write property data to the file
        // outFile<<"\n";
        outFile << agentId << ":" << contact << ":" << size << ":" << roomType << ":" << location << ":" << sellingPrice << endl;
        // Close the file
        outFile.close();
        cout << "Property data added to data.in file successfully." << endl;
    } else {
        cout << "Unable to open data.in file for writing." << endl;
    }
    propertyList.push_back(propertyData);
}

void removeProperty(const string& inputLine) {
    ifstream inFile("data.in");
    ofstream tempFile("temp.in");

    if (!inFile.is_open()) {
        cout << "Unable to open data.in file." << endl;
        return;
    }

    bool found = false;
    string line;
    while (getline(inFile, line)) {
        if (line == inputLine) {
            found = true;
            cout << "Property line: \"" << line << "\" removed." << endl;
        } else {
            // Write line to temporary file if it doesn't match
            tempFile << line << endl;
        }
    }

    inFile.close();
    tempFile.close();

    // Replace original file with temporary file
    remove("data.in");
    rename("temp.in", "data.in");

    if (!found) {
        cout << "No matching property line found." << endl;
    }
}

void addAgent(const Agent& agent) {
    // Open the file in append mode
    std::ofstream outFile("passwords.in", std::ios::app);

    if (!outFile.is_open()) {
        std::cout << "Unable to open password.in file for writing." << std::endl;
        return;
    }
//    outFile<<"\n";
    // Write agent name and password to the file
    outFile << agent.getcontact() << " " << agent.getid() << std::endl;

    // Close the file
    outFile.close();

    std::cout << "Agent added successfully." << std::endl;
}


void orderList(std::list<Data> &propertyList)
{
    char response;
    do
    {
        cout << "What order do you want? ascending=a or descending=d" << endl;
        cin >> response;
        if (response != 'a' && response != 'd')
        {
            cout << "ERROR, Please be careful" << endl;
        }
    } while (response != 'a' && response != 'd');
    propertyList.sort();
    if (response == 'd')
    {
        propertyList.reverse();
    }
}

bool findPassword(string password, string id)
{
    string pass, ag;
    bool found = false;
    std::ifstream passwords;
    passwords.open("passwords.in");
    while (!passwords.eof() && !found)
    {
        passwords >> pass >> ag;

        if (password == pass && ag == id)
        {
            found = true;
        }
    }
    passwords.close();
    return found;
}

bool login(string agentId, string password)
{
    bool pass, granted = false;

    pass = findPassword(password, agentId);
    if (pass)
    {
        cout << "Access granted" << endl;
        granted = true;
    }
    else
    {
        cout << "\nLogin Failed!!\n";
    }
    return granted;
}

void changePassword(string id)
{
    std::list<string> passwords, agentIds;
    string pass, ag;
    std::ifstream passwordFile;
    std::ofstream p;
    passwordFile.open("passwords.in");
    while (!passwordFile.eof())
    {
        passwordFile >> pass >> ag;
        passwords.push_back(pass);
        agentIds.push_back(ag);
    }
    passwordFile.close();
    cout << "Just for security, I will need you to re-login" << endl;
    cout << "What is your current password?" << endl;
    cin >> pass;
    p.open("passwords.in");
    if (login(id, pass))
    {
        cout << "Access granted, please input the new password" << endl;
        cin >> pass;
        while (!agentIds.empty())
        {
            p << passwords.front();
            passwords.pop_front();
        }
    }
}

char menu()
{
    char option;

    cout << "Menu" << endl;
    cout << "(a) Add new property" << endl;
    cout << "(b) Remove property " << endl;
    // cout << "(c) Edit sales entries" << endl;
    cout << "(c) Inquire or search property sales" << endl;
    // cout << "(e) Monthly property sales transaction report" << endl;
    cout << "(d) List property sale items in ascending or descending order" << endl;
    cout << "(e) Administration - add  agent" << endl;
     cout << "(f) Quit" << endl;
    cin >> option;
    return option;
}

void load(std::list<Data> &propertyList)
{
    Data propertyData;

    int i = 0;
    unsigned int found, previous;
    std::string line, agentId, contact, size, roomType, location, sellingPrice;
    std::ifstream infile;
    infile.open("data.in");
    while (getline(infile, line))
    {
        found = line.find(':', 0);
        if (found != std::string::npos)
        {
            agentId = line.substr(0, found);
            propertyData.setAgentId(agentId);
        }
        previous = found + 1;
        found = line.find(':', previous);
        if (found != std::string::npos)
        {
            contact = line.substr(previous, found - previous);
            propertyData.setContact(contact);
        }
        previous = found + 1;
        found = line.find(':', previous);
        if (found != std::string::npos)
        {
            size = line.substr(previous, found - previous);
            propertyData.setPropertySize(size);
        }
        previous = found + 1;
        found = line.find(':', previous);
        if (found != std::string::npos)
        {
            roomType = line.substr(previous, found - previous);
            propertyData.setRoomType(roomType);
        }
        previous = found + 1;
        found = line.find(':', previous);
        if (found != std::string::npos)
        {
            location = line.substr(previous, found - previous);
            propertyData.setLocation(location);
        }
        previous = found + 1;
        sellingPrice = line.substr(previous, line.length() - previous);
        propertyData.setSellingPrice(sellingPrice);

        propertyList.push_back(propertyData);
        i++;
    }
    infile.close();
}
void enquire(const std::string& searchTerm, const std::string& searchAttribute, const std::list<Data>& propertyList) {
     std::vector<Data> matchingProperties;

    // Iterate through the property list
    for (const auto& property : propertyList) {
        // Check if the search attribute matches
        if (searchAttribute == "AgentID" && property.getAgentId() == searchTerm) {
            matchingProperties.push_back(property);
        } else if (searchAttribute == "Contact" && property.getContact() == searchTerm) {
            matchingProperties.push_back(property);
        }else if (searchAttribute == "Location" && property.getLocation() == searchTerm) {
            matchingProperties.push_back(property);
        }else if (searchAttribute == "sellingprice" && property.getSellingPrice() == searchTerm) {
            matchingProperties.push_back(property);
        }
       
        // Similar checks for other attributes
    }
     
    // Display all matching properties
    if (matchingProperties.empty()) {
        std::cout << "No data found for " << searchAttribute << ": " << searchTerm << std::endl;
    } else {
        std::cout << "Matching properties for " << searchAttribute << ": " << searchTerm << std::endl;
        for (const auto& property : matchingProperties) {
            std::cout << "Agent ID: " << property.getAgentId() << std::endl;
            std::cout << "Contact: " << property.getContact() << std::endl;
            std::cout << "Property Size: " << property.getPropertySize() << std::endl;
            std::cout << "Room Type: " << property.getRoomType() << std::endl;
            std::cout << "Location: " << property.getLocation() << std::endl;
            std::cout << "Selling Price: " << property.getSellingPrice() << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}
void show(std::list<Data> &propertyList)
{
    cout << "Property List:" << endl;
    for (const auto &property : propertyList)
    {
        cout << "Agent ID: " << property.getAgentId() << endl;
        cout << "Contact: " << property.getContact() << endl;
        cout << "Property Size: " << property.getPropertySize() << endl;
        cout << "Room Type: " << property.getRoomType() << endl;
        cout << "Location: " << property.getLocation() << endl;
        cout << "Selling Price: " << property.getSellingPrice() << endl;
        cout << "------------------------" << endl;
    }
}

int main()
{
    std::list<Data> propertyList;
    string agentId, password;
    cout << "Please insert your Agent ID" << endl;
    cin >> agentId;
    cout << "Please insert your password" << endl;
    cin >> password;
    if (login(agentId, password))
    {
        load(propertyList);
        char option;
        string toremove;
        Agent newAgent;
         string agent;
         int password;
         string enqattribute;
         string enqcheck;
        do
        {
            option = menu();
            switch (option)
            {
            case 'a':
                addProperty(propertyList);
                break;
            case 'b':
                  cout<<"plz enter the data int the format agentid:contact:size:roomtype:place:price  that u want to remove"<<endl;
                  cin>>toremove;
                 removeProperty(toremove);
                break;
            case 'c':
                 cout<<"which attribute u want to search"<<endl;
                 cin>>enqcheck;
                 cout<<"enter the attribute name"<<endl;
                 cin>>enqattribute;
                 enquire(enqattribute,enqcheck,propertyList);
                break;
            case 'd':
             show(propertyList);
                break;
            case 'e':
              cout<<"plz enter the agent name"<<endl;
              cin>>agent;
              cout<<"plz set the password for security reasons"<<endl;
              cin>>password;
              newAgent.setid(agent);
              newAgent.setcontact(password);
             addAgent(newAgent);
                break;
            case 'f':
             cout << "Goodbye" << endl;
                break;
            default:
                cout << "Wrong selection" << endl;
            }

        } while (option != 'f');
    }
    return (0);
}

