#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <utility>
using namespace std;
class IO{
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) const = 0;
};

//--------------------------------------------------------------
//clasa template
template <bool info = 0>
class grupa{
    int intensitate;
    string nume_grupa;
public:
    grupa();
    grupa(string nume_grupa, int intensitate): intensitate(intensitate), nume_grupa(nume_grupa){};
    grupa(const grupa& gr);
    grupa operator=(const grupa& gr);
    void setIntensitate(int intensitate) {this->intensitate = intensitate;}
    int getInfo() const {return this->intensitate;}
    string getNume() const {return this->nume_grupa;}
    ~grupa(){}
};

//---------------------------------------------------------
class Exercitiu: public IO{
    string nume;
    int nr_repetari;
    int nr_seturi;
    bool info;
    grupa<> upper;
    grupa<1> lower;
public:
    Exercitiu();
    Exercitiu(string nume, int nr_repetari, int nr_seturi, bool info, grupa<> upper, grupa<1> lower);
    Exercitiu(const Exercitiu& ex);
    Exercitiu operator=(const Exercitiu& ex);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    friend istream& operator>>(istream& in, Exercitiu& ex);
    friend ostream& operator<<(ostream& out, const Exercitiu& ex);
    int getInfo() const;
    string getDenumire() const;
    int getReps() {return this->nr_repetari;}
    int getSets() {return this->nr_seturi;}
    string getNume() {return this->nume;}
    ~Exercitiu(){}
};

//--------------------------------------------------------------
class persoana: public IO{
protected:
    string nume;
    int varsta;
public:
    persoana(string nume="Anonim", int varsta = 0): nume(nume), varsta(varsta){}
    persoana(const persoana& per);
    persoana operator=(const persoana& per);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    friend istream& operator>>(istream& in, persoana& per);
    friend ostream& operator<<(ostream& out, const persoana& per);
    virtual list<Exercitiu> getExercitii() {};
    virtual float getSalariu() {return 0;}
    string getNumePersoana() {return this->nume;}
    virtual ~persoana(){}
};

class persoana_sportiva: public persoana{
protected:
    list<Exercitiu> exercitii;
public:
    persoana_sportiva(): persoana() {}
    persoana_sportiva(list<Exercitiu> exercitii, string nume = "", int varsta = 0);
    persoana_sportiva(const persoana_sportiva& per);
    persoana_sportiva operator=(const persoana_sportiva& per);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    friend istream& operator>>(istream& in, persoana_sportiva& per);
    friend ostream& operator<<(ostream& out, const persoana_sportiva& per);
    virtual list<Exercitiu> getExercitii() {return this->exercitii;}
    virtual float getSalariu() {return 0;}
    virtual ~persoana_sportiva();
};

class sportiv_profesionist: public persoana_sportiva{
    float salariu;
public:
    sportiv_profesionist();
    sportiv_profesionist(list<Exercitiu> exercitii, string nume = "", int varsta = 0,
                         float salariu = 0): persoana_sportiva(exercitii, nume, varsta), salariu(salariu) {}
    sportiv_profesionist(const sportiv_profesionist& sportiv);
    sportiv_profesionist operator=(const sportiv_profesionist& sportiv);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    friend istream& operator>>(istream& in, sportiv_profesionist& per);
    friend ostream& operator<<(ostream& out, const sportiv_profesionist& per);
    virtual float getSalariu() {return this->salariu;}
    virtual ~sportiv_profesionist(){};
};
//---------------------------------------------------------------------------
class echipa: public IO{
    string nume_echipa;
    vector<persoana*> sportivi;
    map<string, int> countExercitii;
public:
    echipa();
    echipa(string nume_echipa, vector<persoana*> sportivi, map<string, int> countExercitii);
    echipa(const echipa& echipa);
    echipa operator=(const echipa& echipa);
    istream& read(istream& in);
    ostream& write(ostream& out) const;
    friend istream& operator>>(istream& in, echipa& echipa);
    friend ostream& operator<<(ostream& out, const echipa& echipa);
    template <class T>
    T add(T a, T b);
    template <class T>
    T multiply(T a, T b);
    float buget_Echipa();
    int repetari_Totale();
    set<string> exercitiiCunoscute();
    string getNumeEchipa() {return this->nume_echipa;}
    vector<persoana*> getSportivi(){return this->sportivi;};
    void setSportivi(vector<persoana*> sportivi);
    virtual ~echipa(){this->sportivi.clear(); this->countExercitii.clear();}
};

