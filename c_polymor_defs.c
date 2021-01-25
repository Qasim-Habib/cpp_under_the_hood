//
// Created by kasim on 10/26/2020.
//

#include "c_polymor_defs.h"
#include <stdlib.h>
vtable_TextFormatter vt_TextFotmat = {
        .DTOR_TextFormatterC = DTOR_TextFormatterC,
        .print_TextFormatterC = NULL
};

vtable_DefaultTextFormatter vtable_default = {
        ._base = {
                .DTOR_TextFormatterC = (void(*)(TextFormatterC *))DCTOR_DefaultTextFormatterC,
                .print_TextFormatterC = (void(*)(TextFormatterC *,const char*))print_DefaultTextFormatterC
        },
        .print_DefaultTextFormatterC = (void (*)(DefaultTextFormatterC *, const char *)) print_DefaultTextFormatterC
};

vtable_PrePostFixer vtable_prePost = {
        ._base = {
                ._base.DTOR_TextFormatterC = (void(*)(TextFormatterC *))DTOR_PrePostFixerC,
                ._base.print_TextFormatterC = (void (*)(TextFormatterC *, const char *)) printChar_PrePostFixerC,
                .print_DefaultTextFormatterC = (void (*)(DefaultTextFormatterC *, const char *)) printChar_PrePostFixerC
        },
        .printChar_PrePostFixerC = printChar_PrePostFixerC,
        .printLongChar_PrePostFixerC = printLongChar_PrePostFixerC,
        .getDefaultSymbol_PrePostFixerC = getDefaultSymbol_PrePostFixerC
};

vtable_PrePostDollarFixer vtable_dollarFixer = {
        ._base = {
                ._base._base.DTOR_TextFormatterC = (void(*)(TextFormatterC *))DTOR_PrePostDollarFixerC,
                ._base._base.print_TextFormatterC = (void (*)(TextFormatterC *, const char *)) printChar_PrePostFixerC,
                ._base.print_DefaultTextFormatterC = (void (*)(DefaultTextFormatterC *, const char *)) printChar_PrePostFixerC,
                .printChar_PrePostFixerC = printChar_PrePostFixerC,
                .printLongChar_PrePostFixerC = (void (*)(const PrePostFixerC *, long,
                                                       char)) printLongChar_PrePostDollarFixerC,
                .getDefaultSymbol_PrePostFixerC = (char (*)(const PrePostFixerC *)) getDefaultSymbol_PrePostDollarFixerC
        }

};

vtable_HashFixer vt_hashFixer = {
        ._base = {
                ._base._base._base.DTOR_TextFormatterC = (void (*)(TextFormatterC *)) DTOR_PrePostHashFixerC,
                ._base._base._base.print_TextFormatterC = (void (*)(TextFormatterC *,const char *)) printChar_PrePostFixerC,
                ._base._base.print_DefaultTextFormatterC = (void (*)(DefaultTextFormatterC *,const char *)) printChar_PrePostFixerC,
                ._base.printChar_PrePostFixerC = printChar_PrePostFixerC,
                ._base.printLongChar_PrePostFixerC = (void (*)(const PrePostFixerC *, long, char)) printLongChar_HashFixer,
                ._base.getDefaultSymbol_PrePostFixerC = (char (*)(const PrePostFixerC *)) getDefaultSymbol_HashFixer

        }
};

vtable_FloatDollar vt_FloatDollar = {
        ._base = {
                ._base._base._base.DTOR_TextFormatterC = (void (*)(TextFormatterC *)) DTOR_PrePostFloatDollarFixerC,
                ._base._base._base.print_TextFormatterC = (void (*)(TextFormatterC *,const char *)) printChar_PrePostFixerC,
                ._base._base.print_DefaultTextFormatterC = (void (*)(DefaultTextFormatterC *,const char *)) printChar_PrePostFixerC,
                ._base.printChar_PrePostFixerC = printChar_PrePostFixerC,
                ._base.printLongChar_PrePostFixerC = (void (*)(const PrePostFixerC *, long, char)) printLongChar_PrePostDollarFixerC,
                ._base.getDefaultSymbol_PrePostFixerC = (char (*)(const PrePostFixerC *)) getDefaultSymbol_FloatDollar

        }
};

