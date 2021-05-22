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
ifeq "$(wildcard nbproject/Makefile-local-SW_SPI.mk)" "nbproject/Makefile-local-SW_SPI.mk"
include nbproject/Makefile-local-SW_SPI.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=SW_SPI
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
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
SOURCEFILES_QUOTED_IF_SPACED=app/libcomp.c mcc_generated_files/pin_manager.c mcc_generated_files/device_config.c mcc_generated_files/spi1.c mcc_generated_files/tmr1.c mcc_generated_files/mcc.c mcc_generated_files/interrupt_manager.c mcc_generated_files/eusart.c main.c ../Library/MAX7219.c ../Library/TickTimer.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/app/libcomp.p1 ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 ${OBJECTDIR}/mcc_generated_files/device_config.p1 ${OBJECTDIR}/mcc_generated_files/spi1.p1 ${OBJECTDIR}/mcc_generated_files/tmr1.p1 ${OBJECTDIR}/mcc_generated_files/mcc.p1 ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 ${OBJECTDIR}/mcc_generated_files/eusart.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/_ext/150355788/MAX7219.p1 ${OBJECTDIR}/_ext/150355788/TickTimer.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/app/libcomp.p1.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d ${OBJECTDIR}/mcc_generated_files/device_config.p1.d ${OBJECTDIR}/mcc_generated_files/spi1.p1.d ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d ${OBJECTDIR}/mcc_generated_files/eusart.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/_ext/150355788/MAX7219.p1.d ${OBJECTDIR}/_ext/150355788/TickTimer.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/app/libcomp.p1 ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 ${OBJECTDIR}/mcc_generated_files/device_config.p1 ${OBJECTDIR}/mcc_generated_files/spi1.p1 ${OBJECTDIR}/mcc_generated_files/tmr1.p1 ${OBJECTDIR}/mcc_generated_files/mcc.p1 ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 ${OBJECTDIR}/mcc_generated_files/eusart.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/_ext/150355788/MAX7219.p1 ${OBJECTDIR}/_ext/150355788/TickTimer.p1

