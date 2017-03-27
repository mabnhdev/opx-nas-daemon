#!/bin/sh
# Copyright (c) 2015 Dell Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may
# not use this file except in compliance with the License. You may obtain
# a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
#
# THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
# CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
# LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
# FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
#
# See the Apache Version 2.0 License for specific language governing
# permissions and limitations under the License.
#
if [ -x /usr/bin/netserve ]
then
    # netserve is on the system use it to start opx_nas_daemon. netserve
    # will be present if we're using the Broadcom SAI. 
    /usr/bin/netserve -d 1943 /usr/bin/opx_nas_daemon
else
    # netserve isn't present, it means we're not using the Broadcom SAI,
    # most likely running on a VM with simulated hardware. In this case
    # fork the opx_nas_daemon and create /var/run/netserve.pid to keep
    # /lib/systemd/system/opx-nas.service happy.
    /usr/bin/opx_nas_daemon&
    echo $! > /var/run/netserve.pid
fi
