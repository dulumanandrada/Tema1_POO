//|=================== TEMA 1 POO ======================|// 
//| link GitHub:                                        |//
//|      https://github.com/dulumanandrada/Tema1_POO    |//
//|                                                     |//
//|=====================================================|//

#include <iostream>
#define N 1001

using namespace std;

//===================== DATA =====================//

class Date
{
    //date 
    int zi, luna, an;

    //metode
    public:
    void citire();
    void afisare();
    friend istream& operator>>(istream&, Date&);
    friend ostream& operator<<(ostream&, Date&);
    friend bool operator==(Date&, Date&);
    friend Date operator+(Date& , int&);
    ~Date()
    {
        //cout <<"distruge data \n";
    }
};

void Date::citire()
{
    //cout <<"In ce data suntem? (folositi formatul: zz ll aaaa)\n";
    bool ok = 0;
    while(!ok)
    {
        cin >> zi >> luna >> an;
        if(an / 100000 == 0)
            if(luna <= 12)
                if((luna % 2 == 1 && zi <= 31) || (luna % 2 == 0 && zi <= 30)) {ok = 1; break;}
        cout << "Data invalida! Mai incercati! \n";
    }
}

void Date::afisare()
{
    cout <<"Astazi este data de:\n";
    cout << zi <<"/"<< luna <<"/"<< an <<"\n";
}

istream& operator>>(istream& i, Date& d)
{
    i >> d.zi >> d.luna >> d.an;
    return i;
}

ostream& operator<<(ostream& o, Date& d)
{
    o << d.zi <<"/"<< d.luna <<"/"<< d.an; 
    return o;
}

bool operator==(Date& d1, Date& d2)
{
    return (d1.zi == d2.zi && d1.luna == d2.luna);
}

Date operator+(Date& d, int& nr_zile)
{
    Date a = d;
    while(nr_zile!=0)
    {
        if(a.luna == 12 && a.zi == 31) {a.zi = 1; a.luna = 1; a.an = a.an + 1;}
        else if((a.luna == 2 && a.an % 4 == 1 && a.zi == 28) || (a.luna == 2 && a.an % 4 == 0 && a.zi == 29)){a.zi = 1; a.luna = a.luna + 1;}
            else if(a.luna <= 5 && ((a.luna % 2 == 1 && a.zi == 31) || (a.luna % 2 == 0 && a.zi == 30))) {a.luna = a.luna + 1; a.zi=1;}
                else if(a.luna > 5 && ((a.luna % 2 == 1 && a.zi == 30) || (a.luna % 2 == 0 && a.zi == 31))) {a.luna = a.luna + 1; a.zi=1;}
                    else a.zi = a.zi + 1;
        nr_zile--; 
    }
    return a;
}

void Verificare(Date& d1, Date& d2)
{
    if(d1 == d2) cout <<"Se pare ca astazi este ziua ta...La multi ani!!! \n";
    else cout <<"Nu este inca ziua ta...mai ai de aseptat. \n";

}


//================= CUMPARATURA =================//

class Cumparatura
{
    //date 
    string nume;
    double cantitate;
    double pret;

    //metode
    public:
    void citire();
    void afisare();
    friend istream& operator>>(istream&, Cumparatura&);
    friend ostream& operator<<(ostream&, Cumparatura&);
    friend bool operator==(Cumparatura&, Cumparatura&);
    friend Cumparatura operator+(Cumparatura&, Cumparatura&);
    friend Cumparatura operator-(Cumparatura&, Cumparatura&);
    Cumparatura()
    {
        nume = ""; 
        cantitate = 0; 
        pret = 0;
    }
    ~Cumparatura()
    {
        //cout <<"distruge cumparatura\n";
    }
    Cumparatura(const Cumparatura& c)
    {
        nume = c.nume;
        cantitate = c.cantitate;
        pret = c.pret;
    }

    //set-eri si get-eri
    void set_nume(string n){nume = n;}
    string get_nume(){return nume;}
    void set_cantitate(double c){cantitate = c;}
    double get_cantitate(){return cantitate;}
    void set_pret(double p){pret = p;}
    double get_pret(){return pret;}
};


void Cumparatura::citire()
{
    //cout <<"Ce trebuie cumparat? (nume cant pret)\n";
    cin >> nume >> cantitate >> pret;
}

void Cumparatura::afisare()
{
    //cout <<"Trebuie cumparat: \n";
    cout << nume <<" "<< cantitate <<" "<< pret <<"\n";
}

istream& operator>>(istream& i, Cumparatura& c)
{
    i >> c.nume >> c.cantitate >> c.pret;
    return i;
}

ostream& operator<<(ostream& o, Cumparatura& c)
{
    o << c.nume <<" "<< c.cantitate <<" "<< c.pret;
    return o;
}

bool operator==(Cumparatura& c1, Cumparatura& c2)
{
    return (c1.nume == c2.nume && c1.pret == c2.pret);
}

Cumparatura operator+(Cumparatura& c1, Cumparatura& c2)
{
    Cumparatura c = c1;
    c.cantitate = c1.cantitate + c2.cantitate;
    return c;
}

