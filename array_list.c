/*
 * array_list.c
 *
 * Copyright 2019 Ricardo Angeles Gómez <angeles.ricardo.89@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>

#include "arrayed_list.h"

void print_list(t_arrayed_list *list)
{
	al_element *n;

	for(n = alist_front(*list); n < alist_back(*list); n++){
		printf("value at %lld = [%lld]\n", (long long)(n-alist_front(*list)), (long long)alist_content(n));
	}

}

int test()
{

	t_arrayed_list list;

	alist_init(list);

	printf("size %d\n", alist_size(list));
	printf("elements %d\n", alist_count(list));

	alist_append(list, (void*)123 );
	alist_append(list, (void*)56 );
	alist_append(list, (void*)300 );
	alist_append(list, (void*)320 );
	alist_append(list, (void*)350 );
	alist_append(list, (void*)390 );
	alist_append(list, (void*)60 );
	alist_append(list, (void*)20 );
	long long i;
	for(i=0; i<1000; i++)
		alist_append(list, (void*)(i*i) );

	print_list(&list);

	alist_insert_at(list, 3, (void*)456);


	print_list(&list);

	alist_destroy(list);
	return 0;

}


int main(void) {

	test();

	return EXIT_SUCCESS;
}
