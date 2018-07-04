#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/flowmeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/flowmeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=code/bsp/bsp_mc306.c code/bsp/lib_mc306.c code/driver/drv_uart.c code/driver/drv_timer.c code/flowmeter/fm_skfl500.c code/flowmeter/flowmeter.c code/main/main.c code/main/system.c code/main/imath.c code/main/sys_event.c code/main/version.c code/modbus/mb_master.c code/modbus/mb_slaver.c code/module/md_rs485.c code/module/md_led.c code/module/md_usb.c code/module/md_debug.c code/module/md_ir.c code/module/Drv_print.c code/task/task_manager.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/code/bsp/bsp_mc306.o ${OBJECTDIR}/code/bsp/lib_mc306.o ${OBJECTDIR}/code/driver/drv_uart.o ${OBJECTDIR}/code/driver/drv_timer.o ${OBJECTDIR}/code/flowmeter/fm_skfl500.o ${OBJECTDIR}/code/flowmeter/flowmeter.o ${OBJECTDIR}/code/main/main.o ${OBJECTDIR}/code/main/system.o ${OBJECTDIR}/code/main/imath.o ${OBJECTDIR}/code/main/sys_event.o ${OBJECTDIR}/code/main/version.o ${OBJECTDIR}/code/modbus/mb_master.o ${OBJECTDIR}/code/modbus/mb_slaver.o ${OBJECTDIR}/code/module/md_rs485.o ${OBJECTDIR}/code/module/md_led.o ${OBJECTDIR}/code/module/md_usb.o ${OBJECTDIR}/code/module/md_debug.o ${OBJECTDIR}/code/module/md_ir.o ${OBJECTDIR}/code/module/Drv_print.o ${OBJECTDIR}/code/task/task_manager.o
POSSIBLE_DEPFILES=${OBJECTDIR}/code/bsp/bsp_mc306.o.d ${OBJECTDIR}/code/bsp/lib_mc306.o.d ${OBJECTDIR}/code/driver/drv_uart.o.d ${OBJECTDIR}/code/driver/drv_timer.o.d ${OBJECTDIR}/code/flowmeter/fm_skfl500.o.d ${OBJECTDIR}/code/flowmeter/flowmeter.o.d ${OBJECTDIR}/code/main/main.o.d ${OBJECTDIR}/code/main/system.o.d ${OBJECTDIR}/code/main/imath.o.d ${OBJECTDIR}/code/main/sys_event.o.d ${OBJECTDIR}/code/main/version.o.d ${OBJECTDIR}/code/modbus/mb_master.o.d ${OBJECTDIR}/code/modbus/mb_slaver.o.d ${OBJECTDIR}/code/module/md_rs485.o.d ${OBJECTDIR}/code/module/md_led.o.d ${OBJECTDIR}/code/module/md_usb.o.d ${OBJECTDIR}/code/module/md_debug.o.d ${OBJECTDIR}/code/module/md_ir.o.d ${OBJECTDIR}/code/module/Drv_print.o.d ${OBJECTDIR}/code/task/task_manager.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/code/bsp/bsp_mc306.o ${OBJECTDIR}/code/bsp/lib_mc306.o ${OBJECTDIR}/code/driver/drv_uart.o ${OBJECTDIR}/code/driver/drv_timer.o ${OBJECTDIR}/code/flowmeter/fm_skfl500.o ${OBJECTDIR}/code/flowmeter/flowmeter.o ${OBJECTDIR}/code/main/main.o ${OBJECTDIR}/code/main/system.o ${OBJECTDIR}/code/main/imath.o ${OBJECTDIR}/code/main/sys_event.o ${OBJECTDIR}/code/main/version.o ${OBJECTDIR}/code/modbus/mb_master.o ${OBJECTDIR}/code/modbus/mb_slaver.o ${OBJECTDIR}/code/module/md_rs485.o ${OBJECTDIR}/code/module/md_led.o ${OBJECTDIR}/code/module/md_usb.o ${OBJECTDIR}/code/module/md_debug.o ${OBJECTDIR}/code/module/md_ir.o ${OBJECTDIR}/code/module/Drv_print.o ${OBJECTDIR}/code/task/task_manager.o

