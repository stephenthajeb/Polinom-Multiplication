class Polinom {
    private:
        int degree;
        int *koefs;
        static bool seed;
    public :
        Polinom ();
        Polinom (int,int);
        Polinom(const Polinom&);
        Polinom(const Polinom&,int,int);
        ~Polinom(); 
        void Print();
        Polinom& operator =(const Polinom&);
        friend Polinom operator +(const Polinom&,const Polinom&);
        friend Polinom operator - (const Polinom&,const Polinom &);
        friend Polinom operator * (const Polinom&,int n);
        friend Polinom BFMul(Polinom,Polinom);
        friend Polinom DnCMul(Polinom,Polinom,int);
};


