#include <iostream>
#include <vector>
#include <string>

using namespace std;
///------------------------------------------------------------------------------------------------------------
class IO{
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) const = 0;
};

class Web_Dev: public IO{
protected:
       string nume;
       string prenume;
       int varsta;
       vector<string> tehnologii;
       int experienta;
       float salariu;
       string nivel;

public:
    Web_Dev(string nume="Anonim",
            string prenume="Anonim",
            int varsta=0,
            vector<string> tehnologii= vector<string>(),
            int experienta=0,
            float salariu=0,
            string nivel="junior");
    int getExperienta() {return this->experienta;}
    string getNumeDev() {return this->nume;}
    Web_Dev(const Web_Dev& dev);
    virtual Web_Dev& operator=(const Web_Dev& dev);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    friend istream& operator>>(istream& in, Web_Dev& dev);
    friend ostream& operator<<(ostream& out, const Web_Dev& dev);
    virtual ~Web_Dev() {};
    virtual void participare_curs() = 0;
};

class frontEnd_dev: virtual public Web_Dev{
protected:
        int creativitate;
        int imaginatie;
        int flexibilitate;
        int atentie_la_detalii;
public:
    frontEnd_dev(string nume="Anonim",
                 string prenume="Anonim",
                 int varsta=0,
                 vector<string> tehnologii = vector<string>(),
                 int experienta=0, float salariu=0,
                 string nivel="junior",
                 int creativitate = 0,
                 int imaginatie = 0,
                 int flexibilitate = 0,
                 int atentie_la_detalii = 0);
    frontEnd_dev(const frontEnd_dev& dev);
    virtual frontEnd_dev operator=(const frontEnd_dev& dev);
    //friend frontEnd_dev operator=(Web_Dev& wb, frontEnd_dev& fd);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    friend istream& operator>>(istream& in, frontEnd_dev& dev);
    friend ostream& operator<<(ostream& out, const frontEnd_dev& dev);
    virtual ~frontEnd_dev() {};
    virtual void participare_curs();
};

class backEnd_dev: virtual public Web_Dev{
protected:
    int problem_solving;
    int gandire_logica;
    int Efficient_Time_Management;
public:
    backEnd_dev(string nume="Anonim",
                string prenume="Anonim",
                int varsta=0,
                vector<string> tehnologii= vector<string>(),
                int experienta=0,
                float salariu=0,
                string nivel="junior",
                int problem_solving = 0,
                int gandire_logica = 0,
                int Efficient_Time_Management = 0);
    backEnd_dev(const backEnd_dev& dev);
    virtual backEnd_dev operator=(const backEnd_dev& dev);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    friend istream& operator>>(istream& in, backEnd_dev& dev);
    friend ostream& operator<<(ostream& out, const backEnd_dev& dev);
    virtual ~backEnd_dev() {};
    virtual void participare_curs();
};

class fullStack_dev: virtual public frontEnd_dev, virtual public backEnd_dev{
protected:
    int leadership;
    int comunicare_eficienta;
    int coordonare;
public:
    fullStack_dev(string nume="Anonim",
                  string prenume="Anonim",
                  int varsta=0,
                  vector<string> tehnologii= vector<string>(),
                  int experienta=0, float salariu=0,
                  string nivel="junior",
                  int creativitate = 0,
                  int imaginatie = 0,
                  int flexibilitate = 0,
                  int atentie_la_detalii = 0,
                  int problem_solving = 0,
                  int gandire_logica = 0,
                  int Efficient_Time_Management = 0,
                  int leadership = 0,
                  int comunicare_eficienta = 0,
                  int coordonare = 0);
    fullStack_dev(const fullStack_dev& dev);
    fullStack_dev operator=(const fullStack_dev& dev);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    friend istream& operator>>(istream& in, fullStack_dev& dev);
    friend ostream& operator<<(ostream& out, const fullStack_dev& dev);
    virtual ~fullStack_dev() {};
    virtual void participare_curs();
};


