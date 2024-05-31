
#include "httplib.h"
#include <iostream>
#include <iostream>
#include "Studierender.h"
#include "Jahrgang.h"
#include "FHException.h"
#include "Hilfsfunktionen.h"
#include "FH.h"
#include "REQUEST.h"
//#define CPPHTTPLIB_OPENSSL_SUPPORT



int main() {
    httplib::Server svr;
    auto fh_campus = new FH("FH-Campus Wien", "Fachhochschule");
    const std::string studentInputTxtFile = "Studierende.txt";
    const std::string jahrgangInputTextFile = "Jahrgaenge.txt";
    const std::string angestellteInputTxtFile = "Angestellte.txt";
    fh_campus->dataConfiguration(studentInputTxtFile, jahrgangInputTextFile, angestellteInputTxtFile);


    //Routen

    svr.Get("/", [](const httplib::Request &req, httplib::Response &res) {
        res.set_content("Restfull HTTP Interface for Coding Project BIOINF25", "text/plain");
    });


    svr.Get(R"(/student/(\d+))", [&fh_campus](const httplib::Request &req, httplib::Response &res) {
        auto numbers = req.matches[1];
        auto json = fh_campus->StudentAPIModell(numbers);
        res.set_content(json, "text/plain");
    });

       svr.Get(R"(/angestellter/(\d+))", [&fh_campus](const httplib::Request &req, httplib::Response &res) {
        auto numbers = req.matches[1];
        auto json = fh_campus->EmployeeAPIModell(numbers);
        res.set_content(json, "text/plain");
    });

       svr.Get(R"(/jahrgang/(\w+))", [&fh_campus](const httplib::Request &req, httplib::Response &res) {
        auto name = req.matches[1];
        auto json = fh_campus->JahrgangAPIModell(name);
        res.set_content(json, "text/plain");
    });

       svr.Get(R"(/info/)", [&fh_campus](const httplib::Request &req, httplib::Response &res) {
        //auto numbers = req.matches[1];
        auto json = fh_campus->FhAPIModell();
        res.set_content(json, "text/plain");
    });

    std::cout << "Starting server on http://localhost:8080" << std::endl;
    svr.listen("localhost", 8080);

    return 0;
}