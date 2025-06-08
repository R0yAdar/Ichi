#pragma once

int init_idt();

void systemCall(int sysCallNo, void* ptr);
