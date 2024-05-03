#pragma once

#include <string>
#include <iostream>

#include "Person.h"

/**
 * Ein neuer Datentyp. Er sammelt die Gemeinsamkeiten von Studierenden.
 * Sie alle besitzen Namen und eine Mattrikelnummmer.
 * 
 * Alle Member - hier Attribute - sind ohneweiterer Angabe 'private',also versteckt.
 * Sie können nur von innerhalb der Klasse gesehen/verwendet werden.
 * 
 * Da wir sie von 'main' aus ansprechen wollen, müssen wir sie als 'public' definieren.
 */
class Angestellter : public Person
{
    public:
        // ====================== constructors =============================
        /**
         * Eine Funktion, die einen neuen Studierenden anlegt und initialisiert.
         */
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

        // ====================== getter =============================
        /**
         * @brief return Matrikelnummer of Student
         */
        long getMatrikelnummer(/* const Studierender* this */) const { return m_angestelltennummer; }

        // ====================== setter =============================

        // ====================== public functions =============================
        /**
         * Eine Funktion, die auf die Teile eines Studierenden zugreift, ihn/sie aber nicht ändert. */
        std::string returnEmployeeDataAsJSON();
       
        virtual void print(/* Studierender *this */) const override;

        virtual std::string toString() const override;


        virtual std::string getID() const override;

    private:
        // ====================== private helper functions =============================

    private:
        // member variables
        
        long m_angestelltennummer;
        std::string abteilung; 
        int rang;
        
};
