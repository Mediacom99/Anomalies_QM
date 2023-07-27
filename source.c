//#include <integration.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


/*Comando per compilare:
	gcc ex6.c -I./ -lm -o ex6.unx
*/
/*Per includere i file usare gcc -I./ che include tutti i file nella cartella corrente*/

// Plotting the modified bessel function of the second kind K with imaginary order by using 
// one of the integral representations

const long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647;


long double T(long double a, long double x)
{
	return (x+a);
}

long double Lag_64x[64] = {
2.24158741467052800231e-02,
1.18122512096770479798e-01,
2.90365744018036483988e-01,
5.39286221227979039314e-01,
8.65037004648113944615e-01,
1.26781404077524139816e+00,
1.74785962605943625279e+00,
2.30546373930750871854e+00,
2.94096515672525184062e+00,
3.65475265020729052703e+00,
4.44726634331309435668e+00,
5.31899925449639034364e+00,
6.27049904692365391284e+00,
7.30237000258739574719e+00,
8.41527523948302419443e+00,
9.60993919279610803608e+00,
1.08871503838863721422e+01,
1.22477645042443016180e+01,
1.36927078455475051523e+01,
1.52229811115247288481e+01,
1.68396636526487372097e+01,
1.85439181708591905237e+01,
2.03369959487302355006e+01,
2.22202426659508765396e+01,
2.41951048759332539902e+01,
2.62631372271184857850e+01,
2.84260105275010272995e+01,
3.06855207675259717710e+01,
3.30435992364378291267e+01,
3.55023238911412095872e+01,
3.80639321656464682600e+01,
4.07308354444586263668e+01,
4.35056354664215298514e+01,
4.63911429786161920753e+01,
4.93903990256246866776e+01,
5.25066993413463016516e+01,
5.57436224132783804640e+01,
5.91050619190171066079e+01,
6.25952644001513955965e+01,
6.62188732512475643835e+01,
6.99809803771468292299e+01,
7.38871872324829632103e+01,
7.79436774344631203154e+01,
8.21573037783193042966e+01,
8.65356933494565182113e+01,
9.10873756131330901478e+01,
9.58219400155207320924e+01,
1.00750231969513979628e+02,
1.05884599468799949357e+02,
1.11239207524439582063e+02,
1.16830445051306498462e+02,
1.22677460268538576577e+02,
1.28802878769237672513e+02,
1.35233787949525827835e+02,
1.42003121489931519020e+02,
1.49151665900049388583e+02,
1.56731075132671161240e+02,
1.64808602655150522986e+02,
1.73474946836424274516e+02,
1.82858204691431463648e+02,
1.93151136037072911483e+02,
2.04672028485059455949e+02,
2.18031851935328516337e+02,
2.34809579171326164707e+02};

//Modified second kind bessel function with imaginary order 
long double Lag_64w[64] = {
5.62528423390298457415e-02,
1.19023987312426027814e-01,
1.57496403862144523822e-01,
1.67547050415773947886e-01,
1.53352855779236618084e-01,
1.24221053609329744510e-01,
9.03423009864850577399e-02,
5.94777557683550242119e-02,
3.56275189040360718546e-02,
1.94804104311664060425e-02,
9.74359489938200223986e-03,
4.46431036416627529234e-03,
1.87535958132311482674e-03,
7.22646981575005122724e-04,
2.55487532833496709709e-04,
8.28714353439694217928e-05,
2.46568639678855874602e-05,
6.72671387882966852755e-06,
1.68178536996408889783e-06,
3.85081298154668441490e-07,
8.06872804099049979074e-08,
1.54572370675768882797e-08,
2.70448014761748140999e-09,
4.31677547542720091234e-10,
6.27775254176145220162e-11,
8.30631737628895806350e-12,
9.98403178722016405639e-13,
1.08835388711666268198e-13,
1.07401740344159018535e-14,
9.57573723157444210502e-16,
7.69702802364858610043e-17,
5.56488113745405325697e-18,
3.60975640901044207624e-19,
2.09509536954894766310e-20,
1.08479330109754928762e-21,
4.99469948636380407034e-23,
2.03783697459882230123e-24,
7.33953756427942062218e-26,
2.32378308219864875034e-27,
6.43823470690877180331e-29,
1.55312109578827474413e-30,
3.24425009201953746751e-32,
5.83238626783522807580e-34,
8.96325483310326880324e-36,
1.16870398955072802407e-37,
1.28205598435998071667e-39,
1.17209493740500221911e-41,
8.83533967232947430164e-44,
5.42495559030620008660e-46,
2.67554266667889197253e-48,
1.04291703141136705653e-50,
3.15290235195777262957e-53,
7.22954191064766081503e-56,
1.22423530123008223644e-58,
1.48216850490191038804e-61,
1.23251934881451880776e-64,
6.69149900457126952687e-68,
2.22046594185044891569e-71,
4.12094609473887625236e-75,
3.77439906189648917048e-79,
1.41411505291761941744e-83,
1.59183306404136791788e-88,
2.98948434886063430781e-94,
2.08906350843695277083e-101};


long double Kigx(long double x, long double g)
{	
	long double result = 0.0;
	long double t = 0.0;
	for (int i = 0; i < 64; ++i)
			{
				t = T(0.0,Lag_64x[i]);
				result+= (expl(-x*coshl(t) + t)*cosl(g*t))*Lag_64w[i];
			}
		return result;
}

