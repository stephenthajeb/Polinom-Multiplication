#include <bits/stdc++.h> 
#include "DnC.hpp"

//Global variable
int opMulBF  = 0;
int opSumBF  = 0;

 Polinom BFMul(Polinom P1,Polinom P2){
     Polinom P3(P1.degree+P2.degree,0);
     for (int i=0;i<=P1.degree;i++){
         for(int j=0;j<=P2.degree;j++){
            P3.koefs[i+j] += P1.koefs[i] * P2.koefs[j];
            opMulBF  +=1;
            opSumBF  +=1;
         }
     }
     return P3;
 }

