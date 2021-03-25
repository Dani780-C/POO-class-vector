#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Vector{
    int nr_elemente;
    int *v;
public:
    Vector(){
        nr_elemente = 0;
        v = NULL;
    }
    Vector(int nr_comp,int val = 0){
        nr_elemente = nr_comp;
        v = new int [nr_elemente];
        for(int i = 0;i<nr_elemente;i++)
            v[i] = val;
    }
    Vector(Vector& b){
        nr_elemente = b.nr_elemente;
        v = new int [nr_elemente];
        for(int i = 0; i<nr_elemente; i++){
            v[i] = b.v[i];
        }
    }
    ~Vector(){
        delete [] v;
    }

    void set_nr_elemente(int val){
        nr_elemente = val;
    }
    int get_element(int poz){
        return v[poz];
    }
    void set_element(int poz,int val){
        v[poz] = val;
    }
    void citire_memorare();
    void afisare();
    void reactualizare_vector(int, int);
    int suma();
    int find_maxim();
    int poz_maxim();
    void sortare();
    int get_nr_elemente();
    int& operator [](int);
    void operator = (Vector);
    friend ostream& operator<< (ostream&, const Vector&);
    friend istream& operator>> (istream&, Vector&);
};

void Vector::citire_memorare(){
    Vector t;
    cin>>t;
    v = new int [t.nr_elemente];
    nr_elemente = t.nr_elemente;
    for(int i=0;i<nr_elemente;i++)
        v[i] = t.v[i];
}

void Vector::afisare(){
    for(int i=0;i<nr_elemente;i++)
        cout<<v[i]<<" ";
    cout<<'\n';
}

ostream& operator<< (ostream& out, const Vector& c){
    out<<"\nLungimea vectorului este "<<c.nr_elemente<<".\n";
    out<<"Vectorul este ";
    for(int i=0;i<c.nr_elemente;i++)
        out<<c.v[i]<<" ";
    out<<".\n";
    return out;
}

istream& operator>> (istream& in, Vector& k) {
    cout<<"Cititi numarul de elemente: ";
    in>>k.nr_elemente;
    k.v = new int [k.nr_elemente+1];
    cout<<"Cititi vectorul: ";
    for(int i=0;i<k.nr_elemente; i++)
        in>>k.v[i];
    cout<<'\n';
    return in;
}

int& Vector::operator [](int poz){
    return v[poz];
}

int Vector::get_nr_elemente(){
    return nr_elemente;
}

void Vector::operator = (Vector q){
    delete [] v;
    nr_elemente = q.nr_elemente;
    v = new int [nr_elemente];
    for (int i = 0; i < nr_elemente; i++)
        v[i] = q.v[i];
}

void Vector::sortare(){
    for(int i=1;i<nr_elemente;i++){
        int j = i-1;
        int nr = v[i];
        while(j>=0 && v[j]>nr){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = nr;
    }
}


int Vector::poz_maxim(){
    int m = v[0];
    int poz = 0;
    for(int i=1;i<nr_elemente; i++)
        if(v[i]>m){
            m=v[i];
            poz = i;
        }
    return poz+1;
}

int Vector::find_maxim(){
    int m = v[0];
    for(int i=1;i<nr_elemente; i++)
        if(v[i]>m) m=v[i];
    return m;
}

void Vector::reactualizare_vector(int nr_comp, int val = 0){
    delete [] v;
    nr_elemente = nr_comp;
    v = new int [nr_elemente];
    for(int i=0;i<nr_elemente;i++)
        v[i] = val;
}

int Vector::suma(){
    int s = 0;
    for(int i = 0;i<nr_elemente; i++)
        s+=v[i];
    return s;
}

void meniu(){
    cout<<"-----------------Meniu-----------------\n";
    cout<<" 0  --- Afiseaza lungimea si elementele vectorului.\n";
    cout<<" 1  --- Reactualizeaza vectorul cu un numar nou de componente si initializeaza-l o cu o valoare data.\n";
    cout<<" 2  --- Gaseste maximul din vector.\n";
    cout<<" 3  --- Gaseste pozitia maximului din vector.\n";
    cout<<" 4  --- Gaseste maximul si pozitia lui in vector.\n";
    cout<<" 5  --- Sorteaza vectorul.\n";
    cout<<" 6  --- Afisati suma elementelor din vector.\n";
    cout<<" 7  --- Atribuie unui element din vector o noua valoare.\n";
    cout<<" 8  --- Schimbati numarul vectorului pe care vreti sa lucrati.\n";
    cout<<" 9  --- Afisati toti vectorii.\n";
    cout<<" 10 --- Iesiti din program.\n";
}

int main()
{   int nr;
    cout<<"Dati numarul de vectori ce trebuie memorati: ";
    cin>>nr;
    cout<<'\n';
    Vector a[nr+1];
    for(int i=0;i<nr;i++){
        cout<<"Vectorul "<<i+1<<'\n';
        a[i].citire_memorare();
    }
    int nr_vec;
    cout<<"Alegeti numarul vectorului pe care vreti sa lucrati: ";
    cin>>nr_vec;
    nr_vec--;
    cout<<'\n';
    meniu();
    int run=1,option;
    while(run){
        cout<<"\nAlege o optiune: ";
        cin>>option;
        switch(option){
            cin>>option;
            case 0:{
                cout<<a[nr_vec];
                break;
            }
            case 1:{
                int l,val;
                cout<<"Alegeti noua lungime a vectorului: ";
                cin>>l;
                cout<<"Alegeti valoarea cu care sa fie reinitializat vectorul: ";
                cin>>val;
                a[nr_vec].reactualizare_vector(l,val);
                cout<<"\nVectorul a fost reactualizat!\n";
                break;
            }
            case 2:{
                cout<<"\nMaximul din vector este "<<a[nr_vec].find_maxim()<<".\n";
                break;
            }
            case 3:{
                cout<<"\nPozitia maximului din vector este "<<a[nr_vec].poz_maxim()<<".\n";
                break;
            }
            case 4:{
                cout<<"\nMaximul din vector este "<<a[nr_vec].find_maxim()<<" si se afla pe pozitia "<<a[nr_vec].poz_maxim()<<".\n";
                break;
            }
            case 5:{
                a[nr_vec].sortare();
                cout<<"\nVectorul este sortat!"<<'\n';
                break;
            }
            case 6:{
                cout<<"\nSuma elementelor din vector este "<<a[nr_vec].suma()<<"."<<'\n';
                break;
            }
            case 7:{
                int poz, val;
                cout<<"Alege o pozitie intre 1 si "<<a[nr_vec].get_nr_elemente()<<": ";
                cin>>poz;
                cout<<"Alege o valoare pentru numarul de pe pozitia "<<poz<<": ";
                cin>>val;
                a[nr_vec][poz-1] = val;
                cout<<"\nValoarea elementului a fost modificata!\n";
                break;
            }
            case 8:{
                cout<<"Ati lucrat pe vectorul "<<nr_vec+1<<"."<<'\n';
                cout<<"Alegeti numarul vectorului pe care sa lucrati in continuare: ";
                cin>>nr_vec;
                nr_vec--;
                cout<<'\n';
                meniu();
                break;
            }
            case 9:{
                cout<<'\n';
                for(int i=0;i<nr;i++){
                    cout<<"Vectorul "<<i+1<<"   ";
                    a[i].afisare();
                }
                break;
            }
            case 10:{
                run = 0;
                break;
            }
            default:{
                break;
            }
        }
    }
    return 0;
}
