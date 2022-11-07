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

    void DEBUG_FOR_LAB4(std::string s){
        std::string DEBUG_INFO = "[DEBUG LAB4]: \t" + s + "\n";
        fputs(DEBUG_INFO.c_str(), yyout);
    }
    #endif
%}

%{
    class Node{
    public:
        string idname;
        int id_scope;
    };
    int id_count = 0;
    int id_scope = 0;
    int offset=0;
    vector<int> a;
    
    Node table[200];
%}

commentbegin "/*"
commentelement .|\n
commentend "*/"
%x BLOCKCOMMENT
linecommentbegin "//"
linecommentelement .
linecommentend \n
%x LINECOMMENT

LPAREN "("
RPAREN ")"
LBRACE "{"
RBRACE "}"
LSQR "["
RSQR "]"
POUND "#"
SEMICOLON ";"

EQU "=="
GEQ ">="
LEQ "<="
NEQ "!="
ASSIGN "="
PLUSASSIGN "+="
MINUSASSIGN "-="
MULASSIGN "*="
DIVASSIGN "/="
GRT ">"
LES "<"
PLUS "+"
MINUS "-"
MUL "*"
MOD "%"
DIV "/"
AND "&&"
OR "||"
NOT "!"

INT "int"
CONST "const"
VOID "void"
IF "if"
ELSE "else"
WHILE "while"
BREAK "break"
CONTINUE "continue"
RETURN "return"


OCT 0[0-7]+
DEC ([1-9][0-9]*|0)
HEX 0[X|x][0-9a-fA-F]+
ID [a-zA-Z_][a-zA-Z0-9_]*
EOL (\r\n|\n|\r)
WHITE [\t|\x20]
%%

{LPAREN} {
    fprintf(yyout, "%12s%8s%8d%8d\n", "LPAREN", yytext,yylineno,offset);
    offset+=strlen(yytext);
    }
{RPAREN} {
    fprintf(yyout, "%12s%8s%8d%8d\n", "RPAREN", yytext,yylineno,offset);
    offset+=strlen(yytext);
    }
{LBRACE} {
    fprintf(yyout, "%12s%8s%8d%8d\n", "LBRACE", yytext,yylineno,offset);
    offset+=strlen(yytext);
    id_scope++;
    a.push_back(id_scope);
}
{RBRACE} {
    fprintf(yyout, "%12s%8s%8d%8d\n", "RBRACE", yytext,yylineno,offset);
    offset+=strlen(yytext);
    a.pop_back();}
{LSQR} {fprintf(yyout, "%12s%8s%8d%8d\n", "LSQR", yytext,yylineno,offset);offset+=strlen(yytext);}
{RSQR} {fprintf(yyout, "%12s%8s%8d%8d\n", "RSQR", yytext,yylineno,offset);offset+=strlen(yytext);}
{SEMICOLON} {fprintf(yyout, "%12s%8s%8d%8d\n", "SEMICOLON", yytext,yylineno,offset);offset+=strlen(yytext);}
{POUND} {fprintf(yyout, "%12s%8s%8d%8d\n", "POUND", yytext,yylineno,offset);offset+=strlen(yytext);}

{ASSIGN} {fprintf(yyout, "%12s%8s%8d%8d\n", "ASSIGN", yytext,yylineno,offset);offset+=strlen(yytext);}
{PLUSASSIGN} {fprintf(yyout, "%12s%8s%8d%8d\n", "PLUSASSIGN", yytext,yylineno,offset);offset+=strlen(yytext);}
{MINUSASSIGN} {fprintf(yyout, "%12s%8s%8d%8d\n", "MINUSASSIGN", yytext,yylineno,offset);offset+=strlen(yytext);}
{MULASSIGN} {fprintf(yyout, "%12s%8s%8d%8d\n", "MULASSIGN", yytext,yylineno,offset);offset+=strlen(yytext);}
{DIVASSIGN} {fprintf(yyout, "%12s%8s%8d%8d\n", "DIVASSIGN", yytext,yylineno,offset);offset+=strlen(yytext);}
{EQU} {fprintf(yyout, "%12s%8s%8d%8d\n", "EQU", yytext,yylineno,offset);offset+=strlen(yytext);}
{NEQ} {fprintf(yyout, "%12s%8s%8d%8d\n", "NEQ", yytext,yylineno,offset);offset+=strlen(yytext);}
{GRT} {fprintf(yyout, "%12s%8s%8d%8d\n", "GRT", yytext,yylineno,offset);offset+=strlen(yytext);}
{LES} {fprintf(yyout, "%12s%8s%8d%8d\n", "LES", yytext,yylineno,offset);offset+=strlen(yytext);}
{GEQ} {fprintf(yyout, "%12s%8s%8d%8d\n", "GEQ", yytext,yylineno,offset);offset+=strlen(yytext);}
{LEQ} {fprintf(yyout, "%12s%8s%8d%8d\n", "LEQ", yytext,yylineno,offset);offset+=strlen(yytext);}
{PLUS} {fprintf(yyout, "%12s%8s%8d%8d\n", "PLUS", yytext,yylineno,offset);offset+=strlen(yytext);}
{MINUS} {fprintf(yyout, "%12s%8s%8d%8d\n", "MINUS", yytext,yylineno,offset);offset+=strlen(yytext);}
{MUL} {fprintf(yyout, "%12s%8s%8d%8d\n", "MUL", yytext,yylineno,offset);offset+=strlen(yytext);}
{DIV} {fprintf(yyout, "%12s%8s%8d%8d\n", "DIV", yytext,yylineno,offset);offset+=strlen(yytext);}
{MOD} {fprintf(yyout, "%12s%8s%8d%8d\n", "MOD", yytext,yylineno,offset);offset+=strlen(yytext);}
{AND} {fprintf(yyout, "%12s%8s%8d%8d\n", "AND", yytext,yylineno,offset);offset+=strlen(yytext);}
{OR} {fprintf(yyout, "%12s%8s%8d%8d\n", "OR", yytext,yylineno,offset);offset+=strlen(yytext);}
{NOT} {fprintf(yyout, "%12s%8s%8d%8d\n", "NOT", yytext,yylineno,offset);offset+=strlen(yytext);}

