#include "Jahrgang.h"
#include "Studierender.h"
#include "Hilfsfunktionen.h"

Jahrgang::Jahrgang(const std::string &i_bezeichner, int i_jahr)
  : m_bezeichner(i_bezeichner),
    m_jahr(i_jahr)
{
}

void Jahrgang::readStudents(const std::string &i_fileName)
{
      m_studenten.clear();
   Utility::readStudents(i_fileName, m_studenten);
}

Jahrgang::~Jahrgang()
{

}

Studierender *Jahrgang::findStudent(long i_matrikelNummer) const
{
    for (auto elem : m_studenten)
        if (elem->getMatrikelnummer() == i_matrikelNummer)
            return elem;

    return nullptr;
}

void Jahrgang::addStudent(Studierender *i_pStudent)
{
  m_studenten.push_back(i_pStudent);
}


void Jahrgang::print_Jahrgang(/* Studierender *this */)
{
    // std::cout << this->m_vorname << " " << this->m_familienname << " (" << this->m_matrikelnummer << ")" << std::endl;
    std::cout << m_bezeichner << " " << m_jahr << std::endl;
}