#pragma once

#include <string>
#include <vector>
#include <map>


class FH
{
    public:
     
        FH(const std::string i_fh_name, const std::string i_type);
      
    
        void setupData(const std::string& studentsFile, const std::string& jahrgaengeFile, const std::string& angestellteFile);
        
        std::string getFHName() {return fh_name;};
        std::string getFHType() {return type;};
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
