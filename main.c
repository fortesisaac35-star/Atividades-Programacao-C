#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265358979323846

typedef struct { int hora, minutos, segundos; } Horario;
typedef struct { int dia, mes, ano; } Data;
typedef struct { Data data; Horario horario; char descricao[200]; } Compromisso;
typedef struct { char nome[100]; int idade; char endereco[200]; } Pessoa;
typedef struct { double x, y, z; } Vetor;
typedef struct { double raio, angulo; } Polar;
typedef struct { double x, y; } Cartesiano;

void limpar(void) { int c; while ((c=getchar())!='\n' && c!=EOF) {} }
void texto(char *s, int n) { if(fgets(s,n,stdin)) s[strcspn(s,"\n")]=0; }

void exercicio1(void) {
    Compromisso c;
    puts("\n1 - Data, horario e compromisso");
    printf("Dia mes ano: ");
    if(scanf("%d %d %d",&c.data.dia,&c.data.mes,&c.data.ano)!=3){limpar();return;}
    printf("Hora minutos segundos: ");
    if(scanf("%d %d %d",&c.horario.hora,&c.horario.minutos,&c.horario.segundos)!=3){limpar();return;}
    limpar();
    printf("Descricao: "); texto(c.descricao,sizeof c.descricao);
    printf("%02d/%02d/%04d %02d:%02d:%02d - %s\n",c.data.dia,c.data.mes,c.data.ano,c.horario.hora,c.horario.minutos,c.horario.segundos,c.descricao);
}
void exercicio2(void) {
    Pessoa p;
    puts("\n2 - Dados de uma pessoa");
    printf("Nome: "); texto(p.nome,sizeof p.nome);
    printf("Idade: "); if(scanf("%d",&p.idade)!=1){limpar();return;} limpar();
    printf("Endereco: "); texto(p.endereco,sizeof p.endereco);
    printf("Nome: %s\nIdade: %d\nEndereco: %s\n",p.nome,p.idade,p.endereco);
}
void exercicio3(void) {
    Vetor a,b,s;
    puts("\n3 - Soma de vetores R3");
    printf("Vetor 1 (x y z): ");
    if(scanf("%lf %lf %lf",&a.x,&a.y,&a.z)!=3){limpar();return;}
    printf("Vetor 2 (x y z): ");
    if(scanf("%lf %lf %lf",&b.x,&b.y,&b.z)!=3){limpar();return;}
    limpar();
    s.x=a.x+b.x; s.y=a.y+b.y; s.z=a.z+b.z;
    printf("Soma = (%.2f, %.2f, %.2f)\n",s.x,s.y,s.z);
}
void exercicio4(void) {
    Polar p; Cartesiano c;
    puts("\n4 - Coordenadas polares para cartesianas");
    printf("Raio: "); if(scanf("%lf",&p.raio)!=1){limpar();return;}
    printf("Angulo (graus): "); if(scanf("%lf",&p.angulo)!=1){limpar();return;}
    limpar();
    double rad=p.angulo*PI/180.0;
    c.x=p.raio*cos(rad); c.y=p.raio*sin(rad);
    printf("x = %.4f, y = %.4f\n",c.x,c.y);
}
int main(void) {
    int opcao;
    for(;;) {
        puts("\n=== ATIVIDADES EM C ===\n1 - Compromisso\n2 - Pessoa\n3 - Vetores\n4 - Polar para cartesiana\n0 - Sair");
        printf("Opcao: ");
        if(scanf("%d",&opcao)!=1){limpar();puts("Opcao invalida");continue;}
        limpar();
        switch(opcao) {
            case 1: exercicio1();break;
            case 2: exercicio2();break;
            case 3: exercicio3();break;
            case 4: exercicio4();break;
            case 0: return 0;
            default: puts("Opcao invalida");
        }
    }
}