vtable_PostChecker vt_PostCheck = {
        ._base = {
                ._base._base._base._base.DTOR_TextFormatterC = (void (*)(TextFormatterC *)) DTOR_PrePostCheckerC,
                ._base._base._base._base.print_TextFormatterC = (void (*)(TextFormatterC *,const char *)) printChar_PrePostFixerC,
                ._base._base._base.print_DefaultTextFormatterC = (void (*)(DefaultTextFormatterC *,const char *)) printChar_PrePostFixerC,
                ._base._base.printChar_PrePostFixerC = printChar_PrePostFixerC,
                ._base._base.printLongChar_PrePostFixerC = (void (*)(const PrePostFixerC *, long, char)) printLongChar_PrePostDollarFixerC,
                ._base._base.getDefaultSymbol_PrePostFixerC = (char (*)(const PrePostFixerC *)) getDefaultSymbol_FloatDollar

        }
};

vtable_Mult vt_mult = {
        ._base = {

                ._base.DTOR_TextFormatterC = (void(*)(TextFormatterC *))DTOR_MultiplierC,
                ._base.print_TextFormatterC = (void(*)(TextFormatterC *,const char*))printChar_MultiplierC,
                .print_DefaultTextFormatterC = (void (*)(DefaultTextFormatterC *, const char *)) printChar_MultiplierC
        }

};

int iderC_next_id = 0;

const char PrePostDollarFixerC_DEFAULT_SYMBOL = '$';

const char PrePostHashFixerC_DEFAULT_SYMBOL = '#';

const char FloatFixer_DEFAULT_SYMBOL = '@';

void DTOR_TextFormatterC(TextFormatterC* const tF_c)
{

}

void CTOR_TextFormatterC(TextFormatterC* const tF_c)
{
    tF_c->virtable = &vt_TextFotmat;
}

 void CTOR_DefaultTextFormatterC(DefaultTextFormatterC* const def_text)
{
    def_text->id = ider_getId();

    CTOR_TextFormatterC(&def_text->text_format);

    def_text->text_format.virtable=&vtable_default;

printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", def_text->id);

}

void Assingment_TextFormatterC(TextFormatterC* const tF_c , const TextFormatterC* const other )
{}

void CCTOR_TextFormatterC(TextFormatterC* const tF_c , const TextFormatterC* const other )
{}

void DCTOR_DefaultTextFormatterC(DefaultTextFormatterC* const def_text)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", def_text->id);

    def_text->text_format.virtable=&vt_TextFotmat;

    DTOR_TextFormatterC(&(def_text->text_format));
}

void CCTOR_DefaultTextFormatterC(DefaultTextFormatterC* const def_text, const DefaultTextFormatterC* const other)
{
    CCTOR_TextFormatterC(&(def_text->text_format),&(other->text_format));

    def_text->text_format.virtable = &vtable_default;

    def_text->id = ider_getId();

    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id,def_text->id);
}

DefaultTextFormatterC* Assingment_DefaultTextFormatterC(DefaultTextFormatterC* const def_text, const DefaultTextFormatterC* const other)
{
    Assingment_TextFormatterC(&(def_text->text_format), &(other->text_format));

    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id,def_text->id);

    return def_text;
}

void print_DefaultTextFormatterC(const DefaultTextFormatterC* const def_text , const char* text)
{
    printf("[DefaultTextFormatter::print(const char*)] | ");

    printf("%s\n", text);
}

DefaultTextFormatterC*  generateFormatterArrayC()
{
    DefaultTextFormatterC* def = malloc(sizeof(struct DefaultTextFormatterC)*3);

    size_t cur;

    for(cur = 0; cur < 3; cur++)
        CTOR_DefaultTextFormatterC(def + cur);
    return def;
}

void DTOR_IderC(struct IderC* const ider)
{}

void CTOR_IderC(struct IderC* const ider)
{
}

int ider_getId()
{
    return iderC_next_id++;
}

void CTOR_PrePostFixerC(PrePostFixerC* const pre_fixer,const char* prefix, const char* postfix)
{
    CTOR_DefaultTextFormatterC(&pre_fixer->m_base);

    pre_fixer->m_base.text_format.virtable = &(vtable_prePost);

    pre_fixer->pre = prefix;

    pre_fixer->post = postfix;

    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", pre_fixer->pre, pre_fixer->post);
}

