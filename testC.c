//
// Created by kasim on 10/27/2020.
//

#include "testC.h"
#include "c_polymor_defs.h"
#include <stdlib.h>
void doPrePostFixer()
{
    PrePostFixerC angleBrackets;

    printf("\n--- start doPrePostFixer() ---\n\n");

    CTOR_PrePostFixerC(&angleBrackets,"<<< ", " >>>");

    printChar_PrePostFixerC(&angleBrackets,"Hello World!");

    printLongChar_PrePostFixerC(&angleBrackets,-777,'\0');

    printLongChar_PrePostFixerC(&angleBrackets,350,'#');

    printLongChar_PrePostFixerC(&angleBrackets,(long int)3.14,'\0');

    printf("\n--- end doPrePostFixer() ---\n\n");

    DTOR_PrePostFixerC(&angleBrackets);

}

void doPrePostDollarFixer()
{

    PrePostDollarFixerC asterisks;

    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    CTOR_PrePostDollarFixerC(&asterisks,"***** ", " *****");

    printIntChar_PrePostDollarFixerC(&asterisks,-777, PrePostDollarFixerC_DEFAULT_SYMBOL);

    printIntChar_PrePostDollarFixerC(&asterisks,350,'#');

    printDoubleChar_PrePostDollarFixerC(&asterisks,3.14f, PrePostDollarFixerC_DEFAULT_SYMBOL);

    printf("\n--- end doPrePostDollarFixer() ---\n\n");

    DTOR_PrePostDollarFixerC(&asterisks);
}

