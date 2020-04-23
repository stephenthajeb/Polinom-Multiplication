#include <bits/stdc++.h> 
#include "Polinom.hpp"

//GLobal Variable
int opMulDnC = 0;
int opSumDnC = 0;

Polinom DnCMul(Polinom A,Polinom B,int n){
    if (A.degree != n){ //Penanganan kasus untuk kasus degree A dan B berbeda saat rekursif
        n=A.degree;
    }
    int divdeg = n/2;

    if (n==0){
        Polinom C(0,0);
        C.koefs[0] = A.koefs[0]*B.koefs[0];
        opMulDnC +=1;
        return C;
    }else if (n == 1){
        Polinom C(2,0);
        C.koefs[0] = A.koefs[0]*B.koefs[0];
        C.koefs[1] = A.koefs[0]*B.koefs[1] + A.koefs[1]*B.koefs[0];
        C.koefs[2] = A.koefs[1]*B.koefs[1];
        opMulDnC +=4;
        opSumDnC +=1;
        return C;
    }else{
        Polinom A0(A,0,divdeg-1);
        Polinom A1(A,divdeg,n);
        Polinom B0(B,0,divdeg-1);
        Polinom B1(B,divdeg,n);     
        Polinom Y = DnCMul((A0+A1),(B0+B1),divdeg);
        opSumDnC += 2*(divdeg+1);
        Polinom U = DnCMul(A0,B0,divdeg);
        Polinom Z = DnCMul(A1,B1,divdeg);
        
        opSumDnC += 4*(divdeg+1);//Perhitungan operator untuk operasi yang digunakaan saat return di baris bawah;
        return (U+((Y-U-Z)*divdeg)+(Z*(divdeg*2)));
    }
}




