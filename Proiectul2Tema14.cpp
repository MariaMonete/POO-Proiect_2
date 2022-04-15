#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class ProcesAbs
{
public:

    virtual void tipProces() = 0;  //functie virtuala pura

};

class Proces :public ProcesAbs
{
protected:
    int nrProces;
    string reclamant;
    string reclamat;
    static int An;

public:

    //constructor de initializare
    Proces()
    {
        nrProces = 0;
        reclamant = "Anonim";
        reclamat = "Anonim";
    }

    //constructor cu parametrii
    Proces(int nrProces, string reclamant, string reclamat)
    {
        this->nrProces = nrProces;
        this->reclamant = reclamant;
        this->reclamat = reclamat;
    }

    //constructor de copiere
    Proces(const Proces& p)
    {
        this->nrProces = p.nrProces;
        this->reclamant = p.reclamant;
        this->reclamat = p.reclamat;
    }

    //Desctructorul
    ~Proces()
    {
        //nu avem variabile alocate dinamic
    }

    //Operatorul =
    Proces& operator=(const Proces& p)
    {
        this->nrProces = p.nrProces;
        this->reclamant = p.reclamant;
        this->reclamat = p.reclamat;

        return *this;
    }

    //operator<<
    friend ostream& operator<<(ostream& out, const Proces& p)
    {
        out << "Nr proces: " << p.nrProces << endl;
        out << "Reclamant: " << p.reclamant << endl;
        out << "Reclamat: " << p.reclamat << endl;

        return out;
    }

    //operator>>
    friend istream& operator>>(istream& in, Proces& p)
    {
        cout << "Nr proces= ";
        in >> p.nrProces;

        cout << "Reclamant= ";
        in >> ws;
        getline(in, p.reclamant);

        cout << "Reclamat= ";
        in >> ws;
        getline(in, p.reclamat);

        return in;
    }

    void setNrProces(int nrProces)
    {
        this->nrProces = nrProces;
    }

    int getNrProces()
    {
        return this->nrProces;
    }

    void setReclamant(string reclamant)
    {
        this->reclamant = reclamant;
    }

    string getReclamant()
    {
        return this->reclamant;
    }

    void setReclamat(string reclamat)
    {
        this->reclamat = reclamat;
    }

    string getReclamat()
    {
        return this->reclamat;
    }

    static void setAn(int an)
    {
        Proces::An = an;
    }

    static int getAn()
    {
        return An;
    }

    void tipProces()
    {
        cout << "Acesta este un proces normal" << endl;
    }
};

int Proces::An = 2022;

class Proces_civil : public Proces
{
    double dauneMorale;
    double dauneMateriale;
    int nrMartori;
    bool stadiu;

public:

    //constructor de initializare
    Proces_civil() :Proces()
    {
        dauneMorale = 0;
        dauneMateriale = 0;
        nrMartori = 0;
        if (nrMartori > 5)
            stadiu = 1;
        else
            stadiu = 0;
    }

    //constructor cu parametrii
    Proces_civil(int nrProces, string reclamant, string reclamat, double morale, double materiale, int martori) :Proces(nrProces, reclamant, reclamat)
    {
        this->dauneMorale = morale;
        this->dauneMateriale = materiale;
        this->nrMartori = martori;
        if (nrMartori > 5)
            this->stadiu = 1;
        else
            this->stadiu = 0;
    }

    //constructor de copiere
    Proces_civil(const Proces_civil& pc) : Proces(pc)
    {
        this->dauneMorale = pc.dauneMorale;
        this->dauneMateriale = pc.dauneMateriale;
        this->nrMartori = pc.nrMartori;
        if (nrMartori > 5)
            this->stadiu = 1;
        else
            this->stadiu = 0;
    }

    Proces_civil(const Proces& p) : Proces(p)
    {
        this->dauneMorale = 0;
        this->dauneMateriale = 0;
        this->nrMartori = 0;
        if (nrMartori > 5)
            this->stadiu = 1;
        else
            this->stadiu = 0;
    }

    //destructor
    ~Proces_civil()
    {

    }

