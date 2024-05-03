#include <iostream>
#include "Studierender.h"
#include "Jahrgang.h"
#include "FHException.h"
#include "Hilfsfunktionen.h"
#include "FH.h"
#include "REQUEST.h"


std::string seperator(){
    return "\n*********************************\n";
}




void Unit_Test_FH(FH& fh_campus) {
    std::cout << seperator();
    std::vector<std::string> name({ "Bio", "Chem", "Bot"}); 
    std::cout <<"Unit Test. FH Objekt instanziert." << std::endl;
    
    fh_campus.setupData(name);
    std::cout << seperator();
    std::cout<<fh_campus.StudentAPIModell("11111")<< std::endl;
    std::cout << seperator();
    std::cout<<fh_campus.EmployeeAPIModell("100")<< std::endl;
    std::cout << seperator();
    std::cout<<fh_campus.JahrgangAPIModell("BIOINF25")<< std::endl;
    std::cout << seperator();
    std::cout<<fh_campus.JahrgangAPIModell("MACHINE23")<< std::endl;
    std::cout << seperator();
    std::cout<<fh_campus.JahrgangAPIModell("ANALYT_CHEM23")<< std::endl;
    std::cout << seperator();
    std::cout<<"Alle FH_API_Modelle erfolgreich getestet. Laufzeit wird vorbereitet "<<std::endl;
    std::cout << seperator();

}

   



void url_handler(FH& fh){
        int runtime =1;
        std::cout <<"Valide Routen:"<<std::endl;
        std::cout<<seperator();
        std::cout<< "fh/angestellter/<m_angestelltennummer>"<<std::endl; 
        std::cout<< "fh/student/<m_matrikelnummer>"<<std::endl; 
        std::cout<< "fh/jahrgang/"<<std::endl;
        std::cout<< "fh/info"<<std::endl; 
        while (runtime==1){
            std::cout <<"Please enter request URL:  "<<std::endl;
            std::string command;
            std::cin>>command;
            if(command == "exit") { break;}; 
            auto req = new REQUEST(command);
            std::string res = req->returnPayload(command, fh);
            std::cout<<res<<std::endl;
    };
    }






int main() {  
    auto fh_campus = FH("FH-Campus Wien", "Fachhochschule");
    Unit_Test_FH(fh_campus);
    url_handler(fh_campus);
    //Unit_Test_Person();
    //Unit_Test_FH(); 
   
     }




    