class Proiect{
    string nume_proiect;
    fullStack_dev Team_Leader;
    int nr_oameni;
    vector<Web_Dev*> echipa;
    string deadline;
public:
    Proiect();
    Proiect(string nume_proiect, fullStack_dev Team_Leader, int nr_oameni, vector<Web_Dev*> echipa, string deadline);
    Proiect(const Proiect& P);
    Proiect operator=(const Proiect& P);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    friend istream& operator>>(istream& in, Proiect& P);
    friend ostream& operator<<(ostream& out, const Proiect& P);
    string getNume() {return this->nume_proiect;}
    fullStack_dev getTL() {return this->Team_Leader;}
    int getNr() {return this->nr_oameni;}
    vector<Web_Dev*> getEchipa() {return this->echipa;}
    void setNume(string nume_proiect);
    void setTL(fullStack_dev TL);
    void setEchipa(int nr_oameni, vector<Web_Dev*> echipa);
    void setDeadline(string deadline);
    void concediere();
    ~Proiect();
};

///-------------------------------------------------------------------------------------------------------------
void CRUD_menu(int &ch);
void Create(int &ch);
void Read(vector<Proiect> proiecte, int &ch);
int Update(vector<Proiect> proiecte);
///-------------------------------------------------------------------------------------------------------------
int main() {

    int ch = -1;
    vector<Proiect> proiecte;
    cout<<"Aceasta este o aplicatie ce gestioneaza proiectele unei companii de Web development\n";
    CRUD_menu(ch);
    while(ch != 7){
        switch(ch){
            case 1:{
                Create(ch);
                while(ch != 3){
                    if(ch == 1){
                        Proiect aux;
                        proiecte.push_back(aux);
                    }
                    else{
                        Proiect aux;
                        cin>>aux;
                        proiecte.push_back(aux);
                    }
                    cout<<"\nProiect creat cu succes!\n";
                    Create(ch);
                }
                break;
            }
            case 2:{
                Read(proiecte, ch);
                if(ch != -1){
                    cout<<proiecte[ch-1];
                }
                break;
            }
            case 3:{
                Read(proiecte, ch);
                if(ch != -1){
                    int rez = Update(proiecte);
                    while(rez != 5){
                        switch(rez){
                            case 1:{
                                string aux;
                                cout<<"\nIntroduceti noul nume al proiectului: ";
                                cin.get();
                                getline(cin, aux);
                                proiecte[ch-1].setNume(aux);
                                break;
                            }
                            case 2:{
                                fullStack_dev aux;
                                cout<<"\nIntroduceti datele noului team leader: "; cin>>aux;
                                proiecte[ch-1].setTL(aux);
                                break;
                            }
                            case 3:{
                                int nr_oameni;
                                vector<Web_Dev*> echipa;
                                cout<<"\nIntroduceti noul numar de oameni din echipa: "; cin>>nr_oameni;
                                for(int i=0;i<nr_oameni;i++){
                                    string aux1;
                                    cout<<"\nIntroduceti specializarea developerului "<< i+1 <<": [front-end/back-end] "; cin>>aux1;
                                    if(aux1 == "front-end"){
                                        frontEnd_dev *aux = new frontEnd_dev;
                                        cin>>*aux;
                                        echipa.push_back(aux);
                                    }
                                    else{
                                        backEnd_dev *aux = new backEnd_dev();
                                        cin>>*aux;
                                        echipa.push_back(aux);
                                    }
                                }
                                proiecte[ch-1].setEchipa(nr_oameni, echipa);
                                break;
                            }
                            case 4:{
                                string aux;
                                cout<<"\nIntroduceti noul deadline al proiectului: "; cin>>aux;
                                proiecte[ch-1].setDeadline(aux);
                                break;
                            }
                        }
                        cout<<"\nProiect modificat cu succes!\n";
                        rez = Update(proiecte);
                    }
                }
                break;
            }
            case 4:{
                Read(proiecte, ch);
                if(ch != -1){
                    if(proiecte.size() > 1){
                        for(int i=ch-1; i<proiecte.size()-1;i++)
                            proiecte[i] = proiecte[i+1];
                    }
                    proiecte.pop_back();
                    cout<<"\nProiect sters cu succes!\n";
                }
                break;
            }
            case 5:{
                cout<<"\nAlegeti un proiect:\n";
                Read(proiecte, ch);
                if(ch != -1){
                    int rez = ch-1;
                    cout<<"\nCine doriti sa participe la curs:\n";
                    cout<<"1."<<proiecte[rez].getTL().getNumeDev()<<endl;
                    int index = 2;
                    for(int i=0;i<proiecte[rez].getNr();i++){
                        cout<<index<<"."<<proiecte[rez].getEchipa()[i]->getNumeDev()<<endl;
                        index++;
                    }
                    cout<<index<<".Inapoi\n";
                    cout<<"\nAlegerea este: "; cin>>ch;
                    if(ch != index){
                        int ok = 1;
                        while(ch<1 || ch>index){
                            cout<<"\nVa rog selectati o optiune valida(intre 1 si "<<index<<")\n";
                            cout<<"Alegerea este: ";cin>>ch;
                            if(ch == index)
                                ok = 0;
                        }
                        if(ok == 1){
                            if(ch == 1) {
                                fullStack_dev aux;
                                aux = proiecte[rez].getTL();
                                aux.participare_curs();
                                proiecte[rez].setTL(aux);
                            }
                            else{
                                vector<Web_Dev*> aux;
                                for(int i=0; i<proiecte[rez].getNr();i++){
                                    if(i == ch-2){
                                        Web_Dev* wd;
                                        wd = proiecte[rez].getEchipa()[i];
                                        wd->participare_curs();
                                        aux.push_back(wd);
                                    }
                                    else
                                        aux.push_back(proiecte[rez].getEchipa()[i]);
                                }
                                proiecte[rez].setEchipa(proiecte[rez].getNr(), aux);
                            }
                        }
                    }
                }
                break;
            }
            case 6:{
                Read(proiecte, ch);
                if(ch != -1) {
                    proiecte[ch-1].concediere();
                }
                break;
            }
        }
        CRUD_menu(ch);
    }

    return 0;
}