void DTOR_PrePostFixerC(PrePostFixerC* const pre_fixer)
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", pre_fixer->pre, pre_fixer->post);

    pre_fixer->m_base.text_format.virtable = &vtable_default;

    DCTOR_DefaultTextFormatterC(&pre_fixer->m_base);
}

void printChar_PrePostFixerC(const PrePostFixerC* const pre_fixer,const char* text)
{
    printf("[PrePostFixer::print(const char*)] | ");

    printf("%s%s%s\n", pre_fixer->pre, text, pre_fixer->post);
}

void CTOR_PrePostDollarFixerC(PrePostDollarFixerC* const dollar_fix,const char* prefix, const char* postfix)
{
    CTOR_PrePostFixerC(&dollar_fix->m_base,prefix,postfix);

    dollar_fix->m_base.m_base.text_format.virtable = &vtable_dollarFixer;

    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", dollar_fix->m_base.pre, dollar_fix->m_base.post);
}

void CCTOR_PrePostFixerC(PrePostFixerC* const pre_fixer,const PrePostFixerC* const other)
{
    CCTOR_DefaultTextFormatterC(&pre_fixer->m_base,&other->m_base);

    pre_fixer->m_base.text_format.virtable = &vtable_prePost;

    pre_fixer->pre = other->pre;

    pre_fixer->post = other->post;

}

void CCTOR_PrePostDollarFixerC(PrePostDollarFixerC* const dollar_fix,const PrePostDollarFixerC* const other)
{
    CCTOR_PrePostFixerC(&dollar_fix->m_base,&other->m_base);

    dollar_fix->m_base.m_base.text_format.virtable = &vtable_dollarFixer;

    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", dollar_fix->m_base.pre,dollar_fix->m_base.post);

}

void DTOR_PrePostDollarFixerC(PrePostDollarFixerC* const dollar_fix)
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", dollar_fix->m_base.pre,dollar_fix->m_base.post);

    dollar_fix->m_base.m_base.text_format.virtable = &(vtable_prePost);

    DTOR_PrePostFixerC(&dollar_fix->m_base);
}


void printIntChar_PrePostDollarFixerC(const PrePostDollarFixerC* const dollar_fix,int num, char symbol)
{
    printf("[PrePostDollarFixer::print(int, char)] | ");

    printf("-->\n");

    ((vtable_PrePostDollarFixer*)(dollar_fix->m_base.m_base.text_format.virtable))->_base.printLongChar_PrePostFixerC((const PrePostFixerC *)dollar_fix,(long)num,symbol);

}

void printLongChar_PrePostFixerC(const PrePostFixerC* const pre_fixer,long num, char symbol)
{
    printf("[PrePostFixer::print(long, char)] | ");

    printf("-->\n");

    if (symbol) {

        printf("[PrePostFixer::print_num(long, char)] | ");

        printf("%s%c%ld%s\n", pre_fixer->pre, symbol, num, pre_fixer->post);
    }

    else{

        printf("[PrePostFixer::print_num(long)] | ");

        printf("%s%ld%s\n", pre_fixer->pre, num, pre_fixer->post);
    }
}

void printLongChar_PrePostDollarFixerC(const PrePostDollarFixerC* const dollar_fix,long num, char symbol)
{
    printf("[PrePostDollarFixer::print(long, char)] | ");

    printf("-->\n");

    printLongChar_PrePostFixerC(&dollar_fix->m_base, num,  symbol);
}

void printDoubleChar_PrePostDollarFixerC(const PrePostDollarFixerC* const dollar_fix,double num, char symbol)
{
    printf("[PrePostDollarFixer::print(double, char)] | ");

    printf("%s%c%f%s\n", dollar_fix->m_base.pre, symbol, num, dollar_fix->m_base.post);
}