//----------------------------------------------------------------------------------------
//helpers
int Read(list<echipa> echipe);
list<echipa> Update(list<echipa> echipe, list<echipa> iter, int index);
//------------------------------------------------------------------------
//meniul CRUD de tip singleton
class CRUD{
    static CRUD* obiect;
    CRUD(){};
public:
    static CRUD* getInstance(){
        if(!obiect)
            obiect=new CRUD();
        return obiect;
    }
    void meniu();
};
CRUD* CRUD::obiect = 0;
//-----------------------------------------------------------------------------------------
int main() {
    CRUD *meniulMeu=meniulMeu->getInstance();
    meniulMeu->meniu();
    return 0;
}



//------------------------------------------------------------------------------------
//metode clasa template grupa
template <bool info>
grupa<info>::grupa() {
    this->intensitate = 0;
    if(info == 0)
        this->nume_grupa = "upper";
    else
        this->nume_grupa = "lower";
}
template <bool info>
grupa<info>::grupa(const grupa<info> &gr) {
    this->intensitate = gr.intensitate;
    this->nume_grupa = gr.nume_grupa;
}

template <bool info>
grupa<info> grupa<info>::operator=(const grupa<info> &gr) {
    if(this!=&gr){
        this->intensitate = gr.intensitate;
        this->nume_grupa = gr.nume_grupa;
    }
    return *this;
}

//metode clasa exercitiu:
Exercitiu::Exercitiu() {
    string nume = "";
    int nr_repetari = 0;
    int nr_seturi = 0;
    bool info = 0;
}

Exercitiu::Exercitiu(string nume, int nr_repetari, int nr_seturi, bool info, grupa<> upper, grupa<1> lower): nume(nume), nr_repetari(nr_repetari), nr_seturi(nr_seturi), info(info) {
    this->upper = upper;
    this->lower = lower;
}

Exercitiu::Exercitiu(const Exercitiu &ex) {
    this->nr_repetari= ex.nr_repetari;
    this->nume = ex.nume;
    this->nr_seturi = ex.nr_seturi;
    this->info = ex.info;
    this->upper = ex.upper;
    this->lower = ex.lower;
}

Exercitiu Exercitiu::operator=(const Exercitiu &ex) {
    if(this != &ex){
        this->nr_repetari= ex.nr_repetari;
        this->nume = ex.nume;
        this->nr_seturi = ex.nr_seturi;
        this->info = ex.info;
        this->upper = ex.upper;
        this->lower = ex.lower;
    }
    return *this;
}
int Exercitiu::getInfo() const {
    if(this->info == 0)
        return this->upper.getInfo();
    return this->lower.getInfo();
}
string Exercitiu::getDenumire() const {
    if(this->info == 0)
        return this->upper.getNume();
    return this->lower.getNume();
}

istream &Exercitiu::read(istream &in) {
    cout<<"\nIntroduceti datele exercitiului:\n";
    cout<<"Denumirea exercitiului: ";
    in.get();
    getline(in,this->nume);
    cout<<"Numarul de repetari: "; in>>this->nr_repetari;
    cout<<"Numarul de seturi: "; in>>this->nr_seturi;
    int intensitate;
    cout<<"Intensitatea exercitiului: "; in>>intensitate;
    cout<<"Ce lucreaza acest exercitiu?\n";
    int aux;
    cout<<"1.Upper body\n";
    cout<<"2. Lower body\n";
    cout<<"Raspunsul este: "; cin>>aux;
    bool ok = 1;
    while(ok)
        switch (aux) {
            case 1:{
                this->info = aux - 1;
                this->upper.setIntensitate(intensitate);
                ok = 0;
                break;
            }
            case 2:{
                this->info = aux - 1;
                this->lower.setIntensitate(intensitate);
                ok = 0;
                break;
            }
            default:{
                cout<<"\nAlegeti un numar valid dintre 1 si 2";
                cout<<"\nRaspunsul este: "; cin>>aux;
                break;
            }
        }
    return in;
}