# Source Files
SOURCEFILES=code/bsp/bsp_mc306.c code/bsp/lib_mc306.c code/driver/drv_uart.c code/driver/drv_timer.c code/flowmeter/fm_skfl500.c code/flowmeter/flowmeter.c code/main/main.c code/main/system.c code/main/imath.c code/main/sys_event.c code/main/version.c code/modbus/mb_master.c code/modbus/mb_slaver.c code/module/md_rs485.c code/module/md_led.c code/module/md_usb.c code/module/md_debug.c code/module/md_ir.c code/module/Drv_print.c code/task/task_manager.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/flowmeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GA306
MP_LINKER_FILE_OPTION=,-Tp24FJ64GA306.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/code/bsp/bsp_mc306.o: code/bsp/bsp_mc306.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/bsp" 
	@${RM} ${OBJECTDIR}/code/bsp/bsp_mc306.o.d 
	@${RM} ${OBJECTDIR}/code/bsp/bsp_mc306.o.ok ${OBJECTDIR}/code/bsp/bsp_mc306.o.err 
	@${RM} ${OBJECTDIR}/code/bsp/bsp_mc306.o 
	@${FIXDEPS} "${OBJECTDIR}/code/bsp/bsp_mc306.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/bsp/bsp_mc306.o.d" -o ${OBJECTDIR}/code/bsp/bsp_mc306.o code/bsp/bsp_mc306.c    
	
${OBJECTDIR}/code/bsp/lib_mc306.o: code/bsp/lib_mc306.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/bsp" 
	@${RM} ${OBJECTDIR}/code/bsp/lib_mc306.o.d 
	@${RM} ${OBJECTDIR}/code/bsp/lib_mc306.o.ok ${OBJECTDIR}/code/bsp/lib_mc306.o.err 
	@${RM} ${OBJECTDIR}/code/bsp/lib_mc306.o 
	@${FIXDEPS} "${OBJECTDIR}/code/bsp/lib_mc306.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/bsp/lib_mc306.o.d" -o ${OBJECTDIR}/code/bsp/lib_mc306.o code/bsp/lib_mc306.c    
	
${OBJECTDIR}/code/driver/drv_uart.o: code/driver/drv_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/driver" 
	@${RM} ${OBJECTDIR}/code/driver/drv_uart.o.d 
	@${RM} ${OBJECTDIR}/code/driver/drv_uart.o.ok ${OBJECTDIR}/code/driver/drv_uart.o.err 
	@${RM} ${OBJECTDIR}/code/driver/drv_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/code/driver/drv_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/driver/drv_uart.o.d" -o ${OBJECTDIR}/code/driver/drv_uart.o code/driver/drv_uart.c    
	
${OBJECTDIR}/code/driver/drv_timer.o: code/driver/drv_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/driver" 
	@${RM} ${OBJECTDIR}/code/driver/drv_timer.o.d 
	@${RM} ${OBJECTDIR}/code/driver/drv_timer.o.ok ${OBJECTDIR}/code/driver/drv_timer.o.err 
	@${RM} ${OBJECTDIR}/code/driver/drv_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/code/driver/drv_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/driver/drv_timer.o.d" -o ${OBJECTDIR}/code/driver/drv_timer.o code/driver/drv_timer.c    
	
${OBJECTDIR}/code/flowmeter/fm_skfl500.o: code/flowmeter/fm_skfl500.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/flowmeter" 
	@${RM} ${OBJECTDIR}/code/flowmeter/fm_skfl500.o.d 
	@${RM} ${OBJECTDIR}/code/flowmeter/fm_skfl500.o.ok ${OBJECTDIR}/code/flowmeter/fm_skfl500.o.err 
	@${RM} ${OBJECTDIR}/code/flowmeter/fm_skfl500.o 
	@${FIXDEPS} "${OBJECTDIR}/code/flowmeter/fm_skfl500.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/flowmeter/fm_skfl500.o.d" -o ${OBJECTDIR}/code/flowmeter/fm_skfl500.o code/flowmeter/fm_skfl500.c    
	
