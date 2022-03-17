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
