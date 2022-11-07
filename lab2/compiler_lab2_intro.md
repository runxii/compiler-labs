# basic logic
expr1 basically aim to recognize operation symbols used by calculator
``` yacc
expr  : expr ADD expr { $$ = $1 + $3; }
      | expr SUB expr { $$ = $1 - $3; }
      | expr MUL expr { $$ = $1 * $3; }
      | expr DIV expr { $$ = $1 / $3; }
      | LP expr RP  { $$ = $2; } 
      | SUB expr %prec UMINUS { $$ = -$2; }
      | NUMBER
```

# unix commandline
1. *use bison to compile `.y` files*
`bison -d expr3_liuyang.y`

2. *generate exe file for experiment*
`gcc expr3_liuyang.tab.c -lfl -o expr3`

3. *run the exe*
`./expr3`

