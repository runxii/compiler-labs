%{
/*
expr1.y
YACC f i l e
Date: 2022/10/16
liuyang <1140909574@qq.com>
*/
#include <stdio.h>
#include <stdlib.h>
#ifndef YYSTYPE
#define YYSTYPE double
#endif
int yylex();
int isdigit();
extern int yyparse();
FILE* yyin;
void yyerror(const char* s );
%}

%token NUMBER
%token ADD SUB MUL DIV LP RP
%left ADD SUB
%left MUL DIV
%right UMINUS

%%

lines : lines expr ';' { printf("%f\n", $2); }
      | lines ';'
      |
      ;

expr  : expr ADD expr { $$ = $1 + $3; }
      | expr SUB expr { $$ = $1 - $3; }
      | expr MUL expr { $$ = $1 * $3; }
      | expr DIV expr { $$ = $1 / $3; }
      | LP expr RP  { $$ = $2; }
      | SUB expr %prec UMINUS { $$ = -$2; }
      | NUMBER  {$$ = $1;}
      ;
      


%%
int isdigit(t) // funcitons to check if t is digit, bool actually
{
    if(t=='0'||t=='1'||t=='2'||t=='3'||t=='4'||t=='5'||t=='6'||t=='7'||t=='8'||t=='9')
        return 1;
    else return 0;
}
// programs section
int yylex()
{
    // place your token retrieving code here
    int t;
    while(1)
    {
        t = getchar();
        if(t==' ' || t=='\t' || t== '\n')// 1. ignore space, enter first
        {
            //do nothing
        }
        else if (isdigit(t))// 2. check if t is digit
        {
            yylval = 0;
            while(isdigit(t))
            {
                yylval=yylval * 10 + t - '0';
                t = getchar();
            }
            ungetc(t , stdin );// stdin > t, then put the extra part back in buff area
            return NUMBER;
        }
        else{
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
                    return t; // t not in situations above
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