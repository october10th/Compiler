/* This is a simpled gcc grammar */
/* Copyright (C) 1987 Free Software Foundation, Inc. */
/* BISON parser for a simplied C by Jenq-kuen Lee  Sep 20, 1993    */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"
extern int lineno;
extern FILE *f_asm;
int    errcnt=0;
int    errline=0;
char   *install_symbol();
%}


%union { 
         int       token ;
         char      charv ;
         char      *ident;
       }
/* all identifiers   that are not reserved words
   and are not declared typedefs in the current block */
%token IDENTIFIER INTEGER FLOAT

/* reserved words that specify storage class.
   yylval contains an IDENTIFIER_NODE which indicates which one.  */
%token SCSPEC

/* reserved words that specify type.
   yylval contains an IDENTIFIER_NODE which indicates which one.  */
%token TYPESPEC ENUM STRUCT UNION

/* reserved words that modify type: "const" or "volatile".
   yylval contains an IDENTIFIER_NODE which indicates which one.  */
%token TYPEMOD

%token CONSTANT

/* String constants in raw form.
   yylval is a STRING_CST node.  */
%token STRING


/* the reserved words */
%token SIZEOF  IF ELSE WHILE DO FOR SWITCH CASE DEFAULT_TOKEN
%token BREAK CONTINUE RETURN GOTO ASM

%type <ident> notype_declarator IDENTIFIER primary expr_no_commas

%type <token> CONSTANT

/* Define the operator tokens and their precedences.
   The value is an integer because, if used, it is the tree code
   to use in the expression made from the operator.  */
%left  <charv> ';'
%left IDENTIFIER  SCSPEC TYPESPEC TYPEMOD
%left  <charv> ','
// %right <charv> '='
%right <token> ASSIGN 
%right <charv> '?' ':'
%left <charv> OROR
%left <charv> ANDAND
%left <charv> '|'
%left <charv> '^'
%left <charv> '&'
%left <token> EQCOMPARE
%left <token> ARITHCOMPARE  '>' '<' 
%left <charv> LSHIFT RSHIFT
// %left <charv> '+' '-'
// %left <token> '*' '/' '%'

%right <token> UNARY PLUSPLUS MINUSMINUS 
%left HYPERUNARY 
%left <token> POINTSAT '.'
%right '='
%left '+' '-'
%left '*' '/'
%start program

%{
/* external function is defined here */
void error();
int TRACEON = 100;
%}     


%%

program: /* empty */
          { if (TRACEON) puts("empty -> program");}
	| extdefs
          { if (TRACEON) puts("extdefs -> program");}
	;

extdefs:
        extdef
          { if (TRACEON) puts("extdef -> extdefs");}
		| extdefs  extdef
        { if (TRACEON) puts("extdefs extdef -> extdefs");}
		;

extdef:
	 	TYPESPEC notype_declarator ';'
	  	{ 
	  		if (TRACEON) puts("TYPESPEC notype_declarator ';' -> extdef");
            set_global_vars($2);
        }
        | TYPESPEC notype_declarator
        {
        	if (TRACEON) puts("10");
	        cur_scope++;
	        // exchange these two
	        code_gen_func_header($2);
	        set_scope_and_offset_of_param($2);
	        
        }
        '{'  xdecls 
        {
        	if (TRACEON) puts("---xdecls---");
        	set_local_vars($2);
        }
        stmts
		{
            if (TRACEON) puts("---stmts---");
            pop_up_symbol(cur_scope);
            cur_scope--;
            code_gen_at_end_of_function_body($2);
        }
        '}'
        { puts ("notype_declarator '{'  xdecls stmts '}' -> extdef"); }
  //       | error ';' { if (TRACEON) puts("8 "); }
		// | ';' { if (TRACEON) puts("9 "); }
	;

/* Must appear precede expr for resolve precedence problem */
/* A nonempty list of identifiers.  */

