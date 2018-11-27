/**
 * showfirstwords.c -- программа организует вывод первого слова из строки
 *
 * Copyright (c) 2018, Maksim Zdorovennov <zdoroven@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void showfirstwords_line (int index, int cursor, void* data, char* contents);

void showfirstwords (text txt){

    process_forward(txt, showfirstwords_line, NULL);

}

static void showfirstwords_line (int index, int cursor, void *data ,char* contents){

    assert(contents != NULL);
    
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    
    char* line = strtok(contents, " ");;

    printf("%s\n", line);
}
