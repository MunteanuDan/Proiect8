#include <iostream>
using namespace std;

class TelefonMobil
{
public:
   

    TelefonMobil()
    {
        producator = "";
        model = "";
        nivelBaterie = 0; 
    }

    /*
    TelefonMobil(string _producator, string _model) : TelefonMobil() // asa se apeleaza mai intai TelefonMobil()
    {
        producator = _producator;
        model = _model;
    //    nivelBaterie = 0;
    }
    */

    // varianta 2, este acelasi lucru ca mai sus, se initializeaza altundeva doar
    TelefonMobil(string _producator, string _model) : producator(_producator), model(_model), nivelBaterie(0)
    {
    }

    TelefonMobil(int nivelBaterie) : TelefonMobil()
    {
        this->nivelBaterie = nivelBaterie;
    }

    // constructor de copiere
    TelefonMobil(const TelefonMobil& t) // transmitem prin referinta
    {
        // nu trb neaparat sa punem this in cazul asta
        this->producator = t.producator;
        (*this).model = t.model; // este acelasi this, doar ca scris altfel
        nivelBaterie = t.nivelBaterie - 1; // scadem 1 din baterie cand apelam acest constructor
    //    t.nivelBaterie = 0; // eroare de compilare deoarece t este const
        cout << "Constructor de copiere " << endl;
    }

    // destructor
    ~TelefonMobil()
    {
        cout << "Apel destructor " << endl;
    }

    // getter
    string getProducator()
    {
        return producator;
    }

    int getNivelBaterie()
    {
        return nivelBaterie;
    }

    void setNivelBaterie(int _nivelBaterie)
    {
        if (_nivelBaterie >= 0 && _nivelBaterie <= 100)
        {
            nivelBaterie = _nivelBaterie;
        }
    }

    void incarca(int nivelIncarcare)
    {
        nivelBaterie += nivelIncarcare;
    }

    void descarca(int);

protected:
    string producator;
private:
    string model;
    int nivelBaterie;
};

void TelefonMobil::descarca(int nivelDescarca)
{
    nivelBaterie -= nivelDescarca;
}

TelefonMobil incrementeazaNivelBaterie(TelefonMobil t) 
{
    t.setNivelBaterie(t.getNivelBaterie() + 1);
    return t;
}

int main()
{
    TelefonMobil telefonPersonal;
    
    //constructor alocat in heap
    TelefonMobil* pTelefon = new TelefonMobil();

    // dezalocare constructor
    delete pTelefon;
    pTelefon = nullptr;

    TelefonMobil telefonDeServiciu("Samsung", "S20");
    
    pTelefon = new TelefonMobil("Apple", "Iphone 14");

    delete pTelefon;
    pTelefon = nullptr;

    TelefonMobil telefon3(70);
    TelefonMobil telefon4 = 70; // putem apela si asa daca avem constructor cu un parametru


    // constructor de copiere
    TelefonMobil telefon5(telefon4);
    TelefonMobil telefon6 = telefon5;

  //  incrementeazaNivelBaterie(telefon6); // aici se apeleaza de 2 ori constructor de copiere

    cout << telefonDeServiciu.getProducator() << endl;

    cout << telefon3.getNivelBaterie() << endl;
    telefon3.setNivelBaterie(90);
    cout << telefon3.getNivelBaterie() << endl;

    telefon3.descarca(30);
    cout << telefon3.getNivelBaterie() << endl;

}
