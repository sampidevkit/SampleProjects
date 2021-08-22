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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/AutoMouse.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/AutoMouse.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/clock.c mcc_generated_files/system.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/traps.c mcc_generated_files/interrupt_manager.c mcc_generated_files/tmr1.c main.c m-stack/usb/src/usb.c m-stack/usb/src/usb_hid.c m-stack/apps/hid_mouse/usb_descriptors.c common/hardware.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/tmr1.o ${OBJECTDIR}/main.o ${OBJECTDIR}/m-stack/usb/src/usb.o ${OBJECTDIR}/m-stack/usb/src/usb_hid.o ${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o ${OBJECTDIR}/common/hardware.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/traps.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/tmr1.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/m-stack/usb/src/usb.o.d ${OBJECTDIR}/m-stack/usb/src/usb_hid.o.d ${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o.d ${OBJECTDIR}/common/hardware.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/tmr1.o ${OBJECTDIR}/main.o ${OBJECTDIR}/m-stack/usb/src/usb.o ${OBJECTDIR}/m-stack/usb/src/usb_hid.o ${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o ${OBJECTDIR}/common/hardware.o

# Source Files
SOURCEFILES=mcc_generated_files/clock.c mcc_generated_files/system.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/traps.c mcc_generated_files/interrupt_manager.c mcc_generated_files/tmr1.c main.c m-stack/usb/src/usb.c m-stack/usb/src/usb_hid.c m-stack/apps/hid_mouse/usb_descriptors.c common/hardware.c



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

# The following macros may be used in the pre and post step lines
_/_=\\
ShExtension=.bat
Device=PIC24FJ256GB106
ProjectDir="F:\Git\SAMPI\Ex\PIC24FJ256GB106\AutoMouse.X"
ProjectName=AutoMouse
ConfName=default
ImagePath="dist\default\${IMAGE_TYPE}\AutoMouse.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="dist\default\${IMAGE_TYPE}"
ImageName="AutoMouse.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/AutoMouse.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [copy ${ImagePath} ".\lastbuild.${OUTPUT_SUFFIX}"]"
	@copy ${ImagePath} ".\lastbuild.${OUTPUT_SUFFIX}"
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=24FJ256GB106
MP_LINKER_FILE_OPTION=,--script=p24FJ256GB106.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/239e6e98d9ff032b70a4e9557ea79f53bfafa8ed .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/9f97810fe2890a7cc7bfedaf943209e90c5d7253 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/7b8da65b89edd7c3acd89c1f6132136c16ce9c9b .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/710ea9baf8aedaba128554283819cd0c894a6a6c .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/flags/default/66eb4f7f60a045d99ee59eb5c15bc67b49341347 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/19e727e33d2aec0e02dc61c1a89c4ac88354dc23 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr1.o: mcc_generated_files/tmr1.c  .generated_files/flags/default/e1a7d719622358c30471384583a2d6d3b1203330 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr1.c  -o ${OBJECTDIR}/mcc_generated_files/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/336b022e8ba3f073e272f704659c9e024a5f9f62 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/m-stack/usb/src/usb.o: m-stack/usb/src/usb.c  .generated_files/flags/default/1d5fded93e0878a7dae80842c6c320955c6d9f71 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/m-stack/usb/src" 
	@${RM} ${OBJECTDIR}/m-stack/usb/src/usb.o.d 
	@${RM} ${OBJECTDIR}/m-stack/usb/src/usb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  m-stack/usb/src/usb.c  -o ${OBJECTDIR}/m-stack/usb/src/usb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/m-stack/usb/src/usb.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/m-stack/usb/src/usb_hid.o: m-stack/usb/src/usb_hid.c  .generated_files/flags/default/e5077a546c377636f6eac49dfb2bc0f4494e3bd0 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/m-stack/usb/src" 
	@${RM} ${OBJECTDIR}/m-stack/usb/src/usb_hid.o.d 
	@${RM} ${OBJECTDIR}/m-stack/usb/src/usb_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  m-stack/usb/src/usb_hid.c  -o ${OBJECTDIR}/m-stack/usb/src/usb_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/m-stack/usb/src/usb_hid.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o: m-stack/apps/hid_mouse/usb_descriptors.c  .generated_files/flags/default/dce60ff83ebc8e6e5b489bfad0d098a7007c67db .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/m-stack/apps/hid_mouse" 
	@${RM} ${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  m-stack/apps/hid_mouse/usb_descriptors.c  -o ${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/common/hardware.o: common/hardware.c  .generated_files/flags/default/e73be6f9639161e51bd48a5ec31867c497ca6573 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/common" 
	@${RM} ${OBJECTDIR}/common/hardware.o.d 
	@${RM} ${OBJECTDIR}/common/hardware.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  common/hardware.c  -o ${OBJECTDIR}/common/hardware.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/common/hardware.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/735555d833a7b79f31b1997a7e47caffa994f9ca .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/7dd06fdc25f3032567a3284ca7da0e3ef891cfe1 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/41c681b8a3218e231b09a4f2e4c045872ed21921 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/7329d30cfaa4d5d16877c28b42aa82f591d1dabd .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/flags/default/534cc259f1f1e32b6611411cfb03cbcc40663aa8 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/a8a98095f24f8aeca787be5d9db164e42c3255bf .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr1.o: mcc_generated_files/tmr1.c  .generated_files/flags/default/b5c7abba5549b79f9d9c409e2848e3852aa00465 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr1.c  -o ${OBJECTDIR}/mcc_generated_files/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/db6830eb4f472ab9116da1534c1501964dcb4c4c .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/m-stack/usb/src/usb.o: m-stack/usb/src/usb.c  .generated_files/flags/default/2f13e4f1943c84f7aaa29cbe8db43aceeac90d94 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/m-stack/usb/src" 
	@${RM} ${OBJECTDIR}/m-stack/usb/src/usb.o.d 
	@${RM} ${OBJECTDIR}/m-stack/usb/src/usb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  m-stack/usb/src/usb.c  -o ${OBJECTDIR}/m-stack/usb/src/usb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/m-stack/usb/src/usb.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/m-stack/usb/src/usb_hid.o: m-stack/usb/src/usb_hid.c  .generated_files/flags/default/b362e22c4fd8d8e4d0cac25c3b0b548af1ef8191 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/m-stack/usb/src" 
	@${RM} ${OBJECTDIR}/m-stack/usb/src/usb_hid.o.d 
	@${RM} ${OBJECTDIR}/m-stack/usb/src/usb_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  m-stack/usb/src/usb_hid.c  -o ${OBJECTDIR}/m-stack/usb/src/usb_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/m-stack/usb/src/usb_hid.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o: m-stack/apps/hid_mouse/usb_descriptors.c  .generated_files/flags/default/46e8a5c9f37cd027a31f2972d610f5dc7bc6d200 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/m-stack/apps/hid_mouse" 
	@${RM} ${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  m-stack/apps/hid_mouse/usb_descriptors.c  -o ${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/m-stack/apps/hid_mouse/usb_descriptors.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/common/hardware.o: common/hardware.c  .generated_files/flags/default/63f4369fdf16151a33d558f029140ae9e9cc97e9 .generated_files/flags/default/ee7754f4b18a6d06e207bcb8cb5cd83194b80794
	@${MKDIR} "${OBJECTDIR}/common" 
	@${RM} ${OBJECTDIR}/common/hardware.o.d 
	@${RM} ${OBJECTDIR}/common/hardware.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  common/hardware.c  -o ${OBJECTDIR}/common/hardware.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/common/hardware.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -ffunction-sections -O2 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/AutoMouse.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/AutoMouse.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common"  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD4=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/AutoMouse.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/AutoMouse.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"m-stack/usb/include" -I"m-stack/apps/hid_mouse" -I"common" -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/AutoMouse.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
	@echo Normalizing hex file
	@"C:/Program Files/Microchip/MPLABX/v5.50/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v5.50/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" dist/${CND_CONF}/${IMAGE_TYPE}/AutoMouse.X.${IMAGE_TYPE}.hex -odist/${CND_CONF}/${IMAGE_TYPE}/AutoMouse.X.${IMAGE_TYPE}.hex

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