ostream &Exercitiu::write(ostream &out) const {
    out<<"\nDatele exercitiului sunt:\n";
    out<<"Denumirea: "<<this->nume<<endl;
    out<<"Numarul de repetari: "<<this->nr_repetari<<endl;
    out<<"Numarul de seturi:"<<this->nr_seturi<<endl;
    if(this->info == 0)
        out<<"Exercitiul lucreaza: "<< this->upper.getNume()<< " body"<<endl;
    else
        out<<"Exercitiul lucreaza: "<< this->lower.getNume()<< " body"<<endl;

    out<<"Intensitatea: "<<getInfo();
    return out;
}

istream& operator>>(istream& in, Exercitiu& ex){
    return ex.read(in);
}
ostream& operator<<(ostream& out, const Exercitiu& ex){
    return ex.write(out);
}

//---------------------------------------------------------------
//metode clasa persoana
persoana::persoana(const persoana &per) {
    this->nume = per.nume;
    this->varsta = per.varsta;
}

persoana persoana::operator=(const persoana &per) {
    if(this != &per){
        this->nume = per.nume;
        this->varsta = per.varsta;
    }
    return *this;
}

istream &persoana::read(istream &in) {
    cout<<"\nIntroduceti datele unei persoane:\n";
    cout<<"Numele: ";
    in.get();
    getline(in, this->nume);
    cout<<"Varsta: "; in>>this->varsta;
    return in;
}

ostream &persoana::write(ostream &out) const {
    cout<<"\nDatele persoanei sunt:\n";
    cout<<"Numele: "<<this->nume;
    cout<<"\nVarsta: "<<this->varsta;
    return out;
}
istream& operator>>(istream& in, persoana& per){
    return per.read(in);
}
ostream& operator<<(ostream& out, const persoana& per){
    return per.write(out);
}
//---------------------------------------------------------------------
//metode persoana_sportiva
persoana_sportiva::persoana_sportiva(list<Exercitiu> exercitii, string nume, int varsta): persoana(nume, varsta) {
    this->exercitii = exercitii;
}
persoana_sportiva::persoana_sportiva(const persoana_sportiva &per): persoana(per) {
    this->exercitii = per.exercitii;
}

persoana_sportiva persoana_sportiva::operator=(const persoana_sportiva &per) {
    if(this != &per){
        persoana::operator=(per);
        this->exercitii = per.exercitii;
    }
    return *this;
}

istream &persoana_sportiva::read(istream &in) {
    persoana::read(in);
    cout<<"\nCate exercitii doriti sa adaugati?\n";
    int aux;
    cout<<"Raspunsul este: "; cin>>aux;
    for(int i=0;i<aux;i++){
        cout<<"\nExercitiul "<<i+1<<":\n";
        Exercitiu ex;
        in>>ex;
        this->exercitii.push_back(ex);
    }
    return in;
}

ostream &persoana_sportiva::write(ostream &out) const {
    persoana::write(out);
    for(auto it = this->exercitii.begin();it != this->exercitii.end();++it){
        out<< "\n" << *it;
    }
    return out;
}
istream& operator>>(istream& in, persoana_sportiva& per){
    return per.read(in);
}
ostream& operator<<(ostream& out, const persoana_sportiva& per){
    return per.write(out);
}
persoana_sportiva::~persoana_sportiva() {
    exercitii.clear();
}

//---------------------------------------------------------------
//metode clasa sportiv profesionist
sportiv_profesionist::sportiv_profesionist():persoana_sportiva() {
    this->salariu = 0;
}
sportiv_profesionist::sportiv_profesionist(const sportiv_profesionist &sportiv): persoana_sportiva(sportiv) {
    this->salariu = sportiv.salariu;
}

sportiv_profesionist sportiv_profesionist::operator=(const sportiv_profesionist &sportiv) {
    if(this != &sportiv){
        persoana_sportiva::operator=(sportiv);
        this->salariu = salariu;
    }
    return *this;
}

istream &sportiv_profesionist::read(istream &in) {
    persoana_sportiva::read(in);
    cout<<"Salariul: "; in>>this->salariu;
    return in;
}
ostream &sportiv_profesionist::write(ostream &out) const {
    persoana_sportiva::write(out);
    cout<<"\n\nSalariul: "; out<<this->salariu<<endl;
    return out;
}
istream& operator>>(istream& in, sportiv_profesionist& sportiv){
    return sportiv.read(in);
}
ostream& operator<<(ostream& out, const sportiv_profesionist& sportiv){
    return sportiv.write(out);
}

