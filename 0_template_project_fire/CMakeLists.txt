#must existence
cmake_minimum_required(VERSION 3.5)
#####################################################################################################################################
#project_name
project(STM32CMAKE)
message(${CMAKE_PROJECT_NAME})
message(PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR})
enable_language(ASM)
#####################################################################################################################################
set(CMAKE_SYSTEM_NAME Generic)          
set(CMAKE_SYSTEM_PROCESSOR arm)     
set(CMAKE_CROSSCOMPILING TRUE)          
#####################################################################################################################################
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
set(CMAKE_STRIP "arm-none-eabi-strip")
set(CMAKE_ASM_COMPILER "arm-none-eabi-gcc")
#####################################################################################################################################
#Suppress _CMake_ to compile and link with dynamic link
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
#####################################################################################################################################
#macro_definition
add_definitions(-DUSE_USB_FS)
#####################################################################################################################################
set(START_NAME_PATH Libraries/CMSIS/Device/ST/STM32F7xx/Source/Templates/arm/startup_stm32f767xx.s)
message(START_NAME_PATH=${START_NAME_PATH})
set(LINK_NAME_PATH ${PROJECT_SOURCE_DIR}/User/Dep/STM32F769NIHx_FLASH.ld)
message(LINK_NAME_PATH=${LINK_NAME_PATH})
#####################################################################################################################################
set(ARCH_OPTION "-mthumb -mcpu=cortex-m7")
set(CODE_OPTION "-Os -ffunction-sections -fdata-sections -g")
#####################################################################################################################################
#set(S_OBJECT_OPTION ${ARCH_OPTION})
#message(S_OBJECT_OPTION=${S_OBJECT_OPTION})
set(C_OBJECT_OPTION "${ARCH_OPTION} ${CODE_OPTION}")
message(C_OBJECT_OPTION=${C_OBJECT_OPTION})
set(LINK_OPTION "${ARCH_OPTION} ${CODE_OPTION} -Wl,--gc-sections --specs=nosys.specs -Wl,-Map=${CMAKE_PROJECT_NAME}.map")
message(LINK_OPTION=${LINK_OPTION})
#####################################################################################################################################
#c/c++Compilation Options_Settings ----- Compile
set(CMAKE_C_FLAGS "${C_OBJECT_OPTION}") 
set(CMAKE_CXX_FLAGS "${C_OBJECT_OPTION}")
#c/c++Link Options _ Settings ----------- Links
set(CMAKE_EXE_LINKER_FLAGS "${LINK_OPTION} -T${LINK_NAME_PATH}") 
#####################################################################################################################################
#header_files
include_directories(User
                    Project_BSP
                    Libraries/STM32F7xx_HAL_Driver/Inc
                    Libraries/STM32F7xx_HAL_Driver/Inc/Legacy
                    Libraries/CMSIS/Include
                    Libraries/CMSIS/Device/ST/STM32F7xx/Include
)
#####################################################################################################################################
#source_files
aux_source_directory(User User_src)
aux_source_directory(Project_BSP Project_BSP_src)
aux_source_directory(Libraries/STM32F7xx_HAL_Driver/Src Libraries_STM32F7xx_HAL_Driver_src)
aux_source_directory(Libraries/CMSIS/Device/ST/STM32F7xx/Source/Templates Libraries_CMSIS_Device_ST_STM32F7xx_Source_Templates_src)
#####################################################################################################################################
#add_static_library
add_library(HAL_static STATIC ${Libraries_STM32F7xx_HAL_Driver_src})
#####################################################################################################################################
#merge_all_source_files
set(USER    ${User_src}
            ${Project_BSP_src}
            ${Libraries_STM32F7xx_HAL_Driver_src}
            ${Libraries_CMSIS_Device_ST_STM32F7xx_Source_Templates_src}
        )