Cumparatura operator-(Cumparatura& c1, Cumparatura& c2)
{
    Cumparatura c = c1;
    c.cantitate = c1.cantitate - c2.cantitate;
    return c;
}


//================= LISTA DE CUMPARATURI =================//
class ShoppingList
{
    
    Cumparatura *L = new Cumparatura[N];
    int NR;
    double TOTAL;

    public:
    void citire();
    void afisare();
    void set_nr(int nr) {NR = nr;}
    ShoppingList()
    {
        NR = 0;
        TOTAL = 0;
    }
    ~ShoppingList()
    {
        //cout <<"distruge shoppinglist \n";
    }
    void add_item(Cumparatura& c)
    {
        bool ok = 0;
        for(int i = 1; i <= NR && ok == 0; i++)
            if(L[i] == c)
            {
                ok = 1;
                L[i] = L[i] + c;
            }
        if(ok == 0)
        {
            NR ++;
            L[NR] = c;
        }
        TOTAL = TOTAL + (L[NR].get_cantitate() * L[NR].get_pret());
    } 
    void delete_all()
    {
        NR = 0;
        TOTAL = 0;
    }
    void delete_item(Cumparatura& c)
    {
        for(int i = 1; i <= NR; i++)
            if(L[i] == c)
            {
                if(L[i].get_cantitate() != c.get_cantitate())
                {
                    L[i] = L[i] - c;
                    TOTAL = TOTAL - c.get_cantitate() * c.get_pret();
                }
                else 
                {
                    if(NR > 1) 
                    {
                        for(int j = i; j < NR; j++)
                            L[j] = L[j+1];
                        TOTAL = TOTAL - c.get_cantitate() * c.get_pret();
                        NR --;
                    }
                    else if(NR == 1) delete_all();
                }
            }
    }

    //set-eri si get-eri
    void set_NR(int n){NR = n;}
    int get_NR(){return NR;}
    void set_TOTAL(double t){TOTAL = t;}
    double get_TOTAL(){return TOTAL;}
    void set_item(Cumparatura c, int i){L[i] = c;}
    Cumparatura get_item(int i){return L[i];}

};

void ShoppingList::citire()
{
    cout << "dati nr de items \n";
    cin >> NR;
    cout <<"care sunt? \n";
    for(int i=1; i<=NR; i++)
        cin >> L[i];
}

void ShoppingList::afisare()
{
    for(int i=1; i<=NR; i++)
        cout << L[i] <<"\n";
    cout <<"Total de: "<< TOTAL <<"\n";
}


//==================== INDIVID ===================//

class Individ
{
    //date 
    string nume;
    string prenume;
    Date birthday;
    
    //metode
    public:
    void citire();
    void afisare();
    void citire_prieten();
    void afisare_birthday();
    friend istream& operator>>(istream&, Individ&);
    friend ostream& operator<<(ostream&, Individ&);
    friend bool operator==(Individ&, Individ&);
    ~Individ()
    {
        //cout <<"distruge individ \n";
    }

    //set-eri si get-eri
    void set_nume(string n){nume = n;}
    string get_nume(){return nume;}
    void set_prenume(string p){prenume = p;}
    string get_prenume(){return prenume;}
    void set_birthday(Date d){birthday = d;}
    Date get_birthday(){return birthday;}

}prieteni[N];

void Individ::citire()
{
    cout <<"(numele și prenumele) \n";
    cin >> nume >> prenume;
}

void Individ::afisare()
{
    //cout <<"Numele și prenumele acestei persoane este:\n";
    cout << nume <<" "<< prenume <<" s-a nascut pe: "<< birthday;
    cout <<"\n";
}

void Individ::citire_prieten()
{
    cout <<"Numele si prenumele: ";
    cin >> nume >> prenume;
    cout <<"   Data nasterii: ";
    cin >> birthday;
    cout <<"\n";
}

void Individ::afisare_birthday()
{
    //cout <<"ziua de nastere a acestei persoane este:\n";
    birthday.afisare();
}

istream& operator>>(istream& i, Individ& p)
{
    i >> p.nume >> p.prenume;
    return i;
}

ostream& operator<<(ostream& o, Individ& p)
{
    o << p.nume <<" "<< p.prenume;
    return o;
}

bool operator==(Individ& i1, Individ& i2)
{
    return(i1.nume == i2.nume && i1.prenume == i2.prenume);
}


//===================== MENIU ====================//

void AfisareMeniu()
{
    cout <<"\n";
    cout <<"Acesta este meniul aplicatiei. \n"<<"Pentru a executa o anumita comanda apasati tasta corespunzatoare nr. din fata fiecarei operatii din lista de mai jos: \n";
    cout <<"0. Opriti acest proces acum. \n";
    cout <<"1. Retine lista mea de prieteni si ziua lor de nastere. \n";
    cout <<"2. Care sunt prietenii mei si zilele lor de nastere? \n";
    cout <<"3. Este ziua cuiva din lista mea de prieteni astazi? \n";
    cout <<"4. Retine-mi lista de cumparaturi. \n";
    cout <<"5. Arata-mi ce am de cumparat. \n";
    cout <<"6. Am fost la cumparaturi si vreau sa sterg cateva articole din lista. \n";
    cout <<"7. Am cumparat tot ce trebuia. Sterge-mi lista de cumparaturi. \n";
    cout <<"8. Vreau sa ma teleportez in viitor. \n";
    cout <<"9. Am uitat meniul, poti sa imi readuci aminte? :) \n";
    cout <<"\n";
}


