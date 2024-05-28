#include "Studierender.h"

#include <string>


Studierender::Studierender(const std::string &i_vorname, const std::string &i_familienname, const std::string &svn, const std::string &i_bezeichner, long i_matrikelnummer)
    : Person(i_vorname, i_familienname, svn ),
    m_bezeichner(i_bezeichner),
    m_matrikelnummer(i_matrikelnummer)
{

}

Studierender::Studierender(const std::string &i_familienname, long i_matrikelnummer)
  : Person(i_familienname),
    m_matrikelnummer(i_matrikelnummer)
{
    
}

Studierender::~Studierender()
{
    
}


void Studierender::print() const
{
    
    std::cout << m_vorname << " " << m_familienname << " (" << m_matrikelnummer << ")" << std::endl;
}

std::string Studierender::toString() const
{
    return Person::toString() + "(" + std::to_string(m_matrikelnummer) + ")";
}

std::string Studierender::getID() const
{
    return std::to_string(m_matrikelnummer);    
}
std::string Studierender::returnStudierenderDataAsJSON()
{
    std::string jsonPayload;

    jsonPayload ="{ m_vorname: " + m_vorname  + ", m_familienname: " + m_familienname +", svn:"+ m_svn + ", m_matrikelnummer:" +  std::to_string(m_matrikelnummer) +  ", bezeichner:" +  m_bezeichner + "}"; 
    return jsonPayload;
}
std::string Studierender::getBezeichner() {
    return m_bezeichner; 

}