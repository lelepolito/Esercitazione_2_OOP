#pragma once
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
