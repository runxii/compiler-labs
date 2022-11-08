%code top{
    #include <iostream>
    #include <assert.h>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
}

%code requires {
    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"
}

%union {
    int itype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    Type* type;
    IdQueue* idqueuetype;
    FuncFParams* Fstype;
    FuncRParams* FRtype;
    ConstIdQueue* constidtype;
}

%start Program
%token <strtype> ID 
%token <itype> INTEGER
%token IF ELSE BREAK CONTINUE
%token WHILE
%token INT VOID
%token CONST
%token POUND
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA
%token LSQR RSQR
%token ADD SUB DIV MUL MOD AND OR NOT LESS MORE ASSIGN PLUSASSIGN MINUSASSIGN MULASSIGN DIVASSIGN EQU GEQ LEQ NEQ
%token RETURN
%token LINECOMMENTBEGIN LINECOMMENTELEMENT LINECOMMENTEND COMMENTBEIGN COMMENTELEMENT COMMENTEND

%nterm <stmttype> Stmts Stmt AssignStmt BlockStmt IfStmt ReturnStmt WhileStmt
%nterm <stmttype>  DeclStmt ConstDeclStmt FuncDef SingleStmt
%nterm <exprtype> Exp UnaryExp AddExp MulExp Cond LOrExp PrimaryExp LVal RelExp LAndExp
%nterm <type> Type
%nterm <idqueuetype> IdQueue
%nterm <Fstype> FuncFParams
%nterm <FRtype> FuncRParams
%nterm <constidtype> ConstIdQueue

%precedence THEN
%precedence ELSE
%%
Program
    : Stmts {
        ast.setRoot($1);
    }
    ;
Stmts
    : Stmt {$$=$1;}
    | Stmts Stmt{
        $$ = new SeqNode($1, $2);
    }
    ;
Stmt
    : AssignStmt {$$=$1;}
    | BlockStmt {$$=$1;}
    | IfStmt {$$=$1;}
    | ReturnStmt {$$=$1;}
    | DeclStmt {$$=$1;}
    | ConstDeclStmt {$$=$1;}
    | FuncDef {$$=$1;}
    | WhileStmt {$$=$1;}
    | SEMICOLON {$$ = new EmptyStmt();}
    | BREAK SEMICOLON {$$ = new BreakStmt();}
    | CONTINUE SEMICOLON {$$ = new ContinueStmt();}
    | SingleStmt {$$=$1;}
    ;
// assignment
AssignStmt
    :
    LVal ASSIGN Exp SEMICOLON {
        $$ = new AssignStmt($1, $3);
    }
    ;
BlockStmt
    :   LBRACE 
        {identifiers = new SymbolTable(identifiers);} 
        Stmts RBRACE 
        {
            $$ = new CompoundStmt($3);
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
    ;
IfStmt
    : IF LPAREN Cond RPAREN Stmt %prec THEN {
        $$ = new IfStmt($3, $5);
    }
    | IF LPAREN Cond RPAREN LBRACE RBRACE {
        $$ = new IfStmt($3, new EmptyStmt());
    } 
    | IF LPAREN Cond RPAREN Stmt ELSE Stmt {
        $$ = new IfElseStmt($3, $5, $7);
    }
    ;
WhileStmt
    : WHILE LPAREN Cond RPAREN Stmt {
        $$ = new WhileStmt($3, $5);
    }
    ;
ReturnStmt
    :
    RETURN Exp SEMICOLON {
        $$ = new ReturnStmt($2);
    }
    ;
SingleStmt
    :
    Exp SEMICOLON {
        $$ = new SingleStmt($1);
    }
    ;
Exp
    :
    AddExp {$$ = $1;}
    ;
Cond
    :
    LOrExp {$$ = $1;}
    ;
//��ֵ
LVal
    : ID {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new Id(se);
        delete []$1;
    }
    ;
//基本表达式
PrimaryExp
    :
    LVal {$$ = $1;}
    | INTEGER {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, $1);
        $$ = new Constant(se);
    }
    |
    LPAREN Exp RPAREN {$$=$2;}
    ;
//单目表达式
UnaryExp
    :
    PrimaryExp {$$=$1;}
    |
    ID LPAREN RPAREN 
    { // a()
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "Function \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new FunctionCall(se, nullptr);
        delete []$1;
    }
    |
    ID LPAREN FuncRParams RPAREN 
    { // a(param)
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "Function \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new FunctionCall(se, $3);
        delete []$1;
    }
    |
    ADD UnaryExp {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::ADD, $2);
    }
    |
    SUB UnaryExp {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::SUB, $2);
    }
    |
    NOT UnaryExp {//����!a
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::NOT, $2);
    }
    ;
//AddExp的产生式右部有MulExp，因为表达式当中Mul(*,/)的优先级应当高于Add(+,-)
MulExp
    :
    UnaryExp {$$=$1;}
    |
    MulExp MUL UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MUL, $1, $3);
    }
    |
    MulExp DIV UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::DIV, $1, $3);
    }
    |
    MulExp MOD UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MOD, $1, $3);
    }
    ;
AddExp
    :
    MulExp {$$=$1;}
    |
    AddExp ADD MulExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::ADD, $1, $3);
    }
    |
    AddExp SUB MulExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::SUB, $1, $3);
    }
    ;
//关系表达式
RelExp
    :
    AddExp {$$ = $1;}
    |
    RelExp LESS AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESS, $1, $3);
    }
    |
    RelExp MORE AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MORE, $1, $3);
    }
    |
    RelExp GEQ AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GEQ, $1, $3);
    }
    |
    RelExp LEQ AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LEQ, $1, $3);
    }
    |
    RelExp NEQ AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NEQ, $1, $3);
    }
    |
    RelExp EQU AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::EQU, $1, $3);
    }
    ;
