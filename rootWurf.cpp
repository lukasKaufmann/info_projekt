#include<iostream>
#include<fstream>
#include<math.h>
#include<cmath>
#include "statischeDaten.hpp"
#include "bahnkurve.hpp"

using namespace std;

//#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

void rootWurf () {

	double v; double w; double wRad;

	///Eingabe der erforderlichen Daten (Geschw. , Winkel)
	cout << "Gib eine Abwurfgeschwindigkeit [m/s] ein:  " << endl;
	cin >> v;
	if (v <= 0) {
		cout << "Du wirfst deine Kugel nach hinten. Hast du vorher geschaut, ob da jemand steht? Bitte korrigiere deine Eingabe der Geschwindigkeit!" << endl;
		cin >> v;
	}
	cout << "Gib einen Abwurfwinkel zwischen 0 und 90 Grad ein:  " << endl;
	cin >> wRad; w = (wRad * PI/180);
	if (w <= 0 || w >= PI/2){
		cout << "Eingabe des Winkels kann nicht verwertet werden. Bitte gib einen Winkel zwischen 0 und 90 Grad ein!" << endl;
		cin >> wRad; w = (wRad * PI/180);
	}
	cout >> "Gib eine Masse [kg] ein:  " << endl;
	cin >> m;
	if (m <= 0) {
		cout << "Was ist negative Masse? Bitte korrigiere deine Eingabe der Masse!" << endl;
		cin >> m;
	}
	cout >> "Gib einen Radius [m] ein:  " << endl;
	cin >> r
	if (r<=0) {
		cout << "Du hast einen negativen Radius eingegeben. Bitte gib einen sinnvollen Radius ein!" << endl;
		cin >> r;
	}


	statischeDaten d ;
	cout << "Reichweite des Wurfes (ohne Reibung):  ";
	cout << d.reichweite(v, w) << endl;

	statischeDaten t;
	cout << "Dauer des Wurfes(ohne Reibung):  ";
	cout << t.flugdauer(v, w) << endl;

	bahnkurve s;
	s.plot(v, w);
}
