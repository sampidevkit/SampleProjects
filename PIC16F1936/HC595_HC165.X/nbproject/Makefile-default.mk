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
FINAL_IMAGE=${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=Lib/HC595.c Lib/HC595_Cfg.c Lib/HC165.c Lib/HC165_Cfg.c mcc_generated_files/drivers/spi_master.c mcc_generated_files/device_config.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/spi.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Lib/HC595.p1 ${OBJECTDIR}/Lib/HC595_Cfg.p1 ${OBJECTDIR}/Lib/HC165.p1 ${OBJECTDIR}/Lib/HC165_Cfg.p1 ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1 ${OBJECTDIR}/mcc_generated_files/device_config.p1 ${OBJECTDIR}/mcc_generated_files/mcc.p1 ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 ${OBJECTDIR}/mcc_generated_files/spi.p1 ${OBJECTDIR}/main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/Lib/HC595.p1.d ${OBJECTDIR}/Lib/HC595_Cfg.p1.d ${OBJECTDIR}/Lib/HC165.p1.d ${OBJECTDIR}/Lib/HC165_Cfg.p1.d ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1.d ${OBJECTDIR}/mcc_generated_files/device_config.p1.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d ${OBJECTDIR}/mcc_generated_files/spi.p1.d ${OBJECTDIR}/main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Lib/HC595.p1 ${OBJECTDIR}/Lib/HC595_Cfg.p1 ${OBJECTDIR}/Lib/HC165.p1 ${OBJECTDIR}/Lib/HC165_Cfg.p1 ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1 ${OBJECTDIR}/mcc_generated_files/device_config.p1 ${OBJECTDIR}/mcc_generated_files/mcc.p1 ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 ${OBJECTDIR}/mcc_generated_files/spi.p1 ${OBJECTDIR}/main.p1

# Source Files
SOURCEFILES=Lib/HC595.c Lib/HC595_Cfg.c Lib/HC165.c Lib/HC165_Cfg.c mcc_generated_files/drivers/spi_master.c mcc_generated_files/device_config.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/spi.c main.c



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
Device=PIC16F1936
ProjectDir="C:\Users\liemp\Downloads\HC595_HC165.X"
ProjectName=HC595_HC165
ConfName=default
ImagePath="dist\default\${IMAGE_TYPE}\HC595_HC165.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="dist\default\${IMAGE_TYPE}"
ImageName="HC595_HC165.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif
MDFUHostPath="E:\Microchip\MPLABX\v6.25\mplab_platform\mplab-pymdfu\bin\windows\pymdfu-bin.exe"
PYFWImageBuilderPath="E:\Microchip\MPLABX\v6.25\mplab_platform\mplab-pymdfu\bin\windows\pyfwimagebuilder-bin.exe"

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [copy ${ImagePath} ".\App.${OUTPUT_SUFFIX}"]"
	@copy ${ImagePath} ".\App.${OUTPUT_SUFFIX}"
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=16F1936
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Lib/HC595.p1: Lib/HC595.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Lib" 
	@${RM} ${OBJECTDIR}/Lib/HC595.p1.d 
	@${RM} ${OBJECTDIR}/Lib/HC595.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Lib/HC595.p1 Lib/HC595.c 
	@-${MV} ${OBJECTDIR}/Lib/HC595.d ${OBJECTDIR}/Lib/HC595.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Lib/HC595.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Lib/HC595_Cfg.p1: Lib/HC595_Cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Lib" 
	@${RM} ${OBJECTDIR}/Lib/HC595_Cfg.p1.d 
	@${RM} ${OBJECTDIR}/Lib/HC595_Cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Lib/HC595_Cfg.p1 Lib/HC595_Cfg.c 
	@-${MV} ${OBJECTDIR}/Lib/HC595_Cfg.d ${OBJECTDIR}/Lib/HC595_Cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Lib/HC595_Cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Lib/HC165.p1: Lib/HC165.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Lib" 
	@${RM} ${OBJECTDIR}/Lib/HC165.p1.d 
	@${RM} ${OBJECTDIR}/Lib/HC165.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Lib/HC165.p1 Lib/HC165.c 
	@-${MV} ${OBJECTDIR}/Lib/HC165.d ${OBJECTDIR}/Lib/HC165.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Lib/HC165.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Lib/HC165_Cfg.p1: Lib/HC165_Cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Lib" 
	@${RM} ${OBJECTDIR}/Lib/HC165_Cfg.p1.d 
	@${RM} ${OBJECTDIR}/Lib/HC165_Cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Lib/HC165_Cfg.p1 Lib/HC165_Cfg.c 
	@-${MV} ${OBJECTDIR}/Lib/HC165_Cfg.d ${OBJECTDIR}/Lib/HC165_Cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Lib/HC165_Cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1: mcc_generated_files/drivers/spi_master.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1 mcc_generated_files/drivers/spi_master.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.d ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/device_config.p1: mcc_generated_files/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/device_config.p1 mcc_generated_files/device_config.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/device_config.d ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/mcc.p1: mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/mcc.p1 mcc_generated_files/mcc.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/mcc.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.p1: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 mcc_generated_files/pin_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/pin_manager.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/spi.p1: mcc_generated_files/spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/spi.p1 mcc_generated_files/spi.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/spi.d ${OBJECTDIR}/mcc_generated_files/spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/Lib/HC595.p1: Lib/HC595.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Lib" 
	@${RM} ${OBJECTDIR}/Lib/HC595.p1.d 
	@${RM} ${OBJECTDIR}/Lib/HC595.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Lib/HC595.p1 Lib/HC595.c 
	@-${MV} ${OBJECTDIR}/Lib/HC595.d ${OBJECTDIR}/Lib/HC595.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Lib/HC595.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Lib/HC595_Cfg.p1: Lib/HC595_Cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Lib" 
	@${RM} ${OBJECTDIR}/Lib/HC595_Cfg.p1.d 
	@${RM} ${OBJECTDIR}/Lib/HC595_Cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Lib/HC595_Cfg.p1 Lib/HC595_Cfg.c 
	@-${MV} ${OBJECTDIR}/Lib/HC595_Cfg.d ${OBJECTDIR}/Lib/HC595_Cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Lib/HC595_Cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Lib/HC165.p1: Lib/HC165.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Lib" 
	@${RM} ${OBJECTDIR}/Lib/HC165.p1.d 
	@${RM} ${OBJECTDIR}/Lib/HC165.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Lib/HC165.p1 Lib/HC165.c 
	@-${MV} ${OBJECTDIR}/Lib/HC165.d ${OBJECTDIR}/Lib/HC165.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Lib/HC165.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Lib/HC165_Cfg.p1: Lib/HC165_Cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Lib" 
	@${RM} ${OBJECTDIR}/Lib/HC165_Cfg.p1.d 
	@${RM} ${OBJECTDIR}/Lib/HC165_Cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Lib/HC165_Cfg.p1 Lib/HC165_Cfg.c 
	@-${MV} ${OBJECTDIR}/Lib/HC165_Cfg.d ${OBJECTDIR}/Lib/HC165_Cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Lib/HC165_Cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1: mcc_generated_files/drivers/spi_master.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1 mcc_generated_files/drivers/spi_master.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.d ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/drivers/spi_master.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/device_config.p1: mcc_generated_files/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/device_config.p1 mcc_generated_files/device_config.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/device_config.d ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/mcc.p1: mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/mcc.p1 mcc_generated_files/mcc.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/mcc.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.p1: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 mcc_generated_files/pin_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/pin_manager.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/spi.p1: mcc_generated_files/spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/spi.p1 mcc_generated_files/spi.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/spi.d ${OBJECTDIR}/mcc_generated_files/spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

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
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"Lib" -I"mcc_generated_files" -mwarn=0 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mno-default-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
	@echo Normalizing hex file
	@"E:/Microchip/MPLABX/v6.25/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="E:/Microchip/MPLABX/v6.25/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" ${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.hex -o${DISTDIR}/HC595_HC165.X.${IMAGE_TYPE}.hex

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
