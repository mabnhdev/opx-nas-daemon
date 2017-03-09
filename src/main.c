/*
 * Copyright (c) 2016 Dell Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 * FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
 *
 * See the Apache Version 2.0 License for specific language governing
 * permissions and limitations under the License.
 */

/*!
 * \file   main.c
 * \brief  Main file for hal daemon
 * \date   04-2014
 * \author Amazon Team
 */

#include "hald_init.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <systemd/sd-daemon.h>

#include <stdio.h>

#ifndef ORIGINAL_DELL_CODE
#include "nas_ndi_switch.h"
#endif

int main(int argc, char **argv) {
    if (hald_init()!=STD_ERR_OK) exit (1);

    sd_notify(0,"READY=1");

/* #ifndef ORIGINAL_DELL_CODE */
#if 0
    nas_ndi_switch_param_t param;
    param.u32 = true;

    if (ndi_switch_set_attribute(0, BASE_SWITCH_SWITCHING_ENTITIES_SWITCHING_ENTITY_SWITCH_SHELL_ENABLE, &param) != STD_ERR_OK)
        fprintf(stderr,"Failed to initialize switch shell\n");
#endif

    while (1) {
        sleep(1);
    }
    return 0;
}

