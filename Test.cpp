#include "solver.hpp"
#include "doctest.h"
using namespace solver;
using namespace std;
TEST_CASE("Real"){
    RealVariable x;
        CHECK(solve(x==0)==0);
    SUBCASE("+"){
        CHECK(solve(x+1==0)==-1);
        CHECK(solve(1+x==0)==-1);
        CHECK(solve(x+0.6==0)==-0.6);
        CHECK(solve(x+x==0)==0);
        CHECK(solve(x+0==1)==1);


    }
    SUBCASE("-"){
        CHECK(solve(x-1==0)==1);
        CHECK(solve(1-x==0)==1);
        CHECK(solve(x-0.6==0)==0.6);
        CHECK(solve(x-2==1)==3);
        CHECK(solve(x+x-2==1+x)==-3); 
    }
    SUBCASE("*"){
        CHECK(solve(x-x*0==1)==1);
        CHECK(solve(2*x==0)==0);
        CHECK(solve(x*2==0)==0);
        CHECK(solve(x*0.5==0.5)==1);
        CHECK(solve(x*x==0)==0);
        CHECK(solve(x*(-2)+x==1)==-1);
    }
    SUBCASE("/"){
        CHECK(solve(2*x/2==1)==1);
        CHECK(solve(x*2==2)==1);
        CHECK(solve(x==x*3+8)==-4);
        CHECK(solve((2+2*x)/2==1)==0);
        CHECK(solve((x*2+2)/2==1)==0);

    }
    SUBCASE("^"){
        CHECK((solve((x^2)==1)==1||solve((x^2)==1)==-1));
        CHECK((solve((x^2)==4)==2||solve((x^2)==4)==-2));
        CHECK(solve(((2*x)^2)+x==4*(x^2)+1)==1);
        CHECK(solve((((1+x)^2)==(x^2)+2*x)+x)==1);
        CHECK(solve((((1-x)^2)==(x^2)-2*x)+x)==1);
        CHECK(solve((x^1)==4)==4);
        CHECK(solve((x^0)+x==0)==-1);
        
    }
    SUBCASE("all"){
        CHECK(solve(x+x+x==3)==1);
        CHECK(solve(x-x==x)==0);
        CHECK(solve(x-x-x==3)==-3);
        CHECK(solve(((-1*x)^2)-(x^2)+x==4)==4);
        CHECK(solve(3*(x-1)==x+x)==3);
        CHECK(solve(x+x+x+x==3*x+1)==1);
        CHECK(solve(x*3-2*x==1)==1);
        CHECK(solve(3*x/(4-1)+x==2)==1);
        CHECK(solve(3*x/3-1+x==1)==1);
        CHECK(solve(x*0.5-x/2+x==1)==1);
        CHECK(solve(2*x*(1-0.5)==1)==1);
        CHECK((solve(((2*x*(1-0.5)+1)^2)==2*x)==-1||solve(((2*x*(1-0.5)+1)^2)==2*x)==1));

    }
    SUBCASE("err"){
        CHECK_THROWS(solve(x==x));
        CHECK_THROWS(solve(x-1==x));
        CHECK_THROWS(solve(x/0==x));
        CHECK_THROWS(solve((x^2)==-1));
    }

}
TEST_CASE("Complex"){
    ComplexVariable c;
    CHECK(solve(c==0)==complex<double>(0));
    SUBCASE("+"){
        CHECK(solve(c+1i==0)== -1i);
        CHECK(solve(1i+c==0)== -1i);
        CHECK(solve(c+1==0)== complex<double>(-1));
        CHECK(solve(c+0.6i==0)==0.6i);
        CHECK(solve(c+c==0)==complex<double>(0));
        CHECK(solve(c+0==1i)==1i);
    }
    SUBCASE("-"){
        CHECK(solve(c-1i==0)==1i);
        CHECK(solve(1i-c==0)==1i);
        CHECK(solve(c-0.6i==0)==0.6i);
        CHECK(solve(c-0.6==0)==complex<double>(0.6));
        CHECK(solve(c-2i==1i)==3i);
        CHECK(solve(c+c-2i==1+c)==complex<double>(1,2));
        CHECK(solve(c+c-2==1i+c)==complex<double>(2,1));
    }
    SUBCASE("*"){
        CHECK(solve(c-c*0==1i)==1i);
        CHECK(solve(2i*c==0)==complex<double>(0));
        CHECK(solve(c*2==0)==complex<double>(1));
        CHECK(solve(c*0.5==0.5i)==1i);
        CHECK(solve(c*c==0)==complex<double>(0));
        CHECK(solve(c*(-2i)+c==1)==complex<double>(0.2,0.4));
    }

    SUBCASE("/"){
        CHECK(solve(2*c/2i==1)==1i);
        CHECK(solve(c*2i==2)==complex<double>(2,2));
        CHECK(solve(c==c*3i+3i-1)==complex<double>(-1));
        CHECK(solve((2+2i*c)/2i==1)==complex<double>(0));
        CHECK(solve((c*2+2)/2i==1)==complex<double>(-1,-1));

    }
    
    SUBCASE("^"){
        CHECK(solve((c^2)==-1)==1i);
        CHECK(solve((c^2)==-4)==2i);
        CHECK(solve(((2i*c)^2)+c==-4*(c^2)+1)==complex<double>(1));
        CHECK(solve((((1i+c)^2)==(c^2)+2i*c)-c)==complex<double>(1));
        CHECK(solve((((c-1i)^2)==(c^2)-2i*c)+c)==complex<double>(1));
        CHECK(solve((c^(-1i*1i))==4i)==4i);
        CHECK(solve(((c*1i)^0i)-c==0)==complex<double>(1));

        
    }
    SUBCASE("all"){
        CHECK(solve(c+c+c==3i)==1i);
        CHECK(solve(c-c-c==3i)==-3i);
        CHECK(solve(((-1i*c)^2)-(c^2)==2i*c+1i-c*(2i+(c*0+1)))==1i);
        CHECK(solve(3i*(c-1)==c)==complex<double>(0.9,0.3));
        CHECK(solve(c+c+c+c==4i*c+8)==complex<double>(1,1));
        CHECK(solve(c*3i+2i*c==-1)==1i);
        CHECK(solve(3*c/3-1i+c==1)==1i);
        CHECK(solve(3*c/(4i-1i)+c==2)==complex<double>(1,-1));
        CHECK(solve(3i*c/3i-1+c==1)==complex<double>(1));
        CHECK(solve(c*0.5i-c/2i+c*1i==1)==-1i);
        CHECK(solve(-2*c*(0.5i-0.5)==1)==complex<double>(0.5,0.5));
        CHECK(solve(((2i*c*(1-0.5)+1i)^2)==-2*c)==-1i);
    }
    SUBCASE("err"){
        CHECK_THROWS(solve(c==c));
        CHECK_THROWS(solve(c*1i-1==1i*c));
        CHECK_THROWS(solve(c/0i==c));
    }
}