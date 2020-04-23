#include <bits/stdc++.h> 
#include "Polinom.hpp"
using namespace std;

bool Polinom :: seed = false;

Polinom :: ~Polinom(){
    delete koefs;
}

Polinom operator + (const Polinom &P1,const Polinom &P2){
    if (P1.degree >= P2.degree){
        Polinom Pout(P1.degree,0);
        Pout = P1;
        for (int i=0;i<=P2.degree;i++){
            Pout.koefs[i] += P2.koefs[i];
        }
        return Pout;
    } else {
        Polinom Pout(P2.degree,0);
        Pout = P2;
        for (int i=0;i<=P1.degree;i++){
            Pout.koefs[i] += P1.koefs[i];
        }
        return Pout;
    }
}

Polinom operator - (const Polinom &P1,const Polinom &P2){
    if (P1.degree >= P2.degree){
        Polinom Pout(P1.degree,0);
        Pout = P1;
        for (int i=0;i<=P2.degree;i++){
            Pout.koefs[i] -= P2.koefs[i];
        }
        return Pout;
    } else {
        Polinom Pout(P2.degree,0);
        Pout = P2;
        for (int i=0;i<=P1.degree;i++){
            Pout.koefs[i] -= P1.koefs[i];
        }
        return Pout;
    }
}

Polinom operator * (const Polinom& P1,int n){
    Polinom Pout(P1.degree + n,0);
    
    for (int i=0;i<=P1.degree;i++){
        if (n>0){
            Pout.koefs[i+n] = P1.koefs[i];
        }else{
            Pout.koefs[i] = P1.koefs[i+n];
        }    
    }
    return Pout;
}

Polinom& Polinom::operator = (const Polinom& Pin){ 
    this->koefs = new int [Pin.degree+1];
    this->degree = Pin.degree;
    for (int i=0;i<=Pin.degree;i++){        
        this->koefs[i] = Pin.koefs[i];
    }
    return *this;
}

Polinom :: Polinom(){
    this->degree = 0;
    this->koefs = nullptr;
}

Polinom::Polinom(const Polinom& Pin){
	this->degree = Pin.degree;
    this->koefs = new int [this->degree+1];
    for(int i=0;i<=Pin.degree;i++){
        this->koefs[i] = Pin.koefs[i];
    }
}


void Polinom :: Print(){
if (this->degree != 0){
    cout << this->koefs[0];
}
    for(int i=1;i<this->degree;i++){
        if (koefs[i] != 0){
            if (koefs[i] > 0){
                cout << " + ";
                cout << this->koefs[i] << "x" <<"^"<< i;
            } else {
                cout<<" ";
                cout << this->koefs[i] << "x" <<"^"<< i;
            }
        }
    }
    if (koefs[degree]!= 0){
        if (koefs[degree] > 0 ){
            cout << " + ";
            cout << koefs[degree] << "x" <<"^"<< degree << endl;
        } else {
            cout << koefs[degree] << "x" <<"^"<< degree << endl;
        }
    } else {
        cout <<endl;
    } 
}

Polinom::Polinom(const Polinom& Pin,int startDeg,int endDeg){
	this->degree = endDeg-startDeg;
    this->koefs = new int [this->degree+1];
    for(int i=0;i<=this->degree;i++){
        this->koefs[i] = Pin.koefs[i+startDeg];
    }
}


Polinom:: Polinom(int degree,int kode){//Konstruktor sesuai instruksi kode yang diinput. Default 1 ,kode==0 inisialisasi dengan 0, kode ==1 generate random numbers , kode == 9 array diisi inputan user
    this -> degree = degree;
    this -> koefs = new int [degree+1];
    if (kode == 0){
        for (int i=0;i<=degree;i++){
            this->koefs[i] = 0;
        }
    } else if (kode==9){
        int temp;
        for (int i=0;i<=degree;i++){        
            cin >> temp ;
            this -> koefs[i] = temp;
        }
    } 
    if (kode==1){
        for (int i=0;i<=degree;i++){
            if (!seed){
                srand(time(NULL));
                seed = true;
            }
            this->koefs[i] = rand()-rand();
        }
    }
}
