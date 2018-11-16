/**
 * remove_first_entry_line.c -- функция удаления первой пустой строки из файла
 * 
 * Copyright (c) 2018, Hristoforov Egor <hristofo@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void remove_line(int index, char *contents, int cursor, void *data);

/**
 * Удаляет первую пустую строку
 */
static int flag = 0;
void remove_first_entry_line(text txt){
    process_forward(txt, remove_line, NULL);
    flag = 0;
}

static void remove_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    if(contents[0] == '\n' && !flag){
        contents[0] = '\0';
        flag = 1;
    }
}
