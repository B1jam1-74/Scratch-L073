# STM32L073RZ CMSIS Files

This package contains the CMSIS (Cortex Microcontroller Software Interface Standard) header files for the STM32L073RZ microcontroller.

## Files Included

- **stm32l0xx.h** - Main family header file
- **system_stm32l0xx.h** - System configuration header
- **stm32l073xx.h** - Device-specific header with all peripheral definitions

## How to Use

1. **Copy the Include folder** to your project directory

2. **Update your code** to use the correct headers:
   ```c
   #include <stm32l073xx.h>  // Instead of <stm32g031xx.h>
   ```

3. **Define the device** in your compiler settings or at the top of your main file:
   ```c
   #define STM32L073xx
   ```

4. **Your corrected code** should look like this:

```c
// main.c
#include <stdint.h>
#include <stm32l073xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "timer.h"

int main(void)
{
    GPIO_Init();
    SYSTICK_Init();

    while(1){
        SYSTICK_Delay(1000);
        GPIOA->ODR ^= 1 << GPIO_ODR_OD5_Pos;
    }
}

// gpio.c
#include <stdint.h>
#include <stm32l073xx.h>
#include "main.h"
#include "gpio.h"

void GPIO_Init(void){
    RCC->IOPENR   |= RCC_IOPENR_GPIOAEN | RCC_IOPENR_GPIOBEN | RCC_IOPENR_GPIOCEN;
    GPIOA->MODER  &= ~(GPIO_MODER_MODE5);
    GPIOA->MODER  |= (0x1 << GPIO_MODER_MODE5_Pos);  // Output mode (01)
}
```

## Key Differences from STM32G031

### Register Naming
- Both families use `RCC->IOPENR` for GPIO clock enable
- Both use similar GPIO register structures
- Bit definitions are the same: `GPIO_MODER_MODE5`, `GPIO_ODR_OD5_Pos`, etc.

### LED Pin
- STM32L073RZ Nucleo-64: PA5 (Green LED - LD2)

## Important Notes

1. The STM32L073RZ uses a Cortex-M0+ core (same as G031)
2. Make sure to enable the GPIO clock before configuring the pin
3. The LED on the Nucleo board (LD2) is connected to PA5
4. For output mode, set MODER bits to `01` (0x1)

## Additional Resources

- STM32L073 Reference Manual: RM0367
- STM32L073 Datasheet: Available from STMicroelectronics
- Nucleo-64 User Manual: UM1724

## Compiler Setup

### Makefile
Add the include path:
```makefile
CFLAGS += -DSTM32L073xx
CFLAGS += -I./STM32L0xx/Include
```

### IAR
Project Options > C/C++ Compiler > Preprocessor:
- Defined symbols: `STM32L073xx`
- Additional include directories: `$PROJ_DIR$/STM32L0xx/Include`

### Keil
Project > Options for Target > C/C++:
- Preprocessor Symbols: `STM32L073xx`
- Include Paths: Add `STM32L0xx/Include`

### GCC/Makefile
```makefile
CFLAGS += -DSTM32L073xx
CFLAGS += -I./STM32L0xx/Include
```

## Note on CMSIS Core Files

You'll also need the ARM CMSIS Core files (`core_cm0plus.h`, etc.). These are typically provided by:
- Your IDE (Keil, IAR, STM32CubeIDE)
- ARM CMSIS Pack: https://github.com/ARM-software/CMSIS_5

Place them in the same Include directory or add their path to your project.
