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
void remove_first_entry_line(text txt){
    process_forward(txt, remove_line, NULL);
}
static void remove_line(int index, char *contents, int cursor, void *data)
{
    static int flag = 0;
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    if(strcmp(contents, "\n") == 0 && !flag){
        contents[0] = '\0';
        flag = 1;
    }
    
    /* Если строка пустая */
    /*if (strcmp(contents, "\n") == 0){
        printf("%d. %s", index, "Entry line \n");
    } else {
        printf("%d. %s", index, contents);
    }*/
}
