#include "Studierender.h"

#include <string>

/**
 * Eine Funktion, die einen neuen Studierenden anlegt und initialisiert.
 */
Studierender::Studierender(const std::string &i_vorname, const std::string &i_familienname, const std::string &svn, const std::string &i_bezeichner, long i_matrikelnummer)
    : Person(i_vorname, i_familienname, svn ),
    m_bezeichner(i_bezeichner),
    m_matrikelnummer(i_matrikelnummer)
{
    // Der Platz für die Daten wird vom Heap angefordert. 
    // Der Speicherplatz bleibt reserviert und daher gültig, bis 'delete'
    // auf einen Pointer ausgeführt wird, der auf diesen Speicher zeigt.
}

Studierender::Studierender(const std::string &i_familienname, long i_matrikelnummer)
  : Person(i_familienname),
    m_matrikelnummer(i_matrikelnummer)
{
    // Der Platz für die Daten wird vom Heap angefordert. 
    // Der Speicherplatz bleibt reserviert und daher gültig, bis 'delete'
    // auf einen Pointer ausgeführt wird, der auf diesen Speicher zeigt.
}

/**
 * @brief wird aufgerufen wenn immer ein Objektvom Typ Studierender freigegeben wird.
 */
Studierender::~Studierender()
{
    // zusätzliche Aufräumaktionen 
}

// ====================== setter =============================

// ====================== public functions =============================
/**
 * Eine Funktion, die auf die Teile eines Studierenden zugreift, ihn/sie aber nicht ändert.
 */
void Studierender::print(/* Studierender *this */) const
{
    // std::cout << this->m_vorname << " " << this->m_familienname << " (" << this->m_matrikelnummer << ")" << std::endl;
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