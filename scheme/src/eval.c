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

 	switch (input->type) 
	{
 	
		case SFS_CHARACTER:  
		return input;
		break;
	
		case SFS_STRING:
		return input;
		break;  
		    
		case SFS_NIL:
		return input;
		break;
		       
		case SFS_SYMBOL:
		return input;   
		break;

		case SFS_BOOLEAN:
		return input;  
		break;
	
		case SFS_PAIR; 
		break;  

	

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


	if (is_and(input))
	{
		obj=cdr(obj) /* recupere les arguments*/
		while (obj !())
		{
			if (cdr(obj)== FALSE)
			return FALSE;
			obj=cdr (obj); /* passage a l'argument suivent*/
		}
		return TRUE;

	}

	if(is_quote(input))
	{




	}







	/*  return input; */
}

