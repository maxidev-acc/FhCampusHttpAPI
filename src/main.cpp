#include <iostream>
#include "Studierender.h"
#include "Jahrgang.h"
#include "FHException.h"
#include "Hilfsfunktionen.h"
#include "FH.h"
#include "REQUEST.h"







void runtimeURLHandler(FH* fh){
        int runtime =1;
        std::cout<<"\n******************************************"<<std::endl;
        std::cout <<"Valide Routen:"<<std::endl;
        std::cout<< "fh/angestellter/<m_angestelltennummer>"<<std::endl; 
        std::cout<< "fh/student/<m_matrikelnummer>"<<std::endl; 
        std::cout<< "fh/jahrgang/<bezeichner>"<<std::endl;
        std::cout<< "fh/info"<<std::endl; 
        std::cout<<"\n******************************************"<<std::endl;
        while (runtime==1){
            std::cout <<"Please enter request URL:  "<<std::endl;
            std::string command;
            std::cin>>command;
            if(command == "exit") { break;}; 
            auto req = new REQUEST(command);
            std::string res = req->returnPayload(command, *fh);
            std::cout<<res<<std::endl;
            delete req;
    };
    }






int main(int argc, char *argv[]) { 
    auto fh_campus = new FH("FH-Campus Wien", "Fachhochschule");
    const std::string studentInputTxtFile = "Studierende.txt";
    const std::string jahrgangInputTextFile = "Jahrgaenge.txt";
    const std::string angestellteInputTxtFile = "Angestellte.txt";
 

    fh_campus->dataConfiguration(studentInputTxtFile, jahrgangInputTextFile, angestellteInputTxtFile);
    runtimeURLHandler(fh_campus);
    return 0;
     }




    