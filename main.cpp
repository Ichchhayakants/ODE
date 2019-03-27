#include<fstream>
#include<iostream>
//#include "myODE.hpp"
#include "ODE.cpp"
using namespace std;

int main()
 {
   double x0,xn,y0,h,n;
   int choice;
   cout<<"enter x0:\n";
   cin>>x0;
   cout<<"\nenter xn:\n";     //required for y(xn)
   cin>>xn;
   cout<<"enter the initial value y(0):\n";
   cin>>y0; //initial value
   cout<<"\nenter the value of h:\n";
   cin>>h;
   cout<<"\n enter your choice(method):\n";
   cout<<"\n1.Euler's method:\n";
   cout<<"\n2.RK 2 method:\n";
   cout<<"\n3.RK 3 method:\n";
   cout<<"\n4.RK 4 method:\n";
   cout<<"\n5.Nystrom method:\n";
   cout<<"\n6.Heun's method:\n";
   cout<<"\n7.Kutta method:\n";
   cout<<"\n8.Third order classical method:\n";
   cout<<"\n9.fourth order classical method:\n";
   cout<<"\n10.Adam-Bashforth method:\n";
   cout<<"\n11.NystromeMultistep_method:\n";
   cout<<"\n12.Adam-Moulten_method:\n";
   cout<<"\n13.Milnes_method:\n";
   cout<<"\n14.Predictor-corrector_method:\n";
   cout<<"\n15.Kutta method:\n";
   cin>>choice;
   myODE obj;
   switch(choice)
  	{
   		case 1:
  			obj.Euler_method(x0,xn,h,y0);
  			break;
  		case 2:
  			obj.RK2_method(x0,xn,h,y0);
  			break;
  		case 3:
  			obj.RK3_method(x0,xn,h,y0);
  			break;
  		case 4:
   			obj.RK4_method(x0,xn,h,y0);
   			break;
   		case 5:
   			obj.Nystrom_method(x0,xn,h,y0);
   			break;
   		case 6:
   			obj.Heun_method(x0,xn,h,y0);
   			break;
   		case 7:
   			obj.Kutta_method(x0,xn,h,y0);
   			break;		
   		case 8:
   			obj.Tclassical_method(x0,xn,h,y0);
   			break;
   		case 9:	
   			obj.Fclassical_method(x0,xn,h,y0);
   			break;
   		case 10:
   			obj.AdamBashforth_method(x0,xn,h,y0);
   			break;
   		case 11:
   			obj.NystromeMultistep_method(x0,xn,h,y0);
   			break;
   		case 12:
   			obj.Adam_Moulten_method(x0,xn,h,y0);
   			break;
   		case 13:	
   			obj.Milnes_method(x0,xn,h,y0);
   			break;
   		case 14:	
   			obj.Predictor_corrector_method(x0,xn,h,y0);
   			break;
   		default:
   		    obj.Compare();	
   	}
  
   return 0;
  	
 }
