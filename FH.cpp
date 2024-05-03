#include "Jahrgang.h"
#include "Studierender.h"
#include "Angestellter.h"
#include "Hilfsfunktionen.h"
#include "FH.h"

FH::FH(const std::string i_fh_name, const std::string i_type)
  : fh_name(i_fh_name),
    type(i_type)
{
}


    void FH::setupData(const std::vector<std::string>& jahrgänge) {
        std::cout<<"Set up data"<<std::endl;
        Utility::readStudents("Studierende.txt", o_students);
        Utility::readJahrgang("Jahrga.txt", o_jahr);
        Utility::readEmployees("Angestellte.txt", o_angestellte);

        for (auto jahrgang : o_jahr){
            std::string bezeichner = jahrgang->getName();
            for(auto student : o_students )
            {
                if (student->getBezeichner() == bezeichner){
                    jahrgang->addStudent(student);

                };
            };

        }



        };


        // ====================== public functions =============================
        /**
         * Eine Funktion, die auf die Teile eines Studierenden zugreift, ihn/sie aber nicht ändert.
         */
        void FH::printFH_Data(){
            for (auto *studierender :o_students)
            std::cout << studierender->returnPersonDataAsJSON() << std::endl;
            
            for (auto *jahr :o_jahr)
            jahr->print_Jahrgang();
            for (auto *ang :o_angestellte)
            ang->returnEmployeeDataAsJSON();
                

        }
        std::string FH:: StudentAPIModell(std::string id) {
            std::string payload = "";
            for (auto *studierender :o_students)
                if(studierender->getID() == id) {
                    std::string payload = studierender->returnStudierenderDataAsJSON();
                    return (payload);
                }   

            return ("No dataset found");};


        std::string FH::JahrgangAPIModell(std::string id){
             
            std::vector<Studierender *> temp;
            for(auto jahrgang :o_jahr){
                if(jahrgang->getName() == id) {   
                    temp = jahrgang->getStudents();
                }                
            }
            std::string begin = "{ jahrgang: " + id + ", students: ["; 
            for (auto *stud :temp) 
                begin += stud->returnStudierenderDataAsJSON();
             
            begin += "]}"; 
            
            return begin;
        };

         std::string FH:: EmployeeAPIModell(std::string id) {
            std::string payload = "";
            for (auto *angestellter :o_angestellte)
                if(angestellter->getID() == id) {
                    std::string payload = angestellter->returnEmployeeDataAsJSON();
                    return (payload);
                }   
            
            return ("No dataset found");};


           
        std::string FH:: FhAPIModell(){
            
            std::string payload = "{ name: " + this->getName() +  ", type:" + this->getType() + ", jahrgaenge: ["; 
            for (auto i: o_jahr) {
                payload += i->getName()+ ", ";



            };

            payload += " ]}";
            return payload;
        }
            
            
        