${OBJECTDIR}/code/flowmeter/flowmeter.o: code/flowmeter/flowmeter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/flowmeter" 
	@${RM} ${OBJECTDIR}/code/flowmeter/flowmeter.o.d 
	@${RM} ${OBJECTDIR}/code/flowmeter/flowmeter.o.ok ${OBJECTDIR}/code/flowmeter/flowmeter.o.err 
	@${RM} ${OBJECTDIR}/code/flowmeter/flowmeter.o 
	@${FIXDEPS} "${OBJECTDIR}/code/flowmeter/flowmeter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/flowmeter/flowmeter.o.d" -o ${OBJECTDIR}/code/flowmeter/flowmeter.o code/flowmeter/flowmeter.c    
	
${OBJECTDIR}/code/main/main.o: code/main/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/main" 
	@${RM} ${OBJECTDIR}/code/main/main.o.d 
	@${RM} ${OBJECTDIR}/code/main/main.o.ok ${OBJECTDIR}/code/main/main.o.err 
	@${RM} ${OBJECTDIR}/code/main/main.o 
	@${FIXDEPS} "${OBJECTDIR}/code/main/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/main/main.o.d" -o ${OBJECTDIR}/code/main/main.o code/main/main.c    
	
${OBJECTDIR}/code/main/system.o: code/main/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/main" 
	@${RM} ${OBJECTDIR}/code/main/system.o.d 
	@${RM} ${OBJECTDIR}/code/main/system.o.ok ${OBJECTDIR}/code/main/system.o.err 
	@${RM} ${OBJECTDIR}/code/main/system.o 
	@${FIXDEPS} "${OBJECTDIR}/code/main/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/main/system.o.d" -o ${OBJECTDIR}/code/main/system.o code/main/system.c    
	
${OBJECTDIR}/code/main/imath.o: code/main/imath.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/main" 
	@${RM} ${OBJECTDIR}/code/main/imath.o.d 
	@${RM} ${OBJECTDIR}/code/main/imath.o.ok ${OBJECTDIR}/code/main/imath.o.err 
	@${RM} ${OBJECTDIR}/code/main/imath.o 
	@${FIXDEPS} "${OBJECTDIR}/code/main/imath.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/main/imath.o.d" -o ${OBJECTDIR}/code/main/imath.o code/main/imath.c    
	
${OBJECTDIR}/code/main/sys_event.o: code/main/sys_event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/main" 
	@${RM} ${OBJECTDIR}/code/main/sys_event.o.d 
	@${RM} ${OBJECTDIR}/code/main/sys_event.o.ok ${OBJECTDIR}/code/main/sys_event.o.err 
	@${RM} ${OBJECTDIR}/code/main/sys_event.o 
	@${FIXDEPS} "${OBJECTDIR}/code/main/sys_event.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/main/sys_event.o.d" -o ${OBJECTDIR}/code/main/sys_event.o code/main/sys_event.c    
	
${OBJECTDIR}/code/main/version.o: code/main/version.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/main" 
	@${RM} ${OBJECTDIR}/code/main/version.o.d 
	@${RM} ${OBJECTDIR}/code/main/version.o.ok ${OBJECTDIR}/code/main/version.o.err 
	@${RM} ${OBJECTDIR}/code/main/version.o 
	@${FIXDEPS} "${OBJECTDIR}/code/main/version.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/main/version.o.d" -o ${OBJECTDIR}/code/main/version.o code/main/version.c    
	
${OBJECTDIR}/code/modbus/mb_master.o: code/modbus/mb_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/modbus" 
	@${RM} ${OBJECTDIR}/code/modbus/mb_master.o.d 
	@${RM} ${OBJECTDIR}/code/modbus/mb_master.o.ok ${OBJECTDIR}/code/modbus/mb_master.o.err 
	@${RM} ${OBJECTDIR}/code/modbus/mb_master.o 
	@${FIXDEPS} "${OBJECTDIR}/code/modbus/mb_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/modbus/mb_master.o.d" -o ${OBJECTDIR}/code/modbus/mb_master.o code/modbus/mb_master.c    
	
