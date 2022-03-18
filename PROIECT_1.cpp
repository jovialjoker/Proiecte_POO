#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

class Profesor{
private:
    char* nume;
    char* prenume;
	char initiala;
    bool e_decan;
    int vechime;
    float salariu;
public:
    //constructori:
    Profesor();
    Profesor(char* nume, char* prenume, char initiala, bool e_decan, int vechime, float salariu);
    Profesor(char* nume, char* prenume, char initiala, int vechime, float salariu);
    Profesor(char* nume, char* prenume, char initiala);
    //copy-constructor
    Profesor(const Profesor& prof);
    //getteri:
    char* getNume();
    char* getPrenume();
    char getInitiala();
    bool getE_decan();
    int getVechime();
    float getSalariu();
    //setteri:
    void setNume(char* nume);
    void setPrenume(char* prenume);
    void setInitiala(char initiala);
    void setE_decan(bool e_decan);
    void setVechime(int vechime);
    void setSalariu(float salariu);
    //operatori:
    Profesor operator=(const Profesor& prof);
    friend istream & operator>>(istream &in, Profesor &prof);
    friend ostream & operator<<(ostream &out, const Profesor &prof);
    const Profesor& operator++();
    Profesor operator++(int);
    const Profesor& operator--();
    Profesor operator--(int);
    operator int();
    bool operator<(const Profesor& prof);
    bool operator>(const Profesor& prof);
    bool operator<=(const Profesor& prof);
    bool operator>=(const Profesor& prof);
    bool operator==(const Profesor& prof);
    Profesor operator+(int x);
    friend Profesor operator+(int x, Profesor prof);
    Profesor operator+(Profesor prof);
    Profesor operator-(int x);
    friend Profesor operator-(int x, Profesor prof);
    //functionalitate
    void verificareDecan();
    //destructor:
    ~Profesor();
};
///----------------------------------------------------------------------------------------------------------
class Sala{
private:
    int etaj;
    int nr_sala;
    int capacitate;
    bool e_amfiteatru;
    char* nume_amfiteatru; //in caz ca amfiteatru==true
public:
    //constructori
    Sala();
    Sala(int etaj, int nr_sala, int capacitate, bool e_amfiteatru, char* nume_amfiteatru);
    Sala(int etaj, int nr_sala, int capacitate);
    Sala(int etaj, int nr_sala);
    //copy-constructor
    Sala(const Sala& sala);
    //getteri
    int getEtaj();
    int getNr_sala();
    int getCapacitate();
    bool getE_amfiteatru();
    char* getNume_amfiteatru();
    //setteri
    void setEtaj(int etaj);
    void setNr_sala(int nr_sala);
    void setCapacitate(int capacitate);
    void setE_amfiteatru(bool e_amfiteatru);
    void setNume_amfiteatru(char* nume_amfiteatru);
    //operatori
    Sala operator=(const Sala& sala);
    friend istream & operator>>(istream& in, Sala& sala);
    friend ostream & operator<<(ostream& out, const Sala& sala);
    const Sala operator++();
    Sala operator++(int);
    const Sala operator--();
    Sala operator--(int);
    bool operator<(const Sala& s);
    bool operator>(const Sala& s);
    bool operator<=(const Sala& s);
    bool operator>=(const Sala& s);
    bool operator==(const Sala& s);
    Sala operator+(int x);
    friend Sala operator+(int x, Sala s);
    Sala operator+(Sala s);
    Sala operator-(int x);
    friend Sala operator-(int x, Sala s);
    //functionalitate
    void verificareAmfiteatru();
    //deconstructor
    ~Sala();
};
///-------------------------------------------------------------------------------------------------------------
class Materie {
private:
    string nume_materie;
    Profesor prof;
    Sala s;
    int credite;
    bool are_examen;
public:
    //constructori
    Materie();
    Materie(string nume_materie, Profesor prof, Sala s, int credite, bool are_examen);
    Materie(string nume_materie, Profesor prof);
    Materie(string nume_materie);
    Materie(const Materie& M);
    //getteri
    string getNume_materie();
    Profesor getProf();
    Sala getS();
    int getCredite();
    bool getAre_examen();
    //setteri
    void setNume_materie(string nume_materie);
    void setProf(Profesor prof);
    void setS(Sala s);
    void setCredite(int credite);
    void setAre_examen(bool are_examen);
    //operatori
    Materie operator=(const Materie& M);
    friend istream & operator>>(istream& in, Materie& M);
    friend ostream & operator<<(ostream& out, Materie& M);
    const Materie operator++();
    Materie operator++(int);
    const Materie operator--();
    Materie operator--(int);
    bool operator<(const Materie& M);
    bool operator>(const Materie& M);
    bool operator<=(const Materie& M);
    bool operator>=(const Materie& M);
    bool operator==(const Materie& M);
    Materie operator+(int x);
    friend Materie operator+(int x, Materie M);
    Materie operator+(Materie M);
    Materie operator-(int x);
    friend Materie operator-(int x, Materie M);
    //functionalitate
    void prezentareMaterie();
    //deconstructor
    ~Materie(){}
};
///-------------------------------------------------------------------------------------------------------
class Student {
private:
    char* nume;
    char* prenume;
	char initiala;
    const int nr_matricol;
    static int nr_studenti; //contor pt studenti
    bool are_bursa;
    int nr_materii;
    float* medii;
    double medie_admitere;
    Materie* M;
public:
    //constructori
    Student();
    Student(char* nume, char* prenume, char initiala, bool are_bursa, int nr_materii, float* medii, double medie_admitere, Materie* M);
    Student(char* nume, char* prenume, char initiala);
    Student(char* nume, char* prenume, char initiala, int nr_materii);
    Student(const Student& s);
    //getteri
    char* getNume();
    char* getPrenume();
    char getInitiala();
    int getNr_matricol();
    static int getNr_studenti();
    bool getAre_bursta();
    int getNr_materii();
    float* getMedii();
    double getMedie_admitere();
    Materie* getM();
    //setteri
    void setNume(char* nume);
    void setPrenume(char* prenume);
    void setInitiala(char initiala);
    static void setNr_studenti(int nr_studenti);
    void setAre_bursa(bool are_bursa);
    void setNr_materii(int nr_materii);
    void setMedii(int nr_medii, float* medii);
    void setMedie_admitere(double medie_admitere);
    void setM(int nr_medii, Materie* M);
    //operatori
    Student operator=(const Student& s);
    friend istream & operator>>(istream& in, Student& s);
    friend ostream & operator<<(ostream& out, const Student& s);
    float operator[](int index);
    operator int();
    bool operator<(const Student& S);
    bool operator>(const Student& S);
    bool operator<=(const Student& S);
    bool operator>=(const Student& S);
    bool operator==(const Student& S);
    Student operator+(Student S);
    Student operator+(Materie M);
    friend Student operator+(Materie materie, Student Stud);
    //functionalitate
    float mediaGenerala();
    //deconstructor
    ~Student();
};
int Student::nr_studenti=0;

