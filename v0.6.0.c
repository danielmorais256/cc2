#include <stdio.h>

//Declaração de variáveis globais:
double a, b;
double dx;
double valorexato;
int n;

double f(double x){
	double fx = 0;
	//f(x)
	fx = x*x+x+2;
	return fx;
}

double somaaesquerda(){
	double x;
	x = a;
	double soma = 0;
	int i;
	for(i=0; i<n; i++){
		soma += f(x);
    	x += dx;
    }
    soma *= dx;
    return soma;
}

double somaadireita(){
	double x;
	x = a + dx;
	double soma = 0;
	int i;
	for(i=0; i<n; i++){
		soma += f(x);
    	x += dx;
    }
    soma *= dx;
    return soma;
}

double pontomedio(){
	double x;
	x = a + dx/2;
	double soma = 0;
	int i;
	for(i=0; i<n; i++){
		soma += f(x);
    	x += dx;
    }
    soma *= dx;
    return soma;
}

double trapezio(){
	double x;
	x = a + dx;
	double soma = 0;
	int i;
	for(i=0; i<n-1; i++){
	    soma += f(x);
    	x += dx;
    }
    soma += (f(a)+f(b))/2;
    soma *= dx;
    return soma;
}

/*
	h/3(y0+4y1+y2)
	h = dx/2
*/
double simpson(){
	double x;
	x = a;
	double soma = 0;
	int i;
	for(i=0; i<n; i++){
		soma += (f(x)+4*f(x+dx/2)+f(x+dx));
		x += dx;
	}
	soma *= (dx/6);
	return soma;
}

int main(){
	printf("CÁLCULO DA INTEGRAL DEFINIDA ATRAVÉS DE MÉTODOS NUMÉRICOS\n\n");
	//Demais dados:
	printf("a: ");
	scanf("%lf", &a);
	printf("b: ");
	scanf("%lf", &b);
	printf("valor exato: ");
	scanf("%lf", &valorexato);
	//Loop
	do{
		printf("\n==========================================\n\nn: ");
		scanf("%d", &n);
		//dx
		dx = (b-a)/n;
		printf("dx: %lf\n\n", dx);
		//Preenchendo as variáveis pra evitar calcular de novo a mesma coisa para os cálculos de erro
		double esq = somaaesquerda();
		double dir = somaadireita();
		double med = pontomedio();
		double trap = trapezio();
		double simp = simpson();
		//Output dos valores para cada regra
		printf("ESQ(%d): %lf\n", n, esq);
		printf("DIR(%d): %lf\n", n, dir);
		printf("MED(%d): %lf\n", n, med);
		printf("TRAP(%d): %lf\n", n, trap);
		printf("SIMP(%d): %lf\n", n, simp);
		//ERRO:
		printf("\nERRO:\n");
		printf("ESQ(%d): %f\n", n, valorexato-esq);
		printf("DIR(%d): %f\n", n, valorexato-dir);
		printf("MED(%d): %f\n", n, valorexato-med);
		printf("TRAP(%d): %f\n", n, valorexato-trap);
		printf("SIMP(%d): %f\n", n, valorexato-simp);
		//ERRO(%):
		printf("\nERRO (%%):\n");
		printf("ESQ(%d): %.3lf%%\n", n, ((valorexato-esq)/valorexato)*100);
		printf("DIR(%d): %.3lf%%\n", n, ((valorexato-dir)/valorexato)*100);
		printf("MED(%d): %.3lf%%\n", n, ((valorexato-med)/valorexato)*100);
		printf("TRAP(%d): %.3lf%%\n", n, ((valorexato-trap)/valorexato)*100);
		printf("SIMP(%d): %.3lf%%\n", n, ((valorexato-simp)/valorexato)*100);
	}while(n!=0);
	return 0;
}