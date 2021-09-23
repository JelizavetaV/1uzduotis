#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::fixed;
using std::setw;
using std::left;


struct studentas {
    string vard, pavard;
    float nd[10]{};
    float egz;
    float gal;
};

void pildimas(studentas& kint);
void printas(studentas& kin);

int main()
{
    studentas st1;
    studentas st2{ "Vardas2", "Pavarde2", {5,8,7,4,5,8,9,5,4},9,0 };
    studentas studentai[10];
    for (int i = 0; i < 3; i++)
    {
        pildimas(studentai[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printas(studentai[i]);
    }


}
//------------
void pildimas(studentas& kint)
{
    int n;
    cout << "iveskite studento varda ir pavarde:"; cin >> kint.vard >> kint.pavard;
    cout << "kiek namu darbus bus:"; cin >> n;
    cout << "iveskite pazymius:" << endl;
    float sum = 0;
    float vid = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> kint.nd[i];
        sum += kint.nd[i];
    }
    vid = sum / n;
    
    cout << "iveskite egzamino pazymi: "; cin >> kint.egz;
    kint.gal = vid * 0.4 + kint.egz*0.6;
}
//----------------------------------------
void printas(studentas& kin)
{
    cout << setw(10)<<left<<kin.vard << "  " << setw(10)<<left<< kin.pavard<<"  ";
    for (int i = 0; i < sizeof(kin.nd) / sizeof(kin.nd[0]); i++)
    {
        cout <<setw(4)<< kin.nd[i] << " ";
    }
    cout << "Egzaminas" << "  " << kin.egz << "  ";
    cout << fixed <<std::setprecision(2) << "Galutinis : " << "  "<<setw(7) << kin.gal << endl;
    
}