${OBJECTDIR}/code/modbus/mb_slaver.o: code/modbus/mb_slaver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/modbus" 
	@${RM} ${OBJECTDIR}/code/modbus/mb_slaver.o.d 
	@${RM} ${OBJECTDIR}/code/modbus/mb_slaver.o.ok ${OBJECTDIR}/code/modbus/mb_slaver.o.err 
	@${RM} ${OBJECTDIR}/code/modbus/mb_slaver.o 
	@${FIXDEPS} "${OBJECTDIR}/code/modbus/mb_slaver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/modbus/mb_slaver.o.d" -o ${OBJECTDIR}/code/modbus/mb_slaver.o code/modbus/mb_slaver.c    
	
${OBJECTDIR}/code/module/md_rs485.o: code/module/md_rs485.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/md_rs485.o.d 
	@${RM} ${OBJECTDIR}/code/module/md_rs485.o.ok ${OBJECTDIR}/code/module/md_rs485.o.err 
	@${RM} ${OBJECTDIR}/code/module/md_rs485.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/md_rs485.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/md_rs485.o.d" -o ${OBJECTDIR}/code/module/md_rs485.o code/module/md_rs485.c    
	
${OBJECTDIR}/code/module/md_led.o: code/module/md_led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/md_led.o.d 
	@${RM} ${OBJECTDIR}/code/module/md_led.o.ok ${OBJECTDIR}/code/module/md_led.o.err 
	@${RM} ${OBJECTDIR}/code/module/md_led.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/md_led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/md_led.o.d" -o ${OBJECTDIR}/code/module/md_led.o code/module/md_led.c    
	
${OBJECTDIR}/code/module/md_usb.o: code/module/md_usb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/md_usb.o.d 
	@${RM} ${OBJECTDIR}/code/module/md_usb.o.ok ${OBJECTDIR}/code/module/md_usb.o.err 
	@${RM} ${OBJECTDIR}/code/module/md_usb.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/md_usb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/md_usb.o.d" -o ${OBJECTDIR}/code/module/md_usb.o code/module/md_usb.c    
	
${OBJECTDIR}/code/module/md_debug.o: code/module/md_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/md_debug.o.d 
	@${RM} ${OBJECTDIR}/code/module/md_debug.o.ok ${OBJECTDIR}/code/module/md_debug.o.err 
	@${RM} ${OBJECTDIR}/code/module/md_debug.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/md_debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/md_debug.o.d" -o ${OBJECTDIR}/code/module/md_debug.o code/module/md_debug.c    
	
${OBJECTDIR}/code/module/md_ir.o: code/module/md_ir.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/md_ir.o.d 
	@${RM} ${OBJECTDIR}/code/module/md_ir.o.ok ${OBJECTDIR}/code/module/md_ir.o.err 
	@${RM} ${OBJECTDIR}/code/module/md_ir.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/md_ir.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/md_ir.o.d" -o ${OBJECTDIR}/code/module/md_ir.o code/module/md_ir.c    
	
${OBJECTDIR}/code/module/Drv_print.o: code/module/Drv_print.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/Drv_print.o.d 
	@${RM} ${OBJECTDIR}/code/module/Drv_print.o.ok ${OBJECTDIR}/code/module/Drv_print.o.err 
	@${RM} ${OBJECTDIR}/code/module/Drv_print.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/Drv_print.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/Drv_print.o.d" -o ${OBJECTDIR}/code/module/Drv_print.o code/module/Drv_print.c    
	
${OBJECTDIR}/code/task/task_manager.o: code/task/task_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/task" 
	@${RM} ${OBJECTDIR}/code/task/task_manager.o.d 
	@${RM} ${OBJECTDIR}/code/task/task_manager.o.ok ${OBJECTDIR}/code/task/task_manager.o.err 
	@${RM} ${OBJECTDIR}/code/task/task_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/code/task/task_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/task/task_manager.o.d" -o ${OBJECTDIR}/code/task/task_manager.o code/task/task_manager.c    
	
