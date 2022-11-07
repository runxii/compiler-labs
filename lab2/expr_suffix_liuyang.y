%{
/*
expr1.y
YACC f i l e
Date: 2022/10/16
liuyang <1140909574@qq.com>
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#ifndef YYSTYPE
#define YYSTYPE char*
#endif
char idStr [50];//存储ID字符串
char numStr[50];//存储多位数字
int yylex();
// int isdigit(char t);
extern int yyparse();
FILE* yyin;
void yyerror(const char* s );
%}

%token ID
%token NUMBER
%token ADD SUB MUL DIV LP RP
%left ADD SUB
%left MUL DIV
%right UMINUS

%%

lines : lines expr ';' { printf("%s\n", $2); }
      | lines ';'
      |
      ;

expr  : expr ADD expr { $$ = (char *)malloc(50*sizeof (char)); strcpy($$,$1);
                        strcat($$,$3); strcat($$,"+ "); }
      | expr SUB expr { $$ = (char *)malloc(50*sizeof (char)); strcpy($$,$1);
                        strcat($$,$3); strcat($$,"- "); }
      | expr MUL expr { $$ = (char *)malloc(50*sizeof (char)); strcpy($$,$1);
                        strcat($$,$3); strcat($$,"* "); }
      | expr DIV expr { $$ = (char *)malloc(50*sizeof (char)); strcpy($$,$1);
                        strcat($$,$3); strcat($$,"/ "); }
      | LP expr RP  { $$ = (char *)malloc(50*sizeof (char)); strcpy($$,$2);
                        strcat($$," ");}
      | SUB expr %prec UMINUS { $$ = (char *)malloc(50*sizeof (char)); strcpy($$,"-");
                        strcat($$,$2);strcat($$," ");}
      | NUMBER        { $$ = (char *)malloc(50*sizeof (char));strcpy($$, $1); 
                        strcat($$," ");}
      | ID            { $$ = (char *)malloc(50*sizeof (char));strcpy($$, $1); 
                        strcat($$," ");}
      ;
      


%%
// int isdigit(char t)
// {
//     if(t=='0'||t=='1'||t=='2'||t=='3'||t=='4'||t=='5'||t=='6'||t=='7'||t=='8'||t=='9')
//         return 1;
//     else return 0;
// }
// programs section
int yylex()
{
    // place your token retrieving code here
    int t;
    while(1)
    {
        t = getchar();
        if(t==' ' || t=='\t' || t== '\n')
        {
        }
        else if(isdigit(t))
        {
            int ti = 0;
            while(isdigit(t))
            {
                numStr[ti]=t;
                t = getchar();
                ti++;
            }
            numStr[ti]='\0';
            yylval=numStr;
            ungetc(t , stdin );
            return NUMBER;
        }
        else if(( t>= 'a'&&t<='z')||(t>='A'&&t<='Z')||(t=='_'))
        {
            int ti=0;
            while (( t >= 'a' && t <= 'z' ) || ( t >= 'A' && t<= 'Z' ) || ( t == '_') || 
                   ( t >= '0' && t <= '9' ) ) 
            {
                idStr[ti]=t;
                ti++;
                t = getchar();
            }
                idStr[ ti ]='\0';
                yylval=idStr ;
                ungetc(t , stdin);
                return ID;
        }
        else
        {
            switch(t)
            {
                case '+':
                    return ADD;break;
                case '-':
                    return SUB;break;
                case '*':
                    return MUL;break;
                case '/':
                    return DIV;break;
                case '(':
                    return LP;break;
                case ')':
                    return RP;break;
                default:
                    return t;
            }
        }
    }
    
}

int main(void)
{
    yyin = stdin ;
    do{
        yyparse();
    } while (! feof (yyin));
    return 0;
}
void yyerror(const char* s) {

    fprintf (stderr , "Parse error : %s\n", s );
    exit (1);
}