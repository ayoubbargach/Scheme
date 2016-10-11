
/**
 * @file print.c
 * @author François Cayre <cayre@yiking.(null)>
 * @date Fri Jun 22 20:12:17 2012
 * @brief Printing stuff for SFS.
 *
 * Printing stuff for SFS.
 */

#include "print.h"

#include <stdio.h>

void sfs_print_atom( object o ) {

    /* On vérifie le type de l'object puis on affiche en fonction du résultat du type : */
    switch (o->type)
    {
        case SFS_NUMBER:
            printf("%d \n", o->this.number.this.integer);
        break;
        case SFS_CHARACTER:
            printf("%c \n", o->this.character);
        break;
        case SFS_STRING:
            printf("%s \n", o->this.string);
        break;
        
        /*
        case SFS_BOOLEAN:
            printf("%d \n", o->this.);
        break;
        */
        /* A TERMINER */
        
        
        default:
            printf("%s \n", o->this.symbol);
        break;
    }

    return;
}

void sfs_print_pair( object o ) {
    /* On commence par récupérer Les informations de car et cdr. L'idée est d'afficher car et de rentrer de manière récurisive dans cdr. Dans la suite on commence par afficher car, puis on traite le cas de cdr. */
    
    /* On commence par vérifier que l'on est bien dans le cas d'une paire */
    if ( o->type != SFS_PAIR ) {
    	sfs_print_atom( o );
    }
    else
    {
    	/* o est bien une pair : on affiche le premier élément qui est un atome */
    	sfs_print_atom( o->this.pair.car );
    	
    	/* Comme le cdr est la suite de la liste, on vérifie que la suite n'est pas une liste vide sinon on arrête notre récursivité */
    	if ( o->type == SFS_PAIR ) {
    		sfs_print_pair( (o->this.pair.cdr) );
    	}
    	else if ( o->type != SFS_NIL ) {
    		sfs_print_atom( (o->this.pair.cdr) ); /* Si ce n'est pas une pair, il s'agit d'un atome (NIL exclu) */
    	}
    	
    	/* Si aucun des deux cas n'est vérifié, on sort de la récursivité */
    	
    }
    

    return;
}

void sfs_print( object o ) {

    if ( SFS_PAIR == o->type ) {
        sfs_print_pair( o );
    }
    else {
        sfs_print_atom( o );
    }

}