///------------------------------------------------------------------------------------------------------------
///web dev
Web_Dev::Web_Dev(string nume, string prenume, int varsta, vector<string> tehnologii, int experienta, float salariu,
                 string nivel){
    this->nume = nume;
    this->prenume = prenume;
    this->varsta = varsta;
    this->experienta = experienta;
    this->salariu = salariu;
    this->nivel = nivel;
    for(int i = 0; i<tehnologii.size();i++){
        this->tehnologii[i] = tehnologii[i];
    }
}
Web_Dev::Web_Dev(const Web_Dev &dev) {
    this->nume = dev.nume;
    this->prenume = dev.prenume;
    this->varsta = dev.varsta;
    this->experienta = dev.experienta;
    this->salariu = dev.salariu;
    this->nivel = dev.nivel;
    for(int i = 0; i<dev.tehnologii.size();i++){
        this->tehnologii.push_back(dev.tehnologii[i]);
    }
}

Web_Dev &Web_Dev::operator=(const Web_Dev &dev) {
    if(this != &dev){
        this->nume = dev.nume;
        this->prenume = dev.prenume;
        this->varsta = dev.varsta;
        this->experienta = dev.experienta;
        this->salariu = dev.salariu;
        this->nivel = dev.nivel;
        for(int i = 0; i<dev.tehnologii.size();i++){
            this->tehnologii.push_back(dev.tehnologii[i]);
        }
    }
    return *this;
}

istream &Web_Dev::read(istream &in) {
    cout<<"\nIntroduceti datele unui nou developer:\n";
    cout<<"Numele: "; in>>this->nume;
    cout<<"Prenumele: "; in>>this->prenume;
    cout<<"Varsta: "; in>>this->varsta;
    cout<<"Ce tehnologii cunoaste?\n";
    int ok = 1;
    while(ok == 1){
        cout<<"Nume tehnologie: ";
        string aux;
        in>>aux;
        this->tehnologii.push_back(aux);
        cout<<"Doriti sa adaugati o noua tehnologie?[0/1] "; in>>ok;
    }
    cout<<"Cata experienta are? "; in>>this->experienta;
    cout<<"Ce salariu are? "; in>>this->salariu;
    cout<<"La ce nivel de cunostinte se afla? [junior/mid/senior]"; in>>this->nivel;
    return in;

}

