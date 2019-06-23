#include "statischeDaten.hpp"
#include "math.h"

///Konstruktor definieren:
statischeDaten::statischeDaten(){
        //wüsste nicht, was der wichtiges machen müsste
}

///Destruktor definieren:
statischeDaten::~statischeDaten(){
        //hier auch nicht
}

///Wurfweite berechnen:
double statischeDaten::reichweite(double v, double w){
        return ( (v*v)/9.81 * sin(2*w) );
}
