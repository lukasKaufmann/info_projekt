#ifndef BAHNKURVE_HPP__
#define BAHNKURVE_HPP__ 

#include<iostream>

class bahnkurve: public statischeDaten {
        public:
        bahnkurve();
        ~bahnkurve();
        
        void plot(double v, double w, double m, double r);
};

#endif //BAHNKURVE_HPP__
