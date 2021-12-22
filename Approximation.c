#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//régression lineaire
void lineair_regression(double x[], double y[], int n, double *a, double *b)
{
  int i; 
  double xsomme, ysomme, xysomme, xxsomme;
  double ai,bi;
  xsomme = 0.0; ysomme = 0.0;
  xysomme = 0.0; xxsomme = 0.0;
  for (i=0;i<n;i++)
  {
     xsomme = xsomme + x[i]; 
     ysomme = ysomme + y[i];
     xysomme = xysomme + x[i]*y[i];
     xxsomme = xxsomme + x[i]*x[i];
  }
  ai = (n*xysomme - xsomme*ysomme)/(n*xxsomme - xsomme*xsomme);
  bi = (ysomme - ai*xsomme)/n;
  *a = ai;
  *b = bi;
}

void ln(double y[], int n)
{
  int i;
  for (i=0; i<n; i++)
  {
    y[i]=log(y[i]);
  }
}

//régression exponentielle 
void ln_de_y(double x[], double y[], int n, double *a, double *b)
{
  ln(y,n);
  lineair_regression(x,y,n,a,b);
}

//régression puissance
void ln_de_xy(double x[], double y[], int n, double *a, double *b)
{
  ln(x,n);
  ln(y,n);
  lineair_regression(x,y,n,a,b);
}

// fonction auxilliare 
void avant1bvaut2(double*a, double*b)
{
  (*a)=1;
  (*b)=2;
}

int main()
{
  double a1, b1,a2_1,b2_1,a2_2,b2_2,a2_3,b2_3,a4,b4,a5,b5,c4,d4,c5,d5;
  // jeux d'essai 1
  double X1[11]= {10.0, 8.0,  13.0, 9.0,  11.0, 14.0, 6.0,  4.0,  12.0,  7.0,  5.0};
  double Y1[11]= {8.04, 6.95, 7.58, 8.81, 8.33, 9.96, 7.24, 4.26, 10.84, 4.82, 5.68};
  int n1= 11;

  //jeux d'essai 2
  double X2_1[11]={10.0, 8.0 ,  13.0, 9.0  ,  11.0, 14.0, 6.0,  4.0,  12.0,  7.0,  5.0};
  double Y2_1[11]={9.14, 8.14, 8.74, 8.77 , 9.26, 8.1, 6.13, 3.1, 9.13, 7.26, 4.74};
  double X2_2[11]={10.0, 8.0 ,  13.0, 9.0  ,  11.0, 14.0, 6.0,  4.0,  12.0,  7.0,  5.0};
  double Y2_2[11]={7.46, 6.77, 12.74, 7.11, 7.81, 8.84, 6.08, 5.39, 8.15, 6.42, 5.73};
  double X2_3[11]={8.0, 8.0 ,  8.0, 8.0  ,  8.0, 8.0, 8.0,  19.0,  8.0,  8.0,  8.0};
  double Y2_3[11]={6.58, 5.76, 7.71, 8.84, 8.47, 7.04, 5.25, 12.5, 5.56, 7.91, 6.89};
  int n2=11;
  
  // jeux d'essai 4
  double X4[10]={88,89,90,91,92,93,94,95,96,97 };
  double Y4[10]={5.89, 6.77, 7.87,9.11,10.56,12.27,13.92,15.72,17.91,22.13};
  int n4=10;

  //jeu d'essai 5
  double X5[7]={20,30,40,50,100,300,500};
  double Y5[7]={352,128,62.3,35.7,6.3,0.4,0.1};
  int n5=7;

  avant1bvaut2(&a1, &b1);
  avant1bvaut2(&a2_1, &b2_1);
  avant1bvaut2(&a2_2, &b2_2);
  avant1bvaut2(&a2_3, &b2_3);
  avant1bvaut2(&a4, &b4);
  avant1bvaut2(&a5, &b5);

  //régression linéaire 1
  lineair_regression(X1,Y1,n1,&a1,&b1);
  printf("a1 = %.4lf\n", a1);
  printf("b1 = %.4lf\n", b1);

  //régression linéaire 2
  lineair_regression(X2_1,Y2_1, n2, &a2_1, &b2_1 );
  lineair_regression(X2_2,Y2_2, n2, &a2_2, &b2_2 );
  lineair_regression(X2_3,Y2_3, n2, &a2_3, &b2_3 );
  printf("a2_1 = %.4lf\n", a2_1);
  printf("b2_1 = %.4lf\n", b2_1);
  printf("a2_2 = %.4lf\n", a2_2);
  printf("b2_2 = %.4lf\n", b2_2);
  printf("a2_3 = %.4lf\n", a2_3);
  printf("b2_3 = %.4lf\n", b2_3);

  //régression exponentielle
  ln_de_y(X4,Y4,n4,&a4,&b4);
  c4=a4;
  d4=b4;
  printf("c4 = %.4lf\n", c4);
  printf("d4 = %.4lf\n", d4);

  //régression puissance
  ln_de_xy(X5,Y5,n5,&a5,&b5);
  d5 = a5;
  c5 = exp(b5);
  printf("c5 = %.4lf\n", c5);
  printf("d5 = %.4lf\n", d5);

}

