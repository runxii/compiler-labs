#include "Ast.h"
#include "SymbolTable.h"
#include <string>
#include "Type.h"

extern FILE *yyout;
int Node::counter = 0;

Node::Node()
{
    seq = counter++;
}

void Ast::output()
{
    fprintf(yyout, "program\n");
    if(root != nullptr)
        root->output(4);
}

void BinaryExpr::output(int level)
{
    std::string op_str;
    switch(op) // 操作符，进行跳转
    {
        case ADD:
            op_str = "add";
            break;
        case SUB:
            op_str = "sub";
            break;
        case AND:
            op_str = "and"; // &&
            break;
        case OR:
            op_str = "or"; // ||
            break;
        case LESS:
            op_str = "less";
            break;
        case MORE:
            op_str = "more";
            break;
        case GEQ:
            op_str = "geq"; //greater equal >=
            break;
        case LEQ:
            op_str = "leq"; //less equal <=
            break;
        case EQU:
            op_str = "equ"; //==
            break;
        case NEQ:
            op_str = "neq"; //!=
            break;
        case DIV:
            op_str = "div"; 
            break;
        case MUL:
            op_str = "mul";
            break;
        case MOD:
            op_str = "mod";
            break;
        case PLUSASSIGN:
            op_str = "plusassign"; //+=
            break;
        case MINUSASSIGN:
            op_str = "minusassign"; //-=
            break;
        case MULASSIGN:
            op_str = "mulassign"; // *=
            break;
        case DIVASSIGN:
            op_str = "divassign"; // /=
            break;

    }
    fprintf(yyout, "%*cBinaryExpr\top: %s\n", level, ' ', op_str.c_str());
    expr1->output(level + 4); //因为表达式在子节点上，所以每个expr的level+4，表示在语法树上更深的层次
    expr2->output(level + 4);
}

void UnaryExpr::output(int level)
{
    std::string op_str;
    switch(op) // matching operations
    {
        case ADD:
            op_str = "add";
            break;
        case SUB:
            op_str = "sub";
            break;
        case NOT:
            op_str = "not";
            break;
    }
}

void Constant::output(int level)
{
    std::string type, value;
    type = symbolEntry->getType()->toStr();
    value = symbolEntry->toStr();
    fprintf(yyout, "%*cIntegerLiteral\tvalue: %s\ttype: %s\n", level, ' ',
            value.c_str(), type.c_str());
}

void Id::output(int level)
{
    std::string name, type;
    int scope;
    name = symbolEntry->toStr();
    type = symbolEntry->getType()->toStr();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getScope();
    fprintf(yyout, "%*cId\tname: %s\tscope: %d\ttype: %s\n", level, ' ',
            name.c_str(), scope, type.c_str());
}

void ConstId::output(int level)
{
    std::string name, type;
    int scope;
    name = symbolEntry->toStr();
    type = symbolEntry->getType()->toStr();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getScope();
    fprintf(yyout, "%*cConstId\tname: %s\tscope: %d\ttype: %s\n", level, ' ',
            name.c_str(), scope, type.c_str());
}

void IdQueue::output(int level) // a,b,c
{
fprintf(yyout, "%*cIdQueue\n", level, ' ');
    for(long unsigned int i = 0; i < ids.size(); i++)
    {
        ids[i] -> output(level + 4);
    }
    for(long unsigned int i = 0; i < assigns.size(); i++)
    {
        assigns[i] -> output(level + 4);
    }
}

void ConstIdQueue::output(int level)
{
    fprintf(yyout, "%*cConstIdQueue\n", level, ' ');
    for(long unsigned int i = 0; i < constids.size(); i++)
    {
        constids[i] -> output(level + 4);
    }
    for(long unsigned int i = 0; i < assigns.size(); i++)
    {
        assigns[i] -> output(level + 4);
    }
}

void CompoundStmt::output(int level)
{
    fprintf(yyout, "%*cCompoundStmt\n", level, ' ');
    stmt->output(level + 4);
}

void SeqNode::output(int level)
{
    fprintf(yyout, "%*cSequence\n", level, ' ');
    stmt1->output(level + 4);
    stmt2->output(level + 4);
}

void DeclStmt::output(int level)
{
    fprintf(yyout, "%*cDeclStmt\n", level, ' ');
    ids->output(level + 4);
}

void ConstDeclStmt::output(int level)
{
    fprintf(yyout, "%*cConstDeclStmt\n", level, ' ');
    constids->output(level + 4);
}

void BreakStmt::output(int level)
{
    fprintf(yyout, "%*cBreakStmt\n", level, ' ');
}

void ContinueStmt::output(int level)
{
    fprintf(yyout, "%*cContinueStmt\n", level, ' ');
}

void WhileStmt::output(int level)
{
    fprintf(yyout, "%*cWhileStmt\n", level, ' ');
    cond->output(level + 4);
    loop->output(level + 4);
}

void IfStmt::output(int level)
{
    fprintf(yyout, "%*cIfStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
}

void IfElseStmt::output(int level)
{
    fprintf(yyout, "%*cIfElseStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
    elseStmt->output(level + 4);
}

void ReturnStmt::output(int level)
{
    fprintf(yyout, "%*cReturnStmt\n", level, ' ');
    retValue->output(level + 4);
}

void AssignStmt::output(int level)
{
    fprintf(yyout, "%*cAssignStmt\n", level, ' ');
    lval->output(level + 4);
    expr->output(level + 4);
}

void SingleStmt::output(int level)
{
    fprintf(yyout, "%*cSingleStmt\n", level, ' ');
    expr ->output(level + 4);
}

void EmptyStmt::output(int level)
{
    fprintf(yyout, "%*cEmptyStmt\n", level, ' ');
}

void FuncFParam::output(int level)
{
    std::string name, type; //IdQueue
    int scope;
    name = symbolEntry -> toStr();
    type = symbolEntry -> getType() -> toStr();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry) -> getScope();
    fprintf(yyout, "%*cFuncFParam\tname:%s\tscope:%d\ttype:%s\n", level, ' ',
            name.c_str(), scope, type.c_str());
}

void FuncFParams::output(int level)
{
    fprintf(yyout, "%*cFuncFParams\n", level, ' ');
    for(long unsigned int i = 0; i < FPs.size(); i++)
    {
        FPs[i] -> output(level + 4);
    }
    for(long unsigned int i = 0; i < Assigns.size(); i++)
    {
        Assigns[i] -> output(level + 4);
    }
}

void FuncRParams::output(int level)
{
    fprintf(yyout, "%*cFuncRParams\n", level, ' ');
    for(long unsigned int i = 0; i < Exprs.size(); i++)
    {
        Exprs[i] -> output(level + 4);
    }
}

void FunctionDef::output(int level)
{
    std::string name, type;
    name = se->toStr();
    type = se->getType()->toStr();
    fprintf(yyout, "%*cFunctionDefine\tname: %s, type: %s\n", level, ' ', 
            name.c_str(), type.c_str());
    if(FPs != nullptr){
        FPs -> output(level + 4);
    }
    stmt->output(level + 4);
}

void FunctionCall::output(int level)
{
    std::string name, type;
    name = symbolEntry->toStr();
    type = symbolEntry->getType()->toStr();
    fprintf(yyout, "%*cFunctionCall\tname: %s\ttype: %s\n", level, ' ',
            name.c_str(), type.c_str());
    if(RPs != nullptr)
    {
        RPs -> output(level + 4);
    }
}