void doPrePostChecker()
{

    PrePostCheckerC check;

    printf("\n--- start doPrePostChecker() ---\n\n");

    CTOR_PrePostCheckerC(&check);

    printThisSymbolUsingFunc_PostCheck(&check);

    printThisSymbolDirectly_PostCheck(&check);

    printDollarSymbolByCastDirectly_PotCheck(&check);

    printDollarSymbolByScopeDirectly_PostCheck(&check);

    printDollarSymbolByCastUsingFunc_PostCheck(&check);

    printDollarSymbolByScopeUsingFunc_PostCheck(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");

    DTOR_PrePostCheckerC(&check);
}

void doPrePostFloatDollarFixer()
{
    PrePostFloatDollarFixerC hashes;

    PrePostDollarFixerC hashes2;

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    CTOR_PrePostFloatDollarFixerC(&hashes,"### ", " ###");

    printFloat_FloatDollar(&hashes, -777);

    printFloatChar_FloatDollar(&hashes, 350, '#');

    printFloat_FloatDollar(&hashes,3.14f);

    CCTOR_PrePostDollarFixerC(&hashes2, (const PrePostDollarFixerC *) &hashes);

    printDoubleChar_PrePostDollarFixerC(&hashes2,7.5, PrePostDollarFixerC_DEFAULT_SYMBOL);

    printIntChar_PrePostDollarFixerC(&hashes2,100,PrePostDollarFixerC_DEFAULT_SYMBOL);

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    DTOR_PrePostDollarFixerC(&hashes2);

    DTOR_PrePostFloatDollarFixerC(&hashes);
}

void runAsPrePostFixerRef(const PrePostFixerC* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    ((vtable_PrePostFixer* )(pp->m_base.text_format.virtable))->printLongChar_PrePostFixerC(pp,123,'\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixerC* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    printIntChar_PrePostDollarFixerC(pp,123,PrePostDollarFixerC_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixerC  pp)
{
    PrePostDollarFixerC copy_pp;

    CCTOR_PrePostDollarFixerC(&copy_pp,&pp);

    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    printIntChar_PrePostDollarFixerC(&copy_pp,123, PrePostDollarFixerC_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");

    DTOR_PrePostDollarFixerC(&copy_pp);
}

void runAsPrePostHashFixerRef(const PrePostHashFixerC* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    printIntChar_HashFixer(pp,123,PrePostHashFixerC_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    MultiplierC m1;

    MultiplierC m2;

    MultiplierC m3;

    MultiplierC m4;

    printf("\n--- start doMultiplier() ---\n\n");

    CTOR_MultiplierC(&m1,3);

    CTOR_MultiplierC(&m2,5);

    CCTOR_MultiplierC(&m3,&m1);

    CCTOR_MultiplierC(&m4,&m2);

    printChar_MultiplierC(&m1,"abc ");

    printChar_MultiplierC(&m2,"abc ");

    printChar_MultiplierC(&m3,"abc ");

    printChar_MultiplierC(&m4,"abc ");

    printf("\n--- start doMultiplier() ---\n\n");

    DTOR_MultiplierC(&m4);

    DTOR_MultiplierC(&m3);

    DTOR_MultiplierC(&m2);

    DTOR_MultiplierC(&m1);
}

void doFormatterArray()
{
    PrePostDollarFixerC dol_fix;

    MultiplierC mult;

    PrePostCheckerC post_check;

    int i;

    DefaultTextFormatterC formatters[3];

    printf("\n--- start doFormatterArray() ---\n\n");

    CTOR_PrePostDollarFixerC(&dol_fix,"!!! ", " !!!");

    CCTOR_DefaultTextFormatterC(formatters, (const DefaultTextFormatterC *) &dol_fix);

    DTOR_PrePostDollarFixerC(&dol_fix);

    CTOR_MultiplierC(&mult,4);

    CCTOR_DefaultTextFormatterC(formatters+1, (const DefaultTextFormatterC *) &mult);

    DTOR_MultiplierC(&mult);

    CTOR_PrePostCheckerC(&post_check);

    CCTOR_DefaultTextFormatterC(formatters + 2, (const DefaultTextFormatterC *) &post_check);

    DTOR_PrePostCheckerC(&post_check);

    for ( i = 0; i < 3; ++i)
        print_DefaultTextFormatterC(&formatters[i],"Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");

    for ( i = 2; i >= 0;--i)
        DCTOR_DefaultTextFormatterC(formatters + i);
}

void doFormatterPtrs()
{
    PrePostDollarFixerC* dol_fix = malloc(sizeof(PrePostDollarFixerC));

    MultiplierC* mult = malloc(sizeof(MultiplierC));

    PrePostCheckerC* post_check = malloc(sizeof(PrePostCheckerC));

    int i;

    printf("\n--- start doFormatterPtrs() ---\n\n");

    CTOR_PrePostDollarFixerC(dol_fix,"!!! ", " !!!");

    CTOR_MultiplierC(mult,4);

    CTOR_PrePostCheckerC(post_check);

    DefaultTextFormatterC* pfmt[] =
            {
                    (DefaultTextFormatterC *) dol_fix,
                    (DefaultTextFormatterC *) mult,
                    (DefaultTextFormatterC *) post_check
            };

    for ( i = 0; i < 3; ++i)
        ((vtable_DefaultTextFormatter*)(pfmt[i]->text_format.virtable))->print_DefaultTextFormatterC(pfmt[i],"Hello World!");

    for ( i = 2; i >= 0; --i) {
        ((vtable_DefaultTextFormatter*)(pfmt[i]->text_format.virtable))->_base.DTOR_TextFormatterC(
                (TextFormatterC *) pfmt[i]);
        free(pfmt[i]);
    }

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    int i;

    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatterC* formatters = generateFormatterArrayC();

    for ( i = 0; i < 3; ++i)
        ((vtable_DefaultTextFormatter*)(formatters[i].text_format.virtable))->print_DefaultTextFormatterC(formatters+i,"Hello World!");

    for ( i = 2; i >= 0; --i) {
        ((vtable_DefaultTextFormatter*)(formatters[i].text_format.virtable))->_base.DTOR_TextFormatterC(
                (TextFormatterC *) (formatters + i));
    }
    free(formatters);

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main(){
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();

    doPrePostDollarFixer();

    doPrePostFloatDollarFixer();

    doPrePostChecker();

    PrePostHashFixerC hfix;

    CTOR_PrePostHashFixerC(&hfix,4);

    runAsPrePostFixerRef((const PrePostFixerC *) &hfix);

    runAsPrePostDollarFixerRef((const PrePostDollarFixerC *) &hfix);

    runAsPrePostDollarFixerObj(hfix.m_base);

    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    doFormatterArray();

    doFormatterPtrs();

    doFormatterDynamicArray();

    printf("size of TextFormatter is %lu\n",sizeof(TextFormatterC));

    printf("size of DefaultTextFormatter is %lu\n",sizeof(DefaultTextFormatterC));

    printf("size of PrePostFixer is %lu\n",sizeof(PrePostFixerC));

    printf("size of PrePostDollarFixer is %lu\n",sizeof(PrePostDollarFixerC));

    printf("size of PrePostHashFixer is %lu\n",sizeof(PrePostHashFixerC));

    printf("size of PrePostFloatDollarFixer is %lu\n",sizeof(PrePostFloatDollarFixerC));

    printf("size of PrePostChecker is %lu\n",sizeof(PrePostCheckerC));

    printf("size of Multiplier is %lu\n",sizeof(MultiplierC));

    printf("\n--- End main() ---\n\n");

    DTOR_PrePostHashFixerC(&hfix);

    return 0;
}