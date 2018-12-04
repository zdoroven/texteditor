/**
 * mcf.c -- программа сдвигает курсор на 1 вправо, если может
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
void mcf (text, txt){

    process_forward(txt, move_cursor_forward, txt);

}

void move_cursor_forward(int index, char *contents, void*data){

    assert(contents != NULL);

    UNUSED data;

    if ( cursor > 0){
	if ((contents[cursor+1] != '\n') && contents[cursor+1] != '\0'){
	    cursor++;
	}
    }
    mvcrsr(data, index + 1, cursor + 1);
}

