Nonterminals module variable expressions toplevelexpr expression variables params external function prototype.
Terminals def extern num ident '(' ')' ';' ',' '+' '-' '<' '*' '=' 'if' 'then' 'else' 'for' 'in'. 

Rootsymbol module.
Left 100 '+'.
Left 150 '-'.
Left 200 '*'.
Left 50 '<'.

module -> prototype module : ['$1'|'$2'].
module -> prototype : ['$1'].
module -> function module : ['$1'|'$2'].
module -> function : ['$1'].
module -> external module : ['$1'|'$2'].
module -> external : ['$1'].
module -> toplevelexpr module : ['$1'|'$2'].
module -> toplevelexpr : ['$1'].

toplevelexpr -> expressions ';' : {function, "", [], '$1'}.
prototype -> def ident '(' variables ')' ';' : {prototype, value_of('$2'), '$4'}.
function -> def ident '(' variables ')' expressions ';' : {function, value_of('$2'), '$4', '$6'}.
external -> extern ident '(' variables ')' ';' : {extern, value_of('$2'), '$4'}.

expressions -> expression : '$1'.

expression -> num : {const, value_of('$1')}.
expression -> variable : '$1'.
expression -> '(' expression ')' : '$2'.
expression -> expression '+' expression : {'+', '$1', '$3'}.
expression -> expression '-' expression : {'-', '$1', '$3'}.
expression -> expression '*' expression : {'*', '$1', '$3'}.
expression -> expression '<' expression : {'<', '$1', '$3'}.
expression -> 'if' expression 'then' expression 'else' expression : {'if', '$2','$4','$6'}.
expression -> 'for' variable '=' expression ',' expression 'in' expression : {for, '$2', '$4', '$6', undefined, '$8'}.
expression -> 'for' variable '=' expression ',' expression ',' expression 'in' expression : {for, '$2', '$4', '$6', '$8', '$10'}.
expression -> ident '(' params ')' : {call, value_of('$1'),'$3'}.

params -> expression : ['$1'].
params -> expression ',' params : ['$1'|'$3'].

variables -> variable : ['$1'].
variables -> variable ',' variables : ['$1'|'$3'].

variable -> ident : {variable, value_of('$1')}.

Erlang code.
value_of(Token) ->
    element(3, Token).
