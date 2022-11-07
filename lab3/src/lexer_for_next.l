%option noyywrap
%{
    /*
    * You will need to comment this line in lab5.
    */
    #define ONLY_FOR_LEX
    
    #ifdef ONLY_FOR_LEX
    #else
    #define YYSTYPE void *
    #include "parser.h"
    #endif
    

    #define YY_NO_UNPUT
    #define YY_NO_INPUT
    #include <string>
    #include <vector>

    #ifdef ONLY_FOR_LEX

    #include <ostream>
    #include <fstream>
    #include <math.h>
    using namespace std;
    extern FILE *yyin; 
    extern FILE *yyout;

    void DEBUG_FOR_LAB4(std::string s,int d){
        std::string DEBUG_INFO = "[DEBUG LAB4]: \t" + s + "\t"+ std::to_string(d) + "\n";
        fputs(DEBUG_INFO.c_str(), yyout);
    }
    #endif
%}

%{
    int id_ord=0;
    char id_list[100][20];
    int offset=0;
%}

commentbegin "/*"
commentelement .|\n
commentend "*/"
%x BLOCKCOMMENT
linecommentbegin "//"
linecommentelement .
linecommentend \n
%x LINECOMMENT


OCT 0[0-7]+
DEC ([1-9][0-9]*|0)
HEX 0[X|x][0-9a-fA-F]+
ID [a-zA-Z_][a-zA-Z0-9_]*
EOL (\r\n|\n|\r|\s*\n|\s)
WHITE [\t|\x20]

%%

{OCT} {
    #ifdef ONLY_FOR_LEX
        string temp_text=yytext;
        string temp="OCT\t"+temp_text;
        DEBUG_FOR_LAB4(temp,yylineno);
    #else
        return OCT;
    #endif
}
{DEC} {
    #ifdef ONLY_FOR_LEX
        string temp_text=yytext;
        string temp="DEC\t"+temp_text;
        DEBUG_FOR_LAB4(temp,yylineno);
    #else
        return DEC;
    #endif
}
{HEX} {
    #ifdef ONLY_FOR_LEX
        string temp_text=yytext;
        string temp="HEX\t"+temp_text;
        DEBUG_FOR_LAB4(temp,yylineno);
    #else
        return HEX;
    #endif
}
"int" {
    /*
    * Questions: 
    *   Q1: Why we need to return INT in further labs?
    *   Q2: What is "INT" actually?
    */
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("INT\tint",yylineno);
    #else
        return INT;
    #endif
}
"const" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("CONST\tconst",yylineno);
    #else
        return CONST;
    #endif 
}
"void" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("VOID\tvoid",yylineno);
    #else
        return VOID;
    #endif 
}
"if" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("IF\tif",yylineno);
    #else
        return IF;
    #endif
};
"else" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("ELSE\telse",yylineno);
    #else
        return ELSE;
    #endif
};
"while" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("WHILE\twhile",yylineno);
    #else
        return WHILE;
    #endif 
}
"continue" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("CONTINUE\tcontinue",yylineno);
    #else
        return CONTINUE;
    #endif 
}
"return" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("RETURN\treturn",yylineno);
    #else
        return RETURN;
    #endif
}

"==" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("EQU\t==",yylineno);
    #else
        return EQU;
    #endif
}
">=" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("GEQ\t>=",yylineno);
    #else
        return GEQ;
    #endif
}
"<=" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("LEQ\t<=",yylineno);
    #else
        return LEQ;
    #endif
}
"!=" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("NEQ\t!=",yylineno);
    #else
        return NEQ;
    #endif
}
"+=" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("PLUSASSIGN\t+=",yylineno);
    #else
        return PLUSASSIGN;
    #endif
}
"-=" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("MINUSASSIGN\t-=",yylineno);
    #else
        return NINUSASSIGN;
    #endif
}
"*=" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("MULASSIGN\t*=",yylineno);
    #else
        return MULASSIGN;
    #endif
}
"/=" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("DIVASSIGN\t/=",yylineno);
    #else
        return DIVASSIGN;
    #endif
}

"=" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("ASSIGN\t=",yylineno);
    #else
        return ASSIGN;
    #endif
}
"<" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("LESS\t<",yylineno);
    #else
        return LESS;
    #endif
}
"+" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("ADD\t+",yylineno);
    #else
        return ADD;
    #endif
}
"-" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("MINUS\t-",yylineno);
    #else
        return MINUS;
    #endif
}
"*" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("MUL\t*",yylineno);
    #else
        return MUL;
    #endif
}
"/" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("DIV\t/",yylineno);
    #else
        return DIV;
    #endif
}
"%" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("MOD\t%",yylineno);
    #else
        return ADD;
    #endif
}
";" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("SEMICOLON\t;",yylineno);
    #else
        return SEMICOLON;
    #endif
}
"(" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("LPAREN\t(",yylineno);
    #else
        return LPAREN;
    #endif
}
")" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("RPAREN\t)",yylineno);
    #else
    return RPAREN;
    #endif
}
"{" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("LBRACE\t{",yylineno);
    #else
        return LBRACE;
    #endif
}
"}" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("RBRACE\t}",yylineno);
    #else
        return RBRACE;
    #endif
}
"[" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("LSQR\t{",yylineno);
    #else
        return LSQR;
    #endif
}
"]" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("RSQR\t{",yylineno);
    #else
        return RSQR;
    #endif
}
"#" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("POUND\t{",yylineno);
    #else
        return POUND;
    #endif
}
"&&" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("AND\t&&",yylineno);
    #else
        return AND;
    #endif
}
"||" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("OR\t||",yylineno);
    #else
        return OR;
    #endif
}
"!" {
    #ifdef ONLY_FOR_LEX
        DEBUG_FOR_LAB4("NOT\t!",yylineno);
    #else
        return NOT;
    #endif
}
{ID} {
#ifdef ONLY_FOR_LEX
        string temp_text=yytext;
        string temp="ID\t"+temp_text;
        DEBUG_FOR_LAB4(temp,yylineno);
    #else
        return ID;
    #endif
}
{EOL} yylineno++;
{WHITE}
{commentbegin} {
    BEGIN BLOCKCOMMENT;
    if(strcmp(yytext,"/*\n")==0)
        yylineno++;
}
<BLOCKCOMMENT>{commentelement} {
    if(strcmp(yytext,"\n")==0)
        yylineno++;
}
<BLOCKCOMMENT>{commentend} {
    if(strcmp(yytext,"*/\n")==0)
        yylineno++;
    BEGIN INITIAL;
}

{linecommentbegin} {BEGIN LINECOMMENT;}
<LINECOMMENT>{linecommentelement} {}
<LINECOMMENT>{linecommentend} {yylineno++;BEGIN INITIAL;}


%%

#ifdef ONLY_FOR_LEX
int main(int argc, char **argv){
    if(argc != 5){
        fprintf(stderr, "Argument Not Enough");
        exit(EXIT_FAILURE);
    }

    if(!(yyin = fopen(argv[1], "r"))){
        fprintf(stderr, "No such file or directory: %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    if(!(yyout = fopen(argv[3], "w"))){
        fprintf(stderr, "No such file or directory: %s", argv[3]);
        exit(EXIT_FAILURE);
    }
    string temp="lexeme\ttext\tline\t";
    DEBUG_FOR_LAB4(temp,0);
    yylex();
    return 0;
}


#endif