//逻辑与运算
LAndExp
    :
    RelExp {$$ = $1;}
    |
    LAndExp AND RelExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::AND, $1, $3);
    }
    ;
//逻辑或运算
LOrExp
    :
    LAndExp {$$ = $1;}
    |
    LOrExp OR LAndExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::OR, $1, $3);
    }
    ;
//函数返回值的类型
Type
    : INT {
        $$ = TypeSystem::intType;
    }
    | VOID {
        $$ = TypeSystem::voidType;
    }
    ;
//常量定义和初始化的产生式
ConstDeclStmt
    :
    CONST Type ConstIdQueue SEMICOLON {$$=new ConstDeclStmt($3);}
    ;
ConstIdQueue
    :
    ID ASSIGN Exp {
    //ConstIdQueue表示多个名字
        std::vector<ConstId*> constids;//a,b,c等常量名，表示名字的队列
        std::vector<AssignStmt*> assigns;//表示对ConstIdQueue中不同常量进行赋值
        ConstIdQueue* temp = new ConstIdQueue(constids, assigns);
        SymbolEntry* se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers -> getLevel());//查表项
        identifiers->install($1, se);
        ConstId *t = new ConstId(se);//将新的ConstId添加到ConstIdQueue中，方便返回值的统一
        temp -> constids.push_back(t);
        temp -> assigns.push_back(new AssignStmt(t, $3));
        $$ = temp;
        delete []$1;
    }
    |
    ConstIdQueue COMMA ID ASSIGN Exp {
    //constIdQueue是形为"a,b,c"的常量名队列，而ID表示"d"，$1,$2,$3合起来表示"a,b,c,d"
        ConstIdQueue *temp = $1;
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $3, identifiers->getLevel());
        identifiers->install($3, se);
        ConstId *t = new ConstId(se);
        temp -> constids.push_back(t);//相当于把"d"这个ID添加到$1当中的ConstIDQueue中
        temp -> assigns.push_back(new AssignStmt(t, $5));//把$5当中的赋值分别与常量名对应起来
        $$ = temp;
        delete []$3;
    }
    ;
//变量定义与初始化， 逻辑与常量的类似
DeclStmt
    :
    Type IdQueue SEMICOLON {$$=new DeclStmt($2);}
    ;
IdQueue
    :
    ID {
        std::vector<Id*> ids;
        std::vector<AssignStmt*> assigns;
        IdQueue *temp = new IdQueue(ids, assigns);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        temp -> ids.push_back(new Id(se));
        $$ = temp;
        delete []$1;
    }
    |
    IdQueue COMMA ID {
        IdQueue *temp = $1;
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $3, identifiers->getLevel());
        identifiers->install($3, se);
        temp -> ids.push_back(new Id(se));
        $$ = temp;
        delete []$3;
    }
    |
    ID ASSIGN Exp {
        std::vector<Id*> ids;
        std::vector<AssignStmt*> assigns;
        IdQueue *temp = new IdQueue(ids, assigns);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        Id *t = new Id(se);
        temp -> ids.push_back(t);
        temp -> assigns.push_back(new AssignStmt(t, $3));
        $$ = temp;
        delete []$1;
    }
    |
    IdQueue COMMA ID ASSIGN Exp {
        IdQueue *temp = $1;
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $3, identifiers->getLevel());
        identifiers->install($3, se);
        Id *t = new Id(se);
        temp -> ids.push_back(t);
        temp -> assigns.push_back(new AssignStmt(t, $5));
        $$ = temp;
        delete []$3;
    }
    ;

// 在UnaryExp里使用
FuncRParams
    :
    Exp
    {
        std::vector<ExprNode*> t;
        t.push_back($1);
        FuncRParams *temp = new FuncRParams(t);
        $$ = temp;
    }
    |
    FuncRParams COMMA Exp
    {
        FuncRParams *temp = $1;
        temp -> Exprs.push_back($3);
        $$ = temp;
    }
    ;
// 函数定义
FuncDef
    :   Type ID { //int get
            Type *funcType;
            funcType = new FunctionType($1,{});
            SymbolEntry *se = new IdentifierSymbolEntry(funcType, $2, identifiers->getLevel());
            identifiers->install($2, se);
            identifiers = new SymbolTable(identifiers);
        }
        LPAREN FuncParams {//(param1,param2
            SymbolEntry *se;
            se = identifiers->lookup($2);
            assert(se != nullptr);
            if($5!=nullptr){
                // 将函数参数类型写入符号表
                ((FunctionType*)(se->getType()))->setparamsType(((FuncDefParamsNode*)$5)->getParamsType());
            }   
        } 
        RPAREN BlockStmt { // ) function body
            SymbolEntry *se;
            se = identifiers->lookup($2);
            assert(se != nullptr);
            $$ = new FunctionDef(se, (FuncDefParamsNode*)$5, $8); // $8是BlockStmt
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
            delete []$2;
        }
    ;
// 函数参数列表
FuncParams
    :   FuncParams COMMA FuncParam {
            FuncDefParamsNode* node = (FuncDefParamsNode*)$1;
            node->addNext(((DefNode*)$3)->getId());
            $$ = node;
        }
    |   FuncParam {
            FuncDefParamsNode* node = new FuncDefParamsNode();
            node->addNext(((DefNode*)$1)->getId());
            $$ = node;
        }
    |   %empty {
            $$ = nullptr;
        }
    ;

// 函数参数
FuncParam
    :   Type ID {
            SymbolEntry *se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
            identifiers->install($2, se);
            $$ = new DefNode(new Id(se), nullptr, false, false);
        }
    ;
%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
