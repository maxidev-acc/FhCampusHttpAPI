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


    void FH::setupData(const std::string& studentsFile, const std::string& jahrgaengeFile, const std::string& angestellteFile) {
        std::cout<<"FH-Instanz wird mit Daten gefüllt."<<std::endl;
        Utility::readStudents(studentsFile, o_students);
        Utility::readJahrgang(jahrgaengeFile, o_jahr);
        Utility::readEmployees(angestellteFile, o_angestellte);

        for (auto jahrgang : o_jahr){
            std::string bezeichner = jahrgang->getJahrgangName();
            for(auto student : o_students )
            {
                if (student->getBezeichner() == bezeichner){
                    jahrgang->addStudent(student);

                };
            };
        }
        std::cout <<"Alle Daten wurden erstellt.";
        for (auto jahrgang : o_jahr){
            std::cout << jahrgang->getJahrgangName()<<std::endl;

        };
    }


      


        // ====================== public functions =============================
        /**
         * Eine Funktion, die auf die Teile eines Studierenden zugreift, ihn/sie aber nicht ändert.
         */
      
        std::string FH:: StudentAPIModell(std::string id) {
            std::string payload = "";
            for (auto *studierender :o_students)
                if(studierender->getID() == id) {
                    std::string payload = studierender->returnStudierenderDataAsJSON();
                    return (payload);
                }   

            return ("StudentAPIModell: Kein Datensatz gefunden!");};


        std::string FH::JahrgangAPIModell(std::string id){
             
            std::vector<Studierender *> temp;
            for(auto jahrgang :o_jahr){
                if(jahrgang->getJahrgangName() == id) {   
                    temp = jahrgang->getStudents();
                    std::string payload = "{ jahrgang: " + id + ", students: ["; 
                    for (auto *stud :temp) 
                    payload += stud->returnStudierenderDataAsJSON();
                    payload += "]}"; 
                    return payload;
                }                
            }
            return ("JahrgangAPIModell: Kein Datensatz gefunden!");
            
        };

         std::string FH:: EmployeeAPIModell(std::string id) {
            std::string payload = "";
            for (auto *angestellter :o_angestellte)
                if(angestellter->getID() == id) {
                    std::string payload = angestellter->returnEmployeeDataAsJSON();
                    return (payload);
                }   
            
            return ("EmployeeAPIModell: Kein Datensatz gefunden!");};


           
        std::string FH:: FhAPIModell(){
            
            std::string payload = "{ name: " + this->getFHName() +  ", type:" + this->getFHType() + ", jahrgaenge: ["; 
            for (auto *i: o_jahr) {
                payload += i->getJahrgangName()+ ", ";



            };

            payload += " ]}";
            return payload;
        }
            
            
        