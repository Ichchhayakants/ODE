#include<iostream>
#include<fstream>
#include "myODE.hpp"
#include<math.h>
#define null 0
using namespace std;
double adam,milne,predic,heun;
 myODE::myODE()
  {
    y=null;
    y=new double[1000];
    x=null;
    x=new double[1000]; 
  }


double myODE::function(double x1,double y1)
 {
	return -y1;
 }
 
 double myODE::y1(double x2)
 {
   return exp(-x2);
 } 

 
 double myODE::Euler_method(double x0,double xn,double h,double y0)
  { 
  	cout<<"\n===============EULER'S method======================\n";
  	double e[1000];
  	int i=0;
  	double n;
  	ofstream fout("out.txt");
  	n=(xn-x0)/h;
  	y[0]=y0;
  	x[0]=x0;
  	e[0]=0;
  	double err;
  	//fout<<h<<"\t"<<e[0]<<"\n";
  	do
  	{
  	  while(x[i]<xn)
  	    {
  	      y[i+1]=y[i]+(h*function(x[i],y[i]));
	      x[i+1]=x[i]+h;
		e[i+1]=y1(x[i])-y[i]-h*function(x[i],y[i]);//e[i]+h*(function(x[i],y[i])-y1(x[i]));
	       cout<<"value of y at "<<x[i+1]<<" is "<<y[i+1]<<"\n";
		
		if(x[i+1]==xn)
		err=e[i+1];
	    i++;	
  	    }
  	   fout<<h<<"\t"<<err<<"\n";  
  	  x[i]=x0; 
  	  h=h+(.01);  
  	}while(h<=xn/2);    
  	
  	/*do{
  	
  	 for(i=0;i<n;i++)
  	{	
			y[i+1]=y[i]+(h*function(x[i],y[i]));
			x[i+1]=x[i]+h;
			e[i+1]=y1(x[i])-y[i]-h*function(x[i],y[i]);//e[i]+h*(function(x[i],y[i])-y1(x[i]));
			cout<<"value of y at "<<x[i+1]<<" is "<<y[i+1]<<"\n";
			if(i+1==n)
			err=e[i+1];
			
	}
    		fout<<h<<"\t"<<err<<"\n";	
 		h=h+(0.01);	
 		}while(h<=xn/2);*/
 } 


double myODE::RK2_method(double x0,double xn,double h,double y0)
	{
  	cout<<"\n=================RK2 Method=====================\n";
  	int i;
  	double n;
  	n=(xn-x0)/h;
  	y[0]=y0;
  	x[0]=x0;
  	float k1,k2;
  	for(i=0;i<n;i++)
  	 { 
  	   k1=h*function(x[i],y[i]);
  	   k2=h*function(x[i]+h,y[i]+k1);
  	   y[i+1]=y[i]+(k1+k2)/2;
  	   x[i+1]=x[i]+h;
  	   cout<<"value of y at "<<x[i]<<" is "<<y[i+1]<<"\n";
  	 } 		
	}

double myODE::RK3_method(double x0,double xn,double h,double y0)
	{
  	cout<<"\n=================RK3 Method(third order classical method)=====================\n";
  	int i;
  	double n;
  	n=(xn-x0)/h;
  	y[0]=y0;
  	x[0]=x0;
  	float k1,k2,k3,kp;
  	for(i=0;i<n;i++)
  	 { 
  	   k1=h*function(x[i],y[i]);
  	   k2=h*function(x[i]+(h/2),y[i]+(k1/2));
  	   kp=h*function(x[i]+h,y[i]+k1);
  	   k3=h*function(x[i]+h,y[i]+kp);
  	   y[i+1]=y[i]+(k1+4*k2+k3)/6;
  	   x[i+1]=x[i]+h;
  	   cout<<"value of y at "<<x[i]<<" is "<<y[i+1]<<"\n";
    } 		
	}