else
${OBJECTDIR}/code/bsp/bsp_mc306.o: code/bsp/bsp_mc306.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/bsp" 
	@${RM} ${OBJECTDIR}/code/bsp/bsp_mc306.o.d 
	@${RM} ${OBJECTDIR}/code/bsp/bsp_mc306.o.ok ${OBJECTDIR}/code/bsp/bsp_mc306.o.err 
	@${RM} ${OBJECTDIR}/code/bsp/bsp_mc306.o 
	@${FIXDEPS} "${OBJECTDIR}/code/bsp/bsp_mc306.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/bsp/bsp_mc306.o.d" -o ${OBJECTDIR}/code/bsp/bsp_mc306.o code/bsp/bsp_mc306.c    
	
${OBJECTDIR}/code/bsp/lib_mc306.o: code/bsp/lib_mc306.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/bsp" 
	@${RM} ${OBJECTDIR}/code/bsp/lib_mc306.o.d 
	@${RM} ${OBJECTDIR}/code/bsp/lib_mc306.o.ok ${OBJECTDIR}/code/bsp/lib_mc306.o.err 
	@${RM} ${OBJECTDIR}/code/bsp/lib_mc306.o 
	@${FIXDEPS} "${OBJECTDIR}/code/bsp/lib_mc306.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/bsp/lib_mc306.o.d" -o ${OBJECTDIR}/code/bsp/lib_mc306.o code/bsp/lib_mc306.c    
	
${OBJECTDIR}/code/driver/drv_uart.o: code/driver/drv_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/driver" 
	@${RM} ${OBJECTDIR}/code/driver/drv_uart.o.d 
	@${RM} ${OBJECTDIR}/code/driver/drv_uart.o.ok ${OBJECTDIR}/code/driver/drv_uart.o.err 
	@${RM} ${OBJECTDIR}/code/driver/drv_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/code/driver/drv_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/driver/drv_uart.o.d" -o ${OBJECTDIR}/code/driver/drv_uart.o code/driver/drv_uart.c    
	
${OBJECTDIR}/code/driver/drv_timer.o: code/driver/drv_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/driver" 
	@${RM} ${OBJECTDIR}/code/driver/drv_timer.o.d 
	@${RM} ${OBJECTDIR}/code/driver/drv_timer.o.ok ${OBJECTDIR}/code/driver/drv_timer.o.err 
	@${RM} ${OBJECTDIR}/code/driver/drv_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/code/driver/drv_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/driver/drv_timer.o.d" -o ${OBJECTDIR}/code/driver/drv_timer.o code/driver/drv_timer.c    
	
${OBJECTDIR}/code/flowmeter/fm_skfl500.o: code/flowmeter/fm_skfl500.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/flowmeter" 
	@${RM} ${OBJECTDIR}/code/flowmeter/fm_skfl500.o.d 
	@${RM} ${OBJECTDIR}/code/flowmeter/fm_skfl500.o.ok ${OBJECTDIR}/code/flowmeter/fm_skfl500.o.err 
	@${RM} ${OBJECTDIR}/code/flowmeter/fm_skfl500.o 
	@${FIXDEPS} "${OBJECTDIR}/code/flowmeter/fm_skfl500.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/flowmeter/fm_skfl500.o.d" -o ${OBJECTDIR}/code/flowmeter/fm_skfl500.o code/flowmeter/fm_skfl500.c    
	
${OBJECTDIR}/code/flowmeter/flowmeter.o: code/flowmeter/flowmeter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/flowmeter" 
	@${RM} ${OBJECTDIR}/code/flowmeter/flowmeter.o.d 
	@${RM} ${OBJECTDIR}/code/flowmeter/flowmeter.o.ok ${OBJECTDIR}/code/flowmeter/flowmeter.o.err 
	@${RM} ${OBJECTDIR}/code/flowmeter/flowmeter.o 
	@${FIXDEPS} "${OBJECTDIR}/code/flowmeter/flowmeter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/flowmeter/flowmeter.o.d" -o ${OBJECTDIR}/code/flowmeter/flowmeter.o code/flowmeter/flowmeter.c    
	
