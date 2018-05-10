/**
 * @file CClass.protected.h
 */
#ifndef CLASSNAME_PROTECTED_H
#define CLASSNAME_PROTECTED_H

/**
 * ClassName main instance
 *   TODO : Fix it
 */
struct _ClassName_protected {
	const char* hello;
};

/**
 * detete own members method prototype
 * I recommend it that you move this method in "ClassName.c"
 * if you plan to make the final class.
 */
void delete_ClassName_members(ClassName*);

#endif
