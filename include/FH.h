#pragma once

#include <string>
#include <vector>
#include <map>


class FH
{
    public:

        FH(const std::string& i_fh_name, const std::string& i_type);
        FH() = delete;
        FH(const FH &i_src) = delete;    
        ~FH();
        FH &operator=(const FH &i_src) = delete;



        void dataConfiguration(const std::string& studentsFile, const std::string& jahrgaengeFile, const std::string& angestellteFile);
        const std::string getFHName() {return fh_name;};
        const std::string getFHType() {return type;};
        const std::string StudentAPIModell(const std::string& id);
        const std::string JahrgangAPIModell(const std::string& id);
        const std::string EmployeeAPIModell(const std::string& id);
        const std::string FhAPIModell();



    private:
        

    protected:
        // member variables
        std::string fh_name;
        std::string type;
        std::vector<Studierender *>  o_students;
        std::vector<Jahrgang *>  o_jahr; 
        std::vector <Angestellter *>  o_angestellte;

   
};
