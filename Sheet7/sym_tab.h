#ifndef SYM_TAB_H
#define SYM_TAB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define TRUE 1
#define FALSE 0
#define SYMTAB_MAX_BUCKETS 100
#define SYMTAB_DECL_NOT_ARRAY -1


typedef unsigned char bool;

typedef enum { 
	ET_CONST, ET_DECL, ET_CONST_DECL
} entry_type_t;

typedef enum { 
	DT_BOOL = 0, DT_INT, DT_REAL, DT_STRING, DT_UNDEF, DT_NOTDECL
} data_type_t;

typedef struct _decl {
	char *ident;
	int size;	
} symtab_decl_t;

typedef struct _entry {
	entry_type_t entryType;
	data_type_t dataType;
	union {
		int iValue;
		float fValue;
		char *sValue;
		symtab_decl_t *decl;
	} symbol;
	struct _entry *next;
} symtab_entry_t, *symtab_tab_t;

typedef unsigned long hash_t;

typedef struct _insert {
	symtab_entry_t *entry;
	bool inserted;
} symtab_insert_t;


//Calculates a hash using the djb2 algorithm
hash_t symtab_rawHash(void *val, size_t size);

hash_t symtab_strHash(char *str)
{
	return symtab_rawHash(str, strlen(str));
}

hash_t symtab_hash(entry_type_t entryType, data_type_t dataType, void *val);

unsigned int symtab_hashToIdx(hash_t hash)
{
	return hash % SYMTAB_MAX_BUCKETS;
}

bool symtab_isArray(symtab_entry_t* entry)
{
	return entry->symbol.decl->size != SYMTAB_DECL_NOT_ARRAY;
}

symtab_tab_t* symtab_new()
{
	symtab_tab_t *symTab = (symtab_tab_t*)calloc(SYMTAB_MAX_BUCKETS, sizeof(symtab_entry_t));

	if (!symTab) {
		printf("Out of memory!");
		exit(EXIT_FAILURE);
	}
	return symTab;
}

bool symtab_findCmp(symtab_entry_t *entry, entry_type_t entryType, data_type_t dataType, void *val);

symtab_entry_t* symtab_findByIdx(symtab_tab_t *symTab, unsigned int idx, entry_type_t entryType, data_type_t dataType, void *val);

symtab_entry_t* symtab_find(symtab_tab_t *symTab, entry_type_t entryType, data_type_t dataType, void *val)
{
	return symtab_findByIdx(symTab, symtab_hashToIdx(symtab_hash(entryType, dataType, val)), entryType, dataType, val);
}

symtab_insert_t symtab_insertByIdxEx(symtab_tab_t *symTab, unsigned int idx, entry_type_t entryType, data_type_t dataType, void *val, void *val2);

symtab_entry_t* symtab_insertByIdx(symtab_tab_t *symTab, unsigned int idx, entry_type_t entryType, data_type_t dataType, void *val, void *val2)
{
	return symtab_insertByIdxEx(symTab, idx, entryType, dataType, val, val2).entry;
}

symtab_insert_t symtab_insertEx(symtab_tab_t *symTab, entry_type_t entryType, data_type_t dataType, void *val, void *val2)
{
	return symtab_insertByIdxEx(symTab, symtab_hashToIdx(symtab_hash(entryType, dataType, val)), entryType, dataType, val, val2);
}

symtab_entry_t* symtab_insert(symtab_tab_t *symTab, entry_type_t entryType, data_type_t dataType, void *val, void *val2)
{
	return symtab_insertEx(symTab, entryType, dataType, val, val2).entry;
}


#endif
