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
