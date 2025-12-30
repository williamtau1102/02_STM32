# WARSHIP_UART: STM32F1 UART Project Guidelines

## Project Overview
**WARSHIP_UART** is an embedded microcontroller firmware project for STM32F103ZET6 (STM32F1 family) with a focus on multi-UART serial communication. The project is **generated and maintained by STM32CubeMX**, creating a clear separation between auto-generated code and user modifications.

### Architecture
- **Hardware**: STM32F103ZET6 with 3 UART interfaces (USART1, USART2, USART3)
- **Build System**: CMake-based (modern alternative to STM32CubeMX IDE)
- **HAL Layer**: STM32F1xx HAL drivers (`Drivers/STM32F1xx_HAL_Driver/`)
- **Toolchain**: GCC ARM None-EABI with JLink debugging support
- **Configuration**: STM32CubeMX `.ioc` file (WARSHIP_UART.ioc) is the source of truth for hardware setup

## Critical Developer Workflows

### Build Process
```bash
# Standard build (parallelized)
make -j16

# Rebuild from scratch
rmdir -r build; make -j16
```
- **Build output**: `build/` directory contains compiled output (Debug/Release)
- **Artifacts**: ELF file (`WARSHIP_UART.elf`), HEX file (`WARSHIP_UART.hex`)
- **Configuration**: CMakeLists.txt orchestrates STM32CubeMX cmake subdirectory

### Debugging & Programming
- **Flash via JLink**: Use `jlink-flash` task → programs HEX at 0x8000000
- **Debug with Ozone**: Use `jlink-debug-ozone` task → launches J-Link Ozone GUI debugger
- **Device**: stm32f103zet6 (configured in tasks.json)

### Hardware Configuration Workflow
1. Open `WARSHIP_UART.ioc` in STM32CubeMX GUI
2. Modify peripheral settings (clock, GPIO, UART params)
3. Generate code → updates `cmake/stm32cubemx/` and peripheral init files (e.g., `Src/usart.c`)
4. Rebuild: Generated files regenerate user sections; modifications in `/* USER CODE BEGIN/END */` blocks are preserved

## Code Organization & Patterns

### File Layout
```
Inc/              # Header files (user-facing API)
├── usart.h      # UART function prototypes (MX_USARTx_UART_Init)
├── gpio.h, i2c.h, spi.h, etc.
└── main.h

Src/              # Implementation files (MX-generated peripherals)
├── main.c        # Application entry point
├── usart.c       # UART initialization & ISR handlers
├── stm32f1xx_it.c # Cortex-M3 interrupt handlers
├── stm32f1xx_hal_msp.c # MSP (MCU Support Package) - pin config
└── system_stm32f1xx.c # System clock setup

Drivers/STM32F1xx_HAL_Driver/  # Immutable vendor HAL
├── Inc/stm32f1xx_hal_uart.h  # HAL API definitions
└── Src/                       # HAL implementations
```

### STM32CubeMX-Generated Code Pattern
**All peripheral initialization follows this pattern:**

1. **Header** (`Inc/usart.h`):
   ```c
   void MX_USART1_UART_Init(void);
   extern UART_HandleTypeDef huart1;
   ```

2. **Implementation** (`Src/usart.c`):
   ```c
   UART_HandleTypeDef huart1;  // Handle instance

   void MX_USART1_UART_Init(void) {
       /* USER CODE BEGIN USART1_Init 0 */  // Custom pre-init code
       /* USER CODE END USART1_Init 0 */

       huart1.Instance = USART1;
       huart1.Init.BaudRate = 115200;
       // ... configuration parameters ...

       if (HAL_UART_Init(&huart1) != HAL_OK)
           Error_Handler();

       /* USER CODE BEGIN USART1_Init 2 */  // Custom post-init code
       /* USER CODE END USART1_Init 2 */
   }
   ```

**Critical Rule**: Only modify code within `/* USER CODE BEGIN/END */` blocks. Code outside these blocks is regenerated when CubeMX generates code again.

