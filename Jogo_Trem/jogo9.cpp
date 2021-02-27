//Game desenvolvido por Rodrigo do 2 semestre do curso análise e desenvolvimento de sistemas
//Disciplina Algoritmo
//Professor Alexandre Moreno
//data: 02/12/2020
#include<stdio.h>
#include<conio.c>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
#include<locale.h>
int col=40 , lin=24;
int coltrem1=71, lintrem1=23, coltrem2=34, lintrem2=23;
int coltrem3=0,  lintrem3=22, coltrem4=15,lintrem4=22, coltrem5=40,lintrem5=22;
int coltrem6=71, lintrem6=21, coltrem7=34, lintrem7=21, coltrem8=20, lintrem8=21;
int coltrem9=0,  lintrem9=20, coltrem10=40, lintrem10=20; 
int coltrem11=71, lintrem11=19, coltrem12=34, lintrem12=19;
int coltrem13=0,  lintrem13=18, coltrem14=40,  lintrem14=18;
int coltrem15=37, lintrem15=17, coltrem16=5,   lintrem16=17, coltrem17=15, lintrem17=17, coltrem18=60, lintrem18=17;
int coltrem19=26, lintrem19=25, coltrem20=60,  lintrem20=25;
int linhatiro=2,  colunatiro=3;
int pontuacao=0,nivel=1,subpontuacao=0,velocidade=300;
int scorePonto[4];
int pontoJogadorAtual;
char scoreNome[4][40];
char nomeAtual[40];
FILE *arq;

void instrucoes(){
     system("cls");
     printf("\n\n\n        Neste jogo o quadradinho [] que é você, não pode bater ou ser atropelado nos trens que estao\n\n");
     printf("      andando de uma direção a outra e nem nos que estão fixos parados.\n\n");
     printf("      O objetivo do jogo é atravesar todos os trilhos onde passa os trêns sem bater neles ou deixa-lo bater.\n\n");
     printf("      Ao atravessar todos os trilhos você retorna lá embaixo novamente e um ponto é adicionado em seu jogo.\n\n");
     printf("      A cada 4 pontos você passa de nivel.\n\n");
     printf("      Ao chegar no nivel 3 começa a cair de cima para baixo aleátoriamente um objeto que não pode atingir você.\n\n");
     printf("      Também a cada nivel que passa a velocidade dos trenzinhos e do objeto que cai de cima para baixo aumenta,\n\n");
     printf("      fazendo com que fique cada vez mais dificil jogar.\n\n\n");
     printf("      Caso um trenzinho ou o objeto atingir você, então você perde o jogo. \n\n");
     printf("      Use as setas no teclado para mover o [] e o espaço para pausar o jogo e para despausar use qualquer tecla. \n\n\n\n");
     printf("                                      ");
     system("pause");
}

void inicializaScore(){
  scorePonto[0]=0;
  scorePonto[1]=0;
  scorePonto[2]=0;
  scorePonto[3]=0;
  strcpy(scoreNome[0],"\0");
  strcpy(scoreNome[1],"\0");
  strcpy(scoreNome[2],"\0");    
  strcpy(scoreNome[3],"\0");
}
void classificaScore(){
char tmp_nome[40];
int  x,y,tmp_ponto;        
   strcpy(scoreNome[3],nomeAtual);
   scorePonto[3]=pontoJogadorAtual;
   for (x=0;x<=2;x++)
      for (y=x+1;y<=3;y++)
        if (scorePonto[y]>scorePonto[x])
        {  
           strcpy(tmp_nome,scoreNome[x]);
           strcpy(scoreNome[x],scoreNome[y]);
           strcpy(scoreNome[y],tmp_nome);
           
           tmp_ponto=scorePonto[x];
           scorePonto[x]=scorePonto[y];
           scorePonto[y]=tmp_ponto;
        }
}

