/*
 * command.h
 *
 *  Created on: Nov 7, 2024
 *      Author: DELL
 */

#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_

#include <string.h>
#include "scheduler.h"
#include "uart.h"

void commandExecute(void);
void commandParser(void);

#endif /* INC_COMMAND_H_ */