# Source Files
SOURCEFILES=app/libcomp.c mcc_generated_files/pin_manager.c mcc_generated_files/device_config.c mcc_generated_files/spi1.c mcc_generated_files/tmr1.c mcc_generated_files/mcc.c mcc_generated_files/interrupt_manager.c mcc_generated_files/eusart.c main.c ../Library/MAX7219.c ../Library/TickTimer.c



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
Device=PIC16F877A
ProjectDir="H:\SampleProjects\PIC16F877A\MAX7219.X"
ProjectName=MAX7219
ConfName=SW_SPI
ImagePath="dist\SW_SPI\${IMAGE_TYPE}\MAX7219.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="dist\SW_SPI\${IMAGE_TYPE}"
ImageName="MAX7219.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-SW_SPI.mk dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [copy ${ImagePath} ".\lastbuild.hex"]"
	@copy ${ImagePath} ".\lastbuild.hex"
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=16F877A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/app/libcomp.p1: app/libcomp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/app" 
	@${RM} ${OBJECTDIR}/app/libcomp.p1.d 
	@${RM} ${OBJECTDIR}/app/libcomp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/app/libcomp.p1 app/libcomp.c 
	@-${MV} ${OBJECTDIR}/app/libcomp.d ${OBJECTDIR}/app/libcomp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app/libcomp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.p1: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 mcc_generated_files/pin_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/pin_manager.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/device_config.p1: mcc_generated_files/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/device_config.p1 mcc_generated_files/device_config.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/device_config.d ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/spi1.p1: mcc_generated_files/spi1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/spi1.p1 mcc_generated_files/spi1.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/spi1.d ${OBJECTDIR}/mcc_generated_files/spi1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/spi1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr1.p1: mcc_generated_files/tmr1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/tmr1.p1 mcc_generated_files/tmr1.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr1.d ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/mcc.p1: mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/mcc.p1 mcc_generated_files/mcc.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/mcc.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1: mcc_generated_files/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 mcc_generated_files/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/eusart.p1: mcc_generated_files/eusart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/eusart.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/eusart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/eusart.p1 mcc_generated_files/eusart.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/eusart.d ${OBJECTDIR}/mcc_generated_files/eusart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/eusart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/150355788/MAX7219.p1: ../Library/MAX7219.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/150355788" 
	@${RM} ${OBJECTDIR}/_ext/150355788/MAX7219.p1.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/MAX7219.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/_ext/150355788/MAX7219.p1 ../Library/MAX7219.c 
	@-${MV} ${OBJECTDIR}/_ext/150355788/MAX7219.d ${OBJECTDIR}/_ext/150355788/MAX7219.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/150355788/MAX7219.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/150355788/TickTimer.p1: ../Library/TickTimer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/150355788" 
	@${RM} ${OBJECTDIR}/_ext/150355788/TickTimer.p1.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/TickTimer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/_ext/150355788/TickTimer.p1 ../Library/TickTimer.c 
	@-${MV} ${OBJECTDIR}/_ext/150355788/TickTimer.d ${OBJECTDIR}/_ext/150355788/TickTimer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/150355788/TickTimer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/app/libcomp.p1: app/libcomp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/app" 
	@${RM} ${OBJECTDIR}/app/libcomp.p1.d 
	@${RM} ${OBJECTDIR}/app/libcomp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/app/libcomp.p1 app/libcomp.c 
	@-${MV} ${OBJECTDIR}/app/libcomp.d ${OBJECTDIR}/app/libcomp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app/libcomp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.p1: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 mcc_generated_files/pin_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/pin_manager.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/device_config.p1: mcc_generated_files/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/device_config.p1 mcc_generated_files/device_config.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/device_config.d ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/spi1.p1: mcc_generated_files/spi1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/spi1.p1 mcc_generated_files/spi1.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/spi1.d ${OBJECTDIR}/mcc_generated_files/spi1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/spi1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr1.p1: mcc_generated_files/tmr1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/tmr1.p1 mcc_generated_files/tmr1.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr1.d ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/mcc.p1: mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/mcc.p1 mcc_generated_files/mcc.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/mcc.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1: mcc_generated_files/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 mcc_generated_files/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/eusart.p1: mcc_generated_files/eusart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/eusart.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/eusart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/eusart.p1 mcc_generated_files/eusart.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/eusart.d ${OBJECTDIR}/mcc_generated_files/eusart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/eusart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/150355788/MAX7219.p1: ../Library/MAX7219.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/150355788" 
	@${RM} ${OBJECTDIR}/_ext/150355788/MAX7219.p1.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/MAX7219.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/_ext/150355788/MAX7219.p1 ../Library/MAX7219.c 
	@-${MV} ${OBJECTDIR}/_ext/150355788/MAX7219.d ${OBJECTDIR}/_ext/150355788/MAX7219.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/150355788/MAX7219.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/150355788/TickTimer.p1: ../Library/TickTimer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/150355788" 
	@${RM} ${OBJECTDIR}/_ext/150355788/TickTimer.p1.d 
	@${RM} ${OBJECTDIR}/_ext/150355788/TickTimer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -DXPRJ_SW_SPI=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     -o ${OBJECTDIR}/_ext/150355788/TickTimer.p1 ../Library/TickTimer.c 
	@-${MV} ${OBJECTDIR}/_ext/150355788/TickTimer.d ${OBJECTDIR}/_ext/150355788/TickTimer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/150355788/TickTimer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_SW_SPI=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.map  -DXPRJ_SW_SPI=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O1 -fasmfile -maddrqual=ignore -DUSE_SW_SPI -xassembler-with-cpp -I"app" -I"config" -I"mcc_generated_files" -I"../Library" -mwarn=0 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mc90lib -std=c90 -gdwarf-3 -mstack=hybrid:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	@echo Normalizing hex file
	@"C:/Program Files/Microchip/MPLABX/v5.50/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v5.50/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" dist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.hex -odist/${CND_CONF}/${IMAGE_TYPE}/MAX7219.X.${IMAGE_TYPE}.hex

endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/SW_SPI
	${RM} -r dist/SW_SPI

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