    //operator =
    Proces_civil& operator=(const Proces_civil& pc)
    {
        Proces::operator=(pc);
        this->dauneMorale = pc.dauneMorale;
        this->dauneMateriale = pc.dauneMateriale;
        this->nrMartori = pc.nrMartori;
        if (nrMartori > 5)
            this->stadiu = 1;
        else
            this->stadiu = 0;

        return *this;
    }

    //operator <<
    friend ostream& operator<<(ostream& out, const Proces_civil& pc)
    {
        out << (Proces&)pc;
        out << "Daune morale: " << pc.dauneMorale << endl;
        out << "Daune materiale: " << pc.dauneMateriale << endl;
        out << "Nr martori: " << pc.nrMartori << endl;
        out << "Stadiu: " << pc.stadiu << endl;

        return out;
    }

    //operator >>
    friend istream& operator>>(istream& in, Proces_civil& pc)
    {
        in >> (Proces&)pc;
        cout << "Daune morale= ";
        in >> pc.dauneMorale;
        cout << "Daune materiale= ";
        in >> pc.dauneMateriale;
        cout << "Nr martori= ";
        in >> pc.nrMartori;
        if (pc.nrMartori > 5)
            pc.stadiu = 1;
        else
            pc.stadiu = 0;

        return in;
    }

    void setDauneMorale(double dauneMorale)
    {
        this->dauneMorale = dauneMorale;
    }

    double getDauneMorale()
    {
        return this->dauneMorale;
    }

    void setDauneMateriale(double dauneMateriale)
    {
        this->dauneMateriale = dauneMateriale;
    }

    double getDauneMateriale()
    {
        return this->dauneMateriale;
    }

    void setNrMartori(int nrMartori)
    {
        this->nrMartori = nrMartori;
        if (this->nrMartori > 5)
            this->stadiu = 1;
        else
            this->stadiu = 0;
    }

    int getNrMartori()
    {
        return this->nrMartori;
    }

    bool getStadiu()
    {
        return this->stadiu;
    }

    double taxaTimbru()
    {
        double taxa = (10 * this->dauneMorale) / 100 + (10 * dauneMateriale) / 100;
        return taxa;
    }

    void tipProces()
    {
        cout << "Acesta este un proces civil" << endl;
    }

    void setStadiu(bool stadiu)
    {
        this->stadiu = stadiu;
    }
};


class Proces_penal :public Proces
{
    int dovezi;
    bool stadiu;

public:

    //constructor de initializare
    Proces_penal() :Proces()
    {
        dovezi = 0;
        if (dovezi > 25)
            stadiu = 1;
        else
            stadiu = 0;

    }

    //constructor cu parametrii
    Proces_penal(int nrProces, string reclamant, string reclamat, int dovezi) :Proces(nrProces, reclamant, reclamat)
    {
        this->dovezi = dovezi;
        if (this->dovezi > 25)
            this->stadiu = 1;
        else
            this->stadiu = 0;
    }

    //constructor de copiere
    Proces_penal(const Proces_penal& pp) : Proces(pp)
    {
        this->dovezi = pp.dovezi;
        if (this->dovezi > 25)
            this->stadiu = 1;
        else
            this->stadiu = 0;
    }

    Proces_penal(const Proces& pp) : Proces(pp)
    {
        this->dovezi = 0;
        if (this->dovezi > 25)
            this->stadiu = 1;
        else
            this->stadiu = 0;
    }

    //destructor
    ~Proces_penal()
    {

    }

    //operator =
    Proces_penal& operator=(const Proces_penal& pp)
    {
        Proces::operator=(pp);
        this->dovezi = pp.dovezi;
        if (this->dovezi > 25)
            this->stadiu = 1;
        else
            this->stadiu = 0;

        return *this;
    }

    //operator <<
    friend ostream& operator<<(ostream& out, const Proces_penal& pp)
    {
        out << (Proces&)pp;
        out << "Dovezi: " << pp.dovezi << endl;
        out << "Stadiu: " << pp.stadiu << endl;

        return out;
    }

