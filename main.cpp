#include <iostream>
#include "Studierender.h"
#include "Jahrgang.h"
#include "FHException.h"
#include "Hilfsfunktionen.h"
#include "FH.h"
#include "REQUEST.h"

std::string consoleLogSeperator(){
    return "\n___________________________________\n";
}




void Unit_Test_FH(FH& fh_campus) {

    std::cout<<"\n*****************************************\n"<<std::endl;
    
    std::cout <<"Unit Test. FH Objekt instanziert." << std::endl;
    
    
    std::cout << consoleLogSeperator();
    std::cout<<fh_campus.StudentAPIModell("11111")<< std::endl;
    std::cout << consoleLogSeperator();
    std::cout<<fh_campus.EmployeeAPIModell("100")<< std::endl;
    std::cout << consoleLogSeperator();
    std::cout<<fh_campus.JahrgangAPIModell("BIOINF25")<< std::endl;
    std::cout << consoleLogSeperator();
    std::cout<<fh_campus.JahrgangAPIModell("MACHINE23")<< std::endl;
    std::cout << consoleLogSeperator();
    std::cout<<fh_campus.JahrgangAPIModell("ANALYT_CHEM23")<< std::endl;
    std::cout << consoleLogSeperator();
    std::cout<<fh_campus.JahrgangAPIModell("BIOCHEM22")<< std::endl;
    std::cout << consoleLogSeperator();
    std::cout << consoleLogSeperator();
    std::cout<<fh_campus.FhAPIModell()<< std::endl;
    std::cout<<"Alle FH_API_Modelle erfolgreich getestet. Laufzeit wird vorbereitet "<<std::endl;
    std::cout<<"\n*****************************************\n"<<std::endl;

}

   



void runtimeURLHandler(FH& fh){
        int runtime =1;
        std::cout <<"Valide Routen:"<<std::endl;
        std::cout<<consoleLogSeperator();
        std::cout<< "fh/angestellter/<m_angestelltennummer>"<<std::endl; 
        std::cout<< "fh/student/<m_matrikelnummer>"<<std::endl; 
        std::cout<< "fh/jahrgang/<bezeichner>"<<std::endl;
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
    std::string studentInputTxtFile = "Studierende.txt";
    std::string jahrgangInputTextFile = "Jahrga.txt";
    std::string angestellteInputTxtFile = "Angestellte.txt";
    fh_campus.setupData(studentInputTxtFile, jahrgangInputTextFile, angestellteInputTxtFile);


    Unit_Test_FH(fh_campus);
    runtimeURLHandler(fh_campus);
    return 0;
     }




    