
#include <concepts>
#include <iostream>
#include <type_traits>

template<typename F>
concept FoD = std::is_floating_point_v<F>;
//concept FoD = std::is_same_v<F, float> || std::is_same_v<F, double>;
//Questo metodo fa in modo da creare un concetto che accetta solo float e double ,
//che esclude quindi long double rispetto a quello sopra.


template<typename F> requires FoD<F>
class c_num { 
private :
    F   p_r;
    F   p_i;
public :
    c_num(){
        p_r = 0 ;
        p_i = 0 ;
    }
    c_num(F r,F i){
        p_r = r ;
        p_i = i ;
    }
    c_num coniugate(){
        c_num out;
        out.p_r = p_r; 
        out.p_i = -p_i;
        return out;
    }
    F real(){
        return(p_r);
    }    
    F imm(){
        return(p_i);
    }
    c_num operator*(c_num const& num2){
        c_num out ;
        out.p_i = p_r * num2.p_i + num2.p_r * p_i;    
        out.p_r = p_r * num2.p_r - p_i * num2.p_i;
        return out;
    }
    c_num operator+(c_num const& num2){
        c_num out;
        out.p_i = p_i + num2.p_i;
        out.p_r = p_r + num2.p_r;
        return out;
    }
    c_num operator+=(c_num const& num2){
        p_i = p_i + num2.p_i;
        p_r = p_r + num2.p_r;
        return *this; 
    }
    c_num operator*=(c_num const& num2){
        F temp = p_i; 
        p_i = p_r * num2.p_i + num2.p_r * p_i;    
        p_r = p_r * num2.p_r - temp * num2.p_i;
        return *this;   
    }
    c_num operator+=(F num2){
        p_r = p_r + num2;
        return *this;
    }
    c_num operator+(F const& num2){
        c_num out;
        out.p_i = p_i;
        out.p_r = p_r + num2;
        return out;
    }
    c_num operator*(F const& num2){
        c_num out;
        out.p_i = p_i * num2;
        out.p_r = p_r * num2;
        return out;
    }




};

template<typename F> requires FoD<F>
std::ostream& operator<<(std::ostream& os,c_num<F>& num) {
    if (num.imm() < 0)
        os << num.real() << num.imm()<< "i";
    else if(num.imm() == 0)
        os << num.real();   
    else 
        os << num.real() << "+" << num.imm()<< "i";
    return os;
}

template<typename F> requires FoD<F>
c_num<F> operator+(F const& num2,c_num<F>& num1){
    F temp1 = num1.imm();
    F temp = num1.real();
    temp += num2;
    return c_num<F>(temp,temp1);
}

template<typename F> requires FoD<F>
c_num<F> operator*(F const& num2,c_num<F>& num1){
    F temp1 = num1.imm();
    F temp = num1.real();
    temp *= num2;
    temp1 *= num2;
    return c_num<F>(temp,temp1);
}



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