#####################################################################################################################################
#exe_lists
#add_executable(STM32CMAKE   ${User_src}
#                            ${Project_BSP_src} 
#                            ${Libraries_STM32F7xx_HAL_Driver_src} 
#                            ${Libraries_CMSIS_Device_ST_STM32F7xx_Source_Templates_src} 
#                            ${START_NAME_PATH}
#                            )
#merge_all_files
add_executable(STM32CMAKE ${USER} ${START_NAME_PATH}) 
##################################################################################################################################### 
#link_static_library_to_target
target_link_libraries(STM32CMAKE HAL_static 
)
#####################################################################################################################################
#cmake _shell 
execute_process(COMMAND  arm-none-eabi-objcopy -O binary ${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}.bin)   
#####################################################################################################################################
#set(CMAKE_ASM_FLAGS  ${S_OBJECT_OPTION} ${START_NAME_PATH} -o Startup.o)
#set(CMAKE_C_FLAGS ${C_OBJECT_OPTION} ${Project_BSP_src} ${Libraries_STM32F7xx_HAL_Driver_src} ${Libraries_CMSIS_Device_ST_STM32F7xx_Source_Templates_src} ${User_src} ${CDEFINE})
#set(CMAKE_C_FLAGS ${LINK_OPTION} ${CDEFINE} -T${LINK_NAME_PATH} ${BUILD_PATH}*.o -o ${TARGET_NAME}.elf)
#####################################################################################################################################
              
#all:$(TARGET_NAME).elf $(TARGET_NAME).hex $(TARGET_NAME).bin
#	mkdir -p Obj
#	mv $(BUILD_PATH)$(TARGET_NAME).elf $(OBJECT_PATH)
#	mv $(BUILD_PATH)$(TARGET_NAME).hex $(OBJECT_PATH)
#	mv $(BUILD_PATH)$(TARGET_NAME).bin $(OBJECT_PATH)
#	mv $(BUILD_PATH)*.o $(OBJECT_PATH)
#	mv map.map $(OBJECT_PATH)

#$(TARGET_NAME).elf: $(START_NAME_PATH) $(SOURCE_NAME_PATH)
#	$(AS) $(S_OBJECT_OPTION) $(START_NAME_PATH) -o Startup.o
#	$(CC) $(C_OBJECT_OPTION) $(HEAD_PATH) $(SOURCE_NAME_PATH) $(CDEFINE)
#	$(CC) $(LINK_OPTION) $(CDEFINE) -T$(LINK_NAME_PATH) $(BUILD_PATH)*.o -o $(TARGET_NAME).elf

#$(TARGET_NAME).hex: $(TARGET_NAME).elf
#	$(OBJCOPY) $(HEX_OPTION) $(TARGET_NAME).elf $(TARGET_NAME).hex

#$(TARGET_NAME).bin: $(TARGET_NAME).elf
#	$(OBJCOPY) $(BIN_OPTION) $(TARGET_NAME).elf $(TARGET_NAME).bin
#clean: 
#	rm -rf Obj
#	rm -rf *.o
#	rm -rf *.map
#####################################################################################################################################
#set(linkFlags "-mcpu=cortex-m7 -mthumb -Os -ffunction-sections -fdata-sections -g -Wl,--gc-sections --specs=nosys.specs -Wl,-Map=map.map")
#set(CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m0  -Wall -fsigned-char -fno-builtin  -ffunction-sections -O0 -g")    #设置编译选项
#set(CMAKE_EXE_LINKER_FLAGS "-static -Wl,-T -Xlinker ${PROJECT_SOURCE_DIR}/src/gnu.ld -u Default_Handler -nostartfiles -Wl,-Map -Xlinker -Wl,--gc-sections")        #设置链接选项
#set(CMAKE_ASM_FLAGS "-v")
#set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DDEBUG")
#set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
#set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-s")
#####################################################################################################################################
#set(CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m7 -Os -ffunction-sections -fdata-sections -g -c -DUSE_USB_FS")
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-Map,map.map -Wl,--gc-sections")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-T${LINK_SCRIPT}")
#set(CMAKE_EXE_LINKER_FLAGS "-DUSE_USB_FS ${linkFlags} " " -TUser/Dep/STM32F769NIHx_FLASH.ld")
#####################################################################################################################################
