#pragma once

#include <sstream>
#include <string>
#include <vector>

class Studierender;
class Jahrgang;
class Angestellter;

namespace Utility
{
    // Funktionsdeklarationen, wie sie für den Aufruf der Funktionen nnotwendig sind.
    std::string readNextCSString(std::stringstream &ss);
    void readStudents(const std::string &i_strFileName, std::vector<Studierender *>& o_students);
    void readJahrgang(const std::string &i_strFileName, std::vector<Jahrgang *>& o_jahrgaenge);
    void readEmployees(const std::string &i_strFileName, std::vector<Angestellter *>& o_angestellte);
    void WriteStudents();

}
