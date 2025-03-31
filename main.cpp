
#include "complex.hpp"



int main(){
    std::cout << "Alcuni test per provare il codice " << std::endl;
    c_num<float> f(1,-1);
    c_num<float> f2(2,2);
    c_num<float> f3 = f + f2;
    c_num<double> f5(3,-3);
    c_num<float> f9;
    c_num<float> f6= f.coniugate();
    c_num<float> f4 = f * f2;
    c_num<double> f10 = double(5.0) * f5;
    c_num<float> f11 = f * 50.0f;
    c_num<float> f12 = 50.0f + f;
    float f8= f.imm();
    float f7= f.real();
    std::cout << " Double 3,3  "<<f5 << std::endl;
    std::cout << " Somma con + fra complex 1,1 + 2,2  "<<f3 << std::endl;
    std::cout << "Moltpicazione con * fra complex 1,1 * 2,2  "<<f4 << std::endl;
    std::cout << "Float  1,-1 "<<f << std::endl; 
    std::cout << "Coniugato 1,-1  "<<f6 << std::endl;
    std::cout << "Reale 1,-1 "<<f7 << std::endl;
    f9 = f + 5.0f;
    std::cout << "Somma con  +  con un float prima 50 + 1,-1 "<<f12<< std::endl;    
    std::cout << "Somma con  +  con un float dopo 1,-1 + 5 "<<f9 << std::endl;  
 

    std::cout << "Immaginaria 1,-1 "<< f8 << std::endl;
    std::cout << "Moltiplicazione con * con un Double prima 5* 3,-3  "<<f10 << std::endl;
    std::cout << "Moltiplicazione con * con un float dopo 50* 1,-1  "<<f11 << std::endl;

    f += f2;
    std::cout <<"Somma con += 1,-1 + 2,2 " << f << std::endl;
    f *= f2;
    std::cout <<"Moltiplicazione con *= 3,1 * 2,2  "<< f << std::endl;
    return 0;
};
