%option noyywrap

%{
	#include<stdio.h>
	#include "y.tab.h"
%}

%%

[a|A]				{printf("Found protein Adenine\n"); return yytext[0];}
[t|T]				{printf("Found protein Thyamine\n"); return yytext[0];}
[g|G]				{printf("Found protein Guanine\n"); return yytext[0];}
[c|C]				{printf("Found protein Cytosine\n"); return yytext[0];}
[,]				{printf("Found ','. Waiting to find next pair\n");return yytext[0];}
[$]				{printf("String end\n");return yytext[0];}
[\t\b\f\n\v]			{;}
[.]				{printf("Unknown Character\n");return yytext[0];}

%%