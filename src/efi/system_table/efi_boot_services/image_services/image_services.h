#pragma once

//INFO: Image Services, Section 7.4

#include "../../../basic_data_types.h"
#include "../../../protocols/protocols.h"
#include "input_vars_attributes.h"
#include "image_services_types.h"


typedef enum
{
 EFI_STATUS_EFI_IMAGE_LOAD_EFI_SUCCESS, //INFO:Image was loaded into memory correctly.
 EFI_STATUS_EFI_IMAGE_LOAD_EFI_NOT_FOUND, //INFO: Both SourceBuffer and DevicePath are NULL.
 EFI_STATUS_EFI_IMAGE_LOAD_EFI_INVALID_PARAMETER,/* //INFO:
                                                  *
                                                  * One of the parameters has an invalid value.
                                                  * |
                                                  * ImageHandle is NULL.
                                                  * |
                                                  * ParentImageHandle is NULL.
                                                  * |
                                                  * ParentImageHandle is NULL.
                                                  */
 EFI_STATUS_EFI_IMAGE_LOAD_EFI_UNSUPPORTED, //INFO: The image type is not supported.
 EFI_STATUS_EFI_IMAGE_LOAD_EFI_OUT_OF_RESOURCES, //INFO: Image was not loaded due to insufficient resources.
 EFI_STATUS_EFI_IMAGE_LOAD_EFI_LOAD_ERROR, //INFO:Image was not loaded because the image format was corrupt or not understood.
 EFI_STATUS_EFI_IMAGE_LOAD_EFI_DEVICE_ERROR, //INFO: Image was not loaded because the device returned a read error.
 EFI_STATUS_EFI_IMAGE_LOAD_EFI_ACCESS_DENIED, //INFO: Image was not loaded because the platform policy prohibits the image from being loaded. NULL is returned in ImageHandle.
 EFI_STATUS_EFI_IMAGE_LOAD_EFI_SECURITY_VIOLATION, //INFO: Image was loaded and an ImageHandle was created with a valid EFI_LOADED_IMAGE_PROTOCOL. However, the current platform policy specifies that the image should not be started.
}EFI_STATUS_EFI_IMAGE_LOAD;
typedef EFI_STATUS_EFI_IMAGE_LOAD(*EFI_IMAGE_LOAD) (
    BOOLEAN BootPolicy,
    EFI_HANDLE ParentImageHandle,
    EFI_DEVICE_PATH_PROTOCOL *DevicePath OPTIONAL,
    VOID *SourceBuffer OPTIONAL,
    UINTN SourceSize,
    EFI_HANDLE *ImageHandle);

typedef enum
{
  EFI_STATUS_EFI_IMAGE_START_EFI_INVALID_PARAMETER, //INFO: ImageHandle is either an invalid image handle or the image has already been initialized with StartImage
  EFI_STATUS_EFI_IMAGE_START_EXIT_CODE_FROM_IMAGE, //The current platform policy specifies that the image should not be started.
  EFI_STATUS_EFI_IMAGE_START_EFI_SECURITY_VIOLATION, //INFO:Exit code from image.
}EFI_STATUS_EFI_IMAGE_START;
typedef EFI_STATUS_EFI_IMAGE_START(*EFI_IMAGE_START) (
    EFI_HANDLE ImageHandle,
    UINTN *ExitDataSize,
    CHAR16 **ExitData OPTIONAL
    );

typedef enum
{
 EFI_STATUS_EFI_IMAGE_UNLOAD_EFI_SUCCESS, //INFO: The image has been unloaded.
 EFI_STATUS_EFI_IMAGE_UNLOAD_EFI_UNSUPPORTED, //INFO: The image has been started, and does not support unload.
 EFI_STATUS_EFI_IMAGE_UNLOAD_EFI_INVALID_PARAMETER, //INFO: ImageHandle is not a valid image handle.
 EFI_STATUS_EFI_IMAGE_UNLOAD_EXIT_CODE_FROM_UNLOAD_HANDLER, //INFO: Exit code from the image’s unload function.
}EFI_STATUS_EFI_IMAGE_UNLOAD;
typedef EFI_STATUS_EFI_IMAGE_UNLOAD(*EFI_IMAGE_UNLOAD) (EFI_HANDLE ImageHandle);


typedef enum
{
 EFI_STATUS_EFI_EXIT_EFI_SUCCESS, //INFO: The image specified by ImageHandle was unloaded. This condition only occurs for images that have been loaded with LoadImage() but have not been started with StartImage().
 EFI_STATUS_EFI_EXIT_EFI_INVALID_PARAMETER, //INFO: The image specified by ImageHandle has been loaded and started with LoadImage() and StartImage(), but the image is not the currently executing image.
 //INFO: (Does not return.) Image exit. Control is returned to the StartImage() call that invoked the image specified by ImageHandle.
}EFI_STATUS_EFI_EXIT;
typedef EFI_STATUS_EFI_EXIT(*EFI_EXIT) (
    EFI_HANDLE ImageHandle,
    EFI_STATUS ExitStatus,
    UINTN ExitDataSize,
    CHAR16 *ExitData OPTIONAL);

typedef enum
{
 EFI_STATUS_EFI_EXIT_BOOT_SERVICES_EFI_SUCCESS, //INFO: Boot services have been terminated.
 EFI_STATUS_EFI_EXIT_BOOT_SERVICES_EFI_INVALID_PARAMETER, //INFO: MapKey is incorrect.
}EFI_STATUS_EFI_EXIT_BOOT_SERVICES;
typedef EFI_STATUS_EFI_EXIT_BOOT_SERVICES(*EFI_EXIT_BOOT_SERVICES) (
    EFI_HANDLE ImageHandle,
    UINTN MapKey);