void arquivo(int tp){ //0 - leitura / 1 - gravacao
    int x;
    arq = fopen ("recorde.txt","r"); //leitura
    if (arq == NULL || tp==1){
      arq = fopen ("recorde.txt","w"); //gravacao
      for (x=0;x<=3; x++)
         fprintf (arq, "%d%s\n", scorePonto[x], scoreNome[x]);
    } 
    else {
       for (x=0; x<=3; x++){
         fscanf (arq, "%d", &scorePonto[x]);
         fscanf (arq, "%[^\n]s",scoreNome[x]);
         scoreNome[x][strlen(scoreNome[x])]='\0';
       }  
    }
  fclose(arq);
}
void objeto(int coluna, int linha){
     textcolor(15);
     textbackground(1);
     clrscr();
     gotoxy(coluna,linha); printf("[]");//printf("coluna:%d, linha:%d",coluna,linha);
     //gotoxy(coluna,linha+2); printf(""); 
 }
 void barra(){
    textbackground(4);
    gotoxy(82,23);
    gotoxy(82,23);printf("|");
 }
 void trem1(){
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(coltrem1,lintrem1); 
    printf("[][][][][]"); 
    coltrem1--;
      if(coltrem1 == 0){
         coltrem1=78;
         lintrem1=23;
      } 
 }
 void trem2(){
     gotoxy(coltrem2,lintrem2);
     printf("[][][][]");
     coltrem2--;
     if(coltrem2 == 0){
         coltrem2=78;
         lintrem2=23;
      } 
  }
  void trem3(){
       gotoxy(coltrem3,lintrem3);
       printf("[][][][]");
       coltrem3++;
       if(coltrem3 == 74){
           coltrem3=0;
           lintrem3=22;
       }
  }
  
  void trem4(){
       gotoxy(coltrem4,lintrem4);
       printf("[][][][]");
       coltrem4++;
       if(coltrem4 == 74){
           coltrem4=0;
           lintrem4=22;
       }
  }
  
  void trem5(){
       gotoxy(coltrem5,lintrem5);
       printf("[][][][]");
       coltrem5++;
       if(coltrem5 == 74){
          coltrem5=0;
          lintrem5=22;
       }
  }
  
  void trem6(){
       gotoxy(coltrem6,lintrem6);
       printf("[][]");
       coltrem6--;
       if(coltrem6 ==0){
          coltrem6 = 78;
          lintrem6 = 21;
       }
  }
  
  void trem7(){
       gotoxy(coltrem7,lintrem7);
       printf("[][][][][]");
       coltrem7--;
       if(coltrem7 ==0){
          coltrem7 = 78;
          lintrem7 = 21;
       }
  }
   
  void trem8(){
       gotoxy(coltrem8,lintrem8);
       printf("[][][]");
       coltrem8--;
       if(coltrem8 ==0){
          coltrem8 = 78;
          lintrem8 = 21;
       }
  }
  
   void trem9(){
       gotoxy(coltrem9,lintrem9);
       printf("[][][][]");
       coltrem9++;
       if(coltrem9 == 74){
          coltrem9=0;
          lintrem9=20;
       }
  }
  
   void trem10(){
       gotoxy(coltrem10,lintrem10);
       printf("[][][]");
       coltrem10++;
       if(coltrem10 == 74){
          coltrem10=0;
          lintrem10=20;
       }
  }
  
  void trem11(){
       gotoxy(coltrem11,lintrem11);
       printf("[][][]");
       coltrem11--;
       if(coltrem11 ==0){
          coltrem11 = 78;
          lintrem11 = 19;
       }
  }
  
  void trem12(){
       gotoxy(coltrem12,lintrem12);
       printf("[][]");
       coltrem12--;
       if(coltrem12 ==0){
          coltrem12 = 78;
          lintrem12 = 19;
       }
  }
  
  void trem13(){
       gotoxy(coltrem13,lintrem13);
       printf("[][]");
       coltrem13++;
       if(coltrem13 == 74){
          coltrem13=0;
          lintrem13=18;
       }
  }
  
  void trem14(){
       gotoxy(coltrem14,lintrem14);
       printf("[]");
       coltrem14++;
       if(coltrem14 == 74){
          coltrem14=0;
          lintrem14=18;
       }
  }
  
  void trem15(){
       gotoxy(coltrem15, lintrem15);
       printf("[][][][]");
  }
  
  void trem16(){
       gotoxy(coltrem16, lintrem16);
       printf("[][][][]");
  }
  
  void trem17(){
       gotoxy(coltrem17, lintrem17);
       printf("[][][][][][]");
  }
  
  void trem18(){
       gotoxy(coltrem18, lintrem18);
       printf("[][][][][][]");
  }
  
  void trem19(){
       gotoxy(coltrem19, lintrem19);
       printf("[][][][][][]");
       coltrem19++;
       if(coltrem19 == 68){
          coltrem19=0;
          lintrem19=25;
       }
  }
  
  void trem20(){
       gotoxy(coltrem20, lintrem20);
       printf("[][]");
       coltrem20++;
       if(coltrem20 == 68){
          coltrem20=0;
          lintrem20=25;
       }
  }
  
  void tiro(){
       gotoxy(colunatiro,linhatiro);
       textcolor(1);
       printf("OO"); //printf("coluna:%i linha:%i\n",colunatiro,linhatiro); 
       linhatiro++;
       if (linhatiro>24){
         colunatiro=(rand()%75)+1;
         linhatiro=1;
         //colunatiro=40;
       }   
  }
  
  
  void gameover(){
  textcolor(15);
  textbackground(12);
  gotoxy(10,12); printf(" G A M E   O V E R ");   
  Beep(690,100);
  system("pause");
  
  }
  
  void credito(){
     system("cls");
     arquivo(0);
     printf("Lugar    Pontuação       Nome\n\n\n");
     for (int cont=0; cont<=2; cont++)
     printf ("Score %d %4d             %s \n\n",cont+1,scorePonto[cont],scoreNome[cont]);
     system("pause");  
}
  
  int colisao(){
       if(lin == lintrem1 && col >= coltrem1 && col <= coltrem1+10){
              return 1;
       }else
       if(lin == lintrem2 && col >= coltrem2 && col <= coltrem2+8){
              return 1;
       }else
       if(lin == lintrem3 && col >= coltrem3-2 && col <= coltrem3+6){
              return 1;
       }else
       if(lin == lintrem4 && col >= coltrem4-2 && col <= coltrem4+6){
              return 1;
       }else
       if(lin == lintrem5 && col >= coltrem5-2 && col <= coltrem5+6){
              return 1;
       }else
       if(lin == lintrem6 && col >= coltrem6 && col <= coltrem6+4){
              return 1;       
       }else
       if(lin == lintrem7 && col >= coltrem7 && col <= coltrem7+10){
              return 1;
       }else
       if(lin == lintrem8 && col >= coltrem8 && col <= coltrem8+6){
              return 1;
       }else
       if(lin == lintrem9 && col >= coltrem9-2 && col <= coltrem9+6){
              return 1;
       }else
       if(lin == lintrem10 && col >= coltrem10-2 && col <= coltrem10+4){
              return 1;
       }else
       if(lin == lintrem11 && col >= coltrem11 && col <= coltrem11+6){
              return 1;
       }else
       if(lin == lintrem12 && col >= coltrem12 && col <= coltrem12+4){
              return 1;
       }else
       if(lin == lintrem13 && col >= coltrem13-2 && col <= coltrem13+2){
              return 1;
       }else
       if(lin == lintrem14 && col >= coltrem14-2 && col <= coltrem14){
              return 1;
       }else
       if(lin == lintrem15 && col >= coltrem15-1 && col <= coltrem15+7){
              return 1;
       }else
       if(lin == lintrem16 && col >= coltrem16-1 && col <= coltrem16+7){
              return 1;
       }else
       if(lin == lintrem17 && col >= coltrem17-1 && col <= coltrem17+11){
              return 1;
       }else
       if(lin == lintrem18 && col >= coltrem18-1 && col <= coltrem18+11){
              return 1;
       }else
       if(lin == lintrem19 && col >= coltrem19-2 && col <= coltrem19+10){
              return 1;
       }else
       if(lin == lintrem20 && col >= coltrem20-2 && col <= coltrem20+2){
              return 1;
       }else
       if(lin == linhatiro && col >= colunatiro-1  && col <= colunatiro+1){
              return 1; 
       }else{
              return 0;
       }
  }
  
  
     void placar(){
       gotoxy(60,2);
       printf("PLACAR: %d\n",pontuacao);
       gotoxy(60,3);
       printf("NIVEL: %d\n",nivel);
  }
    
  
  
 int jogo(){
    int tecla = 0;
    srand(time(NULL));
    //int corf = rand()%16;
    //int cort = rand()%16;
    do{
      //col = rand()%78+1;
      //lin = rand()%24+1;
      objeto(col,lin);
      placar();
      barra();
      trem1();
      trem2();
      trem3();
      trem4();
      trem5();
      trem6();
      trem7();
      trem8();
      trem9();
      trem10();
      trem11();
      trem12();
      trem13();
      trem14();
      trem15();
      trem16();
      trem17();
      trem18();
      trem19();
      trem20();
      if(nivel >= 3){
         tiro();        
      } 
      
      Sleep(velocidade);
      //ganha pontos 
      if(lin == 16){
         pontuacao = pontuacao + 1;
         pontoJogadorAtual  = pontoJogadorAtual + 1;
         subpontuacao = subpontuacao + 1;
         lin = 25;
         //col = 40;
         if(subpontuacao == 4){
             subpontuacao = 0;
             //getch();
             nivel = nivel + 1;
             //Beep(120,200);
             velocidade = velocidade - 10;
         }
      }
      //colide
      if(colisao()==1){
         classificaScore();
         arquivo(1);
         pontoJogadorAtual = 0;
         pontuacao = 0;
         nivel = 1;
         subpontuacao = 0;
         velocidade = 310;
         lin = 24;
         col = 40;
         linhatiro=2;  
         colunatiro=3;
         gameover();
         tecla = 27;
      }else{
         printf("       ");
      }
      //movimentação
      if(kbhit()){
         tecla = getch();
         if(tecla==224){
            tecla = getch();
         }
         switch(tecla){
            case 72:
               if(lin >= 1){
                  lin = lin-1;
               }
               break;
            case 80:
                if(lin <= 24){
                   lin = lin+1;
                 }
                 break;
            case 75:
                 if(col >= 2){
                 col = col-1;
                 }
                 break;
            case 77:
                 if(col <= 78){
                   col = col+1;
                 }
                 break;
            case 32:
                 gotoxy(2,2);
                 system("pause");
                 break;
          }
      }
    }while(tecla!=27);
    pontuacao = 0;
    nivel = 1;
    subpontuacao = 0;
    velocidade = 310;
    lin = 24;
    col = 40;
}

