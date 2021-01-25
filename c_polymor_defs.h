//
// Created by kasim on 10/26/2020.
//

#ifndef PHOLOPROJ_C_POLYMOR_DEFS_H
#define PHOLOPROJ_C_POLYMOR_DEFS_H
#include <stdio.h>

/* //// TextFormatter //////////// */
typedef struct vtable_TextFormatter vtable_TextFormatter;

typedef struct TextFormatterC{
    void* virtable;
}TextFormatterC;

void DTOR_TextFormatterC(TextFormatterC* const tF_c);

void CTOR_TextFormatterC(TextFormatterC* const tF_c);

void CCTOR_TextFormatterC(TextFormatterC* const tF_c,const TextFormatterC* const other );

void Assingment_TextFormatterC(TextFormatterC* const tF_c,const TextFormatterC* const other );

typedef struct vtable_TextFormatter{
void(*DTOR_TextFormatterC)(TextFormatterC*);
void(*print_TextFormatterC)(TextFormatterC*,const char*);
}vtable_TextFormatter;

/* //// DefaultTextFormatter //////////// */
extern int iderC_next_id;
int ider_getId();

typedef struct DefaultTextFormatterC{
    TextFormatterC text_format;
     struct IderC{
        char none;
    }Ider;
     int id;
}DefaultTextFormatterC;

void CTOR_IderC(struct IderC* const ider);

void DTOR_IderC(struct IderC* const ider);

 void CTOR_DefaultTextFormatterC(DefaultTextFormatterC* const def_text);

void CCTOR_DefaultTextFormatterC(DefaultTextFormatterC* const def_text,const DefaultTextFormatterC* const other);

DefaultTextFormatterC* Assingment_DefaultTextFormatterC(DefaultTextFormatterC* const def_text,const DefaultTextFormatterC* const other);

void DCTOR_DefaultTextFormatterC(DefaultTextFormatterC* const def_text);

void print_DefaultTextFormatterC(const DefaultTextFormatterC* const def_text,const char* text);

DefaultTextFormatterC*  generateFormatterArrayC();

typedef struct vtable_DefaultTextFormatter{
    vtable_TextFormatter _base;
    void(*print_DefaultTextFormatterC)(DefaultTextFormatterC*,const char*);
}vtable_DefaultTextFormatter;
/* //// PrePostFixer ////////////*/

typedef struct PrePostFixerC{
    DefaultTextFormatterC m_base;
    const char* pre;
    const char* post;
}PrePostFixerC;

void CTOR_PrePostFixerC(PrePostFixerC* const pre_fixer,const char* prefix, const char* postfix);

void DTOR_PrePostFixerC(PrePostFixerC* const pre_fixer);

void CCTOR_PrePostFixerC(PrePostFixerC* const pre_fixer,const PrePostFixerC* const other);

void printChar_PrePostFixerC(const PrePostFixerC* const pre_fixer,const char* text);

void printLongChar_PrePostFixerC(const PrePostFixerC* const pre_fixer,long num, char symbol);/*symbol='\0'default*/

char getDefaultSymbol_PrePostFixerC(const PrePostFixerC* const pre_fixer);

typedef struct vtable_PrePostFixer{
    vtable_DefaultTextFormatter _base;
    void(*printChar_PrePostFixerC)(const PrePostFixerC*,const char*);
    void(*printLongChar_PrePostFixerC)(const PrePostFixerC*,long,char);
    char(*getDefaultSymbol_PrePostFixerC)(const PrePostFixerC*);
}vtable_PrePostFixer;
/* //// PrePostDollarFixer //////////// */

typedef struct PrePostDollarFixerC{
    PrePostFixerC m_base;
}PrePostDollarFixerC;

extern const char PrePostDollarFixerC_DEFAULT_SYMBOL;

void CTOR_PrePostDollarFixerC(PrePostDollarFixerC* const dollar_fix,const char* prefix, const char* postfix);

void CCTOR_PrePostDollarFixerC(PrePostDollarFixerC* const dollar_fix,const PrePostDollarFixerC* const other);

void DTOR_PrePostDollarFixerC(PrePostDollarFixerC* const dollar_fix);

void printIntChar_PrePostDollarFixerC(const PrePostDollarFixerC* const dollar_fix,int num, char symbol);/*symbol = DEFAULT_SYMBOL*/

void printLongChar_PrePostDollarFixerC(const PrePostDollarFixerC* const dollar_fix,long num, char symbol) ;

