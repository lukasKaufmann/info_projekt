#include<iostream>
#include<fstream>
#include<math.h>
#include<cmath>

class statischeDaten {
	public:
	double v; double w;
	
	/// Funktion zur Berechnung der Wurfweite mit Geschw. v unter Winkel w
	double reichweite (double v, double w) {
		return ((v*v)/9.81 * sin(2*w));
	}

	/// Funktion zur Berechnung der Flugdauer mit Geschw. v unter Winkel w
	double flugdauer (double v, double w) {
		return (2/9.81 * v * sin(w));
	}
};

void wurf_root () {
	#define PI 3.14159265
	using namespace std;

	double veloc;
	double winkel;
	double wRad;

	///Eingabe der erforderlichen Daten (Geschw. , Winkel)
	cout << "Enter velocity [m/s]:  " << endl;
	cin >> veloc;
	cout << "Enter angle between 0 and 90 degrees:  " << endl;
	cin >> wRad; winkel = (wRad * PI/180);

	statischeDaten d ;
	cout << "Reichweite des Wurfes:  ";
	cout << d.reichweite(veloc, winkel) << endl;

	statischeDaten t;
	cout << "Dauer des Wurfes:  ";
	cout << t.flugdauer(veloc, winkel) << endl;
}
