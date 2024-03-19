/*! @file io.h
	@brief Library of functions for I/O 
	@author Paolo Gastaldo

	Details.
*/


#ifndef IO_H 
#define IO_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "structs.h"



FILE* OpenFile(char* filePath);
int CloseFile(FILE* fPtr);
int ReadConfigFile(FILE* fPtr, poly_s* pf, double* xinf, double* xsup, int* intervals); 
int ParseLine(poly_s* pf, char* str);

#endif