void CTOR_PrePostHashFixerC(PrePostHashFixerC* const hash_fix,int prc)
{
    CTOR_PrePostDollarFixerC(&hash_fix->m_base,"===> ", " <===");

    hash_fix->m_base.m_base.m_base.text_format.virtable = &(vt_hashFixer);

    hash_fix->precision=prc;

    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", hash_fix->m_base.m_base.pre, hash_fix->m_base.m_base.post,hash_fix->precision );

    printf("[PrePostHashFixer::print(double, char)] | ");

    printf("%s[%c%.*f]%s\n", hash_fix->m_base.m_base.pre, PrePostHashFixerC_DEFAULT_SYMBOL, hash_fix->precision, 9999.9999, hash_fix->m_base.m_base.post);
}

void DTOR_PrePostHashFixerC(PrePostHashFixerC* const hash_fix)
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", hash_fix->m_base.m_base.pre,hash_fix->m_base.m_base.post);

    hash_fix->m_base.m_base.m_base.text_format.virtable = &(vtable_dollarFixer);

    DTOR_PrePostDollarFixerC(&hash_fix->m_base);
}

void printIntChar_HashFixer(const PrePostHashFixerC* const hash_fix,int num, char symbol)
{
    printf("[PrePostHashFixer::print(int, char)] |");

    printf("-->\n");

    printf("[PrePostHashFixer::print(double, char)] | ");

    printf("%s[%c%.*f]%s\n", hash_fix->m_base.m_base.pre, symbol, hash_fix->precision, (double)num, hash_fix->m_base.m_base.post);
}

void printLongChar_HashFixer(const PrePostHashFixerC* const hash_fix,long num, char symbol)
{
    printf("[PrePostHashFixer::print(long, char)] |");

    printf("-->\n");

    printf("[PrePostHashFixer::print(double, char)] | ");

    printf("%s[%c%.*f]%s\n", hash_fix->m_base.m_base.pre, symbol, hash_fix->precision, (double)num, hash_fix->m_base.m_base.post);
}

void CTOR_PrePostFloatDollarFixerC(PrePostFloatDollarFixerC* const float_dol,const char* prefix, const char* postfix)
{
    CTOR_PrePostDollarFixerC(&float_dol->m_base,prefix,postfix);

    float_dol->m_base.m_base.m_base.text_format.virtable = &(vt_FloatDollar);

    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", float_dol->m_base.m_base.pre,float_dol->m_base.m_base.post);
}

void DTOR_PrePostFloatDollarFixerC(PrePostFloatDollarFixerC* const float_dol)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n",float_dol->m_base.m_base.pre,float_dol->m_base.m_base.post);

    float_dol->m_base.m_base.m_base.text_format.virtable = &(vtable_dollarFixer);

    DTOR_PrePostDollarFixerC(&float_dol->m_base);
}

void printFloatChar_FloatDollar(const PrePostFloatDollarFixerC* const float_dol,float num, char symbol)
{
    printf("[PrePostFloatDollarFixer::print(float, char)] |");

    printf("%s%c%.2f%s\n", float_dol->m_base.m_base.pre, symbol, num, float_dol->m_base.m_base.post);
}

void printFloat_FloatDollar(const PrePostFloatDollarFixerC* const float_dol,float num)
{
    printf("[PrePostFloatDollarFixer::print(float)] |");

    printf("-->\n");

    printFloatChar_FloatDollar(float_dol,num, FloatFixer_DEFAULT_SYMBOL);
}

void CTOR_PrePostCheckerC(PrePostCheckerC* const post_check)
{
    CTOR_PrePostFloatDollarFixerC(&post_check->m_base,"[[[[ ", " ]]]]");

    post_check->m_base.m_base.m_base.m_base.text_format.virtable = &(vt_PostCheck);

    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", post_check->m_base.m_base.m_base.pre,post_check->m_base.m_base.m_base.post);

}

void DTOR_PrePostCheckerC(PrePostCheckerC* const post_check)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",post_check->m_base.m_base.m_base.pre,post_check->m_base.m_base.m_base.post );

    post_check->m_base.m_base.m_base.m_base.text_format.virtable = &(vt_FloatDollar);

    DTOR_PrePostFloatDollarFixerC(&post_check->m_base);
}

void printThisSymbolUsingFunc_PostCheck(const PrePostCheckerC* const post_check)
{
    printf("[PrePostChecker::printThisSymbolUsingFunc()] |");

    printf("Default symbol is %c\n", vt_PostCheck._base._base._base.getDefaultSymbol_PrePostFixerC(
            (const PrePostFixerC *) post_check));

}

