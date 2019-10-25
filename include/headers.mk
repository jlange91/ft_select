# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    headers.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 18:04:37 by thdelmas          #+#    #+#              #
#    Updated: 2019/10/22 18:04:54 by thdelmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

H_FILES= \
	ft_select.h

# SUPPA concat loop
H_FILES += $(foreach SUB_DIR,$(SUB_DIRS),$(addprefix $(SUB_DIR)/,$(H_FILES_$(SUB_DIR))))
