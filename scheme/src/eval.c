
/**
 * @file eval.c
 * @author François Cayre <cayre@yiking.(null)>
 * @date Fri Jun 22 20:11:30 2012
 * @brief Evaluation stuff for SFS.
 *
 * Evaluation stuff for SFS.
 */

#include "eval.h"

object sfs_eval( object input )
 {
/* fonction eval recursive */
/*
	input= cdr (input);
	while ( input !() )
		{
		if (car (input))
			{
			if (eval(car (input)) == FALSE)
				{
				return FALSE; 
				}
			object = cdr(input);
			return TRUE;
			}
		}
	}

 if (is_if(input))
	 {
	object = cdr(input);
		{
		if(eval(car(input)==TRUE))
			{
			return eval(car(cdr(input)));
			}
		}
	return eval (car(cdr(cdr(input))));
	}
*/

   return input; 

 }

