#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#define e 2.718281
#define T 20

void B1();
void B2();
void B3();
void B4();
void S1();
void S2();
void S3();
void S4();
void leerM(double [][T], double [][T], double[][T],double [][T], int);
void leerV(double [T], int);
void tam(int *);
void escribirM(double [][T], int);
int EDD(double [][T], int);
int simetricM(double [][T], int);
void escribirV(double [],int);
void inversa(double [][T], int);
double determinante(double [][T], double[][T], int);
double V[T];
void portada();
int pre();
void Menu(int *, int *);

int main(){
	double f[T][T], f2[T][T], vt[T], raiz[T];
	double acum=0, a;
	double M[T][T], M2[T][T], M3[T][T];
	double aux[T][T], despeje[T][T], inicial[T], independiente[T];
	double tol, tol1, suma = 1, det;
	int op, ap, ap2, pri, n, bndr, g, bndr2;
	char ult;
	portada();
	pri = pre();
	switch(pri){
		case 1:
			system("cls");
			do{
				Menu(&ap, &ap2);
				switch(ap){
					case 1:
						//aqui esta la funcion 1//
						switch(ap2){
							case 1:
								//aqui biseccion//
								B1();
								break;
							case 2:
								//aqui secante//
								S1();
								break;
						}
						break;
					case 2:
						//aqui esta la funcion 2//
						switch(ap2){
							case 1:
								//aqui biseccion//
								B2();
								break;
							case 2:
								//aqui secante//
								S2();
								break;
						}
						break;
					case 3:
						//aqui esta la funcion 3//
						switch(ap2){
							case 1:
								//aqui biseccion//
								B3();
								break;
							case 2:
								//aqui secante//
								S3();
								break;
						}
						break;
					case 4:
						//aqui esta la funcion 4//
						switch(ap2){
							case 1:
								//aqui biseccion//
								B4();
								break;
							case 2:
								//aqui secante//
								S4();
								break;
						}
						break;
				}
				printf("Desea repetir el programa?\n");
				printf("1.-Si \t2.-No\n \20");
				scanf("%d",&op);
				while(op < 1 || op > 2){
					printf("Opcion no valida. Intente de nuevo.\n");
					printf(" \20");
					scanf("%d",&op);
				}
			}while(op == 1);
			system("pause");
		break;
		case 2:
			system("cls");
			//aqui los SEL
			do{
				tam(&n);
				do{
					leerM(M, M2, M3, aux, n);
					system("cls");
					bndr = EDD(M, n);
				}while(bndr == 1);
				leerV(V, n);
				escribirM(M, n);
				det = determinante(M, M2, n);
				if(det != 0){
					escribirV(V, n);
					inversa(M3, n);
					printf("\n");
					printf("Aplicando el metodo de jacobii\n");
					printf("de cuanto es la tolerancia\n");
					scanf("%lf",&tol);
					for(int i=0;i<=n-1;i++){
						for(int j=0;j<=n-1;j++){
							if(i!=j){
								despeje[i][j]=(-1*aux[i][j])/aux[i][i];
							}
							if(i==j){
								despeje[i][j]=0;
							}
						}
					}
					for(int q=0;q<=n-1;q++){
						V[q]=V[q]/aux[q][q];
					}
					for(int i=0;i<=n-1;i++){
						independiente[i]=0;
						inicial[i]=0;    
					}
					g=0;
					do {
						double cont;
						cont=0;
						for(int i=0;i<=n-1;i++){
							for(int j=0;j<=n-1;j++){   
								if(despeje[i][j]!=0){     
									cont=cont+despeje[i][j]*inicial[j];  
								}
								if(j==n-1){
									independiente[i]=cont;
									cont=0;   
								}
							}
						}
						for(int i=0;i<=n-1;i++){
							independiente[i]=independiente[i]+V[i];     
						} 
						//buscar la norma espectral
						double a;
						a;
						int b;
						a=independiente[0];
						b=0;
						for(int i=0;i<=n-2;i++){
							if(a<independiente[i+1]){ 
								b=i+1;
								a=independiente[i+1];    
							}
						}
						tol1=fabs(independiente[b]-inicial[b]);
						printf("\nvector numero %d\n",g);
						for(int i=0;i<=n-1;i++){
							printf(" %lf \n",inicial[i]);	
						}
						g++;
						for(int i=0;i<=n-1;i++){
							inicial[i]=independiente[i];
						}
					}while(tol1>tol);
					printf("\nvector numero %d\n",g);
					for(int i=0;i<=n-1;i++){
						printf(" %lf \n",inicial[i]);		
					}
					printf("\n");
					printf("la solucion del sistema es\n");
					for(int i=0;i<=n-1;i++){
						printf("x_ %d %lf \n",i+1,inicial[i]);
					}
				}
				else{
					printf("La matriz no tiene soluci\242n \242 tiene multiples soluciones.");
				}
				printf("Desea calcular otro Sistema de Ecuaciones?\n");
				printf("   s/n   ");
				fflush(stdin);
				scanf("%c",&ult);
				while(ult != 's' && ult != 'n'){
					printf("Opcion no valida.\n");
					printf("Desea calcular otro Sistema de Ecuaciones?\n");
					printf("   s/n   ");
					fflush(stdin);
					scanf("%c",&ult);
				}
			}while(ult == 's');
			system("pause");
		break;
		case 3:
			system("cls");
			printf("Factorizacion LU\n\n");
			tam(&n);
			do{
				leerM(M, M2, M3, aux, n);
				bndr = EDD(M, n);
				bndr2 = simetricM(M, n);
			}while(bndr == 1 || bndr2 ==1);
			for(int i=0;i<=n-1;i++){
				for(int j=0;j<=n-1;j++){
					f[i][j]=0;	
				}
			}
			for(int i=0;i<=n-1;i++){
				for(int j=0;j<=i;j++){
					a=M[i][j];	
					if(i==0 && j==0)	{
						f[0][0]=pow(M[0][0],.5);
					}		
					if(i!=0){
						if(i==j){
							for(int k=0;k<=i-1;k++){
								acum=acum+pow(f[i][k],2);	
							}
							f[i][j]=pow((a-acum),.5);
							acum=0;	
						}
						if(i!=j){	
							for(int k=0;k<=j-1;k++){
								acum=acum+(f[i][k]*f[j][k]);	
							}
							f[i][j]=(a-acum)/f[j][j];
							acum=0;
						}
					}		
				}
			}
			escribirM(M3, n);
			printf("La matriz L es\n");
			printf("\n");
			for(int i=0;i<=n-1;i++){
				printf("\t\263");
				for(int j=0;j<=n-1;j++){
					printf(" %-3lf ",f[i][j]);
				}
				printf("\263\n");
			}
			printf("\nLa matriz U es\n");
			printf("\n");
			for(int i=0;i<=n-1;i++){
				printf("\t\263");
				for(int j=0;j<=n-1;j++){
					f2[i][j]=f[j][i];	
					printf(" %-3lf ",f2[i][j]);
				}
				printf("\263\n");
			}
			do{
				leerV(V, n);
				system("cls");
				escribirM(M3, n);
				escribirV(V, n);
				printf("La matriz L es\n");
				printf("\n");
				for(int i=0;i<=n-1;i++){
					printf("\t\263");
					for(int j=0;j<=n-1;j++){
						printf(" %-3lf ",f[i][j]);
					}
					printf("\263\n");
				}
				printf("\nLa matriz U es\n");
				printf("\n");
				for(int i=0;i<=n-1;i++){
					printf("\t\263");
					for(int j=0;j<=n-1;j++){
						f2[i][j]=f[j][i];	
						printf(" %-3lf ",f2[i][j]);
					}
					printf("\263\n");
				}
				for(int i=0; i<n; i++){
					if(i==0){
						vt[0]=V[0]/f[0][0];
					}	
					if(i!=0){
						acum=0;
						for(int j=0;j<=i-1;j++){
							acum=acum+f[i][j]*vt[j];	
						}	
						vt[i]=(V[i]-acum)/f[i][i];
						acum=0;	
					}	
				}
				printf("\nValores de la primera sustitucion:\n");
				for(int i=0;i<=n-1;i++){
					printf("\t\263 %lf \263\n",vt[i]);
				}
				for(int i=n-1;i>=0;i--){
					if(i==n-1){
						raiz[i]=(vt[i]/f2[i][i]);	
					}
					if(i!=n-1){
						acum=0;
						for(int j=n-1;j>=i+1;j--){
							acum=acum+raiz[j]*f2[i][j];
						}	
						raiz[i]=(vt[i]-acum)/f2[i][i];
						acum=0;	
					}	
				}
				printf("\nLas raices son:\n");
				printf("\n");
				for(int i=0;i<=n-1;i++){
					printf("\t\263 %lf \263\n",raiz[i]);
				}
				printf("\n");
				printf("Desea calcular para otro vector solucion?\n");
				printf("   s/n   ");
				fflush(stdin);
				scanf("%c",&ult);
				while(ult != 's' && ult != 'n'){
					printf("Opcion no valida.\n");
					printf("Desea calcular para otro vector solucion?\n");
					printf("   s/n   ");
					fflush(stdin);
					scanf("%c",&ult);
				}
			}while(ult == 's');
			system("pause");
		break;
		default:
			system("cls");
			printf("Algo se rompio aqui. :(");
			system("pause");
		break;
	}
	return 0;
}
void portada(){
	system("color f4");
	printf("\n\t\t\tPAQUETE FINAL");
	printf("\n\t\t\t_____________\n\n\n");

	system("pause");
	system("cls");
}
int pre(){
	int pri;
	system("cls");
	printf("\t1.-Solucion de ecuaciones.\n");
	printf("\t2.-Solucion de sistemas de ecuaciones.\n");
	printf("\t3.-Factorizacion LU.\n");
	printf("\t  \20");
	fflush(stdin);
	scanf("%d",&pri);
	while(pri<1 || pri>3){
		system("cls");
		printf("Opcion no valida.\n");
		printf("\t1.-Solucion de ecuaciones.\n");
		printf("\t2.-Solucion de sistemas de ecuaciones.\n");
		printf("\t3.-Factorizacion LU.\n");
		printf("\t  \20");
		fflush(stdin);
		scanf("%d",&pri);
	}
	return pri;
}
void Menu(int *p, int *q){
	printf("Selecione la ecuacion que desee:\n\n");
	printf("1.- f(x) = e^x + x^4 Cos(x) + 3\n");
	printf("2.- f(x) = 218 - (12/x^2) e^(-2x) - 1.19\n");
	printf("3.- f(x) = x^3 - Sin(x)\n");
	printf("4.- f(x) = x^3 + 6x^2 + 9.36x - 2.18\n");
	printf(" \20");
	scanf("%d",p);
	while(*p<1 || *p>4){
		printf("Opcion no valida. Intente de nuevo.\n");
		printf(" \20");
		scanf("%d",p);
	}	
	system("pause");
	system("cls");
	printf("Que metodo desea utilizar?\n\n");
	printf("1.- Bisecci\242n.\n");
	printf("2.- Secante.\n");
	printf(" \20");
	scanf("%d",q);
	while(*q<1 || *q>2){
		printf("Opcion no valida. Intente de nuevo.\n");
		printf(" \20");
		scanf("%d",q);
	}
	system("pause");
	system("cls");
}
void B1(){
	int m, i;
	double a, b, fa, fb, r, fr, tol, ea, aux;
	printf("1.- f(x) = e^x + x^4 Cos(x) + 3\n");
	printf("Valor para a= ");
	scanf("%lf",&a);
	printf("Valor para b= ");
	scanf("%lf",&b);
	printf("Maximo de iteraciones= ");
	scanf("%d",&m);
	printf("Tolerancia= ");
	scanf("%lf",&tol);
	fa = pow(e,a) + (pow(a,4) * cos(a)) + 3;
	fb = pow(e,b) + (pow(b,4) * cos(b)) + 3;
	while((fa * fb) > 0){
		printf("La evaluaci\242n de estos valores\nen este intervalo me dice que no hay raiz entre ellos.\n");
		printf("Seleccione otro intervalo.\n");
		printf("Valor para a= ");
		fflush(stdin);
		scanf("%lf",&a);
		printf("Valor para b= ");
		fflush(stdin);
		scanf("%lf",&b);
		fa = pow(e,a) + (pow(a,4) * cos(a)) + 3;
		fb = pow(e,b) + (pow(b,4) * cos(b)) + 3;
	}
	r = (a + b) / 2;
	aux = r;
	fr = pow(e,r) + (pow(r,4) * cos(r)) + 3;
	printf("\na:_______ b:_______ f(a):____  f(b):_____ r:_______  f(r):______  Ea:\n\n");
	printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,fa,fb,r,fr);
	if((fa * fr) < 0){
		b = r;
	}
	else{
		a = r;
	}
	i = 1;
	do{
		fa = pow(e,a) + (pow(a,4) * cos(a)) + 3;
		fb = pow(e,b) + (pow(b,4) * cos(b)) + 3;
		r = (a + b) / 2;
		fr = pow(e,r) + (pow(r,4) * cos(r)) + 3;
		ea = r - aux;
		ea = fabs(ea);
		aux = r;
		printf("\n");
		printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,fa,fb,r,fr,ea);
		if((fa * fr) < 0){
			b = r;
		}
		else{
			a = r;
		}
		i++;
	}while(i <= m && tol < ea);
	printf("\n\nLa raiz aproximada es: %f\n",r);
	system("pause");
	system("cls");
}
void B2(){
	int m, i;
	double a, b, fa, fb, r, fr, tol, ea, aux;
	printf("2.- f(x) = 218 - (12/x^2) e^(-2x) - 1.19\n");
	printf("Valor para a= ");
	scanf("%lf",&a);
	printf("Valor para b= ");
	scanf("%lf",&b);
	printf("Maximo de iteraciones= ");
	scanf("%d",&m);
	printf("Tolerancia= ");
	scanf("%lf",&tol);
	fa = (218 - (12 / pow(a,2)) * pow(e,(-2*a)) - 1.19);
	fb = (218 - (12 / pow(b,2)) * pow(e,(-2*b)) - 1.19);
	while(((fa * fb) > 0) || (a == 0 || b == 0)){
		printf("La evaluaci\242n de estos valores\nen este intervalo me dice que no hay raiz entre ellos.\n");
		printf("Seleccione otro intervalo.\n");
		printf("Valor para a= ");
		scanf("%lf",&a);
		printf("Valor para b= ");
		scanf("%lf",&b);
		fa = (218 - (12 / pow(a,2)) * pow(e,(-2*a)) - 1.19);
		fb = (218 - (12 / pow(b,2)) * pow(e,(-2*b)) - 1.19);
	}
	r = (a + b) / 2;
	aux = r;
	fr = (218 - (12 / pow(r,2)) * pow(e,(-2*r)) - 1.19);
	printf("\na:_______ b:_______ f(a):____  f(b):_____ r:_______  f(r):______  Ea:\n\n");
	printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,fa,fb,r,fr);
	if((fa * fr) < 0){
		b = r;
	}
	else{
		a = r;
	}
	i = 1;
	do{
		fa = (218 - (12 / pow(a,2)) * pow(e,(-2*a)) - 1.19);
		fb = (218 - (12 / pow(b,2)) * pow(e,(-2*b)) - 1.19);
		r = (a + b) / 2;
		fr = (218 - (12 / pow(r,2)) * pow(e,(-2*r)) - 1.19);
		ea = r - aux;
		ea = fabs(ea);
		aux = r;
		printf("\n");
		printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,fa,fb,r,fr,ea);
		if((fa * fr) < 0){
			b = r;
		}
		else{
			a = r;
		}
		i++;
	}while(i <= m && tol < ea);
	printf("\n\nLa raiz aproximada es: %f\n",r);
	system("pause");
	system("cls");
}
void B3(){
	int m, i;
	double a, b, fa, fb, r, fr, tol, ea, aux;
	printf("3.- x^3 - Sin(x)\n");
	printf("Valor para a= ");
	scanf("%lf",&a);
	printf("Valor para b= ");
	scanf("%lf",&b);
	printf("Maximo de iteraciones= ");
	scanf("%d",&m);
	printf("Tolerancia= ");
	scanf("%lf",&tol);
	fa = pow(a,3) - sin(a);
	fb = pow(b,3) - sin(b);
	while((fa * fb) > 0){
		printf("La evaluaci\242n de estos valores\nen este intervalo me dice que no hay raiz entre ellos.\n");
		printf("Seleccione otro intervalo.\n");
		printf("Valor para a= ");
		scanf("%lf",&a);
		printf("Valor para b= ");
		scanf("%lf",&b);
		fa = pow(a,3) - sin(a);
		fb = pow(b,3) - sin(b);
	}
	r = (a + b) / 2;
	aux = r;
	fr = pow(r,3) - sin(r);
	printf("\na:_______ b:_______ f(a):____  f(b):_____ r:_______  f(r):______  Ea:\n\n");
	printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,fa,fb,r,fr);
	if((fa * fr) < 0){
		b = r;
	}
	else{
		a = r;
	}
	i = 1;
	do{
		fa = pow(a,3) - sin(a);
		fb = pow(b,3) - sin(b);
		r = (a + b) / 2;
		fr = pow(r,3) - sin(r);
		ea = r - aux;
		ea = fabs(ea);
		aux = r;
		printf("\n");
		printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,fa,fb,r,fr,ea);
		if((fa * fr) < 0){
			b = r;
		}
		else{
			a = r;
		}
		i++;
	}while(i <= m && tol < ea);
	printf("\n\nLa raiz aproximada es: %f\n",r);
	system("pause");
	system("cls");
}
void B4(){
	int m, i;
	double a, b, fa, fb, r, fr, tol, ea, aux;
	printf("4.- x^3 + 6x^2 + 9.36x - 2.18\n");
	printf("Valor para a= ");
	scanf("%lf",&a);
	printf("Valor para b= ");
	scanf("%lf",&b);
	printf("Maximo de iteraciones= ");
	scanf("%d",&m);
	printf("Tolerancia= ");
	scanf("%lf",&tol);
	fa = pow(a,3) + 6 * pow(a,2) + 9.36 * a - 2.18;
	fb = pow(b,3) + 6 * pow(b,2) + 9.36 * b - 2.18;
	while((fa * fb) > 0){
		printf("La evaluaci\242n de estos valores\nen este intervalo me dice que no hay raiz entre ellos.\n");
		printf("Seleccione otro intervalo.\n");
		printf("Valor para a= ");
		scanf("%lf",&a);
		printf("Valor para b= ");
		scanf("%lf",&b);
		fa = pow(a,3) + 6 * pow(a,2) + 9.36 * a - 2.18;
		fb = pow(b,3) + 6 * pow(b,2) + 9.36 * b - 2.18;
	}
	r = (a + b) / 2;
	aux = r;
	fr = pow(r,3) + 6 * pow(r,2) + 9.36 * r - 2.18;
	printf("\na:_______ b:_______ f(a):____  f(b):_____ r:_______  f(r):______  Ea:\n\n");
	printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,fa,fb,r,fr);
	if((fa * fr) < 0){
		b = r;
	}
	else{
		a = r;
	}
	i = 1;
	do{
		fa = pow(a,3) + 6 * pow(a,2) + 9.36 * a - 2.18;
		fb = pow(b,3) + 6 * pow(b,2) + 9.36 * b - 2.18;
		r = (a + b) / 2;
		fr = pow(r,3) + 6 * pow(r,2) + 9.36 * r - 2.18;
		ea = r - aux;
		ea = fabs(ea);
		aux = r;
		printf("\n");
		printf("%f  %f  %f  %f  %f  %f  %f\n",a,b,fa,fb,r,fr,ea);
		if((fa * fr) < 0){
			b = r;
		}
		else{
			a = r;
		}
		i++;
	}while(i <= m && tol < ea);
	printf("\n\nLa raiz aproximada es: %f\n",r);
	system("pause");
	system("cls");
}
void S1(){
	int m, i;
	double x0, x1, fx0, fx1, x2, fx2, tol, ea, aux;
	printf("1.- f(x) = e^x + x^4 Cos(x) + 3\n");
	printf("Valor para x0= ");
	scanf("%lf",&x0);
	printf("Valor para x1= ");
	scanf("%lf",&x1);
	printf("Maximo de iteraciones= ");
	scanf("%d",&m);
	printf("Tolerancia= ");
	scanf("%lf",&tol);
	fx0 = pow(e,x0) + (pow(x0,4) * cos(x0)) + 3;
	fx1 = pow(e,x1) + (pow(x1,4) * cos(x1)) + 3;
	x2 = x1 - (fx1 * (x0 - x1) / (fx0 - fx1));
	aux = x2;
	fx2 = pow(e,x2) + (pow(x2,4) * cos(x2)) + 3;
	printf("\nx0:______ x1:_____ f(x0):__  f(x1):__ x2:_______  f(x2):______  Ea:\n\n");
	printf("%f  %f  %f  %f  %f  %f  %f\n",x0,x1,fx0,fx1,x2,fx2);
	x0 = x1;
	x1 = x2;
	i = 1;
	do{
		fx0 = pow(e,x0) + (pow(x0,4) * cos(x0)) + 3;
		fx1 = pow(e,x1) + (pow(x1,4) * cos(x1)) + 3;
		x2 = x1 - (fx1 * (x0 - x1) / (fx0 - fx1));
		fx2 = pow(e,x2) + (pow(x2,4) * cos(x2)) + 3;
		ea = x2 - aux;
		ea = fabs(ea);
		aux = x2;
		printf("\n");
		printf("%f  %f  %f  %f  %f  %f  %f\n",x0,x1,fx0,fx1,x2,fx2,ea);
		x0 = x1;
		x1 = x2;
		i++;
	}while(i <= m && tol < ea);
	printf("\n\nLa raiz aproximada es: %f\n",x2);
	system("pause");
	system("cls");
}
void S2(){
	int m, i;
	double x0, x1, fx0, fx1, x2, fx2, tol, ea, aux;
	printf("2.- f(x) = 218 - (12/x^2) e^(-2x) - 1.19\n");
	printf("Valor para x0= ");
	scanf("%lf",&x0);
	printf("Valor para x1= ");
	scanf("%lf",&x1);
	printf("Maximo de iteraciones= ");
	scanf("%d",&m);
	printf("Tolerancia= ");
	scanf("%lf",&tol);
	fx0 = (218 - (12 / pow(x0,2)) * pow(e,(-2*x0)) - 1.19);
	fx1 = (218 - (12 / pow(x1,2)) * pow(e,(-2*x1)) - 1.19);
	x2 = x1 - (fx1 * (x0 - x1) / (fx0 - fx1));
	aux = x2;
	fx2 = (218 - (12 / pow(x2,2)) * pow(e,(-2*x2)) - 1.19);
	printf("\nx0:______ x1:_____ f(x0):__  f(x1):__ x2:_______  f(x2):______  Ea:\n\n");
	printf("%f  %f  %f  %f  %f  %f  %f\n",x0,x1,fx0,fx1,x2,fx2);
	x0 = x1;
	x1 = x2;
	i = 1;
	do{
		fx0 = (218 - (12 / pow(x0,2)) * pow(e,(-2*x0)) - 1.19);
		fx1 = (218 - (12 / pow(x1,2)) * pow(e,(-2*x1)) - 1.19);
		x2 = x1 - (fx1 * (x0 - x1) / (fx0 - fx1));
		fx2 = (218 - (12 / pow(x2,2)) * pow(e,(-2*x2)) - 1.19);
		ea = x2 - aux;
		ea = fabs(ea);
		aux = x2;
		printf("\n");
		printf("%f  %f  %f  %f  %f  %f  %f\n",x0,x1,fx0,fx1,x2,fx2,ea);
		x0 = x1;
		x1 = x2;
		i++;
	}while(i <= m && tol < ea);
	printf("\n\nLa raiz aproximada es: %f\n",x2);
	system("pause");
	system("cls");
}
void S3(){
	int m, i;
	double x0, x1, fx0, fx1, x2, fx2, tol, ea, aux;
	printf("3.- f(x) = x^3 - Sin(x)\n");
	printf("Valor para x0= ");
	scanf("%lf",&x0);
	printf("Valor para x1= ");
	scanf("%lf",&x1);
	printf("Maximo de iteraciones= ");
	scanf("%d",&m);
	printf("Tolerancia= ");
	scanf("%lf",&tol);
	fx0 = pow(x0,3) - sin(x0);
	fx1 = pow(x1,3) - sin(x1);
	x2 = x1 - (fx1 * (x0 - x1) / (fx0 - fx1));
	aux = x2;
	fx2 = pow(x2,3) - sin(x2);
	printf("\nx0:______ x1:_____ f(x0):__  f(x1):__ x2:_______  f(x2):______  Ea:\n\n");
	printf("%f  %f  %f  %f  %f  %f  %f\n",x0,x1,fx0,fx1,x2,fx2);
	x0 = x1;
	x1 = x2;
	i = 1;
	do{
		fx0 = pow(x0,3) - sin(x0);
		fx1 = pow(x1,3) - sin(x1);
		x2 = x1 - (fx1 * (x0 - x1) / (fx0 - fx1));
		fx2 = pow(x2,3) - sin(x2);
		ea = x2 - aux;
		ea = fabs(ea);
		aux = x2;
		printf("\n");
		printf("%f  %f  %f  %f  %f  %f  %f\n",x0,x1,fx0,fx1,x2,fx2,ea);
		x0 = x1;
		x1 = x2;
		i++;
	}while(i <= m && tol < ea);
	printf("\n\nLa raiz aproximada es: %f\n",x2);
	system("pause");
	system("cls");
}
void S4(){
	int m, i;
	double x0, x1, fx0, fx1, x2, fx2, tol, ea, aux;
	printf("4.- f(x) = x^3 + 6x^2 + 9.36x - 2.18\n");
	printf("Valor para x0= ");
	scanf("%lf",&x0);
	printf("Valor para x1= ");
	scanf("%lf",&x1);
	printf("Maximo de iteraciones= ");
	scanf("%d",&m);
	printf("Tolerancia= ");
	scanf("%lf",&tol);
	fx0 = pow(x0,3) + 6 * pow(x0,2) + 9.36 * x0 - 2.18;
	fx1 = pow(x1,3) + 6 * pow(x1,2) + 9.36 * x1 - 2.18;
	x2 = x1 - (fx1 * (x0 - x1) / (fx0 - fx1));
	aux = x2;
	fx2 = pow(x2,3) + 6 * pow(x2,2) + 9.36 * x2 - 2.18;
	printf("\nx0:______ x1:_____ f(x0):__  f(x1):__ x2:_______  f(x2):______  Ea:\n\n");
	printf("%f  %f  %f  %f  %f  %f  %f\n",x0,x1,fx0,fx1,x2,fx2);
	x0 = x1;
	x1 = x2;
	i = 1;
	do{
		fx0 = pow(x0,3) + 6 * pow(x0,2) + 9.36 * x0 - 2.18;
		fx1 = pow(x1,3) + 6 * pow(x1,2) + 9.36 * x1 - 2.18;
		x2 = x1 - (fx1 * (x0 - x1) / (fx0 - fx1));
		fx2 = pow(x2,3) + 6 * pow(x2,2) + 9.36 * x2 - 2.18;
		ea = x2 - aux;
		ea = fabs(ea);
		aux = x2;
		printf("\n");
		printf("%f  %f  %f  %f  %f  %f  %f\n",x0,x1,fx0,fx1,x2,fx2,ea);
		x0 = x1;
		x1 = x2;
		i++;
	}while(i <= m && tol < ea);
	printf("\n\nLa raiz aproximada es: %f\n",x2);
	system("pause");
	system("cls");
}
void tam(int *n){
	system("cls");
	printf("Tama\xA4o de la matriz:");
	scanf("%d",n);
	system("cls");
}
void leerM(double M[T][T], double M2[T][T], double M3[T][T], double aux[T][T], int n){
	int i ,j;
	printf("Matriz.\n\n");
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++){
			printf("Dato %d,%d: ",i+1, j+1);
			scanf("%lf",&M[i][j]);
			M2[i][j] = M[i][j];
			M3[i][j] = M[i][j];
			aux[i][j] = M[i][j];
		}
	}
	system("cls");
}
int EDD(double M[T][T], int n){
	int b, i, j, s;
	b = 0;
	for(i=0 ; i<n ; i++){
		s = 0;
		for(j=0 ; j<n ; j++){
			s = s + fabs(M[i][j]);
		}
		s = s - fabs(M[i][i]);
		if(fabs(M[i][i]) < s){
			printf("La matriz no es E.D.D. en el renglon %d\n",i+1);
			printf("Introdusca otros valores.\n");
			b = 1;
			i = n;
			j = n;
		}
	}
	return b;
}
int simetricM(double M[T][T], int n){
	int b, i, j;
	b = 0;
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++){
			if(M[i][j] != M[j][i]){
				printf("La matriz no es simetrica.\n");
				printf("Introdusca otros valores.\n");
				b = 1;
				i = n;
				j = n;
			}
			
		}
		
	}
	return b;
}
void leerV(double V[T], int n){
	int i;
	printf("Vector independiente.\n\n");
	for(i=0 ; i<n ; i++){
		printf("Dato %d: ",i+1);
		scanf("%lf",&V[i]);
	}
}
void escribirM(double M[T][T], int n){
	int i, j;
	printf("La matriz es:\n");
	for(i=0 ; i<n ; i++){
		printf("\t\263");
		for(j=0 ; j<n ; j++){
			printf(" %-3.0lf",M[i][j]);
		}
		printf("\263\n");
	}
	printf("\n");
}
void escribirV(double V[T], int n){
	int i;
	printf("El vector independiente es:\n");
	for(i=0 ; i<n ; i++){
		printf("\t\263 %.0lf \263\n",V[i]);
	}
	printf("\n");
}
void inversa(double M[][T], int n){
	int i, j, z, r, g, l, h, q, s;
	for(i=0 ; i<=n-1 ; i++){
		for(j=0 ; j<=n-1 ; j++){
			if(i != j){
				M[i][j] = -M[i][j] / M[i][i];
			}        
		}
		for(z=0 ; z<=n-1 ; z++){
			if(z != i){
				for(r=0 ; r<=n-1 ; r++){
					if(r != i){
						M[r][z] = M[i][z] * M[r][i] + M[r][z];
					}
				}      
			}       
		} 
		for(g=0 ; g<=n-1 ; g++){
			if(g != i){
				M[g][i] = M[g][i] / M[i][i];
			}        
		}
		M[i][i] = 1 / M[i][i];             
	}
	printf("La matriz inversa es.\n");
	for(l=0;l<=n-1;l++){
		printf("\t\263");
		for(h=0;h<=n-1;h++){
			printf("%-1lf\t",M[l][h]);         
		}
		printf("\263\n");       
	}  
	printf("\n");
	float ret=0;
	for(q=0;q<=n-1;q++){
		for(s=0;s<=n-1;s++){
			ret = ret + M[q][s] * V[s];           
		}
		printf("x_%d =%lf",q+1,ret);
		printf("\n");
		ret=0;     
	}
}
double determinante(double M[T][T], double M2[T][T], int n){
	double suma=1;
	int z, t, i, j, l;
	for(z=0 ; z<=n-1 ; z++){
		for(i=z+1 ; i<=n-1 ; i++){
			for(j=z ; j<=n-1 ; j++){
				M[i][j] = M[i][j] - ((M2[i][z] / M[z][z]) * M[z][j]);
			}         
		}        
		for(t=0 ; t<=n-1 ; t++){
			for(l=0 ; l<=n-1 ; l++){
				M2[t][l] = M[t][l];        
			}  
		} 
	}
	for(i=0 ; i<=n-1 ; i++){
		for(j=0 ; j<=n-1 ; j++){
			if(i==j){
				suma = suma * M[i][j];        
			}     
		}          
	}
	printf("det = %.0lf\n\n",suma);
	return suma;
}
