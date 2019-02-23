#include<stdio.h>
#include<math.h>
#define e 2.718281


void B1();
void B2();
void B3();
void B4();
void S1();
void S2();
void S3();
void S4();
void Vista();
void Menu(int *, int *);


int main(){
	
	int op, ap, ap2;
	
	Vista();
	
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
	return 0;
}
void Vista(){
	system("color f4");
	printf("\n\t\t\tPROGRAMA 1");
	printf("\n\t\t\t__________\n");
	printf("\n\tEste programa utiliza los metodos de Bisecci\242n\n");
	printf("\ty Secante para la soluci\242n de ecuaciones.\n\n\n");

	system("pause");
	system("cls");
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
