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
FINAL_IMAGE=${DISTDIR}/VCP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/VCP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/nvm/src/nvm.c mcc_generated_files/power/src/power.c mcc_generated_files/reset/src/rstctrl.c mcc_generated_files/system/src/clock.c mcc_generated_files/system/src/config_bits.c mcc_generated_files/system/src/interrupt.c mcc_generated_files/system/src/pins.c mcc_generated_files/system/src/syscfg.c mcc_generated_files/system/src/system.c mcc_generated_files/timer/src/rtc.c mcc_generated_files/usb/src/usb0.c mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.c mcc_generated_files/usb/usb_cdc/usb_cdc.c mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.c mcc_generated_files/usb/usb_common/usb_core.c mcc_generated_files/usb/usb_common/usb_core_descriptors.c mcc_generated_files/usb/usb_common/usb_core_events.c mcc_generated_files/usb/usb_common/usb_core_requests.c mcc_generated_files/usb/usb_common/usb_core_requests_device.c mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.c mcc_generated_files/usb/usb_common/usb_core_requests_interface.c mcc_generated_files/usb/usb_common/usb_core_transfer.c mcc_generated_files/usb/usb_descriptors.c mcc_generated_files/usb/usb_device.c mcc_generated_files/usb/usb_peripheral/usb_peripheral.c mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.c mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.c mcc_generated_files/system/src/protected_io.S main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o ${OBJECTDIR}/mcc_generated_files/power/src/power.o ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o ${OBJECTDIR}/mcc_generated_files/system/src/system.o ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o.d ${OBJECTDIR}/mcc_generated_files/power/src/power.o.d ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o.d ${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d ${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o.d ${OBJECTDIR}/mcc_generated_files/system/src/system.o.d ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o.d ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o.d ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o ${OBJECTDIR}/mcc_generated_files/power/src/power.o ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o ${OBJECTDIR}/mcc_generated_files/system/src/system.o ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=mcc_generated_files/nvm/src/nvm.c mcc_generated_files/power/src/power.c mcc_generated_files/reset/src/rstctrl.c mcc_generated_files/system/src/clock.c mcc_generated_files/system/src/config_bits.c mcc_generated_files/system/src/interrupt.c mcc_generated_files/system/src/pins.c mcc_generated_files/system/src/syscfg.c mcc_generated_files/system/src/system.c mcc_generated_files/timer/src/rtc.c mcc_generated_files/usb/src/usb0.c mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.c mcc_generated_files/usb/usb_cdc/usb_cdc.c mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.c mcc_generated_files/usb/usb_common/usb_core.c mcc_generated_files/usb/usb_common/usb_core_descriptors.c mcc_generated_files/usb/usb_common/usb_core_events.c mcc_generated_files/usb/usb_common/usb_core_requests.c mcc_generated_files/usb/usb_common/usb_core_requests_device.c mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.c mcc_generated_files/usb/usb_common/usb_core_requests_interface.c mcc_generated_files/usb/usb_common/usb_core_transfer.c mcc_generated_files/usb/usb_descriptors.c mcc_generated_files/usb/usb_device.c mcc_generated_files/usb/usb_peripheral/usb_peripheral.c mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.c mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.c mcc_generated_files/system/src/protected_io.S main.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/VCP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=AVR64DU28
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o: mcc_generated_files/nvm/src/nvm.c  .generated_files/flags/default/1a0029d1565809ba85efc955d1ba7865e74926a8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/nvm/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o.d" -MT "${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o.d" -MT ${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o -o ${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o mcc_generated_files/nvm/src/nvm.c 
	
${OBJECTDIR}/mcc_generated_files/power/src/power.o: mcc_generated_files/power/src/power.c  .generated_files/flags/default/eca32d550696d788916df91fedff32dffa94d71d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/power/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power/src/power.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power/src/power.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/power/src/power.o.d" -MT "${OBJECTDIR}/mcc_generated_files/power/src/power.o.d" -MT ${OBJECTDIR}/mcc_generated_files/power/src/power.o -o ${OBJECTDIR}/mcc_generated_files/power/src/power.o mcc_generated_files/power/src/power.c 
	
${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o: mcc_generated_files/reset/src/rstctrl.c  .generated_files/flags/default/5607ae9314f510a67950fdb8522187445bb080c9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/reset/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o.d" -MT "${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o.d" -MT ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o -o ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o mcc_generated_files/reset/src/rstctrl.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/clock.o: mcc_generated_files/system/src/clock.c  .generated_files/flags/default/4903d78c746222e9f31c6343e0e92acb39839193 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/clock.o -o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o mcc_generated_files/system/src/clock.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o: mcc_generated_files/system/src/config_bits.c  .generated_files/flags/default/6939764896d7cb28a2021af97ee0505d865a5ade .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o -o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o mcc_generated_files/system/src/config_bits.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o: mcc_generated_files/system/src/interrupt.c  .generated_files/flags/default/3981916bc400ada359418cfa01fc00693b0fdbe8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o -o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o mcc_generated_files/system/src/interrupt.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/pins.o: mcc_generated_files/system/src/pins.c  .generated_files/flags/default/5082d500b420ab9e611ce0b32009497ff96c80b7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/pins.o -o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o mcc_generated_files/system/src/pins.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o: mcc_generated_files/system/src/syscfg.c  .generated_files/flags/default/e616d64d89a3e8faa5939adeca7091255558d2ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o -o ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o mcc_generated_files/system/src/syscfg.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/system.o: mcc_generated_files/system/src/system.c  .generated_files/flags/default/e971671b825ba396735f108d1da64c181263d30b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/system.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/system.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/system.o -o ${OBJECTDIR}/mcc_generated_files/system/src/system.o mcc_generated_files/system/src/system.c 
	
${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o: mcc_generated_files/timer/src/rtc.c  .generated_files/flags/default/314718f23b68ad4b18d1b1ad7f1eb7dd3091d606 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o.d" -MT "${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o.d" -MT ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o -o ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o mcc_generated_files/timer/src/rtc.c 
	
${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o: mcc_generated_files/usb/src/usb0.c  .generated_files/flags/default/d71476043c984379214809ba263c7c8a7a483c25 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o -o ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o mcc_generated_files/usb/src/usb0.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o: mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.c  .generated_files/flags/default/592b5ac232a171f7e0b6e85a2e11cf8cd0c75208 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o: mcc_generated_files/usb/usb_cdc/usb_cdc.c  .generated_files/flags/default/85f39ba7e46f82888fb606b7dd0a5e1132ba95ec .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o mcc_generated_files/usb/usb_cdc/usb_cdc.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o: mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.c  .generated_files/flags/default/e2308c756771e61d614b9707b6b339b168bdeebb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o: mcc_generated_files/usb/usb_common/usb_core.c  .generated_files/flags/default/cc9ab5d60aa343dd59bdbb9ac0ea614e5760f6d7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o mcc_generated_files/usb/usb_common/usb_core.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o: mcc_generated_files/usb/usb_common/usb_core_descriptors.c  .generated_files/flags/default/c980b28f2221bb8502a96dcc4c4851e426464ab3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o mcc_generated_files/usb/usb_common/usb_core_descriptors.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o: mcc_generated_files/usb/usb_common/usb_core_events.c  .generated_files/flags/default/5ca72c71ec98f1447c472fc5acd4274c0f9e8c76 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o mcc_generated_files/usb/usb_common/usb_core_events.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o: mcc_generated_files/usb/usb_common/usb_core_requests.c  .generated_files/flags/default/ed8ace5f14708ac50a6c87d753b3d11882c5ba0b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o mcc_generated_files/usb/usb_common/usb_core_requests.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o: mcc_generated_files/usb/usb_common/usb_core_requests_device.c  .generated_files/flags/default/2b98023c06ba1c83d401a502c632f1a984ba3cfc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o mcc_generated_files/usb/usb_common/usb_core_requests_device.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o: mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.c  .generated_files/flags/default/4a22588bf15202c647b3fd62a116df7f558ad628 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o: mcc_generated_files/usb/usb_common/usb_core_requests_interface.c  .generated_files/flags/default/93e7318a570133f9a373ad1e1226de50b07b7631 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o mcc_generated_files/usb/usb_common/usb_core_requests_interface.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o: mcc_generated_files/usb/usb_common/usb_core_transfer.c  .generated_files/flags/default/3b733c48b8d46d84c7a2bffb8ab9ded2d2438da4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o mcc_generated_files/usb/usb_common/usb_core_transfer.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o: mcc_generated_files/usb/usb_descriptors.c  .generated_files/flags/default/d024fcf35646d4556ef1975abdd09699876a27ca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o mcc_generated_files/usb/usb_descriptors.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device.o: mcc_generated_files/usb/usb_device.c  .generated_files/flags/default/57c9d93147d2897755aef8fd4236b98123d23505 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o mcc_generated_files/usb/usb_device.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o: mcc_generated_files/usb/usb_peripheral/usb_peripheral.c  .generated_files/flags/default/4074f1f763e6afaa234c9c38c288eccfeea11f4e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o mcc_generated_files/usb/usb_peripheral/usb_peripheral.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o: mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.c  .generated_files/flags/default/94b35f2c0ca3d9331b98d60a9f6eb4b05a5a85c6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o: mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.c  .generated_files/flags/default/546bdfeee2492c8b5dd014bcd9ece80d469a0e9c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.c 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/67ac95e607b02ed2ba4d13bd398ee1a69a3e1ffc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
else
${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o: mcc_generated_files/nvm/src/nvm.c  .generated_files/flags/default/1c41305b0d3208698218a52ad95f908a33b3829d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/nvm/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o.d" -MT "${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o.d" -MT ${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o -o ${OBJECTDIR}/mcc_generated_files/nvm/src/nvm.o mcc_generated_files/nvm/src/nvm.c 
	
${OBJECTDIR}/mcc_generated_files/power/src/power.o: mcc_generated_files/power/src/power.c  .generated_files/flags/default/d6ec7ce99c062c2d4b1be057a5253a23200385fc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/power/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power/src/power.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power/src/power.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/power/src/power.o.d" -MT "${OBJECTDIR}/mcc_generated_files/power/src/power.o.d" -MT ${OBJECTDIR}/mcc_generated_files/power/src/power.o -o ${OBJECTDIR}/mcc_generated_files/power/src/power.o mcc_generated_files/power/src/power.c 
	
${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o: mcc_generated_files/reset/src/rstctrl.c  .generated_files/flags/default/a9382323d67b8c6ba66177ffd14c3c8b3b986aa3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/reset/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o.d" -MT "${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o.d" -MT ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o -o ${OBJECTDIR}/mcc_generated_files/reset/src/rstctrl.o mcc_generated_files/reset/src/rstctrl.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/clock.o: mcc_generated_files/system/src/clock.c  .generated_files/flags/default/7e88c2790d6868b94ed4562f59515e72f12ec64a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/clock.o -o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o mcc_generated_files/system/src/clock.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o: mcc_generated_files/system/src/config_bits.c  .generated_files/flags/default/3c8e10e9d83037f828337154953f4c9226748178 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o -o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o mcc_generated_files/system/src/config_bits.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o: mcc_generated_files/system/src/interrupt.c  .generated_files/flags/default/eef58fdff49521bb859e904089ae1df5de75d15d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o -o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o mcc_generated_files/system/src/interrupt.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/pins.o: mcc_generated_files/system/src/pins.c  .generated_files/flags/default/7b2daf5ca5b339d47fbe230c246614ae4137595 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/pins.o -o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o mcc_generated_files/system/src/pins.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o: mcc_generated_files/system/src/syscfg.c  .generated_files/flags/default/75271faa5c3893004a01899bd8faedbf9c8ef850 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o -o ${OBJECTDIR}/mcc_generated_files/system/src/syscfg.o mcc_generated_files/system/src/syscfg.c 
	
${OBJECTDIR}/mcc_generated_files/system/src/system.o: mcc_generated_files/system/src/system.c  .generated_files/flags/default/5a340d670a0dae55c4e9b2d28ecbf37c3dd2d0d5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/system.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/system.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/system.o -o ${OBJECTDIR}/mcc_generated_files/system/src/system.o mcc_generated_files/system/src/system.c 
	
${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o: mcc_generated_files/timer/src/rtc.c  .generated_files/flags/default/1b4be3c900b0b19b0178a0ff7c9f662a6d619d73 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o.d" -MT "${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o.d" -MT ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o -o ${OBJECTDIR}/mcc_generated_files/timer/src/rtc.o mcc_generated_files/timer/src/rtc.c 
	
${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o: mcc_generated_files/usb/src/usb0.c  .generated_files/flags/default/a4737f08c77910ef270d9a69a10bec31654cc22b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o -o ${OBJECTDIR}/mcc_generated_files/usb/src/usb0.o mcc_generated_files/usb/src/usb0.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o: mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.c  .generated_files/flags/default/548e48762354c5d164a955d56c4761aba8048c47 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.o mcc_generated_files/usb/usb_cdc/circular_buffer/circular_buffer.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o: mcc_generated_files/usb/usb_cdc/usb_cdc.c  .generated_files/flags/default/a1afd5bb218f74b67377a9345e483d79e7634b46 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc.o mcc_generated_files/usb/usb_cdc/usb_cdc.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o: mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.c  .generated_files/flags/default/639ee18055aba4d0b378b2331ef79541914a698a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.o mcc_generated_files/usb/usb_cdc/usb_cdc_virtual_serial_port.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o: mcc_generated_files/usb/usb_common/usb_core.c  .generated_files/flags/default/91b27b696868b4a63b8e1851f205c17995aba5a9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core.o mcc_generated_files/usb/usb_common/usb_core.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o: mcc_generated_files/usb/usb_common/usb_core_descriptors.c  .generated_files/flags/default/ef3f91a0e91dd82b5c9256c930a1d2aa9112ee22 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_descriptors.o mcc_generated_files/usb/usb_common/usb_core_descriptors.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o: mcc_generated_files/usb/usb_common/usb_core_events.c  .generated_files/flags/default/a8a154ae1a25ec47371ebd50b2e661b857e6a528 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_events.o mcc_generated_files/usb/usb_common/usb_core_events.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o: mcc_generated_files/usb/usb_common/usb_core_requests.c  .generated_files/flags/default/123cf84ae6e8fa76026cdee2db8b69c69138fc53 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests.o mcc_generated_files/usb/usb_common/usb_core_requests.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o: mcc_generated_files/usb/usb_common/usb_core_requests_device.c  .generated_files/flags/default/f082a5a6a4295db43d2752fd8dc45935b32e7f4b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_device.o mcc_generated_files/usb/usb_common/usb_core_requests_device.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o: mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.c  .generated_files/flags/default/7cc0a466b1835bb3f01e933a15e6462a870827a2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.o mcc_generated_files/usb/usb_common/usb_core_requests_endpoint.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o: mcc_generated_files/usb/usb_common/usb_core_requests_interface.c  .generated_files/flags/default/5a03310480d87330b41def53af1649bd2a6316d6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_requests_interface.o mcc_generated_files/usb/usb_common/usb_core_requests_interface.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o: mcc_generated_files/usb/usb_common/usb_core_transfer.c  .generated_files/flags/default/25701fbcc8526577502cfff44596c96308384276 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_common" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_common/usb_core_transfer.o mcc_generated_files/usb/usb_common/usb_core_transfer.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o: mcc_generated_files/usb/usb_descriptors.c  .generated_files/flags/default/4945582163a9681bc72a7ad39c670b5b187877e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o mcc_generated_files/usb/usb_descriptors.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device.o: mcc_generated_files/usb/usb_device.c  .generated_files/flags/default/f95ae9d3d5c6bbdfcfa556cace610254cc6117f1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o mcc_generated_files/usb/usb_device.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o: mcc_generated_files/usb/usb_peripheral/usb_peripheral.c  .generated_files/flags/default/345385eb5632d6d8c0f46f1c9d706ccd9a2c0216 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral.o mcc_generated_files/usb/usb_peripheral/usb_peripheral.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o: mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.c  .generated_files/flags/default/6f1a8be9c0557e0cb1f24479059f61a540d71383 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.o mcc_generated_files/usb/usb_peripheral/usb_peripheral_endpoint.c 
	
${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o: mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.c  .generated_files/flags/default/b32458f62f91b51009c735d015e489e4654b450e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o.d" -MT "${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o.d" -MT ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o -o ${OBJECTDIR}/mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.o mcc_generated_files/usb/usb_peripheral/usb_peripheral_read_write.c 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/84032643ecc09ea008ed260d18bc44c9e639b7a3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o: mcc_generated_files/system/src/protected_io.S  .generated_files/flags/default/8ba0f5b74fae6c4c841ff8a7f2bdf3f01769cb6c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o 
	${MP_CC} -c $(MP_EXTRA_AS_PRE) -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x assembler-with-cpp -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem -Wa,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1   -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o -o ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o  mcc_generated_files/system/src/protected_io.S 
	
else
${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o: mcc_generated_files/system/src/protected_io.S  .generated_files/flags/default/3f3f272d275a1ac48dda4fdb569d9dbadf29ea38 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o 
	${MP_CC} -c $(MP_EXTRA_AS_PRE) -mcpu=$(MP_PROCESSOR_OPTION)  -x assembler-with-cpp -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -DXPRJ_default=$(CND_CONF)  -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem -Wa,--defsym=__MPLAB_BUILD=1   -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o.d" -MT "${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o.d" -MT ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o -o ${OBJECTDIR}/mcc_generated_files/system/src/protected_io.o  mcc_generated_files/system/src/protected_io.S 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/VCP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/VCP.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/VCP.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/VCP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} ${DISTDIR}/VCP.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/VCP.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/VCP.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -I"mcc_generated_files" -I"mcc_generated_files/usb" -I"mcc_generated_files/usb/usb_cdc" -I"mcc_generated_files/usb/usb_cdc/circular_buffer" -I"mcc_generated_files/usb/usb_common" -I"mcc_generated_files/usb/usb_peripheral" -Wall -gdwarf-3 -mconst-data-in-progmem -mconst-data-in-config-mapped-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/VCP.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/VCP.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/VCP.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/VCP.X.${IMAGE_TYPE}.hex"
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