ostream &Web_Dev::write(ostream &out) const {
    out<<"\nDatele developerului sunt:\n";
    out<<"Numele: "<<this->nume<<endl;
    out<<"Prenumele: "<<this->prenume<<endl;
    out<<"Varsta: "<<this->varsta<<endl;
    out<<"Tehnologii pe care le cunoaste sunt:\n";
    for(int i=0;i<this->tehnologii.size();i++)
        out<<"Tehnologia "<<i+1<<": "<<tehnologii[i]<<endl;
    out<<"Experienta: "<<this->experienta<<endl;
    out<<"Salariu "<<this->salariu<<endl;
    out<<"Nivelul de cunostinte: "<<this->nivel;
    return out;
}
istream& operator>>(istream& in, Web_Dev& dev){
    return dev.read(in);
}
ostream& operator<<(ostream& out, const Web_Dev& dev){
    return dev.write(out);
}

///------------------------------------------------------------------------------------------------------------
///front end

frontEnd_dev::frontEnd_dev(string nume, string prenume, int varsta, vector<string> tehnologii, int experienta,
                           float salariu, string nivel, int creativitate, int imaginatie, int flexibilitate,
                           int atentie_la_detalii): Web_Dev(nume, prenume, varsta, tehnologii, experienta, salariu,nivel) {
    this->creativitate = creativitate;
    this->imaginatie = imaginatie;
    this->flexibilitate = flexibilitate;
    this->atentie_la_detalii = atentie_la_detalii;
}
frontEnd_dev::frontEnd_dev(const frontEnd_dev &dev) {
    this->nume = dev.nume;
    this->prenume = dev.prenume;
    this->varsta = dev.varsta;
    this->experienta = dev.experienta;
    this->salariu = dev.salariu;
    this->nivel = dev.nivel;
    for(int i = 0; i<dev.tehnologii.size();i++){
        this->tehnologii.push_back(dev.tehnologii[i]);
    }
    this->creativitate = dev.creativitate;
    this->imaginatie = dev.imaginatie;
    this->flexibilitate = dev.flexibilitate;
    this->atentie_la_detalii = dev.atentie_la_detalii;
}

frontEnd_dev frontEnd_dev::operator=(const frontEnd_dev &dev) {
    if(this != &dev){
        Web_Dev::operator=(dev);
        this->creativitate = dev.creativitate;
        this->imaginatie = dev.imaginatie;
        this->flexibilitate = dev.flexibilitate;
        this->atentie_la_detalii = dev.atentie_la_detalii;
    }
    return *this;
}
//frontEnd_dev operator=(Web_Dev& wd, frontEnd_dev& fd){

//}
istream &frontEnd_dev::read(istream &in) {
    Web_Dev::read(in);
    cout<<"Pentru urmatoarele atribute introduceti un numar de la 0 la 100:\n";
    cout<<"Creativitate: "; in>>this->creativitate;
    cout<<"Imaginatie: "; in>>this->imaginatie;
    cout<<"Flexibilitate: "; in>>this->flexibilitate;
    cout<<"Atentie la detalii:"; in>>this->flexibilitate;
    return in;
}

ostream &frontEnd_dev::write(ostream &out) const {
    Web_Dev::write(out);
    out<<"\nCreativitate: "<<this->creativitate<<endl;
    out<<"Imaginatie: "<<this->imaginatie<<endl;
    out<<"Flexibilitate: "<<this->flexibilitate<<endl;
    out<<"Atentie la detalii:"<<this->flexibilitate<<endl;
    return out;
}
istream& operator>>(istream& in, frontEnd_dev& dev){
    return dev.read(in);
}
ostream& operator<<(ostream& out, const frontEnd_dev& dev){
    return dev.write(out);
}