double myODE::RK4_method(double x0,double xn,double h,double y0)
	{
	  cout<<"\n=====================RK4 Method (fourth order classical)===================\n";
	  int i;
	  int n;
	  y[0]=y0;
	  x[0]=x0;
	  n=(xn-x0)/h;
	  float k1,k2,k3,k4;
	  for(i=0;i<n;i++)
	   { 
	     k1=h*function(x[i],y[i]);
	     k2=h*function(x[i]+(h/2),y[i]+(k1/2));
	     k3=h*function(x[i]+(h/2),y[i]+(k2/2));
	     k4=h*function(x[i]+h,y[i]+k3);
     	y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
     	x[i+1]=x[i]+h;
     	cout<<"\nvalue of y at "<<x[i+1]<<" is "<<y[i+1]<<"\n";
     } 	
	
	}

double myODE::Nystrom_method(double x0,double xn,double h,double y0)
  {
    cout<<"\n=====================Nystrom method=======================\n";
    int i;
    double n;
    n=(xn-x0)/h;
  	y[0]=y0;
  	x[0]=x0;
  	float k1,k2,k3;
  	for(i=0;i<n;i++)
   	{ 
      k1=h*function(x[i],y[i]);
      k2=h*function(x[i]+(h*2/3),y[i]+(k1*2/3));
      k3=h*function(x[i]+(h*2/3),y[i]+(k2*2/3));
      y[i+1]=y[i]+(2*k1+3*k2+3*k3)/8;
      x[i+1]=x[i]+h;
      cout<<"value of y at "<<x[i]<<" is "<<y[i+1]<<"\n";
    } 		
      	
  }

double myODE::Heun_method(double x0,double xn,double h,double y0)
	{
  	cout<<"\n=======================Heun method=======================\n";
  	double n;
  	n=(xn-x0)/h;
  	y[0]=y0;
  	x[0]=x0;
  	int i;
  	double yp[20]={0};
  	for(i=0;i<n;i++)
  	 { 
  	 	x[i+1]=x[i]+h;
   		yp[i+1]=y[i]+h*function(x[i],y[i]);
   		y[i+1]=y[i]+h*(function(x[i],y[i])+function(x[i+1],yp[i+1]))/2;  	
   		cout<<"predicted value of y at "<<x[i]<<" is "<<yp[i+1]<<"\n";
   		cout<<"corrector value of y at "<<x[i]<<" is "<<y[i+1]<<"\n";
   		cout<<"\n\n";
  	 }
  	heun=y[i+1]; 
 	}

double myODE::Kutta_method(double x0,double xn,double h,double y0)
	{
	  cout<<"\n=====================Kutta method===================\n";
	  int i;
	  double n;
	  n=(xn-x0)/h;
	  y[0]=y0;
	  x[0]=x0;
	  float k1,k2,k3,k4;
	  for(i=0;i<n;i++)
	   { 
	     k1=h*function(x[i],y[i]);
	     k2=h*function(x[i]+(h/3),y[i]+(k1/3));
	     k3=h*function(x[i]+(h*2/3),y[i]-(k1/3)+(k2));
	     k4=h*function(x[i]+h,y[i]+k1-k2+k3);
	     y[i+1]=y[i]+(k1+3*k2+3*k3+k4)/8; 
	     x[i+1]=x[i]+h;
	     cout<<"value of y at "<<x[i+1]<<" is "<<y[i+1]<<"\n";
	   } 
 	} 
/*============================================Third order classical method===============================*/
double myODE::Tclassical_method(double x0,double xn,double h,double y0)
{
  	
}

/*==========================================Fouth order classical method==================================*/
double myODE::Fclassical_method(double x0,double xn,double h,double y0)
{
	
}