void bracketing(long double(*f)(long double, long double), long double x1, long double x2, 
				int n, long double* xb1, long double* xb2, long double g)
{	

	int nroot = 0;
	long double dx = (x2 - x1) / (long double)n;
	long double x = x1;
	long double fp = f(x1,g);
	for (int i = 0; i < n; ++i)
	{
		long double fc = f(x+=dx,g);

		//printf("%.30Lf,%.30Lf, %.30Lf, %.30Lf\n",x-dx,x,fc,fp);
		//Se c'è il cambio di segno allora salva i valori
		if(fc*fp <= 0.0)
		{
			xb1[nroot] = x-dx;
			xb2[nroot] = x;
			nroot++;
		}
		fp=fc;
	}

	return;

}


//Algoritmo che, partendo dagli intervalli usati da bracketing, ricava precisamente la radice
//xacc = accuratezza entro cui cercare lo zero
long double bisection(long double(*func)(long double, long double), long double x1, long double x2, long double xacc, long double g)
{
	const int JMAX = 100;
	//const int JMAX = 100;
	//maximum allowed number of bisections
	long double dx,xmid,rtb;
	long double f = func(x1,g);
	long double fmid = func(x2,g);
	if(func(x1,g)*func(x2,g) >= 0)
	{
		printf("FUNC(x1,G) = %.30LF\n", func(x1,g));
		printf("FUNC(x2,G) = %.30LF\n", func(x2,g));
		printf("Bracketing da rifare\n");
		exit(EXIT_FAILURE);
	}
	if(f<0.0)
	{
		dx = x2-x1;
		rtb = x1;
	}else
	{
		dx = x1-x2;
		rtb = x2;
	}
	for (int i = 0; i < JMAX; ++i)
	{
		fmid=func(xmid=rtb+(dx*=0.5),g);
		//printf("fmid=%f rtb=%f\n",fmid,rtb);
		if(fmid <= 0.0) rtb = xmid;
		if(fabsl(dx)<xacc || fmid == 0.0) return rtb;
	}
	printf("Troppe iterazioni\n");
	exit(EXIT_FAILURE);

}

long double max(long double* a, int dim)
{	
	long double temp = a[0];
	for (int i = 0; i < dim; ++i)
	{
		if(temp < a[i] && !(temp != temp))
		{
			temp = a[i];
			//printf("%.30LF\n",a[i]);
		}
	}
	return temp;
}

void freeV(long double* a, int dim)
{
	for (int i = 0; i < dim; ++i)
	{
		a[i] = NAN;
	}
	return;
}

void printVec(long double* a, int dim)
{
	for (int i = 0; i < dim; ++i)
	{
		printf("%.30Lf\n",a[i]);
	}
	return;
}

void iniV(long double* a, int dim)
{
	for (int i = 0; i < dim; ++i)
	{
		a[i] = 0.0;
	}
	return;
}

int main(int argc, char const *argv[])
{
	/*

	Plottando la funzione di bessel modificata con ordine immaginario
	usando la formula di rappresentazione integrale nella paper di dunster
	(usando metodo di laguerre)
	*/

	
	FILE* file;
	file = fopen("data.txt","w");
	

	FILE* file2;
	file2 = fopen("zero.txt","w");

	//Plot K_ig

	/*
	long double x;
	long double a = 1.0;
	long double b = 100.0;
	long double g = 3;
	long double k = 0.043089;
	x = a;
	//long double norm = k*sqrtl(2*sinhl(PI*g) / (PI*g));
	//0.122830; 
	//0.350972;
	//1.024645;
	long double N = 10000;
	long double h =  (b-a)/ (long double)N;
	for (int i = 0; i < N; ++i)
	{
		fprintf(file, "%.30LF,%.30LF\n",x,sqrtl(x)*Kigx(k*x,g));
		x+=h;
	}
	
	*/
	
	//TROVARE GLI ZERI DI K_ig 

	//Numero di radici
	int nroot = 10;
	//guess iniziali intervallo in cui cercare gli intervalli che contengono radici
	long double xb1[nroot];
	long double xb2[nroot];
	iniV(xb1,nroot);
	iniV(xb2,nroot);
	long double G = 0.6;
	long double a = 0.001;
	long double b = 1000;
	int N = 100;
	long double h = (long double)(6-G) / (long double)N;
	
	/*
	for (int i = 0; i < N; ++i)
	{
		
	bracketing(Kigx,a,b,1,xb1,xb2,G);
	
	//printf("%.30LF,%.30LF\n",xb1[0],xb2[0]);
	
	printf("%.30LF,%.30LF\n",G,bisection(Kigx,xb1[0],xb2[0],0.0001,G));
	G+=h;

	}
	*/
	
	
	// THIS WORKS FOR G IN (0.6,6) for sure
	long double pos1,pos2;
	for (int j = 0; j < N; ++j)
	{

		bracketing(Kigx,a,b,100000,xb1,xb2,G);
		pos1 = max(xb1,nroot);
		pos2 = max(xb2,nroot);
		printf("MAX xb1 = %.30LF\n", pos1);
		printf("MAX xb2 = %.30LF\n", pos2);
		printf("\n\n\n");
		fprintf(file2,"%.30LF,%.50LF\n",G,bisection(Kigx,pos1,pos2,0.00000001,G));
		G+=h;
		//printVec(xb1,nroot);
		//printf("\n");
		//printVec(xb2,nroot);
		freeV(xb1, nroot);
		freeV(xb2, nroot);

	}
	

	fclose(file);
	fclose(file2);
	

	
	return 0;
}