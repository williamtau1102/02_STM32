# STM32CubeMX generated include paths
set(MX_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/BSP/LED
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/SYSTEM/delay
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/SYSTEM/sys
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/SYSTEM/usart
)

# STM32CubeMX generated application sources
set(MX_Application_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/BSP/LED/led.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/SYSTEM/delay/delay.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/SYSTEM/sys/sys.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/SYSTEM/usart/usart.c
)

# Interface library for includes and symbols
target_include_directories(stm32cubemx INTERFACE ${MX_Include_Dirs})

# Add STM32CubeMX generated application sources to the project
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${MX_Application_Src})
