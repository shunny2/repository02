#include <stdio.h>
#include <locale.h>
#define media_aprovado 7
#define media_reprovado 5

//Protótipos da função;
void CalculaNota (float nota1, float nota2, float nota3, float nota4);
void VerificaAprovacao(float media);
void Exame (float media);

void CalculaNota (float nota1, float nota2, float nota3, float nota4) {
	
	float media;
	media = ((nota1*2+nota2*3+nota3*4+nota4*1) / 4);

	VerificaAprovacao(media);
	
}

void VerificaAprovacao (float media) {
	
	//verifica se a media do aluno é acima de 7
	if (media >= media_aprovado) {
		printf ("Você Foi Aprovado, Parabéns! Sua Média: %.1f",media);
	}else {
		//verifica se a media do aluno é abaixo de 5
		if (media < media_reprovado) {
	     	printf ("Você Foi Reprovado, Tente Outra Vez! Sua Média: %.1f",media);
		}
	    else {
	    	//Caso a media for 5.5, 6 ou 6.5 o aluno tem direito a exame
	    	Exame(media);
		}
			
	}
	
}

void Exame (float media) {

	float exame,resultado;
	
	//Se a média for >= 5 ou <= 7 este aluno vai pra recuperação
	if (media >= media_reprovado || media <= media_aprovado) {
		
		printf ("Informe a sua nota do exame: ");
		scanf ("%f",&exame);
		resultado = (media+exame)/2;
		printf ("Sua Média final é: %.1f",resultado);
	}
	
}

int main ()
{
	//permite utlizar acentuações portuguesas
	setlocale (LC_ALL, "Portuguese");
	
	float nota1,nota2,nota3,nota4;
	
	printf ("Informe as 4 notas: ");
	scanf("%f %f %f %f",&nota1,&nota2,&nota3,&nota4);
	
	CalculaNota(nota1,nota2,nota3,nota4);		 	
	
}

