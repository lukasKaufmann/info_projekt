#include<iostream>
#include<fstream>
#include<math.h>
#include<cmath>
#include "statischeDaten.hpp"

using namespace std;

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

class bahnkurve {
	public:
	///Funktion zum Plotten der Wurfparabel
	void plot_bahn (double v, double w) {
		float x; float vy = v * sin(w); float vx = v * cos(w);
		statischeDaten h;
		double d = h.reichweite(v, w);
		///Erstellt Wurfparabel (ohne Reibung) mit Parametern 0 = Abwurfgeschw. v und 1 = Abwurfwinkel w
		TF1 *f1 = new TF1("f1", "x*tan([1]) - 9.81/(2*[0]*[0]*cos([1])*cos([1])) *x*x", 0., d);
		f1->SetParameter(0, v);
		f1->SetParameter(1, w);
		//f1->Draw();
		///Wurf in Luft
		float k = 6 * PI * 17.1 * 0.000001 * v * 1/15; ///Reibungsfaktor
		double g = 9.81;
		float tU = -1/k * log( g/(k * (vy + g/k)) ); ///Umkehrzeitpunkt
		
		ofstream outputFile;
		outputFile.open("reibung_bahn.txt");
	        for (float t = 0; t/10 < tU; t++) {
                	float x_t = -vx/k * exp(-k * t/10) + vx/k;
                        float y_t = -(vy * k + g)/(k*k) * exp(-k * t/10) - (g/k * t/10) + (vy * k + g)/(k*k);
                        //cout << x_t << "  " << y_t << endl;
                        outputFile << x_t << "  " << y_t << endl;
                };
                outputFile.close();
                TGraph *gr = new TGraph("reibung_bahn.txt");
                f1->Draw();
                gr->Draw("same");

	}
};

void rootWurf () {

	double v; double w; double wRad;

	///Eingabe der erforderlichen Daten (Geschw. , Winkel)
	cout << "Enter velocity [m/s]:  " << endl;
	cin >> v;
	cout << "Enter angle between 0 and 90 degrees:  " << endl;
	cin >> wRad; w = (wRad * PI/180); //mir fällt gerade auf, dass wir eventuell immer mit nem falschen winkel rechnen

	statischeDaten d ;
	cout << "Reichweite des Wurfes:  ";
	cout << d.reichweite(v, w) << endl;

	//statischeDaten t;
	//cout << "Dauer des Wurfes:  ";
	//cout << t.flugdauer(v, w) << endl;

	bahnkurve s;
	s.plot_bahn(v, w);
}