{INT} {fprintf(yyout, "%12s%8s%8d%8d\n", "INT", yytext,yylineno,offset);offset+=strlen(yytext);}
{CONST} {fprintf(yyout, "%12s%8s%8d%8d\n", "CONST", yytext,yylineno,offset);offset+=strlen(yytext);}
{VOID} {fprintf(yyout, "%12s%8s%8d%8d\n", "VOID", yytext,yylineno,offset);offset+=strlen(yytext);}
{IF} {fprintf(yyout, "%12s%8s%8d%8d\n", "IF", yytext,yylineno,offset);offset+=strlen(yytext);}
{ELSE} {fprintf(yyout, "%12s%8s%8d%8d\n", "ELSE", yytext,yylineno,offset);offset+=strlen(yytext);}
{WHILE} {fprintf(yyout, "%12s%8s%8d%8d\n", "WHILE", yytext,yylineno,offset);offset+=strlen(yytext);}
{BREAK} {fprintf(yyout, "%12s%8s%8d%8d\n", "BREAK", yytext,yylineno,offset);offset+=strlen(yytext);}
{CONTINUE} {fprintf(yyout, "%12s%8s%8d%8d\n", "CONTINUE", yytext,yylineno,offset);offset+=strlen(yytext);}
{RETURN} {fprintf(yyout, "%12s%8s%8d%8d\n", "RETURN", yytext,yylineno,offset);offset+=strlen(yytext);}

{DEC} {fprintf(yyout, "%12s%8s%8d%8d\n", "DEC", yytext, yylineno,offset);offset+=strlen(yytext);}
{HEX} {
    string a  = yytext;
        int len = a.length() - 2;
        int all = 0;
        for(int i = 0; i < len; i++)
        {
            int temp1 = (pow(16, (len - i - 1)));
            int temp2;
            if(a[i + 2] >= '0' && a[i + 2] <= '9'){
                temp2 = (a[i + 2] - '0');
            }
            else if(a[i + 2] >= 'A' && a[i + 2] <= 'F'){
                temp2 = a[i + 2] - 'A' + 10;
            }
            else if(a[i + 2] >= 'a' && a[i + 2] <= 'f'){
                temp2 = a[i + 2] - 'a' + 10;
            }
            all = all + temp1 * temp2;         
        }
    fprintf(yyout, "%12s%8d%8d%8d\n", "HEX", all, yylineno,offset);
    offset+=strlen(yytext);
}
{OCT} {
    
    string a  = yytext;
        int len = a.length() - 1;
        int all = 0;
        for(int i = 0; i < len; i++)
        {
            int temp1 = (pow(8, (len - i - 1)));
            int temp2 = (a[i + 1] - '0');
            all = all + temp1 * temp2;         
        }
    fprintf(yyout, "%12s%8d%8d%8d\n", "OCT", all, yylineno,offset);
    offset+=strlen(yytext);
}

{ID} {
int id=0;
bool id_match = 0;
for(int i = 0; i < id_count; i++)
{
    if(table[i].idname == yytext && table[i].id_scope == a.back())
    {
        id = i + 1;
        id_match = 1;
        break;
    }
}
if(!id_match){
    table[id_count].idname = yytext;
    if(a.size() != 0){
        table[id_count].id_scope = a.back();
    }
    id_count++;
    id=id_count;
}
fprintf(yyout, "%12s%8s%8d%8d%8d\n", "ID", yytext,yylineno, offset,id);
offset+=strlen(yytext);
}
{EOL} {yylineno++;offset=0;}
{WHITE} {offset++;}
{commentbegin} {
    BEGIN BLOCKCOMMENT;//start a state
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

    fprintf(yyout, "%12s%8s%8s%8s%8s\n", "lexeme", "text","line","offset","id no.");
    yylex();
    return 0;
}


#endif