void frontEnd_dev::participare_curs() {
    bool oc = 0, oi = 0, of = 0, oa = 0;
    if(this->imaginatie < 100){
        if(this->imaginatie >= 90)
            this->imaginatie += 100-this->imaginatie;
        else
            this->imaginatie += 10;
        oi = 1;
    }
    if(this->creativitate < 100){
        if(this->creativitate >= 90)
            this->creativitate += 100-this->creativitate;
        else
            this->creativitate += 10;
        oc = 1;
    }
    if(this->flexibilitate < 100){
        if(this->flexibilitate >= 90)
            this->flexibilitate += 100-this->flexibilitate;
        else
            this->flexibilitate += 10;
        of = 1;
    }
    if(this->atentie_la_detalii < 100){
        if(this->atentie_la_detalii >= 90)
            this->atentie_la_detalii += 100-this->atentie_la_detalii;
        else
            this->atentie_la_detalii += 10;
        oa = 1;
    }
    oc && cout<<"\nCreativitatea a crescut!\n";
    oi && cout<<"Imaginatia a crescut!\n";
    of && cout<<"Flexibilitatea a crescut!\n";
    oa && cout<<"Atentia la detalii a crescut!\n";
    }

///------------------------------------------------------------------------------------------------------------
///back end
backEnd_dev::backEnd_dev(string nume, string prenume, int varsta, vector<string> tehnologii, int experienta,
                         float salariu, string nivel, int problem_solving, int gandire_logica,
                         int Efficient_Time_Management): Web_Dev(nume, prenume, varsta, tehnologii, experienta, salariu,nivel) {
    this->problem_solving = problem_solving;
    this->gandire_logica = gandire_logica;
    this->Efficient_Time_Management = Efficient_Time_Management;
}
backEnd_dev::backEnd_dev(const backEnd_dev &dev): Web_Dev(dev) {
    this->problem_solving = dev.problem_solving;
    this->gandire_logica = dev.gandire_logica;
    this->Efficient_Time_Management = dev.Efficient_Time_Management;
}

backEnd_dev backEnd_dev::operator=(const backEnd_dev &dev) {
    if(this != &dev){
        Web_Dev::operator=(dev);
        this->problem_solving = dev.problem_solving;
        this->gandire_logica = dev.gandire_logica;
        this->Efficient_Time_Management = dev.Efficient_Time_Management;
    }
    return *this;
}

istream &backEnd_dev::read(istream &in) {
    Web_Dev::read(in);
    cout<<"Pentru urmatoarele atribute introduceti un numar de la 0 la 100:\n";
    cout<<"Problem solving: "; in>>this->problem_solving;
    cout<<"Gandire logica: "; in>>this->gandire_logica;
    cout<<"Efficient Time Management: "; in>>this->Efficient_Time_Management;
    return in;

}
ostream &backEnd_dev::write(ostream &out) const {
    Web_Dev::write(out);
    out<<"\nProblem solving: "<<this->problem_solving<<endl;
    out<<"Gandire logica: "<<this->gandire_logica<<endl;
    out<<"Efficient Time Management: "<<this->Efficient_Time_Management<<endl;
    return out;
}
istream& operator>>(istream& in, backEnd_dev& dev){
    return dev.read(in);
}
ostream& operator<<(ostream& out, const backEnd_dev& dev){
    return dev.write(out);
}

void backEnd_dev::participare_curs() {
    bool op = 0, og = 0, oe = 0;
    if(this->problem_solving < 100){
        if(this->problem_solving >= 90)
            this->problem_solving += 100-this->problem_solving;
        else
            this->problem_solving += 10;
        op = 1;
    }
    if(this->gandire_logica < 100){
        if(this->gandire_logica >= 90)
            this->gandire_logica += 100-this->gandire_logica;
        else
            this->gandire_logica += 10;
        og = 1;
    }
    if(this->Efficient_Time_Management < 100){
        if(this->Efficient_Time_Management >= 90)
            this->Efficient_Time_Management += 100-this->Efficient_Time_Management;
        else
            this->Efficient_Time_Management += 10;
        oe = 1;
    }
    op && cout<<"\nProblem solving-ul a crescut!\n";
    og && cout<<"Gandirea logica a crescut!\n";
    oe && cout<<"Efficient time management-ul a crescut!\n";
}


