#include <iostream>
#include <complex>

namespace solver{
    class RealVariable{
        double var;
        double constant;
        public:
            RealVariable():var(1),constant(0){}
            RealVariable(double d):var(0),constant(d){}
            RealVariable operator+(RealVariable real){
                return *this; 
            }
            RealVariable operator-(RealVariable real){
                return *this;
            }
            RealVariable operator*(RealVariable real){
                return *this;      
            }
            RealVariable operator/(RealVariable real){
                return *this;     
            }
            RealVariable operator^(RealVariable real){
                return *this;     
            }
            RealVariable operator==(RealVariable real){
                return *this-real;      
            }
           
            friend RealVariable operator * (double d,RealVariable real){
                return real*d;
            }
            friend RealVariable operator + (double d,RealVariable real){
                return real*d;
            }
            friend RealVariable operator - (double d,RealVariable real){
                return real*d;
            }
            friend double solve(RealVariable exp);
            
            
           
        
    };
    class ComplexVariable{
        double var;
        std::complex<double>  im;
        public:
            ComplexVariable():var(1),im(0){}
            ComplexVariable(double d):var(0),im(d){}
            ComplexVariable(std::complex<double> c):var(0),im(c){}

            ComplexVariable operator+(ComplexVariable comp){
                return *this;
            }
            ComplexVariable operator-(ComplexVariable comp){
                return *this;
            }
            ComplexVariable operator*(ComplexVariable comp){
                return *this;    
            }
            ComplexVariable operator/(ComplexVariable comp){
                return *this;    
            }
            ComplexVariable operator^(ComplexVariable comp){
                return *this;    
            }
            ComplexVariable operator==(ComplexVariable comp){
                return *this-comp;      
            }
            friend ComplexVariable operator * (std::complex<double> c,ComplexVariable comp){
                return comp*c;
            }
            friend ComplexVariable operator + (std::complex<double> c,ComplexVariable comp){
                return comp*c;
            }
            friend ComplexVariable operator - (std::complex<double> c,ComplexVariable comp){
                return comp*c;
            }
            friend std::complex<double> solve(ComplexVariable exp);
            

        

    };

    double solve(RealVariable exp);
    std::complex<double> solve(ComplexVariable exp);

    
    


}