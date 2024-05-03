#pragma once

#include <string>
#include <vector>
#include <iostream>

enum class Title { None, Mag, DI };
std::string getTitleName(Title);
Title getTitleFromString(const std::string &i_strTile);

/**
 * Ein neuer Datentyp. Er sammelt die Gemeinsamkeiten von Studierenden.
 * Sie alle besitzen Namen und eine Mattrikelnummmer.
 * 
 * Alle Member - hier Attribute - sind ohneweiterer Angabe 'private',also versteckt.
 * Sie können nur von innerhalb der Klasse gesehen/verwendet werden.
 * 
 * Da wir sie von 'main' aus ansprechen wollen, müssen wir sie als 'public' definieren.
 * Abstrakt, da die ein virtuelle Funktion 'std::string getID() const' nicht implementiert ist.
 */
class Person
{
    public:
        // ====================== constructors =============================
        /**
         * Eine Funktion, die einen neuen Studierenden anlegt und initialisiert.
         */
        Person(const std::string &i_vorname, const std::string &i_familienname, const std::string &svn);
        Person(const std::string &i_familienname);
        virtual ~Person();

        // ====================== getter =============================

        // ====================== setter =============================
        // changes the family name
        void setFamilyName(const std::string &i_newFamilyName);

        // ====================== public functions =============================
        /**
         * Eine Funktion, die auf die Teile eines Studierenden zugreift, ihn/sie aber nicht ändert.
         */
        virtual void print(/* Studierender *this */) const;

        /**
         * @brief return full name as string.
         */
        virtual std::string toString() const;

        virtual std::string getID() const = 0;
        std::string returnPersonDataAsJSON();

    private:
        // ====================== private helper functions =============================

    protected:
        // member variables
        std::string m_vorname;
        std::string m_familienname;
        std::string m_svn;
        Title m_titel;

    public:
        static const std::vector<Person *>&getAllInstances() { return sm_allInstances; }
    private:
        static std::vector<Person *>sm_allInstances;
};
