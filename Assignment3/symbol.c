
/*
   This is a very simple c compiler written by Prof. Jenq Kuen Lee,
   Department of Computer Science, National Tsing-Hua Univ., Taiwan,
   Fall 1995.

   This is used in compiler class.
   This file contains Symbol Table Handling.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"

extern FILE *f_asm;
int cur_counter = 0;
int cur_scope   = 1;
char *copys();

// me
int cur_fp=0;




/*

  init_symbol_table();

*/
init_symbol_table()
{

  bzero(&table[0], sizeof(struct symbol_entry)*MAX_TABLE_SIZE);

}

/*
   To install a symbol in the symbol table 

*/
char  *
install_symbol(s)
char *s;
{
	printf("install_symbol %s\n", s);
	if (cur_counter >= MAX_TABLE_SIZE)
		err("Symbol Table Full");
	else {
		table[cur_counter].scope = cur_scope;
		table[cur_counter].name = copys(s);
		// table[cur_counter].offset = cur_scope;
		table[cur_counter].offset = cur_counter-cur_fp+3;
		cur_counter++;
	}
	return(s);
}



/*
   To return an integer as an index of the symbol table

*/
int
look_up_symbol(s)
char *s;
{
   int i;

   if (cur_counter==0) return(-1);
   for (i=cur_counter-1;i>=0; i--)
     {
       if (!strcmp(s,table[i].name))
	 		return(i);
     }
   return(-1);
 }


/*
   Pop up symbols of the given scope from the symbol table upon the
   exit of a given scope.

*/
void
pop_up_symbol(scope)
int scope;
{
   int i;
   if (cur_counter==0) return;
   for (i=cur_counter-1;i>=0; i--)
     {
       if (table[i].scope !=scope) break;
     }
   if (i<0) cur_counter = 0;
   cur_counter = i+1;
  
}



/*
   Set up parameter scope and offset

*/
set_scope_and_offset_of_param(s)
char *s;// s: function name e.g. main, sub..
{
	printf("set_scope_and_offset_of_param %s\n", s);
	int i,j,index;
	int total_args;

	index = look_up_symbol(s);
	if (index<0) err("Error in function header");
	else {

		// e.g. sub(x, y) -> x, y
		table[index].type = T_FUNCTION;
		total_args = cur_counter -index -1;
		table[index].total_args=total_args;
		for (j=total_args, i=cur_counter-1;i>index; i--,j--)
		{
			printf("i = %d j = %d name = %s\n", i, j, table[i].name);
			table[i].scope= cur_scope;
			table[i].offset= j;
			table[i].mode  = ARGUMENT_MODE;
		}
		for(i=0;i<total_args;i++)
			fprintf(f_asm,"\tswi\t$r%d, [$fp+(-%d)]\n",i, (i+5)*4);
	}
	// me 
	cur_fp=cur_counter;


}



/*
   Set up local var offset

*/
set_local_vars(functor)
char *functor;// function name e.g. main
{
	printf("set_local_vars %s\n", functor);
	int i,j,index,index1;
	int total_locals;

	index = look_up_symbol(functor);
	index1 = index + table[index].total_args;
	total_locals= cur_counter -index1 -1;
	if (total_locals <0)
		err("Error in number of local variables");
	table[index].total_locals=total_locals;
	printf("total_lacals = %d\n", total_locals);
	for (j=total_locals, i=cur_counter-1;j>0; i--,j--)
	{
		printf("i = %d j(offset?) = %d name = %s offset = %d\n", i, j, table[i].name, table[i].offset);
		table[i].scope= cur_scope;
		// table[i].offset= j;
		table[i].mode  = LOCAL_MODE;
	}
	// for (j=table[index].total_args-1, i=index+1;j>=0; i++,j--)
	// {
		
	// 	// table[i].scope= cur_scope;
	// 	table[i].offset+=total_locals+cur_fp;
	// 	printf("i = %d j = %d name = %s offset = %d\n", i, j, table[i].name, table[i].offset);
	// 	// table[i].mode  = ARGUMENT_MODE;
	// }
}



/*
  Set GLOBAL_MODE to global variables

*/

set_global_vars(s)
char *s;
{
  int index;
  index =look_up_symbol(s);
  table[index].mode = GLOBAL_MODE;
  table[index].scope =1;
}


/*

To generate house-keeping work at the beginning of the function

*/

code_gen_func_header(function) // just print
char *function;
{
	puts("code_gen_func_header");
	// fprintf(f_asm,"\t.text\n");
	fprintf(f_asm,"\t.align\t2\n");
	fprintf(f_asm,"\t.global\t%s\n",function);
	fprintf(f_asm,"\t.type\t%s, @function\n",function);
	fprintf(f_asm,"%s:\n",function);
	fprintf(f_asm,"\tpush.s\t{ $fp $lp }\n");
	fprintf(f_asm,"\taddi\t$fp, $sp, 8\n");
	fprintf(f_asm,"\taddi\t$sp, $sp, -16\n");
	// fprintf(f_asm,"\taddi\t$sp, $fp, -16\n"); ???


}

/*

  To generate global symbol vars

*/
code_gen_global_vars()
{
  int i;

  // fprintf(f_asm,"_BSS     segment word public 'BSS'\n");
  for (i=0; i<cur_counter; i++)
     {
       if (table[i].mode == GLOBAL_MODE)
	 {
            // fprintf(f_asm,"_%s	label	word\n",table[i].name);
            // fprintf(f_asm,"	db	2 dup (?)\n");
         }
     }
 // fprintf(f_asm,"_BSS    ends\n");


}


/*

 To geenrate house-keeping work at the end of a function

*/

code_gen_at_end_of_function_body(function) // just print
char *function;
{
  // int i;
	fprintf(f_asm,"\taddi\t$sp, $fp, -8\n");
	fprintf(f_asm,"\tpop.s\t{ $fp $lp }\n");
	fprintf(f_asm,"\tret\n");
	fprintf(f_asm,"\t.size\t%s, .-%s\n", function, function);
	// fprintf(f_asm,"\t.ident	\"GCC: (GNU) 4.9.0\"\n");
	
}





/*******************Utility Functions ********************/
/*
 * copyn -- makes a copy of a string with known length
 *
 * input:
 *	  n - lenght of the string "s"
 *	  s - the string to be copied
 *
 * output:
 *	  pointer to the new string
 */

char   *
copyn(n, s)
	register int n;
	register char *s;
{
	register char *p, *q;
	// char   *calloc();

	p = q = calloc(1,n*sizeof(char));
	while (--n >= 0)
		*q++ = *s++;
	return (p);
}


/*
 * copys -- makes a copy of a string
 *
 * input:
 *	  s - string to be copied
 *
 * output:
 *	  pointer to the new string
 */
char   *
copys(s)
	char   *s;
{
	return (copyn(strlen(s) + 1, s));
}