///------------------------------------------------------------------------------------------------------
///meniu interactiv aplicatie
int meniuCRUD();
int meniuCreate();
int meniuCreate_Student();
int meniuCreate_Profesor();
int meniuCreate_Sala();
int meniuCreate_Materie();
int meniuRead();
int meniuUpdate();
int listaStudent( vector<Student>& studenti);
int listaProfesor( vector<Profesor>& profesori);
int listaSala( vector<Sala>& sali);
int listaMaterie( vector<Materie>& materii);
int atributeStudent();
int atributeProfesor();
int atributeSala();
int atributeMaterie();
int meniuDelete();
int main()
{
    cout<<"ACEASTA ESTE O APLICATIE DE GESTIONARE A UNEI FACULTATI"<<endl<<endl;
    vector<Student> studenti;
    vector<Profesor> profesori;
    vector<Sala> sali;
    vector<Materie> materii;
    int rez=meniuCRUD();
    while(rez!=5){
        if(rez == 1){
            rez=meniuCreate();
            while(rez!=5){
                if(rez == 1){
                    rez=meniuCreate_Student();
                    while(rez!=5){
                        if(rez == 1){
                            Student A;
                            studenti.push_back(A);
                            for(int i=0;i<A.getNr_materii();i++){
                                materii.push_back(A.getM()[i]);
                            }
                            }
                        else if(rez == 2){
                            Student A;
                            cin>>A;
                            studenti.push_back(A);
                            for(int i=0;i<A.getNr_materii();i++){
                                materii.push_back(A.getM()[i]);
                            }
                            }
                        else if(rez == 3){
                                char* nume;
                                char* prenume;
                                char initiala;
                                nume = new char[30];
                                prenume = new char[30];
                                cout<<"Numele studentului: "; cin>>nume;
                                cout<<"Preumele studentului: "; cin>>prenume;
                                cout<<"Initiala tatalui studentului: "; cin>>initiala;
                                Student A(nume, prenume, initiala);
                                studenti.push_back(A);
                                for(int i=0;i<A.getNr_materii();i++){
                                    materii.push_back(A.getM()[i]);
                                }
                                delete[] nume;
                                delete[] prenume;
                            }
                        else if(rez == 4){
                                char* nume;
                                char* prenume;
                                char initiala;
                                int nr_materii;
                                nume = new char[30];
                                prenume = new char[30];
                                cout<<endl<<"Numele studentului: "; cin>>nume;
                                cout<<"Preumele studentului: "; cin>>prenume;
                                cout<<"Initiala tatalui studentului: "; cin>>initiala;
                                cout<<"Numarul de materii: "; cin>>nr_materii;
                                Student A(nume, prenume, initiala, nr_materii);
                                studenti.push_back(A);
                                for(int i=0;i<A.getNr_materii();i++){
                                    materii.push_back(A.getM()[i]);
                                }
                                delete[] nume;
                                delete[] prenume;
                            }
                        rez=meniuCreate_Student();
                        }
                    }
                else if(rez == 2){
                    rez=meniuCreate_Profesor();
                    while(rez!=5){
                        if(rez == 1){
                            Profesor A;
                            profesori.push_back(A);
                            }
                        else if(rez == 2){
                            Profesor A;
                            cin>>A;
                            profesori.push_back(A);
                            }
                        else if(rez == 3){
                                char* nume;
                                char* prenume;
                                char initiala;
                                nume = new char[30];
                                prenume = new char[30];
                                cout<<"Numele profesorului: "; cin>>nume;
                                cout<<"Preumele profesorului: "; cin>>prenume;
                                cout<<"Initiala tatalui profesorului: "; cin>>initiala;
                                Profesor A(nume, prenume, initiala);
                                profesori.push_back(A);
                                delete[] nume;
                                delete[] prenume;
                            }
                        else if(rez == 4){
                                char* nume;
                                char* prenume;
                                char initiala;
                                int vechime;
                                float salariu;
                                nume = new char[30];
                                prenume = new char[30];
                                cout<<endl<<"Numele profesorului: "; cin>>nume;
                                cout<<"Preumele profesorului: "; cin>>prenume;
                                cout<<"Initiala tatalui profesorului: "; cin>>initiala;
                                cout<<"Vechimea profesorului: "; cin>>vechime;
                                cout<<"Salariul profesorului: "; cin>>salariu;
                                Profesor A(nume, prenume, initiala, vechime, salariu);
                                profesori.push_back(A);
                                delete[] nume;
                                delete[] prenume;
                            }
                        rez=meniuCreate_Profesor();
                        }
                }
                else if(rez == 3){
                    rez=meniuCreate_Sala();
                    while(rez!=5){
                        if(rez == 1){
                            Sala A;
                            sali.push_back(A);
                            }
                        else if(rez == 2){
                            Sala A;
                            cin>>A;
                            sali.push_back(A);
                            }
                        else if(rez == 3){
                            int nr_sala, etaj;
                            cout<<"Etajul la care se afla sala: "; cin>>etaj;
                            cout<<"Numarul salii: "; cin>>nr_sala;
                            Sala A(etaj, nr_sala);
                            sali.push_back(A);
                            }
                        else if(rez == 4){
                            int nr_sala, etaj, capacitate;
                            cout<<"Etajul la care se afla sala: "; cin>>etaj;
                            cout<<"Numarul salii: "; cin>>nr_sala;
                            cout<<"Capacitatea salii: "; cin>>capacitate;
                            Sala A(etaj, nr_sala, capacitate);
                            sali.push_back(A);
                            }
                        rez=meniuCreate_Sala();
                        }
                }
                else if(rez == 4){
                    rez=meniuCreate_Materie();
                    while(rez!=5){
                        if(rez == 1){
                            Materie A;
                            materii.push_back(A);
                            }
                        else if(rez == 2){
                            Materie A;
                            cin.get();
                            cin>>A;
                            materii.push_back(A);
                            }
                        else if(rez == 3){
                            string numele_materiei;
                            cout<<"Denumirea materiei: ";
                            cin.get(); getline(cin, numele_materiei);
                            Materie A(numele_materiei);
                            materii.push_back(A);
                            }
                        else if(rez == 4){
                            string numele_materiei;
                            Profesor A;
                            cout<<"Denumirea materiei: ";
                            cin.get();
                            getline(cin,numele_materiei);
                            cin>>A;
                            Materie B(numele_materiei, A);
                            materii.push_back(B);
                            }
                        rez=meniuCreate_Materie();
                        }
                }
                rez=meniuCreate();
                }
        }
        else if(rez == 2){
            rez=meniuRead();
            while(rez != 5){
                if(rez == 1){
                    if(studenti.size() == 0)
                        cout<<"Creati un student mai intai"<<endl;
                    else
                        for(int i=0; i<studenti.size();i++)
                        {
                            cout<<"Studentul "<<i+1<<":"<<endl;
                            cout<<studenti[i];
                        }
                }
                else if(rez == 2){
                    if(profesori.size() == 0)
                        cout<<"Creati un profesor mai intai"<<endl;
                    else
                        for(int i=0; i<profesori.size();i++)
                        {
                            cout<<"Profesorul "<<i+1<<":"<<endl;
                            cout<<profesori[i];
                        }
                }
                else if(rez == 3){
                    if(sali.size() == 0)
                        cout<<"Creati o sala mai intai"<<endl;
                    else
                        for(int i=0; i<sali.size();i++)
                        {
                            cout<<"Sala "<<i+1<<":"<<endl;
                            cout<<sali[i];
                        }
                }
                else if(rez == 4){
                    if(materii.size() == 0)
                        cout<<"Creati o materie mai intai"<<endl;
                    else
                        for(int i=0; i<materii.size();i++)
                        {
                            cout<<endl<<"Materia "<<i+1<<":"<<endl;
                            materii[i].prezentareMaterie();
                        }
                }
                rez = meniuRead();
            }

        }
        else if(rez == 3){
            rez=meniuUpdate();
            while(rez != 5){
                if(rez == 1){
                    int indice = listaStudent(studenti)-1;
                    if(indice != -2){
                        rez = atributeStudent();
                        while(rez<9){
                            switch(rez){
                                case 1:{
                                    char* nume;
                                    nume = new char[30];
                                    cout<<endl<<"Introduceti noul nume:"; cin>>nume;
                                    studenti[indice].setNume(nume);
                                    delete[] nume;
                                    break;
                                }
                                case 2:{
                                    char* prenume;
                                    prenume = new char[30];
                                    cout<<endl<<"Introduceti noul prenume:"; cin>>prenume;
                                    studenti[indice].setPrenume(prenume);
                                    delete[] prenume;
                                    break;
                                }
                                case 3:{
                                    char initiala;
                                    cout<<endl<<"Introduceti noua initiala"; cin>>initiala;
                                    studenti[indice].setInitiala(initiala);
                                    break;
                                }
                                case 4:{
                                    bool are_bursa;
                                    cout<<endl<<"Are bursa?(0 pentru NU, 1 pentru DA) ";cin>>are_bursa;
                                    studenti[indice].setAre_bursa(are_bursa);
                                    break;
                                }
                                case 5:{
                                    int nr_materii;
                                    cout<<endl<<"Introduceti noul numar de materii:"; cin>>nr_materii;
                                    studenti[indice].setNr_materii(nr_materii);
                                    float* medii;
                                    medii = new float[nr_materii];
                                    Materie* M;
                                    M = new Materie[nr_materii];
                                    for(int i = 0; i<nr_materii; i++)
                                    {
                                        cout<<endl<<"Materia "<<i+1; cin>>M[i];
                                        cout<<endl<<"Media "; cin>>medii[i];
                                    }
                                    studenti[indice].setMedii(nr_materii, medii);
                                    studenti[indice].setM(nr_materii, M);
                                    delete[] medii;
                                    delete[] M;
                                    break;
                                }
                                case 6:{
                                    cout<<endl<<"Introduceti noile medii:"<<endl;
                                    float* medii;
                                    medii = new float[studenti[indice].getNr_materii()];
                                    for(int i = 0; i<studenti[indice].getNr_materii(); i++)
                                    {
                                        cout<<"Media "<<i+1<<": "; cin>>medii[i];
                                    }
                                    studenti[indice].setMedii(studenti[indice].getNr_materii(), medii);
                                    delete[] medii;
                                    break;
                                }
                                case 7:{
                                    cout<<endl<<"Introduceti noua medie de admitere: "<<endl;
                                    double medie_admitere;
                                    cin>>medie_admitere;
                                    studenti[indice].setMedie_admitere(medie_admitere);
                                    break;
                                }
                                case 8:{
                                    cout<<endl<<"Introduceti noile materii: "<<endl;
                                    Materie* M;
                                    int nr_materii = studenti[indice].getNr_materii();
                                    M = new Materie[nr_materii];
                                    for(int i = 0; i<nr_materii; i++)
                                    {
                                        cout<<endl<<"Materia "<<i+1; cin>>M[i];
                                    }
                                    studenti[indice].setM(nr_materii, M);
                                    delete[] M;
                                    break;
                                }
                            }
                            cout<<"Student modificat!"<<endl;
                            rez = atributeStudent();
                        }
                    }

                }
                else if(rez == 2){
                    int indice = listaProfesor(profesori)-1;
                    if(indice != -2){
                        rez = atributeProfesor();
                        while(rez<7){
                            switch(rez){
                                case 1:{
                                    char* nume;
                                    nume = new char[30];
                                    cout<<endl<<"Introduceti noul nume:"; cin>>nume;
                                    profesori[indice].setNume(nume);
                                    delete[] nume;
                                    break;
                                }
                                case 2:{
                                    char* prenume;
                                    prenume = new char[30];
                                    cout<<endl<<"Introduceti noul prenume:"; cin>>prenume;
                                    profesori[indice].setPrenume(prenume);
                                    delete[] prenume;
                                    break;
                                }
                                case 3:{
                                    char initiala;
                                    cout<<endl<<"Introduceti noua initiala:"; cin>>initiala;
                                    profesori[indice].setInitiala(initiala);
                                    break;
                                }
                                case 4:{
                                    bool e_decan;
                                    cout<<endl<<"Este decan?(0/1):"; cin>>e_decan;
                                    profesori[indice].setE_decan(e_decan);
                                    break;
                                }
                                case 5:{
                                    int vechime;
                                    cout<<endl<<"Introduceti noua vechime:"; cin>>vechime;
                                    profesori[indice].setVechime(vechime);
                                    break;

                                }
                                case 6:{
                                    float salariu;
                                    cout<<endl<<"Introduceti noul salariu:"; cin>>salariu;
                                    profesori[indice].setSalariu(salariu);
                                    break;
                                }
                            }
                            cout<<"Profesor modificat!"<<endl;
                            rez = atributeProfesor();
                        }
                    }
                }
                else if(rez == 3){
                    int indice = listaSala(sali) - 1;
                    if(indice != -2){
                        rez = atributeSala();
                        while(rez<6){
                            switch(rez){
                                case 1:{
                                    int etaj;
                                    cout<<endl<<"Introduceti noul etaj:"; cin>>etaj;
                                    sali[indice].setEtaj(etaj);
                                    break;
                                }
                                case 2:{
                                    int nr_sala;
                                    cout<<endl<<"Introduceti noul numar al salii:"; cin>>nr_sala;
                                    sali[indice].setNr_sala(nr_sala);
                                    break;
                                }
                                case 3:{
                                    int capacitate;
                                    cout<<endl<<"Introduceti noua capacitate:"; cin>>capacitate;
                                    sali[indice].setCapacitate(capacitate);
                                    break;
                                }
                                case 4:{
                                    bool e_amfiteatru;
                                    cout<<endl<<"Este amfiteatru?(0/1):"; cin>>e_amfiteatru;
                                    sali[indice].setE_amfiteatru(e_amfiteatru);
                                    break;
                                }
                                case 5:{
                                    if(sali[indice].getE_amfiteatru() == 0)
                                        cout<<endl<<"Sala nu este amfiteatru, deci nu ii puteti da un nume";
                                    else{
                                        char* nume_amfiteatru;
                                        nume_amfiteatru = new char[100];
                                        string aux;
                                        cout<<endl<<"Introduceti noul nume al amfiteatrului";
                                        cin.get();
                                        getline(cin, aux);
                                        strcpy(nume_amfiteatru, aux.c_str());
                                        sali[indice].setNume_amfiteatru(nume_amfiteatru);
                                        delete[] nume_amfiteatru;
                                    }
                                    break;
                                }
                            }
                            cout<<"Sala modificata!"<<endl;
                            rez = atributeSala();
                        }
                    }
                }
                else if(rez == 4){
                    int indice = listaMaterie(materii) - 1;
                    if(indice != -2){
                        rez = atributeMaterie();
                        while(rez<6){
                            switch(rez){
                                case 1:{
                                    string nume_materie;
                                    cout<<endl<<"Introduceti noul nume al materiei:";
                                    cin.get();
                                    getline(cin, nume_materie);
                                    materii[indice].setNume_materie(nume_materie);
                                    break;
                                }
                                case 2:{
                                    Profesor prof;
                                    cout<<endl<<"Introduceti noul profesor:";
                                    cin>>prof;
                                    materii[indice].setProf(prof);
                                    break;
                                }
                                case 3:{
                                    Sala s;
                                    cout<<endl<<"Introduceti noua sala in care se vor tine orele:";
                                    cin>>s;
                                    materii[indice].setS(s);
                                    break;
                                }
                                case 4:{
                                    int credite;
                                    cout<<endl<<"Introduceti noul numar de credite:";
                                    cin>>credite;
                                    materii[indice].setCredite(credite);
                                    break;
                                }
                                case 5:{
                                    bool are_examen;
                                    cout<<endl<<"Are examen?(0/1):";
                                    cin>>are_examen;
                                    materii[indice].setAre_examen(are_examen);
                                    break;
                                }
                            }
                            cout<<"Materie modificata!"<<endl;
                            rez = atributeMaterie();
                        }
                    }
                }
                rez = meniuUpdate();
            }
        }
        else if(rez == 4){
            rez = meniuDelete();
            while(rez !=5){
                switch(rez){
                    case 1:{
                        int indice = listaStudent(studenti) -1;
                        if(indice != -2){
                            for(int i=indice;i<studenti.size()-1;i++)
                                studenti[i] = studenti[i+1];
                            studenti.pop_back();
                            cout<<endl<<"Student sters!"<<endl;
                        }
                        break;
                    }
                    case 2:{
                        int indice = listaProfesor(profesori) -1;
                        if(indice != -2){
                            for(int i=indice;i<profesori.size()-1;i++)
                                profesori[i] = profesori[i+1];
                            profesori.pop_back();
                            cout<<endl<<"Profesor sters!"<<endl;
                        }
                        break;
                    }
                    case 3:{
                        int indice = listaSala(sali) -1;
                        if(indice != -2){
                            for(int i=indice;i<sali.size()-1;i++)
                                sali[i] = sali[i+1];
                            sali.pop_back();
                            cout<<endl<<"Sala stearsa!"<<endl;
                        }
                        break;
                    }
                    case 4:{
                        int indice = listaMaterie(materii) -1;
                        if(indice != -2){
                            for(int i=indice;i<materii.size()-1;i++)
                                materii[i] = materii[i+1];
                            materii.pop_back();
                            cout<<endl<<"Materie stersa!"<<endl;
                        }
                        break;
                    }
                }
                rez = meniuDelete();
            }
        }
        rez=meniuCRUD();
        }

    return 0;
}


