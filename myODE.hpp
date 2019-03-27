#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

class myODE
 {
 		public:
  	 double n,x0,xn,h,y0,*x,*y;
  	 
  	 myODE();
  	 //~myODE();						
  	 double function(double x1,double y1);
  	 double y1(double x2);
  	 void display();
  	 double Euler_method(double x0,double xn,double h,double y0);
  	 double RK2_method(double x0,double xn,double h,double y0);
  	 double RK3_method(double x0,double xn,double h,double y0);
  	 double RK4_method(double x0,double xn,double h,double y0);
  	 double Nystrom_method(double x0,double xn,double h,double y0);
  	 double Heun_method(double x0,double xn,double h,double y0);
  	 double Kutta_method(double x0,double xn,double h,double y0);
  	 double Tclassical_method(double x0,double xn,double h,double y0);
  	 double Fclassical_method(double x0,double xn,double h,double y0);
  	 double AdamBashforth_method(double x0,double xn,double h,double y0);
  	 double NystromeMultistep_method(double x0,double xn,double h,double y0);
  	 double Adam_Moulten_method(double x0,double xn,double h,double y0);
  	 double Milnes_method(double x0,double xn,double h,double y0);
  	 double Predictor_corrector_method(double x0,double xn,double h,double y0);
     double Compare();
	};
