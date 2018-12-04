/**
 * mcf.c -- программа помещает курсор на 1 вправо, если может
 *
 * Copyright (c) 2018, Zdorovennov Maksim <zdoroven@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */ 
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <ctype.h>
#include <stdlib.h>

static void move_cursor_forward(int index, char *contents, int cursor, void*data);

void mcf (text txt){

    process_forward(txt, move_cursor_forward, txt);

}

static void move_cursor_forward(int index, char *contents, int cursor, void*data){

    assert(contents != NULL);

    UNUSED (data);

    if (cursor > 0){

	int i = 0, j = 0;

	while (j != 1){

	    if (index == i){

		if ((contents[cursor+1] != '\n') && (contents[cursor+1] != '\0')){

		    mwcrsr(data, i + 1, cursor + 2);
		    j = 1;
		}
	    }
	    
	    i++;
	}
	
    }
	
}