/* modified */
expr_no_commas:
	primary
    {
    	if (TRACEON) puts("primary -> expr_no_commas") ;
 		$$= $1;
    }
    
    | 
	 '(' expr_no_commas ')'
		{
			if (TRACEON) puts("'(' expr_no_commas ')' -> expr_no_commas") ;
            
         	// do ??
		  	$$= NULL;
        }
    | expr_no_commas
		// {
  //   		fprintf(f_asm,"\taddi\t$r1, $r0, 0\n");
		// }
		'*' expr_no_commas
		{
			if (TRACEON) puts("expr_no_commas '*' expr_no_commas -> expr_no_commas") ;
            
         //    fprintf(f_asm,"\tlwi\t$r0, [$fp+(-16)])\n");
	        // fprintf(f_asm,"\tlwi\t$r1, [$fp+(-20)])\n");
	        fprintf(f_asm,"\tmul\t$r0, $r1, $r0\n");
	        // fprintf(f_asm,"\tswi\t$r0, [$fp+(-12)]\n");
		  	$$= NULL;
        }
    |
    	expr_no_commas
  //   	{
  //   		fprintf(f_asm,"\taddi\t$r1, $r0, 0\n");
		// }

		'/' expr_no_commas
		{
			if (TRACEON) puts("expr_no_commas '/' expr_no_commas -> expr_no_commas") ;
	        fprintf(f_asm,"\tdivsr\t$r0, $r1, $r1, $r0\n");
		  	$$= NULL;
        }
	| expr_no_commas
		// {
  //   		fprintf(f_asm,"\taddi\t$r1, $r0, 0\n");
		// }
	'+' expr_no_commas
	{ 
		// $$= NULL;
		if (TRACEON) puts("expr_no_commas '+' expr_no_commas -> expr_no_commas") ; 
        // fprintf(f_asm,"\tlwi\t$r0, [$fp+(-16)])\n");
        // fprintf(f_asm,"\tlwi\t$r1, [$fp+(-20)])\n");
        fprintf(f_asm,"\tadd\t$r0, $r1, $r0\n");
        // fprintf(f_asm,"\tswi\t$r0, [$fp+(-12)]\n");
    	$$= NULL;
    }
    | expr_no_commas
  //  	 	{

  //   		fprintf(f_asm,"\taddi\t$r1, $r0, 0\n");
		// }
    '-' expr_no_commas
	{	
		if (TRACEON) puts("expr_no_commas '-' expr_no_commas -> expr_no_commas") ; 
        // printf("%s\n", $1);
        // fprintf(f_asm,"\tlwi\t$r0, [$fp+(-16)])\n");
        // fprintf(f_asm,"\tlwi\t$r1, [$fp+(-20)])\n");
        fprintf(f_asm,"\tsub\t$r0, $r1, $r0\n");// r1 r0?
        // fprintf(f_asm,"\tswi\t$r0, [$fp+(-12)]\n");
    	$$= NULL;

    }
	
	
    |
    IDENTIFIER '=' expr_no_commas
	{
		
		if (TRACEON) puts("IDENTIFIER '=' expr_no_commas");
		
		char *s;
		int index;
		s= $1;
		if (!s) err("improper expression at LHS");
		index = look_up_symbol(s); 
		switch(table[index].mode) {
			case ARGUMENT_MODE:
				fprintf(f_asm,"\tswi\t$r0, [$fp+(-%d)]\n",(4+table[index].offset)*4);	  
			case  LOCAL_MODE:
				// fprintf(f_asm,"\tmovi\t$r0, 3\n" );// 3?
				fprintf(f_asm,"\tswi\t$r0, [$fp+(-%d)]\n",table[index].offset*4);
     		//default: /* Global Vars */
    	}
    }
	// | expr_no_commas ARITHCOMPARE expr_no_commas
	// 	{ if (TRACEON) printf("19 ") ; }
	
	;


/* modified */
primary:
        IDENTIFIER
  	{    	  
  		// int index;

  		if (TRACEON) puts("IDENTIFIER -> primary") ;

  		fprintf(f_asm,"\taddi\t$r1, $r0, 0\n");

  		int index;
		index =look_up_symbol($1);
		switch(table[index].mode) {
			case ARGUMENT_MODE:
			// fprintf(f_asm,"\tlwi\t$r1, [$fp+(-%d)]\n",table[index].offset*4+8);   
			
			// printf("argument offset = %d\n", table[index].total_locals+2+table[index].offset*4);
			fprintf(f_asm,"\tlwi\t$r0, [$fp+(-%d)]\n",(4+table[index].offset)*4);                                               
			break;
			case LOCAL_MODE:
			// fprintf(f_asm,"\tlwi\t$r1, [$fp+(-%d)]\n", table[index].offset*4+8);  
			fprintf(f_asm,"\tlwi\t$r0, [$fp+(-%d)]\n", table[index].offset*4);                                 
			break;
			//default: /* Global Vars */
		}
  		$$=$1;
    }
	| CONSTANT
    { 
    	fprintf(f_asm,"\taddi\t$r1, $r0, 0\n");
    	if (TRACEON) puts("CONSTANT -> primary") ;
		fprintf(f_asm,"\tmovi\t$r0 ,%d\n", $1);
    	// fprintf(f_asm,"\tmovi\t$r0 ,%d\n", $1);
        // fprintf(f_asm,"\tswi\t$r0, [$fp+(-12)]\n");

    }
    | IDENTIFIER '(' CONSTANT ',' CONSTANT ')'
    {
    	// function call
    	// b = sub(10,8);
    	fprintf(f_asm,"\tmovi\t$r0 ,%d\n", 10);
    	fprintf(f_asm,"\tmovi\t$r1 ,%d\n", 8);
  		
    	fprintf(f_asm,"\tjal\t%s\n", $1);
    	// fprintf(f_asm,"\tswi\t$r0, [$fp+(-%d)]\n", 20);
    	// fprintf(f_asm,"\tswi\t$r1, [$fp+(-%d)]\n", 24);

    }

    ;


