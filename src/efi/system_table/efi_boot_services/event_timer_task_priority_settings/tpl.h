#pragma once

#include "../../../basic_data_types.h"

//******************************************************
// EFI_TPL
//******************************************************
typedef UINTN EFI_TPL;
//******************************************************
// Task Priority Levels
//******************************************************
#define TPL_APPLICATION 4
#define TPL_CALLBACK 8
#define TPL_NOTIFY 16
#define TPL_HIGH_LEVEL 31

typedef EFI_TPL (*EFI_RAISE_TPL) (EFI_TPL NewTpl);

typedef VOID (*EFI_RESTORE_TPL) (EFI_TPL OldTpl);
