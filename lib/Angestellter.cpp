#include "Angestellter.h"

#include <string>


Angestellter::Angestellter(const std::string &i_vorname, const std::string &i_familienname, const std::string &svn,  long i_angestelltennummer, const std::string &i_abteilung, int i_rang)
    : Person(i_vorname, i_familienname, svn ),
    m_angestelltennummer(i_angestelltennummer),
    abteilung(i_abteilung),
    rang(i_rang)
{
   
}

Angestellter::~Angestellter()
{
  
}


void Angestellter::print() const
{
 
    std::cout << m_vorname << " " << m_familienname << " (" << m_angestelltennummer << ")" << std::endl;
}

std::string Angestellter::toString() const
{
    return Person::toString() + "(" + std::to_string(m_angestelltennummer) + ")";
}

std::string Angestellter::getID() const
{
    return std::to_string(m_angestelltennummer);    
}


std::string Angestellter::returnEmployeeDataAsJSON() {
    std::string jsonPayload;

    jsonPayload ="{ m_vorname: " + m_vorname  + ", m_familienname: " + m_familienname +", svn:"+ m_svn + ", m_angestelltennummer:" +  std::to_string(m_angestelltennummer) +  ", abteilung:" +  abteilung + "}"; 
    return jsonPayload;
}