//--------------------------------------------------------------
//metode echipa
echipa::echipa() {
    this->nume_echipa = "";
    this->countExercitii.insert(pair<string, int> ("upper", 0));
    this->countExercitii.insert(pair<string, int> ("lower", 0));
}
echipa::echipa(string nume_echipa, vector<persoana *> sportivi, map<string, int> countExercitii) {
    this->nume_echipa = nume_echipa;
    this->sportivi = sportivi;
    this->countExercitii = countExercitii;
}

echipa::echipa(const echipa &echipa) {
    this->nume_echipa = echipa.nume_echipa;
    this->sportivi = echipa.sportivi;
    this->countExercitii = echipa.countExercitii;
}

echipa echipa::operator=(const echipa &echipa) {
    if(this != &echipa){
        this->nume_echipa = echipa.nume_echipa;
        this->sportivi = echipa.sportivi;
        this->countExercitii = echipa.countExercitii;
    }
    return *this;
}

istream &echipa::read(istream &in) {
    //resetam map-ul de exercitii
    this->countExercitii.at("upper") = 0;
    this->countExercitii.at("lower") = 0;
    cout<<"\nIntroduceti datele echipei:\n";
    cout<<"\nNumele echipei: "; in>>this->nume_echipa;
    cout<<"Cate memebri doriti sa aibe echipa?\n";
    int aux;
    cout<<"Raspunsul este: "; cin>>aux;
    for(int i=0;i<aux;i++){
        int aux;
        cout<<"\nCe tip de persoana este membrul "<<i+1<<": \n";
        cout<<"1.persoana sportiva\n";
        cout<<"2.sportiv profesionist\n";
        cout<<"Raspunsul este: "; cin>>aux;
        bool ok = 1;
        persoana* per;
        while(ok)
            switch(aux){
                case 1:{
                    per = new persoana_sportiva();
                    in>>dynamic_cast<persoana_sportiva&>(*per);
                    this->sportivi.push_back(per);
                    ok = 0;
                    list<Exercitiu> lista_aux = dynamic_cast<persoana_sportiva&>(*per).getExercitii();
                    for(auto it = lista_aux.begin(); it != lista_aux.end();++it){
                        string denumire = it->getDenumire();
                        this->countExercitii[denumire]++;
                    }
                    break;
                };
                case 2:{
                    per = new sportiv_profesionist();
                    in>>dynamic_cast<sportiv_profesionist&>(*per);
                    this->sportivi.push_back(per);
                    list<Exercitiu> lista_aux = dynamic_cast<sportiv_profesionist&>(*per).getExercitii();
                    for(auto it = lista_aux.begin(); it != lista_aux.end();++it){
                        string denumire = it->getDenumire();
                        this->countExercitii[denumire]++;
                    }
                    ok = 0;
                    break;
                }
                default:{
                    cout<<"\nVa rog alegeti un numar valid dintre 1 si 2\n";
                    cout<<"Alegerea este: "; cin>>aux;
                    break;
                }
            }
    }
    return in;
}

ostream &echipa::write(ostream &out) const {
    out<<"\nDatele echipei sunt: \n";
    out<<"Numele echipei: "<<this->nume_echipa;
    for(int i=0;i<this->sportivi.size();i++){
        out<<"\nMembrul "<<i+1<<":\n";
        out<<(*this->sportivi[i]);
    }
    cout<<"\n\nEchipa cunoaste in total:\n";
    string aux = "upper";
    cout<<this->countExercitii.at(aux)<<" exercitii de upper body\n";
    aux = "lower";
    cout<<this->countExercitii.at(aux)<<" exercitii de lower body\n";
    return out;
}
istream& operator>>(istream& in, echipa& echipa){
    return echipa.read(in);
}
ostream& operator<<(ostream& out, const echipa& echipa){
    return echipa.write(out);
}

template<class T>
T echipa::add(T a, T b) {
    if(typeid(a+b).name() != typeid(T).name())
        throw 1;
    return a+b;
}
template<class T>
T echipa::multiply(T a, T b) {
    return a*b;
}

float echipa::buget_Echipa() {
    float buget=0;
    for(int i=0;i<this->sportivi.size();i++){
        try{
            if(sportiv_profesionist* aux = dynamic_cast<sportiv_profesionist*>(this->sportivi[i]))
                try{
                    buget = add(buget, this->sportivi[i]->getSalariu());
                }
                catch(...){
                    cout<<"\nSuma iese din limitele tipului float!\n";
                }
            else
                throw 1;
        }
        catch(...){
            cout<<"\nnu e sportiv profesionist\n";
        }
    }
    return buget;
}

