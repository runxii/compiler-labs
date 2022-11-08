#ifndef __AST_H__
#define __AST_H__

#include <fstream>
#include <vector>

class SymbolEntry;

class Node
{
private:
    static int counter;
    int seq;
public:
    Node();
    int getSeq() const {return seq;};
    virtual void output(int level) = 0;
};

class ExprNode : public Node
{
protected:
    SymbolEntry *symbolEntry;
public:
    ExprNode(SymbolEntry *symbolEntry) : symbolEntry(symbolEntry){};
};

class BinaryExpr : public ExprNode 
{
private:
    int op;
    ExprNode *expr1, *expr2;
public:
    enum {ADD, SUB, DIV, MUL, MOD, AND, OR, LESS, MORE, ASSIGN, PLUSASSIGN, MINUSASSIGN, MULASSIGN, DIVASSIGN, EQU, GEQ, LEQ, NEQ};
    BinaryExpr(SymbolEntry *se, int op, ExprNode*expr1, ExprNode*expr2) : ExprNode(se), op(op), expr1(expr1), expr2(expr2){};
    void output(int level);
};

class UnaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr;
public:
    enum {ADD, SUB, NOT};
    UnaryExpr(SymbolEntry *se, int op, ExprNode*expr) : ExprNode(se), op(op), expr(expr){};
    void output(int level);   
};

class Constant : public ExprNode
{
public:
    Constant(SymbolEntry *se) : ExprNode(se){};
    void output(int level);
};

class Id : public ExprNode
{
public:
    Id(SymbolEntry *se) : ExprNode(se){};
    SymbolEntry* getSymbolEntry() {return symbolEntry;}
    void output(int level);
};

class ConstId : public ExprNode
{
public:
    ConstId(SymbolEntry *se) : ExprNode(se){};
    void output(int level);
};

class FuncFParam : public ExprNode
{
public:
    FuncFParam(SymbolEntry *se) : ExprNode(se) {};
    void output(int level);
};

class QueueNode : public Node
{};

class StmtNode : public Node
{};

class EmptyStmt : public StmtNode
{
public:
    void output(int level);
};

class SingleStmt : public StmtNode
{
private:
    ExprNode* expr;
public:
    SingleStmt(ExprNode* expr) : expr(expr){};
    void output(int level);
};

class CompoundStmt : public StmtNode
{
private:
    StmtNode *stmt;
public:
    CompoundStmt(StmtNode *stmt) : stmt(stmt) {};
    void output(int level);
};

class SeqNode : public StmtNode
{
private:
    StmtNode *stmt1, *stmt2;
public:
    SeqNode(StmtNode *stmt1, StmtNode *stmt2) : stmt1(stmt1), stmt2(stmt2){};
    void output(int level);
};

class IfStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
public:
    IfStmt(ExprNode *cond, StmtNode *thenStmt) : cond(cond), thenStmt(thenStmt){};
    void output(int level);
};

class IfElseStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
    StmtNode *elseStmt;
public:
    IfElseStmt(ExprNode *cond, StmtNode *thenStmt, StmtNode *elseStmt) : cond(cond), thenStmt(thenStmt), elseStmt(elseStmt) {};
    void output(int level);
};

class AssignStmt : public StmtNode
{
private:
    ExprNode *lval;
    ExprNode *expr;
public:
    AssignStmt(ExprNode *lval, ExprNode *expr) : lval(lval), expr(expr) {};
    void output(int level);
};

class IdQueue : public QueueNode
{// in order to recognize int a,b,c;
public:
    std::vector<Id*> ids;
    std::vector<AssignStmt*> assigns;
    IdQueue(std::vector<Id*> ids, std::vector<AssignStmt*> assigns): ids(ids),assigns(assigns){};
    void output(int level);
};

class ConstIdQueue : public QueueNode
{// in order to recognize const int a,b,c;
public:
    std::vector<ConstId*> constids;
    std::vector<AssignStmt*> assigns;
    ConstIdQueue(std::vector<ConstId*> constids, std::vector<AssignStmt*> assigns): constids(constids),assigns(assigns){};
    void output(int level);
};

class FuncRParams : public QueueNode
{
public:
    std::vector<ExprNode*> Exprs;
    FuncRParams(std::vector<ExprNode*> Exprs) : Exprs(Exprs){};
    void output(int level);
};

class FuncFParams : public QueueNode
{
public:
    std::vector<FuncFParam*> FPs;
    std::vector<AssignStmt*> Assigns;
    FuncFParams(std::vector<FuncFParam*> FPs, std::vector<AssignStmt*> Assigns) : FPs(FPs), Assigns(Assigns) {};
    void output(int level);
};

class ReturnStmt : public StmtNode
{
private:
    ExprNode *retValue;
public:
    ReturnStmt(ExprNode*retValue) : retValue(retValue) {};
    void output(int level);
};

class DeclStmt : public StmtNode
{
private:
    IdQueue *ids;
public:
    DeclStmt(IdQueue *ids) : ids(ids){};
    void output(int level);
};

class ConstDeclStmt : public StmtNode
{
private:
    ConstIdQueue *constids;
public:
    ConstDeclStmt(ConstIdQueue *constids) : constids(constids) {};
    void output(int level);
};

class FunctionDef : public StmtNode
{
private:
    SymbolEntry *se;
    FuncFParams *FPs;
    StmtNode *stmt;
public:
    FunctionDef(SymbolEntry *se, FuncFParams *FPs, StmtNode *stmt) : se(se), FPs(FPs), stmt(stmt) {};
    void output(int level);
};


class FunctionCall : public ExprNode
{
public:
    FuncRParams *RPs;
    FunctionCall(SymbolEntry *se, FuncRParams *RPs) : ExprNode(se), RPs(RPs) {};
    void output(int level);
};


class Ast
{
private:
    Node* root;
public:
    Ast() {root = nullptr;}
    void setRoot(Node*n) {root = n;}
    void output();
};

#endif
