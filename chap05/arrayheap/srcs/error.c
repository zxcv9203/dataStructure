/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:38:17 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/16 12:15:08 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayHeap.h"
//const char *mallocERROR = "asdasdasdasd";

const char *MALLOC_ERROR = "fail to allocate memory";
const char *TREE_OVERFLOW = "no left space to insert";
const char *TREE_UNDERFLOW = "no left node to remove";
const char *INDEX_ERROR = "unvailable index";

void error(const char *msg)
{
	fprintf(stderr, "%s", msg);	
}