///------------------------------------------------------------------------------------------------------------
///full stack
fullStack_dev::fullStack_dev(string nume, string prenume, int varsta, vector<string> tehnologii, int experienta,
                             float salariu, string nivel, int creativitate, int imaginatie, int flexibilitate,
                             int atentie_la_detalii, int problem_solving, int gandire_logica,
                             int Efficient_Time_Management, int leadership, int comunicare_eficienta, int coordonare): frontEnd_dev(nume, prenume, varsta, tehnologii, experienta, salariu,nivel) {
    this->problem_solving = problem_solving;
    this->gandire_logica = gandire_logica;
    this->Efficient_Time_Management = Efficient_Time_Management;
    this->leadership = leadership;
    this->comunicare_eficienta = comunicare_eficienta;
    this->coordonare = coordonare;
}
fullStack_dev::fullStack_dev(const fullStack_dev &dev): frontEnd_dev(dev) {
    this->problem_solving = dev.problem_solving;
    this->gandire_logica = dev.gandire_logica;
    this->Efficient_Time_Management = dev.Efficient_Time_Management;
    this->leadership = dev.leadership;
    this->comunicare_eficienta = dev.comunicare_eficienta;
    this->coordonare = dev.coordonare;
}
fullStack_dev fullStack_dev::operator=(const fullStack_dev &dev) {
    if(this != &dev){
        frontEnd_dev::operator=(dev);
        this->problem_solving = dev.problem_solving;
        this->gandire_logica = dev.gandire_logica;
        this->Efficient_Time_Management = dev.Efficient_Time_Management;
        this->leadership = dev.leadership;
        this->comunicare_eficienta = dev.comunicare_eficienta;
        this->coordonare = dev.coordonare;
    }
    return *this;
}

istream &fullStack_dev::read(istream &in) {
    frontEnd_dev::read(in);
    cout<<"Problem solving: "; in>>this->problem_solving;
    cout<<"Gandire logica: "; in>>this->gandire_logica;
    cout<<"Efficient Time Management: "; in>>this->Efficient_Time_Management;
    cout<<"Leadership: "; in>>this->leadership;
    cout<<"Comunicare Eficienta: "; in>>this->comunicare_eficienta;
    cout<<"Coordonare: "; in>>this->coordonare;
    return in;
}

ostream &fullStack_dev::write(ostream &out) const {
    frontEnd_dev::write(out);
    out<<"\nProblem solving: "<<this->problem_solving<<endl;
    out<<"Gandire logica: "<<this->gandire_logica<<endl;
    out<<"Efficient Time Management: "<<this->Efficient_Time_Management<<endl;
    out<<"Leadership: "<<this->leadership<<endl;
    out<<"Comunicare Eficienta: "<<this->comunicare_eficienta<<endl;
    out<<"Coordonare: "<<this->coordonare<<endl;
    return out;
}
istream& operator>>(istream& in, fullStack_dev& dev){
    return dev.read(in);
}
ostream& operator<<(ostream& out, const fullStack_dev& dev){
    return dev.write(out);
}

void fullStack_dev::participare_curs() {
    frontEnd_dev::participare_curs();
    backEnd_dev::participare_curs();
    bool ol = 0, oce = 0, oc = 0;
    if(this->leadership < 100){
        if(this->leadership >= 90)
            this->leadership += 100-this->leadership;
        else
            this->leadership += 10;
        ol = 1;
    }
    if(this->comunicare_eficienta < 100){
        if(this->comunicare_eficienta >= 90)
            this->comunicare_eficienta += 100-this->comunicare_eficienta;
        else
            this->comunicare_eficienta += 10;
        oce = 1;
    }
    if(this->coordonare < 100){
        if(this->coordonare >= 90)
            this->coordonare += 100-this->coordonare;
        else
            this->coordonare += 10;
        oc = 1;
    }
    ol && cout<<"\nLeadership-ul a crescut!\n";
    oce && cout<<"Comunicarea efficienta a crescut!\n";
    oc && cout<<"Coordonarea a crescut!\n";
}


