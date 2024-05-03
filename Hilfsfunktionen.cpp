#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Jahrgang.h"
#include "Studierender.h"
#include "Hilfsfunktionen.h"
#include "FHException.h"
#include "Angestellter.h"

using namespace Utility;

/**
 * Hilfsfunktion um das nächste Attribut aus einer Zeile eines Comma-Separated-Filed zu holen.
*/
std::string Utility::readNextCSString(std::stringstream &ss)
{
    std::string strField;
    getline(ss, strField, ',');

    auto start = strField.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";

    auto end = strField.find_last_not_of(" \t");
    return strField.substr(start,end - start + 1);
}









/**
 * Lies alle Studenten aus einer CSV-Datei ein
*/
void Utility::readStudents(const std::string &i_strFileName, std::vector<Studierender *>& o_students)
{
    std::ifstream fStudents("data\\" + i_strFileName);
    if (fStudents.is_open())
    {
        std::string strLine;
        while (!fStudents.eof())
        {
            getline(fStudents, strLine);

            if (strLine.empty())
                continue;
            
            // split up
            std::stringstream ss(strLine);
            std::string firstName = readNextCSString(ss);
            std::string familyName = readNextCSString(ss);
            std::string svn = readNextCSString(ss);
            
            std::string strMatrikelNummer = readNextCSString(ss);
            long nMatrikelNummer = std::stol(strMatrikelNummer);
            std::string bezeichner = readNextCSString(ss);

            auto *pStudent = new Studierender(firstName, familyName, svn, bezeichner, nMatrikelNummer);
            o_students.push_back(pStudent);
        }

        fStudents.close();        
    }
    else
        throw FHException("Can't open file 'data\\" + i_strFileName + "'.");
}



void Utility::readEmployees(const std::string &i_strFileName, std::vector<Angestellter *>& o_angestellte)
{
    std::ifstream fStudents("data\\" + i_strFileName);
    if (fStudents.is_open())
    {
        std::string strLine;
        while (!fStudents.eof())
        {
            getline(fStudents, strLine);

            if (strLine.empty())
                continue;
            
            // split up
            std::stringstream ss(strLine);
            std::string firstName = readNextCSString(ss);
            std::string familyName = readNextCSString(ss);
            std::string svn = readNextCSString(ss);
            
            std::string str_ang = readNextCSString(ss);
            long angestellten_nummer = std::stol(str_ang);
            std::string abteilung = readNextCSString(ss);
            std::string rank = readNextCSString(ss);
            int rang = std::stol(rank);

            auto *angestellter = new Angestellter(firstName, familyName, svn, angestellten_nummer, abteilung, rang);
            o_angestellte.push_back(angestellter);
        }

        fStudents.close();        
    }
   
}

void Utility::readJahrgang(const std::string &i_strFileName, std::vector<Jahrgang *>& o_jahrgaenge)
{
    std::ifstream fStudents("data\\" + i_strFileName);
    if (fStudents.is_open())
    {
        std::string strLine;
        while (!fStudents.eof())
        {
            getline(fStudents, strLine);

            if (strLine.empty())
                continue;
            
            // split up
            std::stringstream ss(strLine);
            std::string m_bezeichner = readNextCSString(ss);
            std::string ganze_bezeichung = readNextCSString(ss);
            std::string i_jahr = readNextCSString(ss);
            int jahr = 2025;
            auto *jahrgang = new Jahrgang(m_bezeichner, jahr);
            o_jahrgaenge.push_back(jahrgang);
        }

        fStudents.close();        
    }
   
}






void Utility::WriteStudents()
{
    std::ofstream fStudents("data\\studierende2.txt");
    if (fStudents.is_open())
    {
        fStudents << "\t" << "Max" << ",\t" << "Mustermann" << ",\t" << 31 << ",\t" << "2022345" << std::endl;

        fStudents.close();        
    }
}

