%option noyywrap
%{
    #define YY_NO_UNPUT
    #define YY_NO_INPUT

    #include "parser.h"
    #include <ostream>
    #include <fstream>
    #include <string>
    #include <math.h>
    using namespace std;

    extern FILE *yyin; 
    extern FILE *yyout;
    extern bool dump_tokens;

    void DEBUG_FOR_LAB4(std::string s){
        std::string DEBUG_INFO = "[DEBUG LAB4]: \t" + s + "\n";
        fputs(DEBUG_INFO.c_str(), yyout);
    }
%}

COMMENTBEGIN "/*"
COMMENTELEMENT .|\n
COMMENTEND "*/"
%x BLOCKCOMMENT
LINECOMMENTBEGIN "//"
LINECOMMENTELEMENT .
LINECOMMENTEND \n
%x LINECOMMENT

OCT 0[0-7]+
DEC ([1-9][0-9]*|0)
HEX 0[X|x][0-9a-fA-F]+
ID [[:alpha:]_][[:alpha:][:digit:]_]*
EOL (\r\n|\n|\r)
WHITE [\t|\x20]

%%
{COMMENTBEGIN} {BEGIN BLOCKCOMMENT;}
<BLOCKCOMMENT>{COMMENTELEMENT} {}
<BLOCKCOMMENT>{COMMENTEND} {BEGIN INITIAL;}

{LINECOMMENTBEGIN} {BEGIN LINECOMMENT;}
<LINECOMMENT>{LINECOMMENTELEMENT} {}
<LINECOMMENT>{LINECOMMENTEND} {BEGIN INITIAL;}

"int" {
    /*
    * Questions: 
    *   Q1: Why we need to return INT in further labs?
    *   Q2: What is "INT" actually?
    */
    if(dump_tokens)
        DEBUG_FOR_LAB4("INT\tint");
    return INT;
}
"const" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("CONST\tconst");
    return CONST;
     
}
"void" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("VOID\tvoid");
    return VOID;
}
"if" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("IF\tif");
    return IF;
}
"else" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("ELSE\telse");
    return ELSE;
}
"return" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("RETURN\treturn");
    return RETURN;
}
"while" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("WHILE\twhile");
    return WHILE;
     
}
"continue" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("CONTINUE\tcontinue");
    return CONTINUE; 
}
"break" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("BREAK\tbreak");
    return BREAK; 
}
"==" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("EQU\t==");
    return EQU;
    
}
">=" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("GEQ\t>=");
    return GEQ;
    
}
"<=" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("LEQ\t<=");
    return LEQ;
    
}
"!=" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("NEQ\t!=");
    return NEQ;
    
}
"+=" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("PLUSASSIGN\t+=");
    return PLUSASSIGN;
    
}
"-=" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("MINUSASSIGN\t-=");
    return MINUSASSIGN;
    
}
"*=" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("MULASSIGN\t*=");
    return MULASSIGN;
    
}
"/=" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("DIVASSIGN\t/=");
    return DIVASSIGN;
    
}
"=" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("ASSIGN\t=");
    return ASSIGN;
}
"<" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("LESS\t<");
    return LESS;
}
">" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("MORE\t>");
    return MORE;
}
"+" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("ADD\t+");
    return ADD;
}
"-" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("SUB\t-");
    return SUB;
}
"/" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("DIV\t/");
    return DIV;
}
"*" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("MUL\t*");
    return MUL;
}
"%" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("MOD\t%");
    return PERC;
}
";" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("SEMICOLON\t;");
    return SEMICOLON;
}
"," {
    if(dump_tokens)
        DEBUG_FOR_LAB4("COMMA\t,");
    return COMMA;
}
"(" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("LPAREN\t(");
    return LPAREN;
}
")" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("RPAREN\t)");
    return RPAREN;
}
"{" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("LBRACE\t{");
    return LBRACE;
}
"}" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("RBRACE\t}");
    return RBRACE;
}
"[" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("LSQR\t{");
    return LSQR;
    
}
"]" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("RSQR\t{");
    return RSQR;
    
}
"#" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("POUND\t{");
    return POUND;
    
}
"&&" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("AND\t&&");
    return AND;
    
}
"||" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("OR\t||");
    return OR;
    
}
"!" {
    if(dump_tokens)
        DEBUG_FOR_LAB4("NOT\t!");
    return NOT;
}

{DEC} {
    if(dump_tokens)
        DEBUG_FOR_LAB4(yytext);
    yylval.itype = atoi(yytext);
    return INTEGER;
}

{ID} {
    if(dump_tokens)
        DEBUG_FOR_LAB4(yytext);
    char *lexeme;
    lexeme = new char[strlen(yytext) + 1];
    strcpy(lexeme, yytext);
    yylval.strtype = lexeme;
    return ID;
}
{EOL} yylineno++;
{WHITE}
%%
