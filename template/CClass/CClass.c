/**
 * @file ClassName.c
 */
/*#include "common/types.h"*/
#include <assert.h>
#include <stdlib.h>
#include "PackageName/CClass.h"

/* this header isn't read from anything other */
/* than inherited object.                     */ 
#include "CClass.protected.h"

/* Private member */
/* TODO : Fix it */
struct _ClassName_private {
	int some_member;
};

/* prototypes TODO : Fix it */
/*static int some_method(ClassName);*/


/*--------------- Constructor / Destructor ---------------*/

/**
 * @brief Create ClassName object
 *
 * @return the pointer of object
 */
ClassName* new_ClassName(void)
{
	ClassName* self;
	ClassName_protected* pro;
	ClassName_private* pri;

	/* make objects */
	self = malloc(sizeof(ClassName));
	pro = malloc(sizeof(ClassName_protected));
	pri = malloc(sizeof(ClassName_private));

	/* check whether object creatin succeeded */
	assert(pro);
	assert(pri);
	assert(self);

	/*--- set private member ---*/
	/* TODO : Fix it */
	pri->some_member = 0;

	/*--- set protected member ---*/
	/* TODO : Fix it */
	pro->hello = "";

	/*--- set public member ---*/
	/* TODO : Fix it */
	self->foobar = 0;
	self->accessor = NULL; /* TODO : Set function pointer */

	/* init ClassName object */
	self->pro = pro;
	self->pri = pri;
	return self;
}

/**
 * @brief delete own member variables
 *
 * @param the pointer of object
 */
void delete_ClassName_members(ClassName* self)
{
	/* delete protected members */
	free(self->pro);

	/* delete private members */
	free(self->pri);
}

/**
 * @brief Delete ClassName object
 *
 * @param the pointer of object
 */
void delete_ClassName(ClassName** self)
{
	/* This is the template that default destractor. */
	assert(self);
	if(NULL == (*self)) return;
	delete_ClassName_members(*self);
	free(*self);
	(*self) = NULL;
}


/*--------------- internal methods ---------------*/

/* TODO : implement it */