${OBJECTDIR}/code/main/main.o: code/main/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/main" 
	@${RM} ${OBJECTDIR}/code/main/main.o.d 
	@${RM} ${OBJECTDIR}/code/main/main.o.ok ${OBJECTDIR}/code/main/main.o.err 
	@${RM} ${OBJECTDIR}/code/main/main.o 
	@${FIXDEPS} "${OBJECTDIR}/code/main/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/main/main.o.d" -o ${OBJECTDIR}/code/main/main.o code/main/main.c    
	
${OBJECTDIR}/code/main/system.o: code/main/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/main" 
	@${RM} ${OBJECTDIR}/code/main/system.o.d 
	@${RM} ${OBJECTDIR}/code/main/system.o.ok ${OBJECTDIR}/code/main/system.o.err 
	@${RM} ${OBJECTDIR}/code/main/system.o 
	@${FIXDEPS} "${OBJECTDIR}/code/main/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/main/system.o.d" -o ${OBJECTDIR}/code/main/system.o code/main/system.c    
	
${OBJECTDIR}/code/main/imath.o: code/main/imath.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/main" 
	@${RM} ${OBJECTDIR}/code/main/imath.o.d 
	@${RM} ${OBJECTDIR}/code/main/imath.o.ok ${OBJECTDIR}/code/main/imath.o.err 
	@${RM} ${OBJECTDIR}/code/main/imath.o 
	@${FIXDEPS} "${OBJECTDIR}/code/main/imath.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/main/imath.o.d" -o ${OBJECTDIR}/code/main/imath.o code/main/imath.c    
	
${OBJECTDIR}/code/main/sys_event.o: code/main/sys_event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/main" 
	@${RM} ${OBJECTDIR}/code/main/sys_event.o.d 
	@${RM} ${OBJECTDIR}/code/main/sys_event.o.ok ${OBJECTDIR}/code/main/sys_event.o.err 
	@${RM} ${OBJECTDIR}/code/main/sys_event.o 
	@${FIXDEPS} "${OBJECTDIR}/code/main/sys_event.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/main/sys_event.o.d" -o ${OBJECTDIR}/code/main/sys_event.o code/main/sys_event.c    
	
${OBJECTDIR}/code/main/version.o: code/main/version.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/main" 
	@${RM} ${OBJECTDIR}/code/main/version.o.d 
	@${RM} ${OBJECTDIR}/code/main/version.o.ok ${OBJECTDIR}/code/main/version.o.err 
	@${RM} ${OBJECTDIR}/code/main/version.o 
	@${FIXDEPS} "${OBJECTDIR}/code/main/version.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/main/version.o.d" -o ${OBJECTDIR}/code/main/version.o code/main/version.c    
	
${OBJECTDIR}/code/modbus/mb_master.o: code/modbus/mb_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/modbus" 
	@${RM} ${OBJECTDIR}/code/modbus/mb_master.o.d 
	@${RM} ${OBJECTDIR}/code/modbus/mb_master.o.ok ${OBJECTDIR}/code/modbus/mb_master.o.err 
	@${RM} ${OBJECTDIR}/code/modbus/mb_master.o 
	@${FIXDEPS} "${OBJECTDIR}/code/modbus/mb_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/modbus/mb_master.o.d" -o ${OBJECTDIR}/code/modbus/mb_master.o code/modbus/mb_master.c    
	
${OBJECTDIR}/code/modbus/mb_slaver.o: code/modbus/mb_slaver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/modbus" 
	@${RM} ${OBJECTDIR}/code/modbus/mb_slaver.o.d 
	@${RM} ${OBJECTDIR}/code/modbus/mb_slaver.o.ok ${OBJECTDIR}/code/modbus/mb_slaver.o.err 
	@${RM} ${OBJECTDIR}/code/modbus/mb_slaver.o 
	@${FIXDEPS} "${OBJECTDIR}/code/modbus/mb_slaver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/modbus/mb_slaver.o.d" -o ${OBJECTDIR}/code/modbus/mb_slaver.o code/modbus/mb_slaver.c    
	