int menu(){
    char tecla;
    int opcao = 1;
    do{
       
       textcolor(15);
       textbackground(9);
       //clrscr();
       system("cls");
       gotoxy (50,10);printf("Jogar      ");
       gotoxy (50,11);printf("Crédito    ");
       gotoxy (50,12);printf("Score      ");
       gotoxy (50,13);printf("Instruções ");
       gotoxy (50,14);printf("Sair       ");
       
       textcolor(0);
       gotoxy (41,7);printf("********** MENU DO JOGO **********");
       textbackground(0);
       textcolor(0);
       gotoxy (40,7);printf("_");
       gotoxy (40,8);printf("|");
       gotoxy (40,9);printf("|");
       gotoxy (40,10);printf("|");
       gotoxy (40,11);printf("|");
       gotoxy (40,12);printf("|");
       gotoxy (40,13);printf("|");
       gotoxy (40,14);printf("|");
       gotoxy (40,15);printf("|");
       gotoxy (40,16);printf("|");
       gotoxy (40,17);printf("|");
       gotoxy (40,18);printf("__________________________________");
       gotoxy (74,7);printf("|");
       gotoxy (74,8);printf("|");
       gotoxy (74,9);printf("|");
       gotoxy (74,10);printf("|");
       gotoxy (74,11);printf("|");
       gotoxy (74,12);printf("|");
       gotoxy (74,13);printf("|");
       gotoxy (74,14);printf("|");
       gotoxy (74,15);printf("|");
       gotoxy (74,16);printf("|");
       gotoxy (74,17);printf("|");
       gotoxy (74,18);printf("|");
       
       textcolor(9);
       textbackground(15);
       
       switch(opcao){
          case 1:
               gotoxy(50,10);printf("Jogar      ");
          break;
          case 2:
               gotoxy(50,11);printf("Crédito    ");
          break;
          case 3:
               gotoxy(50,12);printf("Score      ");
          break;
          case 4:
               gotoxy(50,13);printf("Instruções ");
          break;
          case 5:
               gotoxy(50,14);printf("Sair       ");
          break;      
                   
       }
       
       
       tecla = getch();
       
       switch(tecla){
          case 72:
               if(opcao>1){
                   opcao--;
               }else{
                   opcao = 5;
               }
          break;
          case 80:
               if(opcao<5){
                   opcao++;
               }else{
                   opcao = 1;
               }
          break;
          case 13:
               switch(opcao){
                   case 1:
                        
                        arquivo(0);
                        system("cls");
                        gotoxy(16,16);
                        printf("Digite seu nome: ");
                        gets(nomeAtual);
                        jogo();
                        classificaScore();
                        arquivo(1);
                        pontoJogadorAtual = 0;
                   break;
                   case 2:
                        //chama a função credito
                   break;
                   case 3:
                        //chama a função score
                        credito();
                   break;
                   case 4:
                        //chama a fução instruções
                        instrucoes();
                   break;
                   case 5:
                        tecla = 27;
                   break;
               }
               
       }
       
    }while(tecla!=27);
      
}

int main(){
   setlocale(LC_ALL,"portuguese");
   CONSOLE_CURSOR_INFO cursor = {1, FALSE};
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
   inicializaScore();
   menu();
   clrscr();
   //main();  
   //system("pause");  
}
