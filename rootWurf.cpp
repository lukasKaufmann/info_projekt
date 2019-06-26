#include<iostream>
#include<fstream>
#include<math.h>
#include<cmath>
#include "statischeDaten.hpp"
#include "bahnkurve.hpp"

using namespace std;

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

void rootWurf () {

	double v; double w; double wRad;

	///Eingabe der erforderlichen Daten (Geschw. , Winkel)
	cout << "Enter velocity [m/s]:  " << endl;
	cin >> v;
	cout << "Enter angle between 0 and 90 degrees:  " << endl;
	cin >> wRad; w = (wRad * PI/180);

	statischeDaten d ;
	cout << "Reichweite des Wurfes:  ";
	cout << d.reichweite(v, w) << endl;

	//statischeDaten t;
	//cout << "Dauer des Wurfes:  ";
	//cout << t.flugdauer(v, w) << endl;

	bahnkurve s;
	s.plot(v, w);
}
