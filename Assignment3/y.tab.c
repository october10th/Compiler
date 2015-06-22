#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 5 "101062113_hw3.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"
extern int lineno;
extern FILE *f_asm;
int    errcnt=0;
int    errline=0;
char   *install_symbol();
#line 17 "101062113_hw3.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { 
         int       token ;
         char      charv ;
         char      *ident;
       } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 78 "101062113_hw3.y"
/* external function is defined here */
void error();
int TRACEON = 100;
#line 46 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IDENTIFIER 257
#define INTEGER 258
#define FLOAT 259
#define SCSPEC 260
#define TYPESPEC 261
#define ENUM 262
#define STRUCT 263
#define UNION 264
#define TYPEMOD 265
#define CONSTANT 266
#define STRING 267
#define SIZEOF 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define DO 272
#define FOR 273
#define SWITCH 274
#define CASE 275
#define DEFAULT_TOKEN 276
#define BREAK 277
#define CONTINUE 278
#define RETURN 279
#define GOTO 280
#define ASM 281
#define ASSIGN 282
#define OROR 283
#define ANDAND 284
#define EQCOMPARE 285
#define ARITHCOMPARE 286
#define LSHIFT 287
#define RSHIFT 288
#define UNARY 289
#define PLUSPLUS 290
#define MINUSMINUS 291
#define HYPERUNARY 292
#define POINTSAT 293
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    4,    4,    5,    6,    9,   10,    5,    5,
    5,    3,    3,   11,    3,   12,    3,   13,    3,   14,
    3,    3,    3,    2,    2,    2,    2,    2,   15,   15,
   16,   16,    1,    1,   17,   17,   18,   18,   19,    8,
    8,   20,   20,    7,    7,   21,   21,   22,   23,   23,
   24,   24,
};
static const short yylen[] = {                            2,
    0,    1,    1,    2,    3,    0,    0,    0,    9,    2,
    1,    1,    3,    0,    4,    0,    4,    0,    4,    0,
    4,    3,    3,    1,    1,    4,    1,    2,    0,    1,
    1,    3,    4,    1,    0,    1,    1,    3,    2,    1,
    2,    2,    3,    0,    1,    1,    2,    3,    1,    3,
    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,   11,    0,    0,    3,   10,   34,    0,    4,
    5,    0,    0,    0,    0,    0,   37,    0,    0,   33,
    0,    0,    7,    0,   46,   38,    0,    0,    0,    0,
   47,    0,   48,    0,    0,   25,   27,    0,    0,    0,
    0,    0,   40,    0,   50,    0,    0,    0,   28,   42,
    0,    0,    0,    0,    0,    0,    0,   41,    0,    0,
   30,   43,   13,    0,    0,    0,    0,    0,    0,    9,
    0,   26,    0,    0,    0,    0,   32,
};
static const short yydgoto[] = {                          4,
   27,   40,   41,    5,    6,   13,   23,   42,   30,   57,
   53,   54,   55,   56,   60,   61,   15,   16,   17,   43,
   24,   25,   28,   29,
};
static const short yysindex[] = {                       -36,
  -33, -213,    0,    0,  -36,    0,    0,    0,    9,    0,
    0, -210,  -71, -213,   13,   26,    0, -190,   32,    0,
 -210, -213,    0, -190,    0,    0,  -21,   16,   48,  -35,
    0,    5,    0, -213,   53,    0,    0,    5,    5, -193,
  -47,  -35,    0,  -40,    0,    5,  -44,  -19,    0,    0,
    5,    5,   56,   52,   58,   55,  -20,    0,  -28,   66,
    0,    0,    0,  -40,    0,    5,    5,    5,    5,    0,
    5,    0,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                       110,
    0,    0,    0,    0,  116,    0,    0,    0,   -5,    0,
    0,   78,    0,    0,    0,   79,    0,  -16,    6,    0,
    0,    0,    0,    3,    0,    0,   47,    0,   62,    0,
    0,    0,    0,    0,  -41,    0,    0,    0,    0,  -34,
   95,   -3,    0,   35,    0,   86,   95,   95,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   89,    0,
    0,    0,    0,   70,  -13,    0,    0,    0,    0,    0,
    0,    0,   -6,   15,   22,   43,    0,
};
static const short yygindex[] = {                         0,
   59,    0,   57,    0,  128,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   64,    0,    0,  118,   99,
    0,  119,  111,    0,
};
#define YYTABLESIZE 329
static const short yytable[] = {                         24,
   24,   24,   24,   24,   39,   24,   12,   12,   12,   12,
   12,   50,   12,   51,   62,   71,   51,   24,   12,   24,
   51,   63,    3,   44,   12,    7,   12,   23,   14,   18,
   23,   20,   51,   16,   15,   14,   15,   15,   15,   32,
   15,   51,   45,    8,   39,   23,   39,   23,   12,   39,
   14,   18,   15,   20,   15,   17,   14,   17,   17,   17,
    9,   16,   19,   14,   18,   19,   19,   11,   16,   21,
   22,   12,   19,   17,   33,   17,   14,   18,   52,   20,
   19,   16,   19,   21,   14,   18,   21,   20,   44,   16,
   51,   34,   46,   52,   47,   48,   49,   66,   67,   69,
   68,   21,   59,   21,   70,   51,   72,   64,   65,    1,
   22,   14,   18,   22,   20,    2,   16,    6,   35,   36,
   49,    8,   73,   74,   75,   76,   29,   59,   22,   31,
   14,   18,   10,   20,   77,   16,   14,   18,   26,   20,
   58,   16,   31,    0,   45,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,   35,    0,    0,    2,    0,    0,    0,    0,    0,
   36,   37,    0,    0,    0,    0,    0,    0,   52,    0,
   44,   52,    0,   38,   24,   52,    0,    0,   24,   44,
   44,   12,    0,    0,    0,    0,    0,   52,    0,   45,
    0,   35,   44,    0,    0,    0,   52,    0,   45,   45,
   36,   37,   23,    0,    0,    0,    0,    0,    0,   15,
    0,   45,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   17,    0,    0,    0,    0,    0,    0,   19,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   21,
};
static const short yycheck[] = {                         41,
   42,   43,   44,   45,   40,   47,   41,   42,   43,   44,
   45,   59,   47,   61,   59,   44,   61,   59,   40,   61,
   61,   41,   59,   40,   59,   59,   61,   41,   42,   43,
   44,   45,   61,   47,   41,   42,   43,   44,   45,   61,
   47,   61,   40,  257,   40,   59,   41,   61,   40,   44,
  261,  123,   59,   41,   61,   41,   42,   43,   44,   45,
    2,   47,   41,   42,   43,   44,   45,   59,   47,   44,
  261,   40,   14,   59,   59,   61,   42,   43,   44,   45,
   59,   47,   61,   41,   42,   43,   44,   45,   32,   47,
   44,   44,   40,   59,   38,   39,  290,   42,   47,   45,
   43,   59,   46,   61,  125,   59,   41,   51,   52,    0,
   41,   42,   43,   44,   45,    0,   47,  123,   41,   41,
   59,  125,   66,   67,   68,   69,   41,   71,   59,   41,
   42,   43,    5,   45,   71,   47,   42,   43,   21,   45,
   42,   47,   24,   -1,   34,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  256,
   -1,  257,   -1,   -1,  261,   -1,   -1,   -1,   -1,   -1,
  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,  286,   -1,
  257,  286,   -1,  279,  286,  286,   -1,   -1,  290,  266,
  267,  286,   -1,   -1,   -1,   -1,   -1,  286,   -1,  257,
   -1,  257,  279,   -1,   -1,   -1,  286,   -1,  266,  267,
  266,  267,  286,   -1,   -1,   -1,   -1,   -1,   -1,  286,
   -1,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  286,   -1,   -1,   -1,   -1,   -1,   -1,  286,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 293
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,
0,0,0,0,"':'","';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IDENTIFIER","INTEGER","FLOAT",
"SCSPEC","TYPESPEC","ENUM","STRUCT","UNION","TYPEMOD","CONSTANT","STRING",
"SIZEOF","IF","ELSE","WHILE","DO","FOR","SWITCH","CASE","DEFAULT_TOKEN","BREAK",
"CONTINUE","RETURN","GOTO","ASM","ASSIGN","OROR","ANDAND","EQCOMPARE",
"ARITHCOMPARE","LSHIFT","RSHIFT","UNARY","PLUSPLUS","MINUSMINUS","HYPERUNARY",
"POINTSAT","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : program",
"program :",
"program : extdefs",
"extdefs : extdef",
"extdefs : extdefs extdef",
"extdef : TYPESPEC notype_declarator ';'",
"$$1 :",
"$$2 :",
"$$3 :",
"extdef : TYPESPEC notype_declarator $$1 '{' xdecls $$2 stmts $$3 '}'",
"extdef : error ';'",
"extdef : ';'",
"expr_no_commas : primary",
"expr_no_commas : '(' expr_no_commas ')'",
"$$4 :",
"expr_no_commas : expr_no_commas $$4 '*' expr_no_commas",
"$$5 :",
"expr_no_commas : expr_no_commas $$5 '/' expr_no_commas",
"$$6 :",
"expr_no_commas : expr_no_commas $$6 '+' expr_no_commas",
"$$7 :",
"expr_no_commas : expr_no_commas $$7 '-' expr_no_commas",
"expr_no_commas : expr_no_commas '=' expr_no_commas",
"expr_no_commas : expr_no_commas ARITHCOMPARE expr_no_commas",
"primary : IDENTIFIER",
"primary : CONSTANT",
"primary : IDENTIFIER '(' param_list ')'",
"primary : STRING",
"primary : primary PLUSPLUS",
"param_list :",
"param_list : params",
"params : expr_no_commas",
"params : expr_no_commas ',' params",
"notype_declarator : notype_declarator '(' parmlist ')'",
"notype_declarator : IDENTIFIER",
"parmlist :",
"parmlist : parms",
"parms : parm",
"parms : parms ',' parm",
"parm : TYPESPEC notype_declarator",
"stmts : stmt",
"stmts : stmts stmt",
"stmt : expr_no_commas ';'",
"stmt : RETURN expr_no_commas ';'",
"xdecls :",
"xdecls : decls",
"decls : declists",
"decls : decls declists",
"declists : TYPESPEC declist ';'",
"declist : decl",
"declist : decl ',' declist",
"decl : notype_declarator",
"decl : notype_declarator '=' expr_no_commas",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 443 "101062113_hw3.y"


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




#line 384 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 87 "101062113_hw3.y"
	{ if (TRACEON) puts("empty -> program");}
break;
case 2:
#line 89 "101062113_hw3.y"
	{ if (TRACEON) puts("extdefs -> program");}
break;
case 3:
#line 94 "101062113_hw3.y"
	{ if (TRACEON) puts("extdef -> extdefs");}
break;
case 4:
#line 96 "101062113_hw3.y"
	{ if (TRACEON) puts("extdefs extdef -> extdefs");}
break;
case 5:
#line 101 "101062113_hw3.y"
	{ 
	  		if (TRACEON) puts("TYPESPEC notype_declarator ';' -> extdef");
            set_global_vars(yystack.l_mark[-1].ident);
        }
break;
case 6:
#line 106 "101062113_hw3.y"
	{
        	if (TRACEON) puts("10");
	        cur_scope++;
	        /* exchange these two*/
	        code_gen_func_header(yystack.l_mark[0].ident);
	        set_scope_and_offset_of_param(yystack.l_mark[0].ident);
	        
        }
break;
case 7:
#line 115 "101062113_hw3.y"
	{
        	if (TRACEON) puts("---xdecls---");
        	set_local_vars(yystack.l_mark[-3].ident);
        }
break;
case 8:
#line 120 "101062113_hw3.y"
	{
            if (TRACEON) puts("---stmts---");
            pop_up_symbol(cur_scope);
            cur_scope--;
            code_gen_at_end_of_function_body(yystack.l_mark[-5].ident);
        }
break;
case 9:
#line 127 "101062113_hw3.y"
	{ puts ("notype_declarator '{'  xdecls stmts '}' -> extdef"); }
break;
case 10:
#line 128 "101062113_hw3.y"
	{ if (TRACEON) puts("8 "); }
break;
case 11:
#line 129 "101062113_hw3.y"
	{ if (TRACEON) puts("9 "); }
break;
case 12:
#line 138 "101062113_hw3.y"
	{
    	if (TRACEON) puts("primary -> expr_no_commas") ;
 		yyval.ident= yystack.l_mark[0].ident;
    }
break;
case 13:
#line 145 "101062113_hw3.y"
	{
			if (TRACEON) puts("'(' expr_no_commas ')' -> expr_no_commas") ;
            
         	/* do ??*/
		  	yyval.ident= NULL;
        }
break;
case 14:
#line 152 "101062113_hw3.y"
	{
    		fprintf(f_asm,"\taddi\t$r1, $r0, 0\n");
		}
break;
case 15:
#line 156 "101062113_hw3.y"
	{
			if (TRACEON) puts("expr_no_commas '*' expr_no_commas -> expr_no_commas") ;
            
         /*    fprintf(f_asm,"\tlwi\t$r0, [$fp+(-16)])\n");*/
	        /* fprintf(f_asm,"\tlwi\t$r1, [$fp+(-20)])\n");*/
	        fprintf(f_asm,"\tmul\t$r0, $r1, $r0\n");
	        /* fprintf(f_asm,"\tswi\t$r0, [$fp+(-12)]\n");*/
		  	yyval.ident= NULL;
        }
break;
case 16:
#line 167 "101062113_hw3.y"
	{
    		fprintf(f_asm,"\taddi\t$r1, $r0, 0\n");
		}
break;
case 17:
#line 172 "101062113_hw3.y"
	{
			if (TRACEON) puts("expr_no_commas '/' expr_no_commas -> expr_no_commas") ;
	        fprintf(f_asm,"\tdivsr\t$r0, $r1, $r1, $r0\n");
		  	yyval.ident= NULL;
        }
break;
case 18:
#line 178 "101062113_hw3.y"
	{
    		fprintf(f_asm,"\taddi\t$r1, $r0, 0\n");
		}
break;
case 19:
#line 182 "101062113_hw3.y"
	{ 
		/* $$= NULL;*/
		if (TRACEON) puts("expr_no_commas '+' expr_no_commas -> expr_no_commas") ; 
        /* fprintf(f_asm,"\tlwi\t$r0, [$fp+(-16)])\n");*/
        /* fprintf(f_asm,"\tlwi\t$r1, [$fp+(-20)])\n");*/
        fprintf(f_asm,"\tadd\t$r0, $r1, $r0\n");
        /* fprintf(f_asm,"\tswi\t$r0, [$fp+(-12)]\n");*/
    	yyval.ident= NULL;

  /*   	int index1, index2;*/
  /*   	char *s1, *s2;*/
  /*   	s1=$1;*/
  /*   	s2=$3;*/
		/* if (!s1) err("improper expression at LHS");*/
		/* index1 = look_up_symbol(s1);	*/
		/* if (!s2) err("improper expression at LHS");*/
		/* index2 = look_up_symbol(s2);*/
		/* fprintf(f_asm,"\tlwi  $r2, [$fp+(-%d)]\n",table[index1].offset*4);*/
		/* fprintf(f_asm,"\tlwi  $r1, [$fp+(-%d)]\n",table[index2].offset*4);*/
		/* fprintf(f_asm,"\tadd  $r1, $r2, $r1\n");*/
		/* $$= NULL;*/

    }
break;
case 20:
#line 206 "101062113_hw3.y"
	{

    		fprintf(f_asm,"\taddi\t$r1, $r0, 0\n");
		}
break;
case 21:
#line 211 "101062113_hw3.y"
	{	
		if (TRACEON) puts("expr_no_commas '-' expr_no_commas -> expr_no_commas") ; 
        /* printf("%s\n", $1);*/
        /* fprintf(f_asm,"\tlwi\t$r0, [$fp+(-16)])\n");*/
        /* fprintf(f_asm,"\tlwi\t$r1, [$fp+(-20)])\n");*/
        fprintf(f_asm,"\tsub\t$r0, $r1, $r0\n");/* r1 r0?*/
        /* fprintf(f_asm,"\tswi\t$r0, [$fp+(-12)]\n");*/
    	yyval.ident= NULL;

    }
break;
case 22:
#line 225 "101062113_hw3.y"
	{
		
		if (TRACEON) puts("expr_no_commas '=' expr_no_commas");
		
		char *s;
		int index;
		s= yystack.l_mark[-2].ident;
		if (!s) err("improper expression at LHS");
		index = look_up_symbol(s); 
		switch(table[index].mode) {
			case ARGUMENT_MODE:
				fprintf(f_asm,"\tswi\t$r0, [$fp+(-%d)]\n",(4+table[index].offset)*4);	  
			case  LOCAL_MODE:
				/* fprintf(f_asm,"\tmovi\t$r0, 3\n" );// 3?*/
				fprintf(f_asm,"\tswi\t$r0, [$fp+(-%d)]\n",table[index].offset*4);
     		/*default: /* Global Vars * /*/
    	}
    }
break;
case 23:
#line 244 "101062113_hw3.y"
	{ if (TRACEON) printf("19 ") ; }
break;
case 24:
#line 251 "101062113_hw3.y"
	{    	  
  		/* int index;*/

  		if (TRACEON) puts("IDENTIFIER -> primary") ;

  		

  		int index;
		index =look_up_symbol(yystack.l_mark[0].ident);
		switch(table[index].mode) {
			case ARGUMENT_MODE:
			/* fprintf(f_asm,"\tlwi\t$r1, [$fp+(-%d)]\n",table[index].offset*4+8);   */
			
			/* printf("argument offset = %d\n", table[index].total_locals+2+table[index].offset*4);*/
			fprintf(f_asm,"\tlwi\t$r0, [$fp+(-%d)]\n",(4+table[index].offset)*4);                                               
			break;
			case LOCAL_MODE:
			/* fprintf(f_asm,"\tlwi\t$r1, [$fp+(-%d)]\n", table[index].offset*4+8);  */
			fprintf(f_asm,"\tlwi\t$r0, [$fp+(-%d)]\n", table[index].offset*4);                                 
			break;
			/*default: /* Global Vars * /*/
		}
  		yyval.ident=yystack.l_mark[0].ident;
    }
break;
case 25:
#line 276 "101062113_hw3.y"
	{ 
    	if (TRACEON) puts("CONSTANT -> primary") ;
		fprintf(f_asm,"\tmovi\t$r0 ,%d\n", yystack.l_mark[0].token);
    	/* fprintf(f_asm,"\tmovi\t$r0 ,%d\n", $1);*/
        /* fprintf(f_asm,"\tswi\t$r0, [$fp+(-12)]\n");*/

    }
break;
case 26:
#line 284 "101062113_hw3.y"
	{
    	/* function call*/
    	/* b = sub(10,8);*/
    	/* fprintf(f_asm,"\tmovi\t$r0 ,%d\n", 10);*/
    	/* fprintf(f_asm,"\tmovi\t$r1 ,%d\n", 8);*/
  		
    	fprintf(f_asm,"\tjal\t%s\n", yystack.l_mark[-3].ident);
    	/* fprintf(f_asm,"\tswi\t$r0, [$fp+(-%d)]\n", 20);*/
    	/* fprintf(f_asm,"\tswi\t$r1, [$fp+(-%d)]\n", 24);*/

    }
break;
case 27:
#line 296 "101062113_hw3.y"
	{ 
		if (TRACEON) puts("STRING -> primary") ;
    }
break;
case 28:
#line 300 "101062113_hw3.y"
	{ 
	  if (TRACEON) puts("primary PLUSPLUS -> primary") ;
    }
break;
case 29:
#line 305 "101062113_hw3.y"
	{
    			if (TRACEON) puts("empty -> param_list");
    		}
break;
case 30:
#line 309 "101062113_hw3.y"
	{
				if (TRACEON) puts("params -> param_list");
			}
break;
case 31:
#line 314 "101062113_hw3.y"
	{
			if (TRACEON) puts("expr_no_commas -> params");}
break;
case 32:
#line 317 "101062113_hw3.y"
	{if (TRACEON) puts("expr_no_commas ',' params -> params");}
break;
case 33:
#line 321 "101062113_hw3.y"
	{   
			if (TRACEON) puts("notype_declarator '(' parmlist ')' -> notype_declarator");
		    yyval.ident=yystack.l_mark[-3].ident;
		    /* int main()*/
		    /* int sub(int x, int y)*/
        }
break;
case 34:
#line 328 "101062113_hw3.y"
	{   
			if (TRACEON) puts("IDENTIFIER -> notype_declarator");
            yyval.ident=install_symbol(yystack.l_mark[0].ident);
            /* install decls*/
            /* install x, y*/
        }
break;
case 35:
#line 340 "101062113_hw3.y"
	{ if (TRACEON) puts("empty -> parmlist") ; }
break;
case 36:
#line 343 "101062113_hw3.y"
	{
  			if (TRACEON) puts("parms -> parmlist") ;
  		}
break;
case 37:
#line 352 "101062113_hw3.y"
	{ if (TRACEON) puts("parm -> parms");  }
break;
case 38:
#line 354 "101062113_hw3.y"
	{ if (TRACEON) puts("parms ',' parm -> parms");  }
break;
case 39:
#line 359 "101062113_hw3.y"
	{
  			if (TRACEON) puts("TYPESPEC notype_declarator -> parm");
  		}
break;
case 40:
#line 371 "101062113_hw3.y"
	{ if (TRACEON) puts("stmt -> stmts") ;  }
break;
case 41:
#line 373 "101062113_hw3.y"
	{ if (TRACEON) puts("stmts stmt -> stmts") ;  }
break;
case 42:
#line 380 "101062113_hw3.y"
	{
		puts("expr_no_commas ';' -> stmt");
		/* do sth?*/
		/* fprintf(f_asm,"        pop  cx\n");*/
		/* fprintf(f_asm,"   ;\n");*/
    }
break;
case 43:
#line 388 "101062113_hw3.y"
	{

    	puts("RETURN expr_no_commas ';' -> stmt");
    }
break;
case 44:
#line 397 "101062113_hw3.y"
	{ if (TRACEON) printf("102 ") ; }
break;
case 45:
#line 399 "101062113_hw3.y"
	{ if (TRACEON) printf("103 ") ; }
break;
case 46:
#line 404 "101062113_hw3.y"
	{ if (TRACEON) puts("declists -> decls");
           }
break;
case 47:
#line 407 "101062113_hw3.y"
	{ if (TRACEON) puts("decls declists -> decls");
           }
break;
case 48:
#line 411 "101062113_hw3.y"
	{ if (TRACEON) puts("TYPESPEC declist ';' -> declists");}
break;
case 49:
#line 415 "101062113_hw3.y"
	{ if (TRACEON) puts("decl -> declist");}
break;
case 50:
#line 418 "101062113_hw3.y"
	{
			if (TRACEON) puts("decl ',' declist -> declist");
		}
break;
case 51:
#line 423 "101062113_hw3.y"
	{
         	if (TRACEON) puts("notype_declarator -> decl");
         }
break;
case 52:
#line 428 "101062113_hw3.y"
	{
         	if (TRACEON) puts("notype_declarator '=' expr_no_commas -> decl");
         	char *s;
			int index;
			s= yystack.l_mark[-2].ident;
			printf("notype_declarator (%s)\n", s);
			if (!s) err("improper expression at LHS");
			index = look_up_symbol(s); 
			/* fprintf(f_asm,"\tswi\t$r0, [$fp+(-%d)]\n",table[index].offset*4+8);*/
			fprintf(f_asm,"\tswi\t$r0, [$fp+(-%d)]\n",table[index].offset*4);
         }
break;
#line 975 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