void printThisSymbolDirectly_PostCheck(const PrePostCheckerC* const post_check)
{
    printf("[PrePostChecker::printThisSymbolDirectly()] |");

    printf("Default symbol is %c\n", FloatFixer_DEFAULT_SYMBOL);
}

void printDollarSymbolByCastUsingFunc_PostCheck(const PrePostCheckerC* const post_check)
{
    printf("[PrePostChecker::printDollarSymbolByCastUsingFunc()] |");

    printf("Default symbol is %c\n", vt_PostCheck._base._base._base.getDefaultSymbol_PrePostFixerC(
            (const PrePostFixerC *) (PrePostDollarFixerC *) (post_check)));

}

void printDollarSymbolByScopeUsingFunc_PostCheck(const PrePostCheckerC* const post_check)
{
    printf("[PrePostChecker::printDollarSymbolByScopeUsingFunc()] |");

    printf("Default symbol is %c\n", getDefaultSymbol_PrePostDollarFixerC( &post_check->m_base.m_base));

}

void printDollarSymbolByCastDirectly_PotCheck(const PrePostCheckerC* const post_check)
{
    printf("[PrePostChecker::printDollarSymbolByCastDirectly()] |");

    printf("Default symbol is %c\n", PrePostDollarFixerC_DEFAULT_SYMBOL);
}

void printDollarSymbolByScopeDirectly_PostCheck(const PrePostCheckerC* const post_check)
{
    printf("[PrePostChecker::printDollarSymbolByScopeDirectly()] |");

    printf("Default symbol is %c\n",PrePostDollarFixerC_DEFAULT_SYMBOL);
}

void CTOR_MultiplierC(MultiplierC* const mult,int t)
{
    CTOR_DefaultTextFormatterC(&mult->m_base);

    mult->m_base.text_format.virtable=&(vt_mult);

    mult->times = t;

    printf("--- Multiplier CTOR: times = %d\n", mult->times);
}

void DTOR_MultiplierC(MultiplierC* const mult)
{
    printf("--- Multiplier DTOR: times = %d\n", mult->times);

    mult->m_base.text_format.virtable = &(vtable_default);

    DCTOR_DefaultTextFormatterC(&mult->m_base);
}

void printChar_MultiplierC(const MultiplierC* const mult,const char* text)
{
    int i;
    printf("[Multiplier::print(const char*)] |");

    for ( i = 0; i < mult->times; ++i)
        printf("%s", text);

    printf("\n");
}

char getDefaultSymbol_PrePostFixerC(const PrePostFixerC* const pre_fixer)
{
    return '\0';
}

char getDefaultSymbol_PrePostDollarFixerC(const PrePostDollarFixerC* const dollar_fix)
{
    return PrePostDollarFixerC_DEFAULT_SYMBOL;
}

char getDefaultSymbol_HashFixer(const PrePostHashFixerC* const hash_fix)
{
    return PrePostHashFixerC_DEFAULT_SYMBOL;
}

char getDefaultSymbol_FloatDollar(const PrePostFloatDollarFixerC* const float_dol)
{
    return FloatFixer_DEFAULT_SYMBOL;
}

void CCTOR_MultiplierC(MultiplierC* const mult,const MultiplierC* const other)
{
    CCTOR_DefaultTextFormatterC(&mult->m_base, &other->m_base);

    mult->m_base.text_format.virtable = &vt_mult;

    mult->times = other->times;
}

void CCTOR_PrePostFloatDollarFixerC(PrePostFloatDollarFixerC* const float_dol,const PrePostFloatDollarFixerC* const other)
{
    CCTOR_PrePostDollarFixerC(&float_dol->m_base,&other->m_base);

    float_dol->m_base.m_base.m_base.text_format.virtable = &vt_FloatDollar;
}

void CCTOR_PrePostCheckerC(PrePostCheckerC* const post_check,const PrePostCheckerC* const other)
{

    CCTOR_PrePostFloatDollarFixerC(&post_check->m_base,&other->m_base);

    post_check->m_base.m_base.m_base.m_base.text_format.virtable = &(vt_PostCheck);
}