///------------------------------------------------------------------------------------------------------------
///proiect
Proiect::Proiect() {
    this->nume_proiect = "";
    this->nr_oameni = 0;
    this->deadline = "";
}
Proiect::Proiect(string nume_proiect, fullStack_dev Team_Leader, int nr_oameni, vector<Web_Dev*> echipa, string deadline) {
    this->nume_proiect = nume_proiect;
    this->Team_Leader = Team_Leader;
    this->nr_oameni = nr_oameni;
    for(int i=0;i<nr_oameni;i++){
        this->echipa.push_back(echipa[i]);
    }
    this->deadline = deadline;
}
Proiect::Proiect(const Proiect &P) {
    this->nume_proiect = P.nume_proiect;
    this->Team_Leader = P.Team_Leader;
    this->nr_oameni = P.nr_oameni;
    for(int i=0;i<P.nr_oameni;i++)
        this->echipa.push_back(P.echipa[i]);
    this->deadline = P.deadline;
}

Proiect Proiect::operator=(const Proiect &P) {
    if(this != &P){
        if(this->echipa.size() != 0){
            this->echipa.clear();
        }
        this->nume_proiect = P.nume_proiect;
        this->Team_Leader = P.Team_Leader;
        this->nr_oameni = P.nr_oameni;
        for(int i=0;i<P.nr_oameni;i++)
            this->echipa.push_back(P.echipa[i]);
        this->deadline = P.deadline;
    }
    return *this;
}

istream &Proiect::read(istream &in) {
    cout<<"\nIntroduceti datele pentru un nou proiect:\n";
    cout<<"\nNumele proiectului:\n";
    cin.get();
    getline(in, this->nume_proiect);
    cout<<"\nTeam Leader:\n";
    in>>this->Team_Leader;
    cout<<"\nNumar oameni: "; in>>this->nr_oameni;
    for(int i=0;i<this->nr_oameni;i++){
        string aux1;
        cout<<"\nIntroduceti specializarea developerului "<< i+1 <<": [front-end/back-end] "; in>>aux1;
        if(aux1 == "front-end"){
            frontEnd_dev *aux = new frontEnd_dev;
            in>>*aux;
            this->echipa.push_back(aux);
        }
        else{
            backEnd_dev *aux = new backEnd_dev();
            in>>*aux;
            this->echipa.push_back(aux);
        }
    }
    cout<<"Deadline-ul proiectului: "; in>>this->deadline;
    return in;
}

ostream &Proiect::write(ostream &out) const {
    out<<"\nDatele despre acest proiect sunt: \n";
    out<<"Numele proiectului: "<<this->nume_proiect<<endl;
    out<<"Team Leader: \n"<<this->Team_Leader<<endl;
    out<<"Numar oameni: "<<this->nr_oameni<<endl;
    for(int i=0;i<this->nr_oameni;i++){
        out<<"Developerul "<< i+1 <<": ";
        out<<*echipa[i]<<endl;
    }
    out<<"\nDeadline-ul proiectului: "<<this->deadline<<endl;
    return out;
}
istream& operator>>(istream& in, Proiect& P){
    return P.read(in);
}
ostream& operator<<(ostream& out, const Proiect& P){
    return P.write(out);
}
void Proiect::setNume(string nume_proiect) {
    this->nume_proiect = nume_proiect;
}

void Proiect::setTL(fullStack_dev TL) {
    this->Team_Leader = TL;
}

void Proiect::setEchipa(int nr_oameni, vector<Web_Dev *> echipa) {
    if(this->echipa.size() != 0){
        this->echipa.clear();
    }
    this->nr_oameni = nr_oameni;
    for(int i=0;i<nr_oameni;i++)
        this->echipa.push_back(echipa[i]);
}

