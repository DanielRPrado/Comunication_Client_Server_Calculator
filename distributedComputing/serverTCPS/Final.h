#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100
#include <string.h>
double stack[LIMIT][2];
int top = -1;
char numero[20];
int cr;
int cor=1;
void push(char element, double num){
      if (top == LIMIT - 1){
            printf("Stack Overflow: Cannot push element\n");
        }
        else{
          top++;
          stack[top][0] = element;
          stack[top][1]= num;
        }
}
void pop(){
    if(top!=-1)top--;
}
int solvable(){
    return (top>-1&&stack[top][0]!='(');
}
double solve(double a, char b, double c){
    if(b=='-')return a-c;
    if(b=='+')return a+c;
    if(b=='/')return a/c;
    if(b=='*')return a*c;
    if(b=='(')return a*c;
}
double convertir(){
    cr=0;
    char *eptr;
    return strtod(numero,&eptr);
}
double eval(char expresion[]){
    double ac=0.0;
    int nullnum= 1;
    int punto=0;
    for( int i=0; expresion[i]!='\0'&&cor; i++){
        if(expresion[i]=='-'){
            if(nullnum==1)
                push('-',0);
            else{
                if(cr>0)
                    ac=convertir();
                while(solvable()){
                    ac=solve(stack[top][1],stack[top][0],ac);
                    pop();
                }
                push('-',ac);
                nullnum=1;
            }
        }
        if(expresion[i]=='+'){
            if(nullnum==1)
                push('+',0);
            else{
                if(cr>0)
                    ac=convertir();
                while(solvable()){
                    ac=solve(stack[top][1],stack[top][0],ac);
                    pop();
                }
                push('+',ac);
                nullnum=1;
            }
        }
        if(expresion[i]=='*'){
            if(nullnum==1)
                cor=0;
            else{
                if(cr>0)
                    ac=convertir();
                while(solvable()){
                    ac=solve(stack[top][1],stack[top][0],ac);
                    pop();
                }
                push('*',ac);
                nullnum=1;
            }
        }
        if(expresion[i]=='/'){
            if(nullnum==1)
                cor=0;
            else{
                if(cr>0)
                    ac=convertir();
                while(solvable()){
                    ac=solve(stack[top][1],stack[top][0],ac);
                    pop();
                }
                push('/',ac);
                nullnum=1;
            }
        }
        if(expresion[i]=='('){
            if(nullnum==1)
                push('(',1.0);
            else{
                if(cr>0){
                    ac=convertir();
                while(solvable()){
                    ac=solve(stack[top][1],stack[top][0],ac);
                    pop();
                }
                push('(',ac);
                    
                } else
                    push('(',1.0);
                
                nullnum=1;
            }
        }
        if(expresion[i]==')'){
            if(nullnum==1){
                cor=0;
                
            }
            else{
                if(cr>0){
                    ac=convertir();
                    while(solvable()){
                        ac=solve(stack[top][1],stack[top][0],ac);
                        pop();
                    }
                }
                if(stack[top][0]=='('){
                    ac=solve(stack[top][1],stack[top][0],ac);
                    pop();
                    while(solvable()){
                        ac=solve(stack[top][1],stack[top][0],ac);
                        pop();
                    }
                }
                else cor=0;
                cr=0;
            }
        }
        if(nullnum==1){
                punto=0;
                numero[0]='\0';
                cr=0;
        }
        if(expresion[i]>='0'&&expresion[i]<='9'||expresion[i]=='.'){
            if(nullnum==1){
                punto=0;
                numero[0]='\0';
                cr=0;
            }
            if(expresion[i]=='.')
                if(punto==1)cor=0;
                else punto++;
            nullnum=0;
            numero[cr]=expresion[i];
            cr++;
            numero[cr]='\0';
        }
    }
    if(cr>0&&cor==1){
        ac=convertir();
        while(solvable()){
            ac=solve(stack[top][1],stack[top][0],ac);
            pop();
        }
    }
    if(top>-1)cor=0;

    return ac;
}

char *itoa(double n)
{
  static char   buf[32];
  sprintf(buf,"%lfa",n);
  return  buf;
}
void operation(dir)
char *dir;
{
strcpy(dir,itoa(eval(dir)));
if(cor==0)
strcpy(dir,"errora");
printf("%s\n",dir);
}
