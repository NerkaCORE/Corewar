/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:49:16 by ybitton           #+#    #+#             */
/*   Updated: 2017/12/21 15:28:16 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "asm.h"

# define ERR_LFT_QUOTE_NAME "error between \" and "NAME_CMD_STRING
# define ERR_LFT_QUOTE_COMMENT "error between \" and "COMMENT_CMD_STRING
# define ERR_ALRD_SET_NAME NAME_CMD_STRING" is already set"
# define ERR_ALRD_SET_COMMENT COMMENT_CMD_STRING" is already set"
# define ERR_LENGTH_NAME "length of string is too large in "NAME_CMD_STRING
# define ERR_LENGTH_COM "length of string is too large in "COMMENT_CMD_STRING
# define ERR_TOO_MNY_NAME "too many \" in "NAME_CMD_STRING
# define ERR_TOO_MNY_COMMENT "too many \" in "COMMENT_CMD_STRING
# define ERR_TOO_LRG_NAME "length of string is too large in "NAME_CMD_STRING
# define ERR_TOO_LRG_COM "length of string is too large in "COMMENT_CMD_STRING

#endif