//===================== MAIN =====================//

int main()
{
    //declarare date necesare
    int task, nr_prieteni = 0, nr_prieteni_total = 0, nr_items = 0, nr_items_total = 0, i, j, ct;
    bool ok;
    Individ pers;                   
    Date today, d;
    ShoppingList list;
    Cumparatura item;

    cout <<"In ce data suntem? (folositi formatul: zz ll aaaa)\n";
    today.citire();

    cout <<"Servus! \n"<<"Aceasta este agenda ta personala. \n"<<"Cum te numesti? \n";
    pers.citire();

    cout <<"Buna "<< pers <<"! Imi pare bine sa te cunosc! \n"<<"Care este ziua ta de nastere? \n";
    d.citire();
    pers.set_birthday(d);
    Verificare(d, today);

    AfisareMeniu();
    cout <<"Ce comanda vrei sa executi? \n";

    cin >> task;
    while(task)
    {
        if(task == 1)
        {
            cout <<"Cati prieteni ai? \n";
            cin >> nr_prieteni;
            if(nr_prieteni != 0)
                {
                    cout <<"Care sunt acestia? \n";
                    for(i = 1; i <= nr_prieteni; i++)
                    {
                        cout << i <<". ";
                        prieteni[i].citire_prieten();
                    }
                    nr_prieteni_total += nr_prieteni;
                }
            else cout <<"Imi pare rau sa aud asta! Mai iesi din casa... \n";
        }

        if(task == 2)
        {
            if(nr_prieteni_total != 0)
            {
                cout <<"Acestia sunt toti prietenii tai si zilele lor de nastere: \n";
                for(i = 1; i <= nr_prieteni_total; i++)
                {
                    cout << i << ". ";
                    prieteni[i].afisare();
                }
            }
            else cout <<"Nu mi-ai spus despre niciun prieten momentan. Apasa tasta 1 pentru a face acest lucru. \n";
        }

        if(task == 3)
        {
            ct = 0;
            for(i = 1; i <= nr_prieteni_total; i ++)
                {
                    d = prieteni[i].get_birthday();
                    if(d == today && ct == 0) 
                    {
                        ct ++;
                        cout <<"Astazi este ziua lui: \n";
                        cout << prieteni[i] <<"\n";
                    }
                    else if(today == d && ct != 0) cout << prieteni[i] <<"\n";
                }
            if(ct == 0) cout <<"Nu este ziua nimanui astazi...\n";
        }

        if(task == 4)
        {
            cout <<"Cate produse ai de cumparat? \n";
            cin >> nr_items;
            if(nr_items != 0)
            {
                cout <<"Ce trebuie cumparat? (nume cantitate pret) \n";
                for(i = 1; i <= nr_items; i++)
                    {
                        cin >> item;
                        list.add_item(item);
                    }
                nr_items_total += nr_items;
            }
            else cout <<"Nu ai nimic de cumparat declarat. \n";
        }

        if(task == 5)
        {
            if(nr_items_total != 0)
            {
                cout <<"Aceasta este lista dumneavoastra de cumparaturi: \n";
                list.afisare();
            }
            else cout <<"Nu ai nimic de cumparat. Inca ;) \n";
        }


        if(task == 6)
        {
            cout <<"Super! As vrea sa stiu ce ai reusit sa cumperi pana acum. Cate produse ai achizionat? \n";
            cin >> ct;
            if(ct != 0)
            {
                cout <<"Care sunt acestea? (nume cantitate pret) \n";
                Cumparatura c;
                while(ct != 0)
                {
                    ok = 0;
                    cin >> c;
                    list.delete_item(c);
                    ct--;
                }
            }
        }

        if(task == 7)
        {
            cout <<"Felicitari! Ai reusit sa bifezi tot ce era pe lista!! \n";
            list.delete_all();
            nr_items_total = 0;
        }
        

        if(task == 8)
        {
            int nr_zile;
            cout <<"Cu cate zile in viitor vrei sa te deplasezi? \n";
            cin >> nr_zile;
            today = today + nr_zile;
            today.afisare();
            d = pers.get_birthday();
            Verificare(today, d);
            ct = 0;
            for(i = 1; i <= nr_prieteni; i ++)
                {
                    d = prieteni[i].get_birthday();
                    if(d == today && ct == 0) 
                    {
                        cout <<"Si este ziua lui: \n";
                        cout << prieteni[i] <<"\n";
                        ct ++;
                    }
                    else if(today == d && ct != 0) cout << prieteni[i] <<"\n";
                }
        }

        if(task == 9)
            AfisareMeniu();

        cout <<"Ce comanda vrei sa executi in continuare? \n";
        cin >>task;
    }
    
    return 0;
}



