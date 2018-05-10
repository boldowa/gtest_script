/**
 * @file main.c
 *   Application entry point
 */
#include <stdio.h>

extern int ProjectName(int argc, char** argv);
int main(int argc, char** argv)
{
	return ProjectName(argc, argv);
}