void printDoubleChar_PrePostDollarFixerC(const PrePostDollarFixerC* const dollar_fix,double num, char symbol);

char getDefaultSymbol_PrePostDollarFixerC(const PrePostDollarFixerC* const dollar_fix);

typedef struct vtable_PrePostDollarFixer{
    vtable_PrePostFixer _base;
}vtable_PrePostDollarFixer;

/* //// PrePostHashFixer //////////// */

typedef struct PrePostHashFixerC{
    struct PrePostDollarFixerC m_base;
    int precision;
}PrePostHashFixerC;

extern const char PrePostHashFixerC_DEFAULT_SYMBOL ;

void CTOR_PrePostHashFixerC(PrePostHashFixerC* const hash_fix,int prc);/*=4 default*/

void DTOR_PrePostHashFixerC(PrePostHashFixerC* const hash_fix);

void printIntChar_HashFixer(const PrePostHashFixerC* const hash_fix,int num, char symbol);

void printLongChar_HashFixer(const PrePostHashFixerC* const hash_fix,long num, char symbol);

char getDefaultSymbol_HashFixer(const PrePostHashFixerC* const hash_fix);

typedef struct vtable_HashFixer{
    vtable_PrePostDollarFixer _base;
}vtable_HashFixer;

/* //// PrePostFloatDollarFixer //////////// */
typedef struct PrePostFloatDollarFixerC{
    struct PrePostDollarFixerC m_base;
}PrePostFloatDollarFixerC;

extern const char FloatFixer_DEFAULT_SYMBOL;

void CTOR_PrePostFloatDollarFixerC(PrePostFloatDollarFixerC* const float_dol,const char* prefix, const char* postfix);

void DTOR_PrePostFloatDollarFixerC(PrePostFloatDollarFixerC* const float_dol);

void CCTOR_PrePostFloatDollarFixerC(PrePostFloatDollarFixerC* const float_dol,const PrePostFloatDollarFixerC* const other);

void printFloat_FloatDollar(const PrePostFloatDollarFixerC* const float_dol,float num);

void printFloatChar_FloatDollar(const PrePostFloatDollarFixerC* const float_dol,float num, char symbol);

char getDefaultSymbol_FloatDollar(const PrePostFloatDollarFixerC* const float_dol);

typedef struct vtable_FloatDollar{
    vtable_PrePostDollarFixer _base;
}vtable_FloatDollar;

/* //// PrePostChecker //////////// */

typedef struct PrePostCheckerC{
    PrePostFloatDollarFixerC m_base;
}PrePostCheckerC;

void CTOR_PrePostCheckerC(PrePostCheckerC* const post_check);

void DTOR_PrePostCheckerC(PrePostCheckerC* const post_check);

void CCTOR_PrePostCheckerC(PrePostCheckerC* const post_check,const PrePostCheckerC* const other);

void printThisSymbolUsingFunc_PostCheck(const PrePostCheckerC* const post_check);

void printThisSymbolDirectly_PostCheck(const PrePostCheckerC* const post_check);

void printDollarSymbolByCastUsingFunc_PostCheck(const PrePostCheckerC* const post_check);

void printDollarSymbolByScopeUsingFunc_PostCheck(const PrePostCheckerC* const post_check);

void printDollarSymbolByCastDirectly_PotCheck(const PrePostCheckerC* const post_check);

void printDollarSymbolByScopeDirectly_PostCheck(const PrePostCheckerC* const post_check);

typedef struct vtable_PostChecker{
    vtable_FloatDollar _base;
}vtable_PostChecker;
/* //// Multiplier //////////// */
typedef struct MultiplierC{
    DefaultTextFormatterC m_base;
    int times;
}MultiplierC;

void CTOR_MultiplierC(MultiplierC* const mult,int t);

void DTOR_MultiplierC(MultiplierC* const mult);

void CCTOR_MultiplierC(MultiplierC* const mult,const MultiplierC* const other);

void printChar_MultiplierC(const MultiplierC* const mult,const char* text);

typedef struct vtable_Mult{
    vtable_DefaultTextFormatter _base;
}vtable_Mult;

extern vtable_PrePostFixer vtable_prePost;

extern vtable_PrePostDollarFixer vtable_dollarFixer;

extern vtable_HashFixer vt_hashFixer;

extern vtable_TextFormatter vt_TextFotmat;

extern vtable_DefaultTextFormatter vtable_default;

#endif //PHOLOPROJ_C_POLYMOR_DEFS_H
