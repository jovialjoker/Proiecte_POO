#include <iostream>
#include <string.h>

using namespace std;
///--------------------------------------------------------------------------------------
class Profesor{
private:
    char* nume;
    char* prenume;
	char initiala;
    bool e_decan;
    int vechime;
    float salariu;
public:
    ///constructori:
    Profesor() {
        this->nume = new char[strlen("Profesor")+1];
        strcpy(this->nume, "Profesor");
        this->prenume = new char[strlen("Anonim")+1];
        strcpy(this->prenume, "Anonim");
        this->initiala='X';
        this->e_decan = false;
        this->vechime = 0;
        this->salariu = 0.0;
    }
    Profesor(char* nume, char* prenume, char initiala, bool e_decan, int vechime, float salariu){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
        this->initiala = initiala;
        this->e_decan = e_decan;
        this->vechime = vechime;
        this->salariu = salariu;
    }
    Profesor(char* nume, char* prenume, char initiala, int vechime, float salariu){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
        this->initiala = initiala;
        this->e_decan = false;
        this->vechime = vechime;
        this->salariu = salariu;
    }
    Profesor(char* nume, char* prenume){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
        this->initiala = '/';
        this->e_decan = false;
        this->vechime = 0;
        this->salariu = 0.0;
    }

    ///copy-constructor
    Profesor(const Profesor& prof){
        this->nume = new char[strlen(prof.nume)+1];
        strcpy(this->nume, prof.nume);
        this->prenume = new char[strlen(prof.prenume)+1];
        strcpy(this->prenume, prof.prenume);
        this->initiala = prof.initiala;
        this->e_decan = prof.e_decan;
        this->vechime = prof.vechime;
        this->salariu = prof.salariu;
    }

    ///getteri:
    char* getNume(){
        return this->nume;
    }
    char* getPrenume(){
        return this->prenume;
    }
    char getInitiala(){
        return this->initiala;
    }
    bool getE_decan(){
        return this->e_decan;
    }
    int getVechime(){
        return this->vechime;
    }
    float getSalariu(){
        return this->salariu;
    }
    ///setteri:
    void setNume(char* nume){
        delete[] this->nume;
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
    }
    void setPrenume(char* prenume){
        delete[] this->prenume;
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
    }
    void setInitiala(char initiala){
        this->initiala = initiala;
    }
    void setE_decan(bool e_decan){
        this->e_decan = e_decan;
    }
    void setVechime(int vechime){
        this->vechime = vechime;
    }
    void setSalariu(float salariu){
        this->salariu = salariu;
    }

