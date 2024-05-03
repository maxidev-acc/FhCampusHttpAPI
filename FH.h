#pragma once

#include <string>
#include <vector>
#include <map>


class FH
{
    public:
        // ====================== constructors =============================
        /**
         * Eine Funktion, die einen neuen Studierenden anlegt und initialisiert.
         */
        FH(const std::string i_fh_name, const std::string i_type);
      


        // ====================== getter =============================

        // ====================== setter =============================
        // changes the family name
        void setupData(const std::vector<std::string>& jahrgänge);
        void printFH_Data();


        // ====================== public functions =============================
        /**
         * Eine Funktion, die auf die Teile eines Studierenden zugreift, ihn/sie aber nicht ändert.
         */
        std::string getName() {return fh_name;};
        std::string getType() {return type;};
        std::string StudentAPIModell(std::string id);
        std::string JahrgangAPIModell(std::string id);
        std::string EmployeeAPIModell(std::string id);
        std::string FhAPIModell();



    private:
        // ====================== private helper functions =============================

    protected:
        // member variables
        std::string fh_name;
        std::string type;
        std::vector<Studierender *>  o_students;
        std::vector<Jahrgang *>  o_jahr; 
        std::vector <Angestellter *>  o_angestellte;

   
};