    //operator >>
    friend istream& operator>>(istream& in, Proces_penal& pp)
    {
        in >> (Proces&)pp;
        cout << "Dovezi= ";
        in >> pp.dovezi;
        if (pp.dovezi > 25)
            pp.stadiu = 1;
        else
            pp.stadiu = 0;

        return in;
    }

    void setDovezi(int dovezi)
    {
        this->dovezi = dovezi;
        if (this->dovezi > 25)
            this->stadiu = 1;
        else
            this->stadiu = 0;
    }

    int getDovezi()
    {
        return this->dovezi;
    }

    bool getStadiu()
    {
        return this->stadiu;
    }

    void tipProces()
    {
        cout << "Acesta este un proces penal" << endl;
    }

    void setStadiu(bool stadiu)
    {
        this->stadiu = stadiu;
    }

};


int main()
{
    //verificare constructori si operator = pt proces
    Proces p1;
    Proces p2(15, "Chirita Andrei", "Zidaru Razvan");
    Proces p3 = p2;
    Proces p4;
    p4 = p2;

    //verificare operator << pentru proces
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;

    //pentru verificare operator >>

    /*Proces p5;
    cin >> p5;
    cout << p5 << endl;*/

    //verificare contructori pt proces_civil
    Proces_civil pc1;
    Proces_civil pc2(25, "Serban Ovidiu", "Ene Andrei", 2.5, 4.5, 6);
    Proces_civil pc3(26, "Nicolae Paul", "Pantucu Alex", 2.5, 4, 3);
    Proces_civil pc4(27, "Marinescu Cosmin", "Daniel Silviu", 1.5, 7.4, 10);
    Proces_civil pc5;

    //afisarea procesului civil cu cea mai mare taxa de trimbru
    Proces_civil pcmax = pc1;  //verificare operator =  pt proces_civil
    Proces_civil vector[] = { pc1,pc2,pc3,pc4,pc5 };

    for (int i = 0; i < 5; i++)
        if (pcmax.taxaTimbru() < vector[i].taxaTimbru())
            pcmax = vector[i];

    cout << "Procesul civil cu cea mai mare taxa de trimbru este: " << pcmax << endl;

    //verificare operator << pt proces_civil
    cout << pc1 << endl;
    cout << pc2 << endl;
    cout << pc3 << endl;
    cout << pc4 << endl;

    //verificare operator >> pt proces_civil
   /* Proces_civil pc;
    cin >> pc;
    cout <<pc << endl;*/


    //verificare constructori si operator = pt proces_penal
    Proces_penal pp1;
    Proces_penal pp2(33, "Ivana Florin", "Vlad Roland", 26);
    Proces_penal pp3 = pp2;
    Proces_penal pp4;
    pp4 = pp2;


    //verificare operator << pt proces_penal
    cout << pp1 << endl;
    cout << pp2 << endl;
    cout << pp3 << endl;
    cout << pp4 << endl;

    //verificare operator >> pt proces_penal
    /*Proces_penal pp5;
    cin >> pp5;
    cout << pp5 << endl;*/

    //verificare functie taxaTimbru pt proces_civil
    cout << pc2.taxaTimbru() << endl;

    //verificare functie static pt proces_penal
    /*cout << pp2.getAn() << endl;
    pp2.setAn(2019);
    cout << pp2.getAn() << endl;*/






    //up-casting
    Proces* pointerProces = &pc2;
    cout << *pointerProces;
    pointerProces->tipProces();
    cout << endl;



    //down-casting
    Proces_penal* pointerPenal = (Proces_penal*)(&p2);
    cout << p2;
    p2.tipProces();
    cout << endl;
    cout << *pointerPenal;
    pointerPenal->tipProces();

    /*cout << "stadiu:";
    pc1.setStadiu(1);
    cout << pc1;*/

    //cout << pointerPenal->getDovezi();   //verificare getter dovezi


    //cout << pc3.getNrProces();

    int n;
    cin >> n;
    Proces* v = new Proces[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
    int m;
    cin >> m;
    Proces_civil* w = new Proces_civil[m];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cout << w[i];
    }
    int p;
    cin >> p;
    Proces_penal* x = new Proces_penal[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cout << x[i];
    }
}