${OBJECTDIR}/code/module/md_rs485.o: code/module/md_rs485.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/md_rs485.o.d 
	@${RM} ${OBJECTDIR}/code/module/md_rs485.o.ok ${OBJECTDIR}/code/module/md_rs485.o.err 
	@${RM} ${OBJECTDIR}/code/module/md_rs485.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/md_rs485.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/md_rs485.o.d" -o ${OBJECTDIR}/code/module/md_rs485.o code/module/md_rs485.c    
	
${OBJECTDIR}/code/module/md_led.o: code/module/md_led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/md_led.o.d 
	@${RM} ${OBJECTDIR}/code/module/md_led.o.ok ${OBJECTDIR}/code/module/md_led.o.err 
	@${RM} ${OBJECTDIR}/code/module/md_led.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/md_led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/md_led.o.d" -o ${OBJECTDIR}/code/module/md_led.o code/module/md_led.c    
	
${OBJECTDIR}/code/module/md_usb.o: code/module/md_usb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/md_usb.o.d 
	@${RM} ${OBJECTDIR}/code/module/md_usb.o.ok ${OBJECTDIR}/code/module/md_usb.o.err 
	@${RM} ${OBJECTDIR}/code/module/md_usb.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/md_usb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/md_usb.o.d" -o ${OBJECTDIR}/code/module/md_usb.o code/module/md_usb.c    
	
${OBJECTDIR}/code/module/md_debug.o: code/module/md_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/md_debug.o.d 
	@${RM} ${OBJECTDIR}/code/module/md_debug.o.ok ${OBJECTDIR}/code/module/md_debug.o.err 
	@${RM} ${OBJECTDIR}/code/module/md_debug.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/md_debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/md_debug.o.d" -o ${OBJECTDIR}/code/module/md_debug.o code/module/md_debug.c    
	
${OBJECTDIR}/code/module/md_ir.o: code/module/md_ir.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/md_ir.o.d 
	@${RM} ${OBJECTDIR}/code/module/md_ir.o.ok ${OBJECTDIR}/code/module/md_ir.o.err 
	@${RM} ${OBJECTDIR}/code/module/md_ir.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/md_ir.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/md_ir.o.d" -o ${OBJECTDIR}/code/module/md_ir.o code/module/md_ir.c    
	
${OBJECTDIR}/code/module/Drv_print.o: code/module/Drv_print.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/module" 
	@${RM} ${OBJECTDIR}/code/module/Drv_print.o.d 
	@${RM} ${OBJECTDIR}/code/module/Drv_print.o.ok ${OBJECTDIR}/code/module/Drv_print.o.err 
	@${RM} ${OBJECTDIR}/code/module/Drv_print.o 
	@${FIXDEPS} "${OBJECTDIR}/code/module/Drv_print.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/module/Drv_print.o.d" -o ${OBJECTDIR}/code/module/Drv_print.o code/module/Drv_print.c    
	
${OBJECTDIR}/code/task/task_manager.o: code/task/task_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/code/task" 
	@${RM} ${OBJECTDIR}/code/task/task_manager.o.d 
	@${RM} ${OBJECTDIR}/code/task/task_manager.o.ok ${OBJECTDIR}/code/task/task_manager.o.err 
	@${RM} ${OBJECTDIR}/code/task/task_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/code/task/task_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"code/main" -I"code/bsp" -I"code/driver" -I"code/task" -I"code/module" -I"code/flowmeter" -I"code/modbus" -mlarge-code -MMD -MF "${OBJECTDIR}/code/task/task_manager.o.d" -o ${OBJECTDIR}/code/task/task_manager.o code/task/task_manager.c    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/flowmeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/flowmeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/flowmeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/flowmeter.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/flowmeter.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
