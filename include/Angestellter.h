#pragma once

#include <string>
#include <iostream>

#include "Person.h"

class Angestellter : public Person
{
    public:
     
        Angestellter() = delete;
        Angestellter(const Angestellter &) = delete;
        Angestellter(const std::string &i_vorname, const std::string &i_familienname, const std::string &svn,  long i_angestelltennummer, const std::string &i_abteilung, int i_rang);

        virtual ~Angestellter();

        Angestellter &operator=(const Angestellter &) = delete;

        bool operator==(const Angestellter &i_cmp) const
        {
            return this->m_angestelltennummer == i_cmp.m_angestelltennummer;
        }
        bool operator!=(const Angestellter &i_cmp) const
        {
            return ! operator==(i_cmp);
        }

    
        long getMatrikelnummer() const { return m_angestelltennummer; }
        std::string returnEmployeeDataAsJSON();
        virtual void print() const override;
        virtual std::string toString() const override;
        virtual std::string getID() const override;

    private:
        

    private:
        
        long m_angestelltennummer;
        std::string abteilung; 
        int rang;
        
};
