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

class bahnkurve {
	public:
	///Funktion zum Plotten der Wurfparabel
	void plot_bahn (double v, double w) {
		float x;
		statischeDaten h;
		h.reichweite(v, w);
		///Erstellt Wurfparabel mit Parametern 0 = Abwurfgeschw. v und 1 = Abwurfwinkel w
		TF1 *f1 = new TF1("f1", "x*tan([1]) - 9.81/(2*[0]*[0]*cos([1])*cos([1])) *x*x", 0., h);
		f1->SetParameter(0, v);
		f1->SetParameter(1, w);
		f1->Draw();
	}
};

void rootWurf () {
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

	bahnkurve s;
	s.plot_bahn(veloc, winkel);
}