    ///operatori:
    Profesor operator=(const Profesor& prof){
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

    friend istream & operator>>(istream &in, Profesor &prof){
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

    friend ostream & operator<<(ostream &out, const Profesor &prof){
        out<<"Nume:"<<prof.nume<<endl;
        out<<"Prenume:"<<prof.prenume<<endl;
        out<<"Initiala:"<<prof.initiala<<endl;
        if(prof.e_decan == 1)
            out<<"E_decan:"<<"DA"<<endl;
        else
            out<<"E_decan:"<<"NU"<<endl;
        out<<"Vechime:"<<prof.vechime<<endl;
        out<<"Salariu:"<<prof.salariu<<endl;
        return out;
    }
    ///destructor:
    ~Profesor(){
        if(this->nume!=NULL)
            delete[] this->nume;
        if(this->prenume!=NULL)
            delete[] this->prenume;
    }
};

///---------------------------------------------------------------------------------------
class Sala{
private:
    int etaj;
    int nr_sala;
    int capacitate;
    bool e_amfiteatru;
    char* nume_amfiteatru; //in caz ca amfiteatru==true
public:
    ///constructori
    Sala(){
        this->etaj = 0;
        this->nr_sala = 0;
        this->capacitate = 0;
        this->e_amfiteatru = false;
        this->nume_amfiteatru = new char[2];
        strcpy(this->nume_amfiteatru, "/");
    }
    Sala(int etaj, int nr_sala, int capacitate, bool e_amfiteatru, char* nume_amfiteatru){
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
    Sala(int etaj, int nr_sala, int capacitate){
        this->etaj = etaj;
        this->nr_sala = nr_sala;
        this->capacitate = capacitate;
        this->e_amfiteatru = false;
        this->nume_amfiteatru = new char[2];
        strcpy(this->nume_amfiteatru, "/");
    }
    Sala(int etaj, int nr_sala){
        this->etaj = etaj;
        this->nr_sala = nr_sala;
        this->capacitate = 0;
        this->e_amfiteatru = false;
        this->nume_amfiteatru = new char[2];
        strcpy(this->nume_amfiteatru, "/");
    }

    ///copy-constructor
    Sala(const Sala& sala){
        this->etaj = sala.etaj;
        this->nr_sala = sala.nr_sala;
        this->capacitate = sala.capacitate;
        this->e_amfiteatru = sala.e_amfiteatru;
        this->nume_amfiteatru = new char[strlen(sala.nume_amfiteatru)+1];
        strcpy(this->nume_amfiteatru, sala.nume_amfiteatru);
    }

    ///getteri
    int getEtaj(){
        return this->etaj;
    }
    int getNr_sala(){
        return this->nr_sala;
    }
    int getCapacitate(){
        return this->capacitate;
    }
    bool getE_amfiteatru(){
        return this->e_amfiteatru;
    }
    char* getNume_amfiteatru(){
        return this->nume_amfiteatru;
    }

    ///setteri
    void setEtaj(int etaj){
        this->etaj = etaj;
    }
    void setNr_sala(int nr_sala){
        this->nr_sala = nr_sala;
    }
    void setCapacitate(int capacitate){
        this->capacitate = capacitate;
    }
    void setE_amfiteatru(bool e_amfiteatru){
        this->e_amfiteatru = e_amfiteatru;
    }
    void setNume_amfiteatru(char* nume_amfiteatru){
        if(this->nume_amfiteatru!=NULL)
            delete[] this->nume_amfiteatru;
        this->nume_amfiteatru = new char[strlen(nume_amfiteatru)+1];
        strcpy(this->nume_amfiteatru, nume_amfiteatru);
    }


    ///operatori
    Sala operator=(const Sala& sala){
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
    friend istream & operator>>(istream& in, Sala& sala){
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
            in>>sala.nume_amfiteatru;
        }
        else{
            sala.nume_amfiteatru = new char[2];
            strcpy(sala.nume_amfiteatru, "/");
        }
        return in;
    }
    friend ostream & operator<<(ostream& out, const Sala& sala){
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
        return out;
    }

    ///deconstructor
    ~Sala(){
        if(this->nume_amfiteatru!=NULL)
            delete[] this->nume_amfiteatru;
    }

};

///-------------------------------------------------------------------------------------
class Materie {
private:
    string nume_materie;
    Profesor prof;
    Sala s;
    int credite;
    bool are_examen;
public:
    ///constructori
    Materie(){
        this->nume_materie = "Materie";
        this->credite = 0;
        this->are_examen = false;
    }
    Materie(string nume_materie, Profesor prof, Sala s, int credite, bool are_examen){
        this->nume_materie = nume_materie;
        this->prof = prof;
        this->s = s;
        this->credite = credite;
        this->are_examen = are_examen;
    }
    Materie(string nume_materie, Profesor prof){
        this->nume_materie = nume_materie;
        this->prof = prof;
        this->credite = 0;
        this->are_examen = false;
    }
    Materie(string nume_materie){
        this->nume_materie = nume_materie;
        this->credite = 0;
        this->are_examen = false;
    }
    Materie(const Materie& M){
        this->nume_materie = M.nume_materie;
        this->prof = M.prof;
        this->s = M.s;
        this->credite = M.credite;
        this->are_examen = M.are_examen;
    }
    ///getteri
    string getNume_materie(){
        return this->nume_materie;
    }
    Profesor getProf(){
        return this->prof;
    }
    Sala getS(){
        return this->s;
    }
    int getCredite(){
        return this->credite;
    }
    bool getAre_examen(){
        return this->are_examen;
    }

    ///setteri
    void setNume_materie(string nume_materie){
        this->nume_materie = nume_materie;
    }
    void setProf(Profesor prof){
        this->prof = prof;
    }
    void setS(Sala s){
        this->s = s;
    }
    void setCredite(int credite){
        this->credite = credite;
    }
    void setAre_examen(bool are_examen){
        this->are_examen = are_examen;
    }

    ///operatori
    Materie operator=(const Materie& M){
        if(this!=&M){
            this->nume_materie = M.nume_materie;
            this->prof = M.prof;
            this->s = M.s;
            this->credite = M.credite;
            this->are_examen = M.are_examen;
        }
        return *this;
    }

    friend istream & operator>>(istream& in, Materie& M){
        cout<<"Introduceti datele despre materie:"<<endl;
        cout<<"Nume materie: "; in>>M.nume_materie;
        in>>M.prof;
        in>>M.s;
        cout<<"Nr credite: "; in>>M.credite;
        cout<<"Are examen? "; in>>M.are_examen;
        return in;
    }
    friend ostream & operator<<(ostream& out, Materie& M){
        out<<"Date despre aceasta materie:"<<endl;
        out<<"Nume materie: "<<M.nume_materie<<endl;
        out<<M.prof;
        out<<M.s;
        cout<<"Nr credite: "<<M.credite<<endl;
        cout<<"Are examen? "<<M.are_examen<<endl;
        return out;
    }
};

///----------------------------------------------------------------------------
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
    ///constructori
    Student():nr_matricol(nr_studenti*50+1){
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
    Student(char* nume, char* prenume, char initiala, bool are_bursa, int nr_materii, float* medii, double medie_admitere, Materie* M):nr_matricol(nr_studenti*50+1){
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
    Student(char* nume, char* prenume, char initiala):nr_matricol(nr_studenti*50+1){
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
    Student(char* nume, char* prenume, char initiala, int nr_materii, float* medii):nr_matricol(nr_studenti*50+1){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
        this->initiala = initiala;
        this->nr_studenti++;
        this->are_bursa = false;
        this->nr_materii = nr_materii;
        this->medii = new float[nr_materii];
        for(int i=0; i<nr_materii; i++)
            this->medii[i] = medii[i];
        this->medie_admitere = 0;
        this->M = NULL;
    }
    Student(const Student& s):nr_matricol(nr_studenti*50+1){
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

    ///getteri
    char* getNume(){return this->nume;}
    char* getPrenume() {return this->prenume;}
    char getInitiala() {return this->initiala;}
    int getNr_matricol() {return this->nr_matricol;}
    static int getNr_studenti() {return Student::nr_studenti;}
    bool getAre_bursta() {return this->are_bursa;}
    int getNr_materii(){return this->nr_materii;}
    float* getMedii() {return this->medii;}
    double getMedie_admitere(){return this->medie_admitere;}
    Materie* getM() {return this->M;}

    ///setteri
    void setNume(char* nume){
        delete[] this->nume;
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
    }
    void setPrenume(char* prenume){
        delete[] this->prenume;
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
    }
    void setInitiala(char initiala){
        this->initiala = initiala;
    }
    static void setNr_studenti(int nr_studenti){
        Student::nr_studenti = nr_studenti;
    }
    void setAre_bursa(bool are_bursa){
        this->are_bursa = are_bursa;
    }
    void setNr_materii(int nr_materii){
        this->nr_materii = nr_materii;
    }
    void setMedii(int nr_medii, float* medii){
        setNr_materii(nr_medii);
        if(this->medii != NULL)
            delete[] this->medii;
        this->medii = new float[nr_medii];
        for(int i=0; i<nr_medii; i++)
            this->medii[i] = medii[i];
    }
    void setMedie_admitere(double medie_admitere){
        this->medie_admitere = medie_admitere;
    }
    void setM(int nr_medii, Materie* M){
        this->nr_materii = nr_medii;
        for(int i=0; i<this->nr_materii;i++){
            this->M[i].setNume_materie(M[i].getNume_materie());
            this->M[i].setProf(M[i].getProf());
            this->M[i].setS(M[i].getS());
            this->M[i].setCredite(M[i].getCredite());
            this->M[i].setAre_examen(M[i].getAre_examen());
        }
    }
    ///operatori
    Student operator=(const Student& s){
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

    friend istream & operator>>(istream& in, Student& s){
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
    friend ostream & operator<<(ostream& out, const Student& s){
        out<<"DATELE STUDENTULUI SUNT:"<<endl<<endl;
        out<<"Nume: "<<s.nume<<endl;
        out<<"Prenume: "<<s.prenume<<endl;
        out<<"Initiala: "<<s.initiala<<endl;
        out<<"Are bursa: "<<s.are_bursa<<endl;
        out<<"Nr materii: "<<s.nr_materii<<endl;
        out<<"Materiile studentului: ";
        for(int i=0;i<s.nr_materii;i++){
            out<<"Materia "<<i<<": "<<endl;
            out<<s.M[i];
            out<<"Media: "<<s.medii[i]<<endl;
        }
        out<<endl<<"medie_admitere: "<<s.medie_admitere<<endl;
        return out;
    }
    ///deconstructor
    ~Student(){
        if(this->medii != NULL)
            delete[] this->medii;
        if(this->nume!=NULL)
            delete[] this->nume;
        if(this->prenume!=NULL)
            delete[] this->prenume;
        if(this->M!=NULL)
            delete[] this->M;
    }
};
int Student::nr_studenti=0;


int main()
{
    Student A;
    cin>>A;
    cout<<endl;
    cout<<endl;
    cout<<A;
    return 0;
}
