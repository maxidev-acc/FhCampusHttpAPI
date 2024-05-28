#pragma once

#include <string>
#include <vector>
#include <iostream>

enum class Title { None, Mag, DI };
std::string getTitleName(Title);
Title getTitleFromString(const std::string &i_strTile);


class Person
{
    public:
        
        Person(const std::string &i_vorname, const std::string &i_familienname, const std::string &svn);
        Person(const std::string &i_familienname);
        virtual ~Person();
        void setFamilyName(const std::string &i_newFamilyName);
        virtual void print() const;
        virtual std::string toString() const;

        virtual std::string getID() const = 0;
        std::string returnPersonDataAsJSON();

    private:
        

    protected:
        std::string m_vorname;
        std::string m_familienname;
        std::string m_svn;
        Title m_titel;

    public:
        static const std::vector<Person *>&getAllInstances() { return sm_allInstances; }
    private:
        static std::vector<Person *>sm_allInstances;
};
