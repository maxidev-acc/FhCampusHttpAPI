#pragma once

#include <string>
#include <iostream>

#include "Person.h"

class Studierender : public Person
{
    public:
      
        Studierender() = delete;
        Studierender(const Studierender &) = delete;
        Studierender(const std::string &i_vorname, const std::string &i_familienname, const std::string &svn, const std::string &i_bezeichner, long i_matrikelnummer);
        Studierender(const std::string &i_familienname, long i_matrikelnummer);
        virtual ~Studierender();

        Studierender &operator=(const Studierender &) = delete;

        bool operator==(const Studierender &i_cmp) const
        {
            return this->m_matrikelnummer == i_cmp.m_matrikelnummer;
        }
        bool operator!=(const Studierender &i_cmp) const
        {
            return ! operator==(i_cmp);
        }

        long getMatrikelnummer() const { return m_matrikelnummer; }
        virtual void print() const override;

        virtual std::string toString() const override;

        virtual std::string getID() const override;
        virtual std::string getBezeichner();

        std::string returnStudierenderDataAsJSON();

    private:
    
    private:
        std::string m_bezeichner; 
        long m_matrikelnummer;
        
};
