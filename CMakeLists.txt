cmake_minimum_required(VERSION 3.13)

# Project name
project(NetworkPacketProcessing LANGUAGES C)

# Specify the target hardware (optional)
# set(CMAKE_SYSTEM_NAME Generic)
# set(CMAKE_SYSTEM_PROCESSOR ARM)

# FreeRTOS Kernel
set(FREERTOS_KERNEL_DIR ${CMAKE_SOURCE_DIR}/FreeRTOS-Kernel)

# Compiler options
add_compile_options(-Wall -Wextra -std=gnu99)

# Define the source files
set(SOURCES
    src/main.c
    src/reception.c
    src/processing.c
    src/forwarding.c
)

# Include directories
include_directories(
    ${FREERTOS_KERNEL_DIR}/include
    ${CMAKE_SOURCE_DIR}/include
)

# Add FreeRTOS Kernel files
set(FREERTOS_SOURCES
    ${FREERTOS_KERNEL_DIR}/tasks.c
    ${FREERTOS_KERNEL_DIR}/queue.c
    ${FREERTOS_KERNEL_DIR}/timers.c
    ${FREERTOS_KERNEL_DIR}/event_groups.c
    ${FREERTOS_KERNEL_DIR}/list.c
    ${FREERTOS_KERNEL_DIR}/portable/GCC/ARM_CM4F/port.c
    ${FREERTOS_KERNEL_DIR}/portable/MemMang/heap_4.c
)

# Add the executable
add_executable(NetworkPacketProcessing ${SOURCES} ${FREERTOS_SOURCES})

# Link necessary libraries (adjust as needed)
target_link_libraries(NetworkPacketProcessing m)