void Proiect::setDeadline(string deadline) {
    this->deadline = deadline;
}
void Proiect::concediere() {
    if(this->echipa.size() > 1){
        int min_val = 9999999, min_index = -1;
        for(int i=0;i<this->echipa.size();i++)
            if(this->echipa[i]->getExperienta() <= min_val){
                min_val = this->echipa[i]->getExperienta();
                min_index = i;
            }
        for(int i = min_index; i<this->echipa.size()-1;i++){
            this->echipa[i] = this->echipa[i+1];
        }
        this->echipa.pop_back();
        this->nr_oameni--;
        cout<<"\nMembrul "<<min_index+1<<" a fost concediat datorita faptului ca avea cea mai putina experienta!\n";
    }
    else
        cout<<"\nEchipa este prea mica pentru a concedia pe cineva!\n";
}
Proiect::~Proiect() {
    if(this->echipa.size() != 0){
        this->echipa.clear();
    }
}
///------------------------------------------------------------------------------------------------------------
///crud
void CRUD_menu(int &ch){
    cout<<"-------------------------------------------------------------------------------------\n";
    cout<<"\nSelectati actiunea pe care doriti sa o faceti:\n";
    cout<<"1.Create\n";
    cout<<"2.Read\n";
    cout<<"3.Update\n";
    cout<<"4.Delete\n";
    cout<<"5.Creste statusurile unui membru al unui echipe\n";
    cout<<"6.Concediati membrul cu cea mai putina experienta\n";
    cout<<"7.Inchidere aplicatie\n";
    cout<<"\nAlegerea este: "; cin>>ch;

    while(ch < 1 || ch > 7){
        cout<<"\nVa rog selectati o optiune valida(intre 1 si 6)\n";
        cout<<"Alegerea este: ";cin>>ch;
    }
}
void Create(int &ch){
    cout<<"\nCum doriti sa creati un proiect?\n";
    cout<<"1.Fara parametrii\n";
    cout<<"2.Cu toti parametrii\n";
    cout<<"3.Inapoi\n";
    cout<<"\nAlegerea este: "; cin>>ch;
    while(ch < 1 || ch > 3){
        cout<<"\nVa rog selectati o optiune valida(intre 1 si 3)\n";
        cout<<"Alegerea este: ";cin>>ch;
    }
}

void Read(vector<Proiect> proiecte, int &ch){
    if(proiecte.size() == 0){
        ch = -1;
        cout<<"\nCreati un proiect mai intai!\n";
    }
    else{
        cout<<"\nAcestea sunt proiectele dumnevoastra:\n";
        for(int i = 0; i < proiecte.size(); i++)
            cout<<"\nProiectul "<<i+1<<": "<<proiecte[i].getNume();
        cout<<"\n"<<proiecte.size()+1<<".Inapoi\n";
        cout<<"\nCe proiect doriti sa selectati?\nAlegerea este: "; cin>>ch;
        if(ch == proiecte.size()+1)
            ch=-1;
        else{
            while(ch<1 || ch>proiecte.size()+1){
                cout<<"\nVa rog selectati o optiune valida(intre 1 si "<<proiecte.size()+1<<")\n";
                cout<<"Alegerea este: ";cin>>ch;
                if(ch == proiecte.size()+1)
                    ch=-1;
            }
        }
    }
}

int Update(vector<Proiect> proiecte){
    int rez;
    cout<<"\nCe doriti sa modificati la acest proiect: \n";
    cout<<"1.Numele proiectului\n";
    cout<<"2.Team leader-ul\n";
    cout<<"3.Echipa(se va modifica si numarul de oameni)\n";
    cout<<"4.Deadline-ul\n";
    cout<<"5.Inapoi\n";
    cout<<"\nAlegerea este: "; cin>>rez;
    while(rez<1 || rez>5){
        cout<<"\nVa rog selectati o optiune valida(intre 1 si 5\n";
        cout<<"Alegerea este: ";cin>>rez;
    }
}