### UART Configuration (3x Instances)
All UART peripherals are configured identically:
- **Baud Rate**: 115200
- **Word Length**: 8-bit
- **Stop Bits**: 1
- **Parity**: None
- **Mode**: TX/RX enabled
- **Hardware Flow Control**: Disabled
- **Oversampling**: 16x (standard)

Instances: USART1 (PB6/PB7), USART2 (PA2/PA3), USART3 (PB10/PB11)

## Integration Points

### Hardware Initialization Chain
```
main() → SystemClock_Config() → MX_*_Init() functions → HAL_*_Init()
         → HAL_UART_Init(&huart) → [MSP callback] HAL_UART_MspInit()
```
- **MSP functions** in `stm32f1xx_hal_msp.c` configure GPIO pins and clock enables
- **IRQ handlers** in `stm32f1xx_it.c` redirect to `HAL_UART_IRQHandler(&huart)`

### External Dependencies
- **STM32F1xx HAL**: Located in `Drivers/STM32F1xx_HAL_Driver/` (vendor-provided, don't modify)
- **CMSIS**: `Drivers/CMSIS/` contains Cortex-M3 core definitions
- **Linker Script**: `STM32F103XX_FLASH.ld` defines memory layout
- **Startup Code**: `startup_stm32f103xe.s` (ARM ASM, minimal modifications needed)

### Build Dependencies
- **CMake**: Version 3.22+ required (see CMakeLists.txt)
- **Compiler**: ARM GCC (`arm-none-eabi-gcc`) configured via `cmake/gcc-arm-none-eabi.cmake`
- **CMake Presets**: `CMakePresets.json` defines Debug build configuration

## Project-Specific Conventions

### Error Handling
- **Single error callback**: `Error_Handler()` in `main.c` (infinite loop by default)
- **Convention**: All HAL init calls check return value: `if (HAL_UART_Init(...) != HAL_OK) Error_Handler();`
- **Status codes**: `HAL_StatusTypeDef` (HAL_OK, HAL_ERROR, HAL_TIMEOUT, HAL_BUSY)

### Callback Registration
- **Available callbacks**: TX complete, RX complete, errors, IDLE detection, etc.
- **Location**: User code should register weak callbacks in `main.c` or init code, NOT in HAL files
- **Example**: Override `HAL_UART_RxCpltCallback(huart)` for RX interrupt handling

### Memory Model
- **Flash**: 512KB (STM32F103ZET6)
- **RAM**: 64KB total
- **Stack**: Grows downward from end of RAM (defined in linker script)
- **Heap**: Used by malloc/free (if enabled)

## When Modifying Code

### Safe Modifications
- ✅ Add code in `/* USER CODE BEGIN/END */` blocks
- ✅ Modify `main.c` application logic
- ✅ Add custom peripheral handlers in `stm32f1xx_it.c` USER CODE sections
- ✅ Change configuration via STM32CubeMX `.ioc` file

### Dangerous Modifications
- ❌ Editing HAL driver files (`Drivers/STM32F1xx_HAL_Driver/`)
- ❌ Modifying generated code outside USER CODE blocks (lost on regeneration)
- ❌ Manually changing `.ioc`-generated code in `Src/usart.c`, `Src/gpio.c`, etc.
- ❌ Changing linker script memory regions without updating hardware device database

### After CubeMX Changes
1. Regenerate code in STM32CubeMX GUI
2. Rebuild project: `rmdir -r build; make -j16`
3. All USER CODE modifications persist; generated sections update

## Compilation & Debugging

### Understanding Build Output
- `compile_commands.json` generated for clangd indexing (see `.clangd` settings)
- Problem matchers in tasks.json parse GCC output to populate VS Code "Problems" panel
- Ninja build system used in `build/Debug/` (configured by CMake)

### Debug Symbols
- Debug build includes `-g` flag for Ozone/GDB compatibility
- ELF file contains full symbol table; HEX file is deployment format

### Common Build Issues
- **"make: not found"**: Install MinGW or use Git Bash
- **"arm-none-eabi-gcc not in PATH"**: Install ARM toolchain; verify in `cmake/gcc-arm-none-eabi.cmake`
- **CMake cache stale**: Run full rebuild with `rmdir -r build` first
