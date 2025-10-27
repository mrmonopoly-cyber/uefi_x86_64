#pragma once

//INFO: UEFI specs, Release 2.11
//INFO: Basic Data Types Section 2.3.1

#include <stdint.h>
#include <arch.h>

typedef uint8_t BOOLEAN;
enum
{
  FALSE = 0,
  TRUE = 1,
};

#ifdef __i386__
typedef int32_t INTN;
typedef uint32_t UINTN;
#elif __x86_64__
typedef int64_t INTN;
typedef uint64_t UINTN;
#else
#   error "Unknown architecture!"
#endif

typedef int8_t INT8;
typedef uint8_t UINT8;

typedef int16_t INT16;
typedef uint16_t UINT16;

typedef int32_t INT32;
typedef uint32_t UINT32;

typedef int64_t INT64;
typedef uint64_t UINT64;

//FIX: missing INT128 and UINT128

typedef struct
{
  uint64_t low;
  int64_t high;
}INT128;

typedef struct
{
  uint64_t low;
  uint64_t high;
}UINT128;

typedef char CHAR8;
typedef uint16_t CHAR16;

typedef void VOID;

//******************************************************
//EFI_GUID
//******************************************************
typedef struct {
  UINT32 Data1;
  UINT16 Data2;
  UINT16 Data3;
  UINT8 Data4[8];
} EFI_GUID;

typedef UINTN EFI_STATUS;

typedef VOID* EFI_HANDLE;
typedef VOID* EFI_EVENT;

typedef UINT64 EFI_LBA;
typedef UINTN EFI_TPL;

typedef struct 
{
  uint32_t cells[4];
}EFI_MAC_ADDRESS;

typedef struct 
{
  uint8_t cells[4];
}EFI_IPV4_ADDRESS;

typedef struct 
{
  uint16_t cells[4];
}EFI_IPV6_ADDRESS;

typedef struct 
{
  uint16_t cells[4];
}EFI_IP_ADDRESS;

//INFO: EFI Table Header, Section 4.2
typedef struct {
  UINT64 Signature;
  UINT32 Revision;
  UINT32 HeaderSize;
  UINT32 CRC32;
  UINT32 Reserved;
} EFI_TABLE_HEADER;
