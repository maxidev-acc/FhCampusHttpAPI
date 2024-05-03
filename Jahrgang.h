#pragma once

#include <string>
#include <vector>
#include <map>

// forward declaration anstelle eines Includes
class Studierender;

class Jahrgang
{
    public:
        // 'structors
        Jahrgang() = delete;
        Jahrgang(const std::string &i_bezeichner, int i_jahr);
        Jahrgang(const Jahrgang &i_src) = delete;    // default copy constructor
        ~Jahrgang();
        Jahrgang &operator=(const Jahrgang &i_src) = delete;
        // getter
        const std::string &getName() const { return m_bezeichner; }
        int getJahr() const { return m_jahr; }
        Studierender *findStudent(long i_matrikelNummer) const;

        //setter
        void addStudent(Studierender *i_pStudent);
        std::vector <Studierender *> getStudents()
        {

            return m_studenten;
        }


        void readStudents(const std::string &i_fileName);
        void print_Jahrgang(/* Studierender *this */);

        // useful operators
        bool operator==(const Jahrgang &i_cmp) const
        {
            return (this->m_bezeichner == i_cmp.m_bezeichner) && (this->m_jahr == i_cmp.m_jahr);
        }
        bool operator != (const Jahrgang &i_cmp) const
        {
            return ! operator==(i_cmp);
        }

        // puplic methods

    private:
        std::string m_bezeichner;
        int m_jahr;
        std::vector<Studierender *> m_studenten;
};