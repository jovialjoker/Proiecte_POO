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
    char* materie_predata;
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
        this->materie_predata = new char[strlen("Materie predata")+1];
        strcpy(this->materie_predata, "Materie predata");
    }
    Profesor(char* nume, char* prenume, char initiala, bool e_decan, int vechime, float salariu, char* materie_predata){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
        this->initiala = initiala;
        this->e_decan = e_decan;
        this->vechime = vechime;
        this->salariu = salariu;
        this->materie_predata = new char[strlen(materie_predata)+1];
        strcpy(this->materie_predata, materie_predata);
    }
    Profesor(char* nume, char* prenume, char initiala, int vechime, float salariu, char* materie_predata){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
        this->initiala = initiala;
        this->e_decan = false;
        this->vechime = vechime;
        this->salariu = salariu;
        this->materie_predata = new char[strlen(materie_predata)+1];
        strcpy(this->materie_predata, materie_predata);
    }
    Profesor(char* nume, char* prenume, char* materie_predata){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
        this->initiala = '/';
        this->e_decan = false;
        this->vechime = 0;
        this->salariu = 0.0;
        this->materie_predata = new char[strlen(materie_predata)+1];
        strcpy(this->materie_predata, materie_predata);
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
        this->materie_predata = new char[strlen(prof.materie_predata)+1];
        strcpy(this->materie_predata, prof.materie_predata);
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
    char* getMaterie_predata(){
        return this->materie_predata;
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
    void setMaterie_predata(char* materie_predata){
        delete[] this->materie_predata;
        this->materie_predata= new char[strlen(materie_predata)+1];
        strcpy(this->materie_predata, materie_predata);
    }

    ///operatori:
    Profesor operator=(const Profesor& prof){
        if(this != &prof){
            if(this->nume!=NULL)
                delete[] this->nume;
            if(this->prenume!=NULL)
                delete[] this->prenume;
            if(this->materie_predata!=NULL)
                delete[] this->materie_predata;
            this->nume = new char[strlen(prof.nume)+1];
            strcpy(this->nume, prof.nume);
            this->prenume = new char[strlen(prof.prenume)+1];
            strcpy(this->prenume, prof.prenume);
            this->initiala = prof.initiala;
            this->e_decan = prof.e_decan;
            this->vechime = prof.vechime;
            this->salariu = prof.salariu;
            this->materie_predata = new char[strlen(prof.materie_predata)+1];
            strcpy(this->materie_predata, prof.materie_predata);
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
        cout<<"Materie predata:";
        in>>prof.materie_predata;
        return in;
    }

    friend ostream & operator<<(ostream &out, Profesor &prof){
        out<<"Nume:"<<prof.nume<<endl;
        out<<"Prenume:"<<prof.prenume<<endl;
        out<<"Initiala:"<<prof.initiala<<endl;
        if(prof.e_decan == 1)
            out<<"E_decan:"<<"DA"<<endl;
        else
            out<<"E_decan:"<<"NU"<<endl;
        out<<"Vechime:"<<prof.vechime<<endl;
        out<<"Salariu:"<<prof.salariu<<endl;
        out<<"Materie predata:"<<prof.materie_predata<<endl;
        return out;
    }
    ///destructor:
    ~Profesor(){
        if(this->nume!=NULL)
            delete[] this->nume;
        if(this->prenume!=NULL)
            delete[] this->prenume;
        if(this->materie_predata!=NULL)
            delete[] this->materie_predata;
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
    ///!!!!de adaugat vectorul de materii
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
    }
    Student(char* nume, char* prenume, char initiala, bool are_bursa, int nr_materii, float* medii, double medie_admitere):nr_matricol(nr_studenti*50+1){
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
    double getMedie_admitere(){return medie_admitere;}

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
    ///de adaugat un setter pentru const !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

    ///deconstructor
    ~Student(){
        if(this->medii != NULL)
            delete[] this->medii;
        if(this->nume!=NULL)
            delete[] this->nume;
        if(this->prenume!=NULL)
            delete[] this->prenume;
    }
};
int Student::nr_studenti=0;


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
    friend ostream & operator<<(ostream& out, Sala& sala){
        cout<<"Detalii despre sala:"<<endl;
        cout<<"Nr etaj: "<<sala.etaj<<endl;
        cout<<"Nr sala: "<<sala.nr_sala<<endl;
        cout<<"Capacitate sala: "<<sala.capacitate<<endl;
        if(sala.e_amfiteatru == 1){
            cout<<"Este amfiteatru? "<<"DA"<<endl;
            cout<<"Nume amfiteatru: "<<sala.nume_amfiteatru<<endl;
        }
        else{
            cout<<"Este amfiteatru? "<<"NU"<<endl;
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
    char* nume_materie;
    Profesor prof;
    Sala s;
    int credite;
    bool are_examen;
public:

};

int main()
{
    Student::setNr_studenti(5);
    float medii[] = {1.7, 2.5, 4.7, 1.4, 3.5, 9};
    Student A("Florea", "George", 'A', 1, 6, medii, 8.754332);
    cout<<A.getMedii()[2]<<endl;
    return 0;
}
