#ifndef STATISCHEDATEN_HPP__
#define STATISCHEDATEN_HPP__

#include<iostream>

class statischeDaten{
        public:
        statischeDaten(); ///Konstruktor der Klasse
        ~statischeDaten(); ///Destruktor der Klasse
        
        /**     
        *       Methode, die die Reichweite des reibungsfreien
        *       Wurfes in Abhaengigkeit der eingelesenen Werte
        *       berechnet und als Double zurueckgibt (genaue
        *       Rechnung in statischeDaten.cpp ).
        */
        double reichweite(double v, double w);
        
        /**
        *       Methode, die die Flugdauer des reibungsfreien
        *       Wurfes in Abhaengigkeit der eingelesenen Werte
        *       berechnet und als Double zurueckgibt (genaue
        *       Rechnung in statischeDaten.cpp).
        */        
        double flugdauer(double v, double w);
};

#endif //STATISCHEDATEN_HPP__
