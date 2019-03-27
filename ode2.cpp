#include<iostream>
#include<math.h>
#include<fstream>
#include<iomanip>
using namespace std;
double f1(double x,double y)
{
  
  return (x-y)/2;
}

/*double function2(double x,double y)
{
 return 2*(pow(x,2));
}*/

double f2(double x,double y)
{
  return (2-x+y)/4;
}

double f3(double x,double y)
{
  return (-2+x-y)/8;
}

double f4(double x,double y)
{
  return (2-x+y)/16;
} 

double exact(double x)
{
  return 3*exp(-x/2)-2+x;
}

int main()
{
 int i,n;
 double e[100],y[100],x[100],x0,y0,xn,h,err;//,e1[100],y2[100],x2[100],e3[100],y3[100],x3[100]x0,y0;
 cout<<"enter the value of x0 and y0,xn:\n";
 cin>>x0>>y0>>xn;
 ofstream fout("out.txt");
 fout<<"#h\t#error\n";
do{
 i=0;
 x[0]=x0;
 y[0]=y0;
 e[0]=0;
 cout<<"enter h:\n";
 cin>>h;
  cout<<"h\tx\ty\n";
 cout<<h<<"\t"<<x[i]<<"\t"<<y[i]<<"\n";
  while(x[i]<xn)
  	    	{
  	      y[i+1]=y[i]+(h*f1(x[i],y[i]))+(pow(h,2)/2)*(f2(x[i],y[i]))+(pow(h,3)/6)*(f3(x[i],y[i]))+(pow(h,4)/24)*(f4(x[i],y[i]));
	      	x[i+1]=x[i]+h;
					e[i+1]=abs(exact(y[i+1])-y[i+1]);
	       	cout<<h<<"\t"<<x[i+1]<<"\t"<<setprecision(8)<<y[i+1]<<"\n";
	        //fout<<x<<"\t"<<y1(x[i+1])<<"\n";
						if(x[i+1]==xn)
						err=e[i+1];
	    			
	    			i++;	
  	    	}
  	 fout<<h<<"\t"<<err<<"\n";   	
  }while(h<1);	    	

 }
