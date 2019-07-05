#ifndef BAHNKURVE_HPP__
#define BAHNKURVE_HPP__ 

#include<iostream>
#include "statischeDaten.hpp"

class bahnkurve: public statischeDaten {
        public:
        bahnkurve(); ///Konstruktor der Klasse
        ~bahnkurve(); ///Destruktor der Klasse
        
        /**
        *       Methode, die mit den eingelesenen Daten beide Plots
        *       erstellt, in ein Canvas malt und anzeigt/ speichert
        *       (genaue Vorgehensweise in bahnkurve.cpp).
        */
        void plot(double v, double w, double m, double r);
};

#endif //BAHNKURVE_HPP__
