/**
 * rh.c -- программа удаления первой строки
 *
 * Copyright (c) 2018, Zdorovennov Maksim <zdoroven@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */ 
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#include "text/text.h"
static void remove_first_line(int index, char *contents, int cursor, void *data);

static void remove_first_line(int index, char *contents, int cursor, void *data)
{
    assert(contents != NULL);
	delete_line(data, 0);
	
}
