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
class Studierender : public Person
{
    public:
        // ====================== constructors =============================
        /**
         * Eine Funktion, die einen neuen Studierenden anlegt und initialisiert.
         */
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

        // ====================== getter =============================
        /**
         * @brief return Matrikelnummer of Student
         */
        long getMatrikelnummer(/* const Studierender* this */) const { return m_matrikelnummer; }

        // ====================== setter =============================

        // ====================== public functions =============================
        /**
         * Eine Funktion, die auf die Teile eines Studierenden zugreift, ihn/sie aber nicht ändert.
         */
        virtual void print(/* Studierender *this */) const override;

        virtual std::string toString() const override;

        virtual std::string getID() const override;
        virtual std::string getBezeichner();

        std::string returnStudierenderDataAsJSON();

    private:
        // ====================== private helper functions =============================

    private:
        // member variables
        std::string m_bezeichner; 
        long m_matrikelnummer;
        
};
