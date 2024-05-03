#include "Angestellter.h"

#include <string>

/**
 * Eine Funktion, die einen neuen Studierenden anlegt und initialisiert.
 */
Angestellter::Angestellter(const std::string &i_vorname, const std::string &i_familienname, const std::string &svn,  long i_angestelltennummer, const std::string &i_abteilung, int i_rang)
    : Person(i_vorname, i_familienname, svn ),
    m_angestelltennummer(i_angestelltennummer),
    abteilung(i_abteilung),
    rang(i_rang)
{
    // Der Platz für die Daten wird vom Heap angefordert. 
    // Der Speicherplatz bleibt reserviert und daher gültig, bis 'delete'
    // auf einen Pointer ausgeführt wird, der auf diesen Speicher zeigt.
}


/**
 * @brief wird aufgerufen wenn immer ein Objektvom Typ Studierender freigegeben wird.
 */
Angestellter::~Angestellter()
{
    // zusätzliche Aufräumaktionen 
}


void Angestellter::print(/* Studierender *this */) const
{
    // std::cout << this->m_vorname << " " << this->m_familienname << " (" << this->m_matrikelnummer << ")" << std::endl;
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