#include<iostream>
#include<string>
#include<cmath>

#define PI 3.14159265

using namespace std;

class statische_daten {
	public:
		double v;
		double w;
	///
	/// Funktion zur Errechnung der Reichweite des Wurfes
	///
	double reichweite (double v, double w) {
		return ((v * v)/9.81 * sin(2*w));
	}
	
	///
	/// Funktion zur Berechnung der Wurfdauer
	///
	double flugdauer (double v, double w) {
		return (2/9.81 * v * sin(w));
	}
};

int main() {
	double winkel, veloc, wRad;
	double g = 9.81;
	
	///
	///Eingabe der erforderlichen Angaben (Abwurfgeschw., -winkel)
	///
	cout << "Enter a velocity [m/s]: " << endl;
	cin >> veloc;
	cout << "Enter an angle a between 0 and 90 degrees: " << endl;
	cin >> wRad;
	winkel = (wRad * PI/180);

	double vx = sin(winkel);
	double vy = cos(winkel);
	
	///
	///Berechnung statischer Daten der Bahnkurve
	///
	statische_daten d;
	cout << "Die Reichweite des Wurfes beträgt:  ";
	cout << d.reichweite (veloc, winkel) << "m" << endl;

	statische_daten t;
	cout << "Die Flugdauer beträgt:  ";
	cout << t.flugdauer (veloc, winkel) << "s" << endl;
	return 0;
}
