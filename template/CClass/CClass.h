/**
 * @file CClass.h
 */
#ifndef CLASSNAME_H
#define CLASSNAME_H
#ifdef __cplusplus
extern "C" {
#endif

/**
 * public accessor
 *   TODO : fix it
 */
typedef struct _ClassName ClassName;
typedef struct _ClassName_protected ClassName_protected;
typedef struct _ClassName_private ClassName_private;
struct _ClassName {
	/* some global variable */
	int foobar;
	/* member method */
	int (*accessor)(ClassName*);
	/* protected members */
	ClassName_protected* pro;
	/* private members */
	ClassName_private* pri;
};

/**
 * Constructor
 */
ClassName* new_ClassName(void);

/**
 * Destractor
 */
void delete_ClassName(ClassName**);


#ifdef __cplusplus
}
#endif
#endif