int echipa::repetari_Totale() {
    int reps_totale = 0;
    for(int i=0;i<this->sportivi.size();i++) {
        list<Exercitiu> lista_aux = this->sportivi[i]->getExercitii();
        for (auto it = lista_aux.begin(); it != lista_aux.end(); ++it){
            int aux = this->multiply(it->getReps(), it->getSets());
            reps_totale = this->add(reps_totale, aux);
        }
    }
    return reps_totale;
}
set<string> echipa::exercitiiCunoscute() {
    set<string> exercitii;
    for(int i=0;i<this->sportivi.size();i++) {
        list<Exercitiu> lista_aux = this->sportivi[i]->getExercitii();
        for (auto it = lista_aux.begin(); it != lista_aux.end(); ++it){
            exercitii.insert(it->getNume());
        }
    }
    return exercitii;
}

void echipa::setSportivi(vector<persoana *> sportivi) {
    this->countExercitii.clear();
    this->sportivi = sportivi;
    for(int i=0;i<sportivi.size();i++){
        list<Exercitiu> lista_aux = sportivi[i]->getExercitii();
        for(auto it = lista_aux.begin(); it != lista_aux.end();++it){
            string denumire = it->getDenumire();
            this->countExercitii[denumire]++;
        }
    }
}

//----------------------------------------------------------------------------
//helpers
int Read(list<echipa> echipe){
    if(echipe.size() == 0)
        throw 1;
    int ok = 1;
    while(ok){
        list<echipa>:: iterator it;
        int i=0;
        for(it = echipe.begin(); it != echipe.end(); ++it)
            cout<<"\nEchipa "<<++i<<": "<<it->getNumeEchipa();
        int comanda;
        cout<<"\nAlegeti o echipa: "; cin>>comanda;
        try{
            if(comanda > 0 && comanda <= echipe.size())
                return comanda;
            throw -1;
        }
        catch(...){
            cout<<"\Selectati un numar corect(intre 1 si "<<echipe.size()<<")"<<endl;
        }
        }
}
list<echipa> Update(list<echipa> echipe, list<echipa>::iterator iter, int index){
    if(iter->getSportivi().size() == 0)
        throw 1;
    else{
        cout<<"\nOptiunile sunt:\n";
        cout<<"1.Adaugare membru\n";
        cout<<"2.Stergere membru\n";
        int comanda;
        cout<<"Alegerea este: [1/2]"; cin>>comanda;
        vector<persoana*> sportivi = iter->getSportivi();
        if(comanda != 1){
            cout<<"\nLista de sportivi din echipa este:\n";
            for(int i=0;i< sportivi.size();i++)
                cout<<"\nMembrul "<<i+1<<": "<<sportivi[i]->getNumePersoana();
            int ok = 1;
            while(ok){
                if(sportivi.size() == 0)
                    throw 1;
                cout<<"\nAlegerea dumneavoastra este: "; cin>>comanda;
                if(comanda > 0 && comanda <= sportivi.size()){
                    int j=0;
                    for(auto it = sportivi.begin(); it != sportivi.end() && j<=comanda-1;++it){
                        if(j == comanda-1){
                            sportivi.erase(it);
                            ok = 0;
                        }

                        j++;}
                }
                else{
                    cout<<"\Selectati un numar corect(intre 1 si "<<sportivi.size()<<")"<<endl;
                }
            }
            }
            else{
                int aux;
                cout<<"\nCe tip de persoana este noul membrul: \n";
                cout<<"1.persoana sportiva\n";
                cout<<"2.sportiv profesionist\n";
                cout<<"Raspunsul este: [1/2]"; cin>>aux;
                bool ok = 1;
                persoana* per;
                while(ok)
                    switch(aux){
                        case 1:{
                            per = new persoana_sportiva();
                            cin>>dynamic_cast<persoana_sportiva&>(*per);
                            sportivi.push_back(per);
                            ok=0;
                            break;
                        };
                        case 2:{
                            per = new sportiv_profesionist();
                            cin>>dynamic_cast<sportiv_profesionist&>(*per);
                            sportivi.push_back(per);
                            ok=0;
                            break;
                        }
                        default:{
                            cout<<"\nVa rog alegeti un numar valid dintre 1 si 2\n";
                            cout<<"Alegerea este: "; cin>>aux;
                            break;
                        }
                    }
            }
            echipa aux = *iter;
            if(index == echipe.size()-1)
                echipe.pop_back();
            else if(index == 0)
                    echipe.pop_front();
            else
                echipe.erase(iter);
            aux.setSportivi(sportivi);
            echipe.push_back(aux);
            return echipe;
        }
}
//----------------------------------------------------------------------
//metode CRUD
void CRUD::meniu(){
    list<echipa> echipe;
    set<string> exercitii;
    int k=1;
    while(k==1){
        cout<<"\n1 Create ";
        cout<<"\n2 Read ";
        cout<<"\n3 Update ";
        cout<<"\n4 Delete ";
        cout<<"\n5 Calculeaza bugetul total al unei echipei ";
        cout<<"\n6 Calculeaza cate repetari au fost efectuate de o echipa pana acum ";
        cout<<"\n7 Exercitiile executate de catre echipe ";
        cout<<"\n8 Stop\n";
        cout<<"Alegerea este: ";
        int comanda;
        cin>> comanda;
        switch(comanda){
            case 1:{
                echipa aux;
                cin>>aux;
                echipe.push_back(aux);
                set<string> ex_aux = aux.exercitiiCunoscute();
                for(auto it = ex_aux.begin(); it != ex_aux.end(); ++it)
                    exercitii.insert(it->data());
                break;
            }
            case 2:{
                try{
                    int aux = Read(echipe);
                    int j=0;
                    for(auto it = echipe.begin(); it != echipe.end() && j<=aux-1; ++it) {
                        if (j == aux - 1)
                            cout << *it;
                        j++;
                    }
                }
                catch(...){
                    cout<<"\nCreati un obiect mai intai!\n";
                }
                break;
            }
            case 3:{
                try{
                    int aux = Read(echipe);
                    int j=0;
                    list<echipa>::iterator it;
                    for(it = echipe.begin(); it != echipe.end() && j<=aux-1; ++it) {
                        if (j == aux - 1){
                            try {
                                echipe = Update(echipe, it, aux-1);
                            }
                            catch(...){
                                cout<<"\nNu mai exista memebri";
                            }
                        }
                        j++;
                    }
                }
                catch(...){
                    cout<<"\nCreati un obiect mai intai!\n";
                }
                break;
            }
            case 4:{
                try{
                    int aux = Read(echipe);
                    int j=0;
                    list<echipa>::iterator it;
                    for(it = echipe.begin(); it != echipe.end() && j<=aux-1; ++it) {
                        if (j == aux - 1){
                            if(j == echipe.size()-1)
                                echipe.pop_back();
                            else if(j == 0)
                                echipe.pop_front();
                            else
                                echipe.erase(it);
                        }
                        j++;
                    }
                }
                catch(...){
                    cout<<"\nCreati un obiect mai intai!\n";
                }
                break;
            }
            case 5:{
                try{
                    int aux = Read(echipe);
                    int j=0;
                    for(auto it = echipe.begin(); it != echipe.end() && j<=aux-1; ++it){
                        if(j == aux-1){
                            cout<<"\nBugetul este de: "<<it->buget_Echipa()<<endl;
                            break;
                        }
                        j++;
                    }
                }
                catch(...){
                    cout<<"\nCreati un obiect mai intai!\n";
                }
                break;
            }
            case 6:{
                try{
                    int aux = Read(echipe);
                    int j=0;
                    for(auto it = echipe.begin(); it != echipe.end() && j<=aux-1; ++it){
                        if(j == aux-1){
                            cout<<"\nNumarul de repetari este: "<<it->repetari_Totale()<<endl;
                            break;
                        }
                        j++;
                    }
                }
                catch(...){
                    cout<<"\nCreati un obiect mai intai!\n";
                }
                break;
            }
            case 7:{
                cout<<"\nExercitiile executate sunt: ";
                for(auto it = exercitii.begin(); it != exercitii.end(); ++it)
                    cout<<it->data()<<", ";
                cout<<endl;
                break;
            }
            case 8:{
                k = 0;
            }
            default:{
                cout<<"Choose a number between 1 and 8\n";
            }
        }
    }
}