///------------------------------------------------------------------------------------------------------------------------
///metode student
//constructori
Student::Student():nr_matricol(nr_studenti*50+1){
    this->nume = new char[strlen("Student")+1];
    strcpy(this->nume, "Student");
    this->prenume = new char[strlen("Anonim")+1];
    strcpy(this->prenume, "Anonim");
    this->initiala = '/';
    this->nr_studenti++;
    this->are_bursa = 0;
    this->nr_materii = 0;
    this->medii = NULL;
    this->medie_admitere = 0.0;
    this->M = NULL;
}
Student::Student(char* nume, char* prenume, char initiala, bool are_bursa, int nr_materii, float* medii, double medie_admitere, Materie* M):nr_matricol(nr_studenti*50+1){
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
    this->prenume = new char[strlen(prenume)+1];
    strcpy(this->prenume, prenume);
    this->initiala = initiala;
    this->nr_studenti++;
    this->are_bursa = are_bursa;
    this->nr_materii = nr_materii;
    this->medii = new float[nr_materii];
    for(int i=0; i<nr_materii; i++)
        this->medii[i] = medii[i];
    this->medie_admitere = medie_admitere;
    this->M = new Materie[nr_materii];
    for(int i=0;i<nr_materii;i++){
        this->M[i].setNume_materie(M[i].getNume_materie());
        this->M[i].setProf(M[i].getProf());
        this->M[i].setS(M[i].getS());
        this->M[i].setCredite(M[i].getCredite());
        this->M[i].setAre_examen(M[i].getAre_examen());
    }
}
Student::Student(char* nume, char* prenume, char initiala):nr_matricol(nr_studenti*50+1){
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
    this->prenume = new char[strlen(prenume)+1];
    strcpy(this->prenume, prenume);
    this->initiala = initiala;
    this->nr_studenti++;
    this->are_bursa = 0;
    this->nr_materii = 0;
    this->medii = NULL;
    this->medie_admitere = 0.0;
    this->M = NULL;
}
Student::Student(char* nume, char* prenume, char initiala, int nr_materii):nr_matricol(nr_studenti*50+1){
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
    this->prenume = new char[strlen(prenume)+1];
    strcpy(this->prenume, prenume);
    this->initiala = initiala;
    this->nr_studenti++;
    this->are_bursa = false;
    this->nr_materii = nr_materii;
    this->medii = NULL;
    this->medie_admitere = 0;
    this->M = NULL;
}
Student::Student(const Student& s):nr_matricol(nr_studenti*50+1){
    this->nume = new char[strlen(s.nume)+1];
    strcpy(this->nume, s.nume);
    this->prenume = new char[strlen(s.prenume)+1];
    strcpy(this->prenume, s.prenume);
    this->initiala = s.initiala;
    this->nr_studenti++;
    this->are_bursa = s.are_bursa;
    this->nr_materii = s.nr_materii;
    this->medii = new float[s.nr_materii];
    for(int i=0; i<s.nr_materii; i++)
        this->medii[i] = s.medii[i];
    this->medie_admitere = s.medie_admitere;
    this->M = new Materie[s.nr_materii];
    for(int i=0;i<nr_materii;i++){
        this->M[i].setNume_materie(s.M[i].getNume_materie());
        this->M[i].setProf(s.M[i].getProf());
        this->M[i].setS(s.M[i].getS());
        this->M[i].setCredite(s.M[i].getCredite());
        this->M[i].setAre_examen(s.M[i].getAre_examen());
    }
}
//getteri
char* Student::getNume(){return this->nume;}
char* Student::getPrenume() {return this->prenume;}
char Student::getInitiala() {return this->initiala;}
int Student::getNr_matricol() {return this->nr_matricol;}
int Student::getNr_studenti() {return Student::nr_studenti;}
bool Student::getAre_bursta() {return this->are_bursa;}
int Student::getNr_materii(){return this->nr_materii;}
float* Student::getMedii() {return this->medii;}
double Student::getMedie_admitere(){return this->medie_admitere;}
Materie* Student::getM() {return this->M;}
//setteri
void Student::setNume(char* nume){
    delete[] this->nume;
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
}
void Student::setPrenume(char* prenume){
    delete[] this->prenume;
    this->prenume = new char[strlen(prenume)+1];
    strcpy(this->prenume, prenume);
}
void Student::setInitiala(char initiala){
    this->initiala = initiala;
}
void Student::setNr_studenti(int nr_studenti){
    Student::nr_studenti = nr_studenti;
}
void Student::setAre_bursa(bool are_bursa){
    this->are_bursa = are_bursa;
}
void Student::setNr_materii(int nr_materii){
    this->nr_materii = nr_materii;
}
void Student::setMedii(int nr_medii, float* medii){
    setNr_materii(nr_medii);
    if(this->medii != NULL)
        delete[] this->medii;
    this->medii = new float[nr_medii];
    for(int i=0; i<nr_medii; i++)
        this->medii[i] = medii[i];
}
void Student::setMedie_admitere(double medie_admitere){
    this->medie_admitere = medie_admitere;
}
void Student::setM(int nr_medii, Materie* M){
    if (this->M != NULL)
        delete[] M;
    this->nr_materii = nr_medii;
    this->M = new Materie[nr_materii];
    for(int i=0; i<this->nr_materii;i++){
        this->M[i].setNume_materie(M[i].getNume_materie());
        this->M[i].setProf(M[i].getProf());
        this->M[i].setS(M[i].getS());
        this->M[i].setCredite(M[i].getCredite());
        this->M[i].setAre_examen(M[i].getAre_examen());
    }
}
//operatori
Student Student::operator=(const Student& s){
    if(this != &s){
        if(this->nume!=NULL)
            delete[] this->nume;
        if(this->prenume!=NULL)
            delete[] this->prenume;
        if(this->medii!=NULL)
            delete[] this->medii;
        if(this->M!=NULL)
            delete[] this->M;
        this->nume = new char[strlen(s.nume)+1];
        strcpy(this->nume, s.nume);
        this->prenume = new char[strlen(s.prenume)+1];
        strcpy(this->prenume, s.prenume);
        this->initiala = s.initiala;
        this->nr_studenti++;
        this->are_bursa = s.are_bursa;
        this->nr_materii = s.nr_materii;
        this->medii = new float[s.nr_materii];
        for(int i=0; i<s.nr_materii; i++)
            this->medii[i] = s.medii[i];
        this->medie_admitere = s.medie_admitere;
        this->M = new Materie[s.nr_materii];
        for(int i=0;i<nr_materii;i++){
            this->M[i].setNume_materie(s.M[i].getNume_materie());
            this->M[i].setProf(s.M[i].getProf());
            this->M[i].setS(s.M[i].getS());
            this->M[i].setCredite(s.M[i].getCredite());
            this->M[i].setAre_examen(s.M[i].getAre_examen());
        }
    }
    return *this;
}
istream & operator>>(istream& in, Student& s){
    cout<<"INTRODUCETI DATELE STUDENTULUI:"<<endl<<endl;
    cout<<"nume: "; in>>s.nume;
    cout<<"prenume: "; in>>s.prenume;
    cout<<"initiala: "; in>>s.initiala;
    s.nr_studenti++;
    cout<<"are bursa: "; in>>s.are_bursa;
    cout<<"nr materii: "; in>>s.nr_materii;
    cout<<"mediile studentului: ";
    s.medii = new float[s.nr_materii];
    for(int i=0;i<s.nr_materii;i++)
        in>>s.medii[i];
    cout<<"medie_admitere: "; in>>s.medie_admitere;
    s.M = new Materie[s.nr_materii];
    cout<<"Materii: "<<endl;
    for(int i=0;i<s.nr_materii;i++){
        cout<<"Materia "<<i<<": "<<endl;
        in>>s.M[i];
    }
    return in;
}
ostream & operator<<(ostream& out, const Student& s){
    out<<"DATELE STUDENTULUI SUNT:"<<endl<<endl;
    out<<"Nume: "<<s.nume<<endl;
    out<<"Prenume: "<<s.prenume<<endl;
    out<<"Initiala: "<<s.initiala<<endl;
    out<<"Are bursa: "<<s.are_bursa<<endl;
    out<<"Nr materii: "<<s.nr_materii<<endl;
    out<<"Materiile studentului: \n";
    for(int i=0;i<s.nr_materii;i++){
        out<<"Materia "<<i+1<<": "<<endl;
        out<<s.M[i];
        out<<"Media: "<<s.medii[i]<<endl;
    }
    out<<endl<<"medie_admitere: "<<s.medie_admitere<<endl;
    cout<<endl<<endl;
    return out;
}
float Student::operator[](int index) {
    return this->medii[index];
}
Student::operator int() {
    return (int)this->medie_admitere;
}
bool Student::operator<(const Student& S){
    if(this->medie_admitere < S.medie_admitere)
        return true;
    return false;
}
bool Student::operator>(const Student& S){
    if(this->medie_admitere > S.medie_admitere)
        return 1;
    return 0;
}
bool Student::operator<=(const Student& S){
    if(this->medie_admitere<=S.medie_admitere)
        return 1;
    return 0;
}
bool Student::operator>=(const Student& S){
    if(this->medie_admitere>=S.medie_admitere)
        return 1;
    return 0;
}
bool Student::operator==(const Student& S){
    if(strcmp(this->nume, S.nume) == 0 && strcmp(this->prenume, S.prenume) == 0 && this->initiala == S.initiala)
        return 1;
    return 0;
}
Student Student::operator+(Student S){
    if(this->nr_materii <= S.nr_materii)
        for (int i = 0; i < this->nr_materii; ++i) {
            S.medii[i] += this->medii[i] ;
        }
    else
        for (int i = 0; i < S.nr_materii; ++i) {
            S.medii[i] += this->medii[i] ;
        }
    return S;
}
Student Student::operator+(Materie M){
    Student rez(*this);
    Materie* aux;
    aux = new Materie[rez.nr_materii];
    for(int i=0;i<rez.nr_materii;i++)
        aux[i] = rez.M[i];
    delete[] rez.M;
    rez.nr_materii++;
    rez.M = new Materie[rez.nr_materii];
    for(int i=0;i<rez.nr_materii-1;i++)
        rez.M[i] = aux[i];
    rez.M[rez.nr_materii-1] = M;
    delete[] aux;
    return rez;
}
Student operator+(Materie materie, Student Stud){
    Materie* aux;
    aux = new Materie[Stud.nr_materii];
    for(int i=0;i<Stud.nr_materii;i++)
        aux[i] = Stud.M[i];
    delete[] Stud.M;
    Stud.nr_materii++;
    Stud.M = new Materie[Stud.nr_materii];
    for(int i=0;i<Stud.nr_materii-1;i++)
        Stud.M[i] = aux[i];
    Stud.M[Stud.nr_materii-1] = materie;
    delete[] aux;
    return Stud;
}
//functionalitate
float Student::mediaGenerala(){
    float mg=0;
    for(int i=0;i<this->nr_materii;i++)
        mg+=this->medii[i];
    mg = mg / this->nr_materii;
    return mg;
}
//deconstructor
Student::~Student(){
    if(this->medii != NULL)
        delete[] this->medii;
    if(this->nume!=NULL)
        delete[] this->nume;
    if(this->prenume!=NULL)
        delete[] this->prenume;
    if(this->M!=NULL)
        delete[] this->M;
}
///-------------------------------------------------------------------------------------------------------
///metode materii
//constructori
Materie::Materie(){
    this->nume_materie = "Materie";
    this->credite = 0;
    this->are_examen = false;
}
Materie::Materie(string nume_materie, Profesor prof, Sala s, int credite, bool are_examen){
    this->nume_materie = nume_materie;
    this->prof = prof;
    this->s = s;
    this->credite = credite;
    this->are_examen = are_examen;
}
Materie::Materie(string nume_materie, Profesor prof){
    this->nume_materie = nume_materie;
    this->prof = prof;
    this->credite = 0;
    this->are_examen = false;
}
Materie::Materie(string nume_materie){
    this->nume_materie = nume_materie;
    this->credite = 0;
    this->are_examen = false;
}
Materie::Materie(const Materie& M){
    this->nume_materie = M.nume_materie;
    this->prof = M.prof;
    this->s = M.s;
    this->credite = M.credite;
    this->are_examen = M.are_examen;
}
//getteri
string Materie::getNume_materie(){
    return this->nume_materie;
}
Profesor Materie::getProf(){
    return this->prof;
}
Sala Materie::getS(){
    return this->s;
}
int Materie::getCredite(){
    return this->credite;
}
bool Materie::getAre_examen(){
    return this->are_examen;
}
//setteri
void Materie::setNume_materie(string nume_materie){
    this->nume_materie = nume_materie;
}
void Materie::setProf(Profesor prof){
    this->prof = prof;
}
void Materie::setS(Sala s){
    this->s = s;
}
void Materie::setCredite(int credite){
    this->credite = credite;
}
void Materie::setAre_examen(bool are_examen){
    this->are_examen = are_examen;
}
//operatori
Materie Materie::operator=(const Materie& M){
    if(this!=&M){
        this->nume_materie = M.nume_materie;
        this->prof = M.prof;
        this->s = M.s;
        this->credite = M.credite;
        this->are_examen = M.are_examen;
    }
    return *this;
}
istream & operator>>(istream& in, Materie& M){
    cout<<"Introduceti datele despre materie:"<<endl;
    cout<<"Nume materie: ";
    in.get();
    getline(in,M.nume_materie);
    in>>M.prof;
    in>>M.s;
    cout<<"Nr credite: "; in>>M.credite;
    cout<<"Are examen? "; in>>M.are_examen;
    return in;
}
ostream & operator<<(ostream& out, Materie& M){
    out<<"Date despre aceasta materie:"<<endl;
    out<<"Nume materie: "<<M.nume_materie<<endl;
    out<<M.prof;
    out<<M.s;
    cout<<"Nr credite: "<<M.credite<<endl;
    cout<<"Are examen? "<<M.are_examen<<endl;
    cout<<endl<<endl;
    return out;
}
const Materie Materie::operator++(){
    this->credite++;
    return *this;
}
Materie Materie::operator++(int){
    Materie aux(*this);
    this->credite++;
    return aux;
}
const Materie Materie::operator--(){
    this->credite--;
    return *this;
}
Materie Materie::operator--(int){
    Materie aux(*this);
    this->credite--;
    return aux;
}
bool Materie::operator<(const Materie& M){
    if(this->credite < M.credite)
        return true;
    return false;
}
bool Materie::operator>(const Materie& M){
    if(this->credite > M.credite)
        return 1;
    return 0;
}
bool Materie::operator<=(const Materie& M){
    if(this->credite<=M.credite)
        return 1;
    return 0;
}
bool Materie::operator>=(const Materie& M){
    if(this->credite>=M.credite)
        return 1;
    return 0;
}
bool Materie::operator==(const Materie& M){
    if(this->nume_materie == M.nume_materie && this->credite == M.credite)
        return 1;
    return 0;
}
Materie Materie::operator+(int x){
    Materie aux(*this);
    aux.credite += x;
    return aux;
}
Materie operator+(int x, Materie M){
    M.credite += x;
    return M;
}
Materie Materie::operator+(Materie M){
    M.credite += this->credite;
    return M;
}
Materie Materie::operator-(int x){
    Materie aux(*this);
    if(aux.credite < x)
        aux.credite = 0;
    else
        aux.credite -= x;
    return aux;
}
Materie operator-(int x, Materie M){
    if(M.credite < x)
        M.credite = 0;
    else
        M.credite -= x;

    return M;
}
void Materie::prezentareMaterie(){
    cout<<"Numele acestei materii este "<<this->nume_materie<<endl;
    cout<<this->nume_materie<<" este predata de "<<this->prof.getNume()<< " "<<this->prof.getInitiala()<<" "<<this->prof.getPrenume()<<endl;
    cout<<this->nume_materie<<" se tine in sala numarul "<<this->s.getNr_sala()<<" aflata la etajul "<<this->s.getEtaj()<<endl;
    cout<<"Acesta materie are "<< this->credite<< " credite";
    if(this->are_examen == 1)
        cout<<" si are examen"<<endl;
    else
        cout<<" si nu are examen"<<endl;
}
///---------------------------------------------------------------------------------------------------------------
///metode sala
//constructori
Sala::Sala(){
    this->etaj = 0;
    this->nr_sala = 0;
    this->capacitate = 0;
    this->e_amfiteatru = false;
    this->nume_amfiteatru = new char[2];
    strcpy(this->nume_amfiteatru, "/");
}
Sala::Sala(int etaj, int nr_sala, int capacitate, bool e_amfiteatru, char* nume_amfiteatru){
    this->etaj = etaj;
    this->nr_sala = nr_sala;
    this->capacitate = capacitate;
    this->e_amfiteatru = e_amfiteatru;
    if(this->e_amfiteatru == 1){
        this->nume_amfiteatru = new char[strlen(nume_amfiteatru)+1];
        strcpy(this->nume_amfiteatru, nume_amfiteatru);
    }
    else{
        this->nume_amfiteatru = new char[2];
        strcpy(this->nume_amfiteatru, "/");
    }
}
Sala::Sala(int etaj, int nr_sala, int capacitate){
    this->etaj = etaj;
    this->nr_sala = nr_sala;
    this->capacitate = capacitate;
    this->e_amfiteatru = false;
    this->nume_amfiteatru = new char[2];
    strcpy(this->nume_amfiteatru, "/");
}
Sala::Sala(int etaj, int nr_sala){
    this->etaj = etaj;
    this->nr_sala = nr_sala;
    this->capacitate = 0;
    this->e_amfiteatru = false;
    this->nume_amfiteatru = new char[2];
    strcpy(this->nume_amfiteatru, "/");
}
//copy-constructor
Sala::Sala(const Sala& sala){
    this->etaj = sala.etaj;
    this->nr_sala = sala.nr_sala;
    this->capacitate = sala.capacitate;
    this->e_amfiteatru = sala.e_amfiteatru;
    this->nume_amfiteatru = new char[strlen(sala.nume_amfiteatru)+1];
    strcpy(this->nume_amfiteatru, sala.nume_amfiteatru);
}
//getteri
int Sala::getEtaj(){
    return this->etaj;
}
int Sala::getNr_sala(){
    return this->nr_sala;
}
int Sala::getCapacitate(){
    return this->capacitate;
}
bool Sala::getE_amfiteatru(){
    return this->e_amfiteatru;
}
char* Sala::getNume_amfiteatru(){
    return this->nume_amfiteatru;
}
//setteri
void Sala::setEtaj(int etaj){
    this->etaj = etaj;
}
void Sala::setNr_sala(int nr_sala){
    this->nr_sala = nr_sala;
}
void Sala::setCapacitate(int capacitate){
    this->capacitate = capacitate;
}
void Sala::setE_amfiteatru(bool e_amfiteatru){
    this->e_amfiteatru = e_amfiteatru;
}
void Sala::setNume_amfiteatru(char* nume_amfiteatru){
    if(this->nume_amfiteatru!=NULL)
        delete[] this->nume_amfiteatru;
    this->nume_amfiteatru = new char[strlen(nume_amfiteatru)+1];
    strcpy(this->nume_amfiteatru, nume_amfiteatru);
}
//operatori
Sala Sala::operator=(const Sala& sala){
    if(this!=&sala){
        if(this->nume_amfiteatru!=NULL)
            delete[] this->nume_amfiteatru;
        this->etaj = sala.etaj;
        this->nr_sala = sala.nr_sala;
        this->capacitate = sala.capacitate;
        this->e_amfiteatru = sala.e_amfiteatru;
        this->nume_amfiteatru = new char[strlen(sala.nume_amfiteatru)+1];
        strcpy(this->nume_amfiteatru, sala.nume_amfiteatru);
    }
    return *this;
}
istream & operator>>(istream& in, Sala& sala){
    cout<<"Introduceti datele necesare pentru a adauga o sala noua"<<endl;
    cout<<"Nr etaj:";
    in>>sala.etaj;
    cout<<"Nr sala:";
    in>>sala.nr_sala;
    cout<<"Capacitate sala:";
    in>>sala.capacitate;
    cout<<"Este amfiteatru:";
    in>>sala.e_amfiteatru;
    if(sala.e_amfiteatru == 1){
        cout<<"Nume amfiteatru:";
        string nume_amfiteatru;
        in.get();
        getline(in, nume_amfiteatru);
        strcpy(sala.nume_amfiteatru, nume_amfiteatru.c_str());
    }
    else{
        sala.nume_amfiteatru = new char[2];
        strcpy(sala.nume_amfiteatru, "/");
    }
    return in;
}
ostream & operator<<(ostream& out, const Sala& sala){
    out<<"Detalii despre sala:"<<endl;
    out<<"Nr etaj: "<<sala.etaj<<endl;
    out<<"Nr sala: "<<sala.nr_sala<<endl;
    out<<"Capacitate sala: "<<sala.capacitate<<endl;
    if(sala.e_amfiteatru == 1){
        out<<"Este amfiteatru? "<<"DA"<<endl;
        out<<"Nume amfiteatru: "<<sala.nume_amfiteatru<<endl;
    }
    else{
        out<<"Este amfiteatru? "<<"NU"<<endl;
    }
    cout<<endl<<endl;
    return out;
}
const Sala Sala::operator++() {
    this->capacitate++;
    return *this;
}
Sala Sala::operator++(int) {
    Sala aux(*this);
    this->capacitate++;
    return aux;
}
const Sala Sala::operator--() {
    this->capacitate--;
    return *this;
}
Sala Sala::operator--(int) {
    Sala aux(*this);
    this->capacitate--;
    return aux;
}
bool Sala::operator<(const Sala& s){
    if(this->capacitate < s.capacitate)
        return true;
    return false;
}
bool Sala::operator>(const Sala& s){
    if(this->capacitate > s.capacitate)
        return 1;
    return 0;
}
bool Sala::operator<=(const Sala& s){
    if(this->capacitate<=s.capacitate)
        return 1;
    return 0;
}
bool Sala::operator>=(const Sala& s){
    if(this->capacitate>=s.capacitate)
        return 1;
    return 0;
}
bool Sala::operator==(const Sala& s){
    if(this->etaj == s.etaj && this->nr_sala == s.nr_sala)
        return 1;
    return 0;
}
Sala Sala::operator+(int x){
    Sala aux(*this);
    aux.capacitate += x;
    return aux;
}
Sala operator+(int x, Sala s){
    s.capacitate += x;
    return s;
}
Sala Sala::operator+(Sala s){
    s.capacitate += this->capacitate;
    return s;
}
Sala Sala::operator-(int x){
    Sala aux(*this);
    if(aux.capacitate < x)
        aux.capacitate = 0;
    else
        aux.capacitate -= x;
    return aux;
}
Sala operator-(int x, Sala s){
    if(s.capacitate < x)
        s.capacitate = 0;
    else
        s.capacitate -= x;

    return s;
}
//functionalitate
void Sala::verificareAmfiteatru(){
    if(this->capacitate >= 70 && this->e_amfiteatru == 0){
        this->e_amfiteatru = 1;
        string nume;
        cout<<"Introduceti un nume pentru amfiteatru: ";
        cin.get();
        getline(cin, nume);
        this->nume_amfiteatru = new char[nume.size()+1];
        strcpy(this->nume_amfiteatru, nume.c_str());
    }
}
//deconstructor
Sala::~Sala(){
    if(this->nume_amfiteatru!=NULL)
        delete[] this->nume_amfiteatru;
}

