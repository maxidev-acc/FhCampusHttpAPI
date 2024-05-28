#include "Person.h"
#include <string>

std::string getTitleName(Title i_title)
{
    switch(i_title)
    {
        case Title::None:
            return "None";
        case Title::Mag:
            return "Mag";
        case Title::DI:
            return "DI";
        default:
            return "";
    }
}

Title getTitleFromString(const std::string &i_strTitle)
{
    if (i_strTitle == "None")
        return Title::None;
    else if (i_strTitle == "Mag")
        return Title::Mag;
    else if (i_strTitle == "DI")
        return Title::DI;
    else
        return Title::None;
}

std::vector<Person *> Person::sm_allInstances;

Person::Person(const std::string &i_vorname, const std::string &i_familienname, const std::string &svn)
    : m_vorname(i_vorname),
    m_familienname(i_familienname),
    m_titel(Title::None),
    m_svn(svn)
{
  
    sm_allInstances.push_back(this);
}

Person::Person(const std::string &i_familienname)
    : m_vorname(""),
    m_familienname(i_familienname)
{

    sm_allInstances.push_back(this);
}


Person::~Person()
{
    
}


void Person::setFamilyName(const std::string &i_newFamilyName)
{
    m_familienname = i_newFamilyName;
}


void Person::print() const
{
   
    std::cout << m_vorname << " " << m_familienname << std::endl;
}


std::string Person::toString() const
{
    return m_vorname + " " + m_familienname;
}
std::string Person::returnPersonDataAsJSON()
{
    std::string jsonPayload;
    jsonPayload ="{ m_vorname: " + m_vorname  + ", m_familienname: " + m_familienname +", svn:"+ m_svn + "}"; 
    return jsonPayload;
}