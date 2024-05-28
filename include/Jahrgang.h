#pragma once

#include <string>
#include <vector>
#include <map>


class Studierender;

class Jahrgang
{
    public:
        
        Jahrgang() = delete;
        Jahrgang(const std::string &i_bezeichner, int i_jahr);
        Jahrgang(const Jahrgang &i_src) = delete;    
        ~Jahrgang();
        Jahrgang &operator=(const Jahrgang &i_src) = delete;
    
        const std::string &getJahrgangName() const { return m_bezeichner; }
        int getJahr() const { return m_jahr; }
        Studierender *findStudent(long i_matrikelNummer) const;

 
        void addStudent(Studierender *i_pStudent);
        std::vector <Studierender *> getStudents()
        {

            return m_studenten;
        }


        void readStudents(const std::string &i_fileName);
        void print_Jahrgang();

   
        bool operator==(const Jahrgang &i_cmp) const
        {
            return (this->m_bezeichner == i_cmp.m_bezeichner) && (this->m_jahr == i_cmp.m_jahr);
        }
        bool operator != (const Jahrgang &i_cmp) const
        {
            return ! operator==(i_cmp);
        }

        
    private:
        std::string m_bezeichner;
        int m_jahr;
        std::vector<Studierender *> m_studenten;
};