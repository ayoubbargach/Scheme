
/**
 * @file object.c
 * @author François Cayre <cayre@yiking.(null)>
 * @date Fri Jun 15 18:02:57 2012
 * @brief Object definitions for SFS.
 *
 * Object definitions for SFS.
 */

#include "object.h"
#include "mem.h"


object make_object( uint type ) {

    object t = sfs_malloc( sizeof( *t ) );
    t->type = type;
    return t;
}

object make_nil( void ) {

    object t = make_object( SFS_NIL );
    t->this.special = t; /* fonction qui cree l'objet empty_list*/
    return t;
}

/* objet make_emptylist(void) meme chose que make_nil*/

object make_boolean ( void ) 
{
	object t = make_object ( SFS_BOOLEAN);
	t -> this.boolean = t;
	return t;

}

object make_symbol(string s) {				 /* le type string est defini dans objet.h comme une chaine de carractere*/
object t=make_object(SFS_SYMBOL);
strcpy( t->this.symbol, s ); 				/* on recopie la chaine de carractere s dans t->this.symbol */
return t;

}

object make_integer( int x ) 
{ 				/* le type num est defini dans objet.h */
object t=make_object(SFS_NUMBER); /* le type SFS_INTEGER est inclu dans SFS_NUMBER*/
t->this.number.numtype=NUM_INTEGER;
t->this.number.this.integer=x;
return t;
}

object make_real( double x ) 
{ 				/* le type num est defini dans objet.h */
object t=make_object(SFS_NUMBER); /* le type SFS_INTEGER est inclu dans SFS_NUMBER*/
t->this.number.numtype=NUM_REAL;
t->this.number.this.real=x;
return t;
}

object make_character (char c){
object t=make_object(SFS_CHARACTER);
t->this.character=c; 
return t;
}


object make_pair (object p, object l){
object t=make_object(SFS_PAIR);
t->this.pair.car= p;
t->this.pair.cdr= l;
return t;
}

object make_string (string st) {
object t=make_object(SFS_STRING);
strcpy( t->this.string,st); /* comme il s'agit de chaine de carractere in ne peut pas les copier directement*/
return t;
}
