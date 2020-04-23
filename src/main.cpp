#include <bits/stdc++.h> 
#include "BF.hpp"

 
using namespace std;

int main (){
    int degree;
    clock_t start,end;
    double cpu_time_used;
    cout <<"Masukkan derajat Polinomial : ";
    cin >> degree;

    Polinom a(degree,1);
    Polinom b(degree,1);
    Polinom c(2*degree,0);
    Polinom d(2*degree,0);
    printf("Polinomial 1 :\n");
    a.Print();
    printf("Polinomial 2 :\n");
    b.Print();
    printf("\n");

    start = clock();
    c = BFMul(a,b);
    end=clock();
    printf("Brute Forces Multiplication :\n");
    c.Print();
    printf("Jumlah operasi penjumlahan yang digunakan: %d\n",opSumBF);
    printf("Jumlah operasi perkalian yang digunakan: %d\n",opMulBF);
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC)*1000000;
    printf("Run time : %.5f microseconds\n", cpu_time_used); 
 

    start = clock();
    d = DnCMul(a,b,degree);
    end=clock();
    printf("\nDivide And Conquer Multiplication :\n");
    d.Print();
    printf("Jumlah operasi penjumlahan yang digunakan : %d\n",opSumDnC);
    printf("Jumlah operasi perkalian yang digunakan: %d\n",opMulDnC);
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC)*1000000;
    printf("Run time : %.5f microseconds\n", cpu_time_used); 


    printf("===========================================================================================\n");
    return 0;
}