///----------------------------------------------------------------------------------------------------
///metode profesor
//constructori
Profesor::Profesor() {
    this->nume = new char[strlen("Profesor")+1];
    strcpy(this->nume, "Profesor");
    this->prenume = new char[strlen("Anonim")+1];
    strcpy(this->prenume, "Anonim");
    this->initiala='X';
    this->e_decan = false;
    this->vechime = 0;
    this->salariu = 0.0;
}
Profesor::Profesor(char* nume, char* prenume, char initiala, bool e_decan, int vechime, float salariu){
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
    this->prenume = new char[strlen(prenume)+1];
    strcpy(this->prenume, prenume);
    this->initiala = initiala;
    this->e_decan = e_decan;
    this->vechime = vechime;
    this->salariu = salariu;
}
Profesor::Profesor(char* nume, char* prenume, char initiala, int vechime, float salariu){
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
    this->prenume = new char[strlen(prenume)+1];
    strcpy(this->prenume, prenume);
    this->initiala = initiala;
    this->e_decan = false;
    this->vechime = vechime;
    this->salariu = salariu;
}
Profesor::Profesor(char* nume, char* prenume, char initiala){
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
    this->prenume = new char[strlen(prenume)+1];
    strcpy(this->prenume, prenume);
    this->initiala = initiala;
    this->e_decan = false;
    this->vechime = 0;
    this->salariu = 0.0;
}
//copy-constructor
Profesor::Profesor(const Profesor& prof){
    this->nume = new char[strlen(prof.nume)+1];
    strcpy(this->nume, prof.nume);
    this->prenume = new char[strlen(prof.prenume)+1];
    strcpy(this->prenume, prof.prenume);
    this->initiala = prof.initiala;
    this->e_decan = prof.e_decan;
    this->vechime = prof.vechime;
    this->salariu = prof.salariu;
}
//getteri:
char* Profesor::getNume(){
    return this->nume;
}
char* Profesor::getPrenume(){
    return this->prenume;
}
char Profesor::getInitiala(){
    return this->initiala;
}
bool Profesor::getE_decan(){
    return this->e_decan;
}
int Profesor::getVechime(){
    return this->vechime;
}
float Profesor::getSalariu(){
    return this->salariu;
}
//setteri:
void Profesor::setNume(char* nume){
    delete[] this->nume;
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);
}
void Profesor::setPrenume(char* prenume){
    delete[] this->prenume;
    this->prenume = new char[strlen(prenume)+1];
    strcpy(this->prenume, prenume);
}
void Profesor::setInitiala(char initiala){
    this->initiala = initiala;
}
void Profesor::setE_decan(bool e_decan){
    this->e_decan = e_decan;
}
void Profesor::setVechime(int vechime){
    this->vechime = vechime;
}
void Profesor::setSalariu(float salariu){
    this->salariu = salariu;
}
//operatori:
Profesor Profesor::operator=(const Profesor& prof){
    if(this != &prof){
        if(this->nume!=NULL)
            delete[] this->nume;
        if(this->prenume!=NULL)
            delete[] this->prenume;
        this->nume = new char[strlen(prof.nume)+1];
        strcpy(this->nume, prof.nume);
        this->prenume = new char[strlen(prof.prenume)+1];
        strcpy(this->prenume, prof.prenume);
        this->initiala = prof.initiala;
        this->e_decan = prof.e_decan;
        this->vechime = prof.vechime;
        this->salariu = prof.salariu;
    }
    return *this;
}
istream & operator>>(istream &in, Profesor &prof){
    cout<<"Introduceti datele profesorului: "<<endl;
    cout<<"Nume:";
    in>>prof.nume;
    cout<<"Prenume:";
    in>>prof.prenume;
    cout<<"Initiala:";
    in>>prof.initiala;
    cout<<"E_decan:";
    in>>prof.e_decan;
    cout<<"Vechime:";
    in>>prof.vechime;
    cout<<"Salariu:";
    in>>prof.salariu;
    return in;
}
ostream & operator<<(ostream &out, const Profesor &prof){
    out<<"Date despre profesor:"<<endl;
    out<<"Nume:"<<prof.nume<<endl;
    out<<"Prenume:"<<prof.prenume<<endl;
    out<<"Initiala:"<<prof.initiala<<endl;
    if(prof.e_decan == 1)
        out<<"E_decan:"<<"DA"<<endl;
    else
        out<<"E_decan:"<<"NU"<<endl;
    out<<"Vechime:"<<prof.vechime<<endl;
    out<<"Salariu:"<<prof.salariu<<endl;
    cout<<endl<<endl;
    return out;
}
const Profesor& Profesor::operator++(){
    this->vechime++;
    return *this;
}
Profesor Profesor::operator++(int){
    Profesor aux(*this);
    this->vechime++;
    return aux;
}
const Profesor& Profesor::operator--(){
    this->vechime++;
    return *this;
}
Profesor Profesor::operator--(int){
    Profesor aux(*this);
    this->vechime++;
    return aux;
}
Profesor::operator int() {
    return (int)this->salariu;
}
bool Profesor::operator<(const Profesor& prof){
    if(this->vechime<prof.vechime)
        return true;
    return false;
}
bool Profesor::operator>(const Profesor& prof){
    if(this->vechime>prof.vechime)
        return 1;
    return 0;
}
bool Profesor::operator<=(const Profesor& prof){
    if(this->vechime<=prof.vechime)
        return 1;
    return 0;
}
bool Profesor::operator>=(const Profesor& prof){
    if(this->vechime>=prof.vechime)
        return 1;
    return 0;
}
bool Profesor::operator==(const Profesor& prof){
    if(strcmp(this->nume, prof.nume) == 0 && strcmp(this->prenume, prof.prenume) == 0 && this->initiala == prof.initiala)
        return 1;
    return 0;
}
Profesor Profesor::operator+(int x){
    Profesor aux(*this);
    aux.vechime += x;
    return aux;
}
Profesor operator+(int x, Profesor prof){
    prof.vechime += x;
    return prof;
}
Profesor Profesor::operator+(Profesor prof){
    prof.vechime += this->vechime;
    prof.salariu += this->salariu;
    return prof;
}
Profesor Profesor::operator-(int x){
    Profesor aux(*this);
    if(aux.vechime < x)
        aux.vechime = 0;
    else
        aux.vechime -= x;
    return aux;
}
Profesor operator-(int x, Profesor prof){
    if(prof.vechime < x)
        prof.vechime = 0;
    else
        prof.vechime -= x;

    return prof;
}
//functionalitate
void Profesor::verificareDecan(){
    if(this->e_decan == 0 && this->vechime >=30){
        this->e_decan = true;
        this->salariu += 10000;
    }
}
//destructor:
Profesor::~Profesor(){
    if(this->nume!=NULL)
        delete[] this->nume;
    if(this->prenume!=NULL)
        delete[] this->prenume;
}
///------------------------------------------------------------------------------------------------------
///meniu interactiv aplicatie
int meniuCRUD(){
    int x;
    cout<<"Optiunile sunt:"<<endl;
    cout<<"1.Create"<<endl;
    cout<<"2.Read"<<endl;
    cout<<"3.Update"<<endl;
    cout<<"4.Delete"<<endl;
    cout<<"5.Inchidere aplicatie"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>5){
        cout<<"Va rog alegeti un numar intre 1 si 5"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int meniuCreate(){
    int x;
    cout<<endl<<"Alegeti ce obiect doriti sa creati:"<<endl;
    cout<<"1. Student"<<endl;
    cout<<"2. Profesor"<<endl;
    cout<<"3. Sala"<<endl;
    cout<<"4. Materie"<<endl;
    cout<<"5. Inapoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>5){
        cout<<"Va rog alegeti un numar intre 1 si 5"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int meniuCreate_Student(){
    int x;
    cout<<endl<<"Alegeti cum doriti sa construiti studentul:"<<endl;
    cout<<"1. Fara niciun parametru"<<endl;
    cout<<"2. Cu toti parametrii"<<endl;
    cout<<"3. Doar cu numele intreg"<<endl;
    cout<<"4. Folosind numele intreg si numarul de materii pe care le are"<<endl;
    cout<<"5. Inapoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>5){
        cout<<"Va rog alegeti un numar intre 1 si 5"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int meniuCreate_Profesor(){
    int x;
    cout<<endl<<"Alegeti cum doriti sa construiti profesorul:"<<endl;
    cout<<"1. Fara niciun parametru"<<endl;
    cout<<"2. Cu toti parametrii"<<endl;
    cout<<"3. Doar cu numele intreg"<<endl;
    cout<<"4. Folosind numele intreg, vechimea si salariul"<<endl;
    cout<<"5. Inapoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>5){
        cout<<"Va rog alegeti un numar intre 1 si 5"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int meniuCreate_Sala(){
    int x;
    cout<<endl<<"Alegeti cum doriti sa construiti sala:"<<endl;
    cout<<"1. Fara niciun parametru"<<endl;
    cout<<"2. Cu toti parametrii"<<endl;
    cout<<"3. Folosind etajul si numarul salii"<<endl;
    cout<<"4. Folosind etajul, numarul salii si capacitatea acesteia"<<endl;
    cout<<"5. Inapoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>5){
        cout<<"Va rog alegeti un numar intre 1 si 5"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int meniuCreate_Materie(){
    int x;
    cout<<endl<<"Alegeti cum doriti sa construiti materia:"<<endl;
    cout<<"1. Fara niciun parametru"<<endl;
    cout<<"2. Cu toti parametrii"<<endl;
    cout<<"3. Doar cu denumirea materiei"<<endl;
    cout<<"4. Folosind denumirea materiei si profesorul"<<endl;
    cout<<"5. Inapoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>5){
        cout<<"Va rog alegeti un numar intre 1 si 5"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int meniuRead(){
    int x;
    cout<<endl<<"Alegeti ce obiect doriti sa vizualizati:"<<endl;
    cout<<"1. Student"<<endl;
    cout<<"2. Profesor"<<endl;
    cout<<"3. Sala"<<endl;
    cout<<"4. Materie"<<endl;
    cout<<"5. Inapoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>5){
        cout<<"Va rog alegeti un numar intre 1 si 5"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int meniuUpdate(){
    int x;
    cout<<endl<<"Alegeti ce tip de obiect doriti sa schimbati:"<<endl;
    cout<<"1. Student"<<endl;
    cout<<"2. Profesor"<<endl;
    cout<<"3. Sala"<<endl;
    cout<<"4. Materie"<<endl;
    cout<<"5. Inapoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>5){
        cout<<"Va rog alegeti un numar intre 1 si 5"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int listaStudent( vector<Student>& studenti){
    int x;
    if(studenti.size() == 0){
        cout<<"Creati un student mai intai"<<endl;
        return -1;
    }
    else
        for(int i=0; i<studenti.size();i++)
        {
            cout<<"Studentul "<<i+1<<": "<<studenti[i].getNume()<<endl;
        }
    cout<<studenti.size()+1<<".Inapoi"<<endl;
    cout<<endl;
    cout<<"Alegerea este:";
    cin>>x;
    while(x<1 || x>studenti.size()+1){
        cout<<"Va rog alegeti un numar intre 1 si "<<studenti.size()+1<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;

}
int listaProfesor( vector<Profesor>& profesori){
    int x;
    if(profesori.size() == 0){
        cout<<"Creati un profesor mai intai"<<endl;
        return -1;
    }

    else
        for(int i=0; i<profesori.size();i++)
        {
            cout<<"Studentul "<<i+1<<": "<<profesori[i].getNume()<<endl;

        }
    cout<<profesori.size()+1<<".Inapoi"<<endl;
    cout<<endl;
    cout<<"Alegerea este:";
    cin>>x;
    while(x<1 || x>profesori.size()+1){
        cout<<"Va rog alegeti un numar intre 1 si "<<profesori.size()+1<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;

}
int listaSala( vector<Sala>& sali){
    int x;
    if(sali.size() == 0){
        cout<<"Creati o sala mai intai"<<endl;
        return -1;
    }
    else
        for(int i=0; i<sali.size();i++)
        {
            cout<<"Sala "<<i+1<<": "<<sali[i].getNr_sala()<<endl;
        }
    cout<<sali.size()+1<<".Inapoi"<<endl;
    cout<<endl;
    cout<<"Alegerea este:";
    cin>>x;
    while(x<1 || x>sali.size()+1){
        cout<<"Va rog alegeti un numar intre 1 si "<<sali.size()+1<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;

}
int listaMaterie( vector<Materie>& materii){
    int x;
    if(materii.size() == 0){
        cout<<"Creati o materie mai intai"<<endl;
        return -1;
    }
    else
        for(int i=0; i<materii.size();i++)
        {
            cout<<"Sala "<<i+1<<": "<<materii[i].getNume_materie()<<endl;
        }
    cout<<materii.size()+1<<".Inapoi"<<endl;
    cout<<endl;
    cout<<"Alegerea este:";
    cin>>x;
    while(x<1 || x>materii.size()+1){
        cout<<"Va rog alegeti un numar intre 1 si "<<materii.size()+1<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;

}
int atributeStudent(){
    int x;
    cout<<endl<<"Alegeti atributul pe care doriti sa il schimabti:"<<endl;
    cout<<"1. Numele"<<endl;
    cout<<"2. Prenumele"<<endl;
    cout<<"3. Initiala tatalui"<<endl;
    cout<<"4. Are bursa?"<<endl;
    cout<<"5. Numarul de materii(vor trebui modificate si mediile si materiile studentului)"<<endl;
    cout<<"6. Mediile studentului"<<endl;
    cout<<"7. Media de admitere"<<endl;
    cout<<"8. Materiile studentului"<<endl;
    cout<<"9. Inapoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>9){
        cout<<"Va rog alegeti un numar intre 1 si 9"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;

}
int atributeProfesor(){
    int x;
    cout<<endl<<"Alegeti atributul pe care doriti sa il schimabti:"<<endl;
    cout<<"1. Numele"<<endl;
    cout<<"2. Prenumele"<<endl;
    cout<<"3. Initiala"<<endl;
    cout<<"4. Este decan? "<<endl;
    cout<<"5. Vechime"<<endl;
    cout<<"6. Salariu"<<endl;
    cout<<"7. Inpoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>7){
        cout<<"Va rog alegeti un numar intre 1 si 7"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int atributeSala(){
    int x;
    cout<<endl<<"Alegeti atributul pe care doriti sa il schimabti:"<<endl;
    cout<<"1. Etajul"<<endl;
    cout<<"2. Numarul salii"<<endl;
    cout<<"3. Capacitate"<<endl;
    cout<<"4. Este amfiteatru? "<<endl;
    cout<<"5. Numele amfiteatrului(Poate fi schimbat doar daca este amfiteatru)"<<endl;
    cout<<"6. Inpoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>6){
        cout<<"Va rog alegeti un numar intre 1 si 6"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int atributeMaterie(){
    int x;
    cout<<endl<<"Alegeti atributul pe care doriti sa il schimabti:"<<endl;
    cout<<"1. Numele materiei"<<endl;
    cout<<"2. Profesorul"<<endl;
    cout<<"3. Sala"<<endl;
    cout<<"4. Numarul de credite"<<endl;
    cout<<"5. Are examen?"<<endl;
    cout<<"6. Inapoi"<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>6){
        cout<<"Va rog alegeti un numar intre 1 si 6"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
int meniuDelete(){
    int x;
    cout<<endl<<"Alegeti ce tip de obiect doriti sa stergeti:"<<endl;
    cout<<"1. Student"<<endl;
    cout<<"2. Profesor"<<endl;
    cout<<"3. Sala"<<endl;
    cout<<"4. Materie"<<endl;
    cout<<"5. Inapoi"<<endl<<endl;
    cout<<"Alegerea este:"; cin>>x;
    while(x<1 || x>5){
        cout<<"Va rog alegeti un numar intre 1 si 5"<<endl;
        cout<<"Alegerea este:"; cin>>x;
    }
    return x;
}
