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

/**
 * Eine Funktion, die einen neuen Studierenden anlegt und initialisiert.
 */
Person::Person(const std::string &i_vorname, const std::string &i_familienname, const std::string &svn)
    : m_vorname(i_vorname),
    m_familienname(i_familienname),
    m_titel(Title::None),
    m_svn(svn)
{
    // Der Platz für die Daten wird vom Heap angefordert. 
    // Der Speicherplatz bleibt reserviert und daher gültig, bis 'delete'
    // auf einen Pointer ausgeführt wird, der auf diesen Speicher zeigt.
    sm_allInstances.push_back(this);
}

Person::Person(const std::string &i_familienname)
    : m_vorname(""),
    m_familienname(i_familienname)
{
    // Der Platz für die Daten wird vom Heap angefordert. 
    // Der Speicherplatz bleibt reserviert und daher gültig, bis 'delete'
    // auf einen Pointer ausgeführt wird, der auf diesen Speicher zeigt.
    sm_allInstances.push_back(this);
}

/**
 * @brief wird aufgerufen wenn immer ein Objektvom Typ Studierender freigegeben wird.
 */
Person::~Person()
{
    // zusätzliche Aufräumaktionen 
    std::cout <<"emdl";
    //for (auto iter = sm_allInstances.begin(); iter != sm_allInstances.end(); iter++)
      //  if (*iter == this)
        //    sm_allInstances.erase(iter);
}

// ====================== setter =============================
// changes the family name
void Person::setFamilyName(const std::string &i_newFamilyName)
{
    m_familienname = i_newFamilyName;
}

// ====================== public functions =============================
/**
 * Eine Funktion, die auf die Teile eines Studierenden zugreift, ihn/sie aber nicht ändert.
 */
void Person::print(/* Studierender *this */) const
{
    // std::cout << this->m_vorname << " " << this->m_familienname << " (" << this->m_matrikelnummer << ")" << std::endl;
    std::cout << m_vorname << " " << m_familienname << std::endl;
}

/**
 * @brief return full name as string.
 * 
 */
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