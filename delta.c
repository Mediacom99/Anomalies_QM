#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "integrationS.h"


const long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647;
const long double PHI = -0.244058298905427762659753987235745798131278180478499954070; //DIPENDE DA G: arg(Gamma(1+ig))
const long double gamma = 1.7810724179901979852365041031071795491696452143034302053576658765; //exp(cost eulero-masch)

long double F1(long double t, long double x, long double g)
{
	return cosl(x*sinl(t))*coshl(g*t);
}

long double F2(long double t,long double x,long double g)
{
	return expl(-x*sinhl(t))*sinl(g*t)*expl(t); //l'ultimo *exp(t) serve per integrazione laguerre 
}

long double  G1(long double t,long double x,long double g)
{
	return sinl(x*sinl(t))*sinhl(g*t);
}

long double G2(long double t,long double x,long double g)
{
	return expl(-x*sinhl(t))*cosl(g*t)*expl(t); //l'ultimo *exp(t) serve per integrazione laguerre
}

long double  F(long double x,long double g)
{

	long double res1 = Legendre(0,PI,F1,x,g);
	long double res2 = Laguerre(0,F2,x,g);
	return (1.0/PI)*(1.0/coshl(g*PI / 2.0))*res1 - (2.0/PI) * sinhl(g*PI/2.0)*res2;
}


long double G(long double x, long double g)
{

	long double ges1 = Legendre(0,PI,G1,x,g);
	long double ges2 = Laguerre(0,G2,x,g);
	return (1.0/PI)*(1.0/sinhl(g*PI / 2.0))*ges1 - 2.0/PI * coshl(g*PI/2.0)*ges2;
}

long double delta(long double x, long double g)
{	
	long double var = G(x,g) / F(x,g);
	long double result = -atanl(var)- PI/4.0;
	//printf("A/B = %.30Lf, atanl = %.30Lf, G = %.30Lf, F = %.30Lf\n", var, atanl(var), G(x,g), F(x,g));
	return result;
}

//Espansioni F, G per x -> 0 e g > 0 (strettamente) [dunster]

long double F_small(long double x, long double g)
{
	long double result = 

		sqrtl(2*tanhl(g*PI / 2.0) / g*PI)*(cosl(g*logl(x / 2.0) - PHI));

	return result;
}

long double G_small(long double x, long double g)
{
	long double result = 

		sqrtl(2*(1.0 / tanhl(g*PI / 2.0)) / g*PI)*(sinl(g*logl(x / 2.0) - PHI));

	return result;
}

long double delta_xsmall(long double x, long double g)
{	
	long double var = G_small(x,g) / F_small(x,g);
	long double result1 = -atanl(var) - PI/4.0;
	//printf("%.30LF,%.30LF\n",var,result1);
	return result1;
}

//Formula 38 del griffith

long double deltaG(long double x, long double g)
{	
	long double csi = g*logl(x / 2.0) - PHI;
	printf("%.30LF\n", csi);
	long double A = tanl(csi) + tanhl(PI*g / 2.0);
	long double B = tanl(csi) - tanhl(PI*g / 2.0);
	return atanl(A / B);
}


//plot delta(ke) con g = 0
long double delta0(long double x)
{
	long double a = logl(gamma*x / 2.0);
	return atanl((a + PI/2.0) / (a - PI/2.0));
}

//Plot fig7 eq 47
long double deltaRn(long double x)
{
	return atanl((logl(x) + PI/2.0)/(logl(x)-PI/2.0));
}

//Plot fig8 eq 42
long double eps(long double g)
{	
	long double k1 = 0.1;
	return 2.0 / (gamma*k1) * expl(-PI*g);
}





int main(int argc, char const *argv[])
{
	FILE* file = fopen("deltaDati.txt","w");
	long double g = 0.5;
	long double a,b;
	a = 0.01;
	b = 4.0; //powl(10.0, 1);
	int N = 100000;
	long double h = (b-a) / (long double)N;
	printf("%.30Lf\n",h);
	long double x = a;
	
	/*
	for (int i = 0; i < N; ++i)
	{
		fprintf(file, "%.50Lf,%.50Lf\n",x,delta(x,g));
		x+=h;
	}
	*/
	

	//Tutti e 3 i modi sembrano essere uguali per x << 10^(-2,-3)
	
	
	while(x < b)
	{
		//fprintf(file, "%.70Lf,%.70Lf\n",x,delta(x,g));
		fprintf(file, "%.70Lf,%.70Lf\n",x,deltaRn(x));
		x*=1.01;
	}
		
	
	/*
	x = 0.00000928446791485507077246619472453079136009534977; //-1.34156105901010435710925955410388610289373900741339
	fprintf(file, "%.50Lf,%.50Lf\n",x,delta_xsmall(x,g));
	x = 0.00001392670187228260615869929208679618704014302466; //1.56060946608188715186912864929524857871001586318016
	fprintf(file, "%.50Lf,%.50Lf\n",x,delta_xsmall(x,g));
	*/

	fclose(file);
	return 0;
}