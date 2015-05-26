#include "sym_tab.h"


symtab_insert_t symtab_makeInsert(symtab_entry_t *entry, bool inserted)
{
	symtab_insert_t insert = {.entry = entry, .inserted = inserted};
	return insert;
}

hash_t symtab_rawHash(void *val, size_t size)
{
    unsigned long hash = 5381;
    int i;

    for (i = 0; i < size; i++)
        hash = ((hash << 5) + hash) + ((unsigned char*)val)[i]; 
    return hash;
}

hash_t symtab_hash(entry_type_t entryType, data_type_t dataType, void *val)
{
	switch (entryType) {
		case ET_CONST:
			switch (dataType) {
				case DT_BOOL:
				case DT_INT:
					return symtab_rawHash(val, sizeof(int));
				case DT_REAL:
					return symtab_rawHash(val, sizeof(float));
				case DT_STRING:
					return symtab_strHash(val);
				default:
					break;
			}
		case ET_DECL:
		case ET_CONST_DECL:
			return symtab_strHash(val);
	}
	return 0;
}

bool symtab_findCmp(symtab_entry_t *entry, entry_type_t entryType, data_type_t dataType, void *val)
{
	if ((entryType == ET_DECL || entryType == ET_CONST_DECL) && 
		(entry->entryType == ET_DECL || entry->entryType == ET_CONST_DECL))
		return strcmp(entry->symbol.decl->ident, (char*)val) == 0;
	if (entry->entryType == entryType && entry->dataType == dataType) {
		switch (dataType) {
			case DT_BOOL:
			case DT_INT:
				return entry->symbol.iValue == *(int*)val;
			case DT_REAL:
				return entry->symbol.fValue == *(float*)val;
			case DT_STRING:
				return strcmp(entry->symbol.sValue, (char*)val) == 0;
			default:
				break;
		}
	}
	return FALSE;
}

symtab_entry_t* symtab_findByIdx(symtab_tab_t *symTab, unsigned int idx, entry_type_t entryType, data_type_t dataType, void *val)
{
	symtab_entry_t *entry = symTab[idx];

	while (entry && !symtab_findCmp(entry, entryType, dataType, val))
		entry = entry->next;
	return entry;
}

symtab_insert_t symtab_insertByIdxEx(symtab_tab_t *symTab, unsigned int idx, entry_type_t entryType, data_type_t dataType, void *val, void *val2)
{
	symtab_entry_t *entry = symtab_findByIdx(symTab, idx, entryType, dataType, val);

	if (entry) 
		return symtab_makeInsert(entry, FALSE);

	entry = (symtab_entry_t*)malloc(sizeof(symtab_entry_t));
	if (!entry) {
		printf("Out of memory!");
		exit(EXIT_FAILURE);
	}
	entry->entryType = entryType;
	entry->dataType = dataType;
	entry->next = NULL; 
	switch (entryType) {
		case ET_CONST:
			switch (dataType) {
				case DT_BOOL:
				case DT_INT:
					entry->symbol.iValue = *(int*)val;
					break;
				case DT_REAL:
					entry->symbol.fValue = *(float*)val;
					break;
				case DT_STRING:
					entry->symbol.sValue = (char*)val;
					break;
				default:
					break;
			}
			break;
		case ET_DECL:
		case ET_CONST_DECL:
			entry->symbol.decl = (symtab_decl_t*)malloc(sizeof(symtab_decl_t));
			if (!entry->symbol.decl) {
				printf("Out of memory!");
				exit(EXIT_FAILURE);
			}
			entry->symbol.decl->ident = (char*)val;
			entry->symbol.decl->size = val2 ? *(int*)val2 : SYMTAB_DECL_NOT_ARRAY;
			break;
	}
	if (!symTab[idx]) 
		symTab[idx] = entry;
	else {
		symtab_entry_t *first = symTab[idx];

		while (first->next) 
			first = first->next;
		first->next = entry;
	}
	return symtab_makeInsert(entry, TRUE);
}