// param_list:/* empty */
//     		{
//     			if (TRACEON) puts("empty -> param_list");
//     		}
// 			| expr_no_commas
// 			{
// 				if (TRACEON) puts("expr_no_commas -> param_list");
// 			}
// 			| param_list ',' expr_no_commas
// 			{if (TRACEON) puts("param_list ',' expr_no_commas -> params");}
// 			;

notype_declarator:
	  	notype_declarator '(' parmlist ')' // %prec '.'
		{   
			if (TRACEON) puts("notype_declarator '(' parmlist ')' -> notype_declarator");
		    $$=$1;
		    // int main()
		    // int sub(int x, int y)
        }                  
        | IDENTIFIER
		{   
			if (TRACEON) puts("IDENTIFIER -> notype_declarator");
            $$=install_symbol($1);
            // install decls
            // install x, y
        }                  
	;

/* This is what appears inside the parens in a function declarator.
   Is value is represented in the format that grokdeclarator expects.  */
parmlist: 
	/* empty */
   	{ if (TRACEON) puts("empty -> parmlist") ; }
		
	| parmlist ',' parm
  		{
  			if (TRACEON) puts("parmlist ',' parm -> parmlist") ;
  		}
	| parm
  		{ if (TRACEON) puts("parm -> parmlist");  }
	;

// /* A nonempty list of parameter declarations or type names.  */
// parms:	
// 	parm
//   		{ if (TRACEON) puts("parm -> parms");  }
// 	| parms ',' parm
//   		{ if (TRACEON) puts("parms ',' parm -> parms");  }
	
// 	;

parm:
	  TYPESPEC notype_declarator
  		{
  			if (TRACEON) puts("TYPESPEC notype_declarator -> parm");
  		}
   ;


/* at least one statement, the first of which parses without error.  */
/* stmts is used only after decls, so an invalid first statement
   is actually regarded as an invalid decl and part of the decls.  */

stmts:
	stmt
               { if (TRACEON) puts("stmt -> stmts") ;  }
	| stmts stmt
               { if (TRACEON) puts("stmts stmt -> stmts") ;  }
	;


/* modified */
stmt:
	expr_no_commas ';'
	{
		puts("expr_no_commas ';' -> stmt");
		// do sth?
		// fprintf(f_asm,"        pop  cx\n");
		// fprintf(f_asm,"   ;\n");
    }
    |
    RETURN expr_no_commas ';'
    {

    	puts("RETURN expr_no_commas ';' -> stmt");
    }
	;


xdecls:
	/* empty */
           { if (TRACEON) printf("102 ") ; }
	| decls
           { if (TRACEON) printf("103 ") ; }
	;

decls:
	declists
           { if (TRACEON) puts("declists -> decls");
           }
	| decls declists
           { if (TRACEON) puts("decls declists -> decls");
           }
	;
declists: TYPESPEC declist ';'
         { if (TRACEON) puts("TYPESPEC declist ';' -> declists");}
      
      ;
declist: decl
         { if (TRACEON) puts("decl -> declist");}
		|
		decl ',' declist
		{
			if (TRACEON) puts("decl ',' declist -> declist");
		}
      ;
decl: notype_declarator
         {
         	if (TRACEON) puts("notype_declarator -> decl");
         }
      |
      notype_declarator '=' expr_no_commas
         {
         	if (TRACEON) puts("notype_declarator '=' expr_no_commas -> decl");
         	char *s;
			int index;
			s= $1;
			printf("notype_declarator (%s)\n", s);
			if (!s) err("improper expression at LHS");
			index = look_up_symbol(s); 
			// fprintf(f_asm,"\tswi\t$r0, [$fp+(-%d)]\n",table[index].offset*4+8);
			fprintf(f_asm,"\tswi\t$r0, [$fp+(-%d)]\n",table[index].offset*4);
         }
      ;


%%


/*
 *	  s - the error message to be printed
 */
void 
yyerror(s)
	char   *s;
{
	err(s);
}


err(s)
char   *s;
{
	if (! errcnt++)
		errline = lineno;
         fprintf(stderr,"Error on line %d \n",lineno);
	
	exit(1);
}