/*=========================================Adam-Bashforth method===========================================*/
double myODE::AdamBashforth_method(double x0,double xn,double h,double y0)
	{
  	double yp[20]={0};
  	int i;
  	double n;
  	n=(xn-x0)/h;
  	x[0]=x0;
  	y[0]=y0;
  	RK4_method(x[0],x[0]+3*h,h,y[0]);
  	cout<<"\n---------------predictor-corrector-----------------------------\n";
  	for(i=3;i<n;i++)
  		{
    		yp[i+1]=y[i]+h*(55*function(x[i],y[i])-59*function(x[i-1],y[i-1])+37*function(x[i-2],y[i-2])-9*function(x[i-3],y[i-3]))/24;
    	  y[i+1] =y[i]+h*(9*function(x[i+1],yp[i+1])+19*function(x[i],y[i])-5*function(x[i-1],y[i-1])+function(x[i-2],y[i-2]))/24;
    	  x[i+1]=x[i]+h;
    	  cout<<"predicted value of y at "<<x[i+1]<<" is "<<yp[i+1]<<"\n";
    	  cout<<"corrector value of y at "<<x[i+1]<<" is "<<y[i+1]<<"\n";
    	  cout<<"\n\n";
  		}
  	adam=y[i+1];	
	}

/*=========================================Nystrom multistep method===================================*/
double myODE::NystromeMultistep_method(double x0,double xn,double h,double y0)
	{
	
	}

/*=======================================Adam-Moulten method==============================================*/
double myODE::Adam_Moulten_method(double x0,double xn,double h,double y0)
	{
	
	
	}

double myODE::Milnes_method(double x0,double xn,double h,double y0)
	{
		 cout<<"\n==================Milne's Predictor corrector method==================\n";
 		 double yp[20]={0};
	 	 int i;
 	   double n;
  	 n=(xn-x0)/h;
  	 x[0]=x0;
  	 y[0]=y0;
   	 RK4_method(x[0],x[0]+3*h,h,y[0]);
     cout<<"\n---------------predictor-corrector-----------------------------------------------------------\n";
  	 for(i=3;i<n;i++)
      {
    	  yp[i+1]=y[i-3]+4*h*(2*function(x[i-2],y[i-2])-function(x[i-1],y[i-1])+2*function(x[i],y[i]))/3;
    	  y[i+1] =y[i-1]+h*(function(x[i-1],y[i-1])+4*function(x[i],y[i])+function(x[i+1],yp[i+1]))/3;
    	  x[i+1]=x[i]+h;
    	  cout<<"\npredicted value of y at "<<x[i+1]<<" is "<<yp[i+1]<<"\n";
    	  cout<<"corrector value of y at "<<x[i+1]<<" is "<<y[i+1]<<"\n";
    	  cout<<"\n\n";	
      }
   milne=y[i+1];
  }

double myODE::Predictor_corrector_method(double x0,double xn,double h,double y0)
	{
  	cout<<"\n=================predictor corrector method(The Hamming method)=================\n";
  	double yp[20]={0};
  	int i;
  	double n;
  	n=(xn-x0)/h;
  	x[0]=x0;
  	y[0]=y0;
  	RK4_method(x[0],x[0]+3*h,h,y[0]);
  	cout<<"\n---------------predictor-corrector-----------------------------------------------------------\n";
  	for(i=3;i<n;i++)
  		{
   	    yp[i+1]=y[i-3]+4*h*(2*function(x[i-2],y[i-2])-function(x[i-1],y[i-1])+2*function(x[i],y[i]))/3;
    	  y[i+1] =((-y[i-2]+9*y[i])/8)+3*h*(-function(x[i-1],y[i-1])+2*function(x[i],y[i])+function(x[i+1],yp[i+1]))/8;
      	x[i+1]=x[i]+h;
      	cout<<"\npredicted value of y at "<<x[i+1]<<" is "<<yp[i+1]<<"\n";
      	cout<<"corrector value of y at "<<x[i+1]<<" is "<<y[i+1]<<"\n";
      	cout<<"\n\n";	
      }
     predic=y[i+1]; 	
   }
double myODE::Compare()
 {
  cout<<"\nAdam-Bashforth="<<adam;
  cout<<"\nMilne's method="<<milne;
  cout<<"\nPredictor-corrector="<<predic;
 }
