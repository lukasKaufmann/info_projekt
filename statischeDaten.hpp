#ifndef STATISCHEDATEN_HPP__
#define STATISCHEDATEN_HPP__

#include<iostream>

class statischeDaten{
        public:
        statischeDaten(); ///Konstruktor der Klasse
        ~statischeDaten(); ///Destruktor der Klasse
        
        ///Funktion zur Berechnung der Reichweite des
        ///reibungsfreien Wurfes
        double reichweite(double v, double w);
        
        ///Funktion zur Berechnung der Flugdauer des
        ///reibungsfreien Wurfes
        double flugdauer(double v, double w);
};

#endif //STATISCHEDATEN_HPP__
