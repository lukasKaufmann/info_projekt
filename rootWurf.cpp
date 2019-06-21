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
		float x; float vy = v * sin(w); float vx = v * cos(w);
		statischeDaten h;
		double d = h.reichweite(v, w);
		///Erstellt Wurfparabel (ohne Reibung) mit Parametern 0 = Abwurfgeschw. v und 1 = Abwurfwinkel w
		TF1 *f1 = new TF1("f1", "x*tan([1]) - 9.81/(2*[0]*[0]*cos([1])*cos([1])) *x*x", 0., d);
		f1->SetParameter(0, v);
		f1->SetParameter(1, w);
		//f1->Draw();
		///Wurf in Luft
		float k = 6 * Pi * 17.1 * 0.000001 * v * 1/15; ///Reibungsfaktor
		double g = 9.81;
		float tU = -1/k * log( g/(k * (vy + g/k) ); ///Umkehrzeitpunkt
		
		ofstream outputFile;
		outputFile.open("reibung_bahn.txt");
	        for (float t = 0; t/10 < tU; t++) {
                	float x_t = -vx/k * exp(-k * t/10) + vx/k;
                        float y_t = -(vy * k + g)/(k*k) * exp(-k * t/10) - (g/k * t/10) + (vy * k + g)/(k*k);
                        //cout << x_t << "  " << y_t << endl;
                        outputFile << x_t << "  " << y_t << endl;
                };
                outputFile.close();
                TGraph *gr = new TGraph("reibung.txt");
                f1->Draw();
                gr->Draw("same");

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
