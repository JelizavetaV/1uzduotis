

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::fixed;
using std::setw;
using std::left;
//streamsize prec = cout.precision();


struct studentas {
    string vard, pavard;
    float nd[10]{};
    float egz;
    float galv;
    float galm;
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
    cout << setw(10) << left << "Vardas" << setw(10) << left << "Pavarde" << setw(8) << left << "GalVid" << setw(8) << left << "GalMed" << endl;
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
    float median = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> kint.nd[i];
        sum += kint.nd[i];
    }
    vid = sum / n;
    
    cout << "iveskite egzamino pazymi: "; cin >> kint.egz;
    kint.galv = vid * 0.4 + kint.egz*0.6;
    int temp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (kint.nd[j] > kint.nd[j + 1]) {
                temp = kint.nd[j];
                kint.nd[j] = kint.nd[j + 1];
                kint.nd[j + 1] = temp;
            }
        }
    }
    if (n % 2 == 1)
        kint.galm = kint.nd[n / 2];
    else kint.galm = (kint.nd[n / 2 - 1] + kint.nd[n / 2]) / 2;
         
}
//----------------------------------------
void printas(studentas& kin)
{
    cout << setw(10)<<left<<"  "<<kin.vard << "  " << setw(10)<<left<< kin.pavard<<"  ";

    cout << kin.egz << "  ";
    
    cout << fixed <<setprecision(3)  << "  "<<setw(7) << kin.galv << "  ";
    cout << fixed << setprecision(3)  << "  " << setw(7) << kin.galm << endl;
    
}














// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
