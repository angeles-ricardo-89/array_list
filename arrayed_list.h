/*
 * arrayed_list.h
 *
 * Copyright 2019 Ricardo Angeles Gómez <ricardo@localhost>
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


#ifndef ARRAYED_LIST_H_
#define ARRAYED_LIST_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAYED_LIST_INCREMENT_SIZE (32)
#define ARRAYED_LIST_DEFAULT_INITIAL_SIZE (4*ARRAYED_LIST_INCREMENT_SIZE)

typedef void * al_element;

typedef struct {
	al_element *data;
	int data_size;
	int count;
	al_element *swap;
} t_arrayed_list;

typedef t_arrayed_list *p_arrayed_list;

/*If you ar using custom mem allocation functions you can replace malloc and free here*/
#define malloc_call malloc
#define free_call free

/* returns the value in the pointer */
#define alist_content(_element_) (*(_element_))

#define alist_swap_ptr(l) ((l).swap)
#define alist_data_ptr(l) ((l).data)
#define alist_size(l) ((l).data_size)

/*get the number of elements in the list*/
#define alist_count(l) ((l).count)

#define alist_alloc(l, s)  {alist_data_ptr(l) = (al_element*)malloc_call((s)*sizeof(al_element));}
#define alist_resize(l) 	{alist_swap_ptr(l) = alist_data_ptr(l);\
							alist_size(l) += ARRAYED_LIST_INCREMENT_SIZE;\
							alist_alloc(l, alist_size(l));\
							memcpy(alist_data_ptr(l), alist_swap_ptr(l), alist_count(l)*sizeof(al_element));\
							free_call(alist_swap_ptr(l));\
							alist_swap_ptr(l)=NULL;}

#define alist_resize_if_needed(l) {if(alist_count(l)==alist_size(l)){alist_resize(l);}}

/*Returns the element at position i*/
#define alist_element(l, i) (&(alist_data_ptr(l)[i]))

/*First element in the list*/
#define alist_front(l) (alist_element(l,0))

/*Last element in the list + 1*/
#define alist_back(l) (alist_element(l,alist_count(l)))

#define alist_set_size(l,s) (alist_size(l)=(s))



#define alist_init_with(_l_, _s_) { memset(&(_l_), 0 , sizeof(t_arrayed_list)); \
									alist_alloc(_l_, _s_);\
									memset(alist_data_ptr(_l_),0,(_s_)*sizeof(al_element));\
									alist_set_size(_l_,_s_);}

/*Initializes the arrayed list*/
#define alist_init(_l_) alist_init_with(_l_, ARRAYED_LIST_DEFAULT_INITIAL_SIZE)

/*Destroys the list and de-allocate memory*/
#define alist_destroy(_l_) {free_call(alist_data_ptr(_l_));\
							memset(&(_l_), 0 , sizeof(t_arrayed_list)); }

#define alist_move_data_right(l, begin, count) {memmove(begin+count,begin,(int)(alist_back(l)-begin)*sizeof(al_element));}
#define alist_move_data_left(l, begin, count) {memmove(begin-count,begin,(alist_back(l)-begin)*sizeof(al_element));}


#define alist_insert_before(l, element, data) {alist_move_data_right(l, element, 1);\
												alist_content(element) = (data);\
												alist_resize_if_needed(l);\
												alist_count(l)++;}

#define alist_insert_at(l, position, data) {alist_insert_before(l,alist_element(l, position),data);}

#define alist_append(l,data) {alist_content(alist_back(l))=(data);\
							  alist_resize_if_needed(l);\
							  alist_count(l)++;}



#endif /* ARRAYED_LIST_H_ */
