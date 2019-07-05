#include "bahnkurve.hpp"
#include "math.h"
#include "TF1.h"
#include "TLegend.h"
#include "TApplication.h"
#include "TCanvas.h"

using namespace std;

#define PI 3.141592653

///Konstruktor definieren:
bahnkurve::bahnkurve() {
}

///Destruktor definieren:
bahnkurve::~bahnkurve() {
}

///Plots erstellen/ speichern
void bahnkurve::plot(double v, double w, double m, double r) {
        ///Grundlegende Variablen
        double x; double vy = (v * sin(w)); double vx = (v * cos(w));
        double g = 9.81;
        statischeDaten h;
        double d = h.reichweite(v, w); ///reichweite Methode aus statischeDaten
        
        ///Erstellen eines TCanvas, in dem die Bahnkurven angezeigt werden
        TApplication *a1 = new TApplication("a1", 0, 0);
        TCanvas *c1 = new TCanvas("c1", "Bahnkurven", 750, 500);
        
        ///Flugbahn ohne Reibung
        TF1 *f1 = new TF1("f1", "x * tan([1]) - [2]/(2*[0]*[0]*cos([1])*cos([1])) *x*x", 0., d);
        f1->SetParameter(0, v); f1->SetParameter(1, w); f1->SetParameter(2, g);
        
        ///Flugbahn mit Reibung
        double k = (6 * PI * 17.1 * 0.000001 * r/m); ///Reibungsfaktor/Masse nach STOKES
        
        TF1 *f2 = new TF1("f2", "[2]/([3]*[3]) * log(1 - [3]/[0] *x) + ([1] + [2]/[3]) * x/[0]", 0., d);
        f2->SetParameter(0, vx); f2->SetParameter(1, vy); f2->SetParameter(2, g); f2->SetParameter(3, k);
        f2->SetLineColor(4);
        f1->SetTitle("Bahnkurven");
        f1->Draw("c1"); 
        f2->Draw("same");
        
        ///Erstellen einer Legende
        auto legend = new TLegend(0.1, 0.7, 0.48, 0.9);
        legend->SetHeader("LEGENDE", "C");
        legend->AddEntry(f1, "Bahnkurve ohne Reibung", "L");
        legend->AddEntry(f2, "Bahnkurve mit Reibung", "L");
        legend->Draw("same");
        
        ///Erzeugen des TCanvas und speichern der Bahnkurven
        c1->Update();
        c1->Draw();
        c1->SaveAs("plot.png");
        
        a1->Run();
}
