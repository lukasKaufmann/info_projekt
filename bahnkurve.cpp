#include "bahnkurve.hpp"
#include "math.h"

using namespace std;
#define PI 3.141592653

bahnkurve::bahnkurve() {
}

bahnkurve::~bahnkurve() {
}

void bahnkurve::plot(double v, double w) {
        double x; double vy = (v * sin(w)); double vx = (v * cos(w));
        statischeDaten h;
        double d = h.reichweite(v, w);
        
        ///Flugbahn ohne Reibung
        TF1 *f1 = new TF1("fVakuum", "x * tan([1]) - 9.81/(2*[0]*[0]*cos([1])*cos([1])) *x*x", 0., d);
        f1->SetParameter(0, v); f1->SetParameter(1, w);
        
        ///Flugbahn mit Reibung
        double k = (6 * PI * 17.1 * 0.001 * 1/15);
        double g = 9.81;
        
        TF1 *f2 = new TF1("fReibung", "[2]/([1]*[1]) * log(1 - [1]/[3] *x) + ([0] + [2]/[1]) * x/[3]", 0., d);
        f2->SetParameter(0, vy); f2->SetParameter(1, k); f2->SetParameter(2, g); f2->SetParameter(3, vx);
        f2->SetLineColor(4);
        f1->SetTitle("Bahnkurven");
        f1->Draw();
        f2->Draw("same");
}
