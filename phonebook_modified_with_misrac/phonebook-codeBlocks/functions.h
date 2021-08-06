/*
 ============================================================================
 Name        : Phonebook_in_c.c
 Author      : Merna Saleh
 Version     :
 Copyright   : Your copyright notice
 Description : Functions of phone book in C, Ansi-style
 ============================================================================
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct
{

	int PhoneNumber;
	char Name[50];
	char Email[50];
}phonebook;
typedef	unsigned char		__uint8_t;
typedef	unsigned int		__uint32_t;
typedef	signed char		__int8_t;
typedef	signed int		__int32_t;
void menu(void);
void Add_Record(void);
void List_File(void);
void Modify_Record(void);
void Search_File(void);
void Delete_Record(void);
void main(void);
__int32_t getch (void);
#endif /* FUNCTIONS_H_ */
