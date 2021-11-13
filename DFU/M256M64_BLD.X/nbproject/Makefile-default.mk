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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/M256M64_BLD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/M256M64_BLD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../Lib/Bootloader/BLD_Nvm_PIC32.c ../Lib/Bootloader/Bootloader.c ../Lib/Bootloader/HexParsing.c ../Lib/Bootloader/asm.S mcc_generated_files/memory/flash.c mcc_generated_files/mcc.c mcc_generated_files/system.c mcc_generated_files/uart3.c mcc_generated_files/interrupt_manager.c mcc_generated_files/clock.c mcc_generated_files/pin_manager.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o ${OBJECTDIR}/_ext/1245858882/Bootloader.o ${OBJECTDIR}/_ext/1245858882/HexParsing.o ${OBJECTDIR}/_ext/1245858882/asm.o ${OBJECTDIR}/mcc_generated_files/memory/flash.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/uart3.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o.d ${OBJECTDIR}/_ext/1245858882/Bootloader.o.d ${OBJECTDIR}/_ext/1245858882/HexParsing.o.d ${OBJECTDIR}/_ext/1245858882/asm.o.d ${OBJECTDIR}/mcc_generated_files/memory/flash.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/uart3.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o ${OBJECTDIR}/_ext/1245858882/Bootloader.o ${OBJECTDIR}/_ext/1245858882/HexParsing.o ${OBJECTDIR}/_ext/1245858882/asm.o ${OBJECTDIR}/mcc_generated_files/memory/flash.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/uart3.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=../Lib/Bootloader/BLD_Nvm_PIC32.c ../Lib/Bootloader/Bootloader.c ../Lib/Bootloader/HexParsing.c ../Lib/Bootloader/asm.S mcc_generated_files/memory/flash.c mcc_generated_files/mcc.c mcc_generated_files/system.c mcc_generated_files/uart3.c mcc_generated_files/interrupt_manager.c mcc_generated_files/clock.c mcc_generated_files/pin_manager.c main.c



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
Device=PIC32MM0256GPM064
ProjectDir="F:\Git\SAMPI\Ex_MCU32\DFU\M256M64_BLD.X"
ProjectName=M256M64_BLD
ConfName=default
ImagePath="dist\default\${IMAGE_TYPE}\M256M64_BLD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="dist\default\${IMAGE_TYPE}"
ImageName="M256M64_BLD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/M256M64_BLD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [copy ${ImagePath} ".\bld.${OUTPUT_SUFFIX}"]"
	@copy ${ImagePath} ".\bld.${OUTPUT_SUFFIX}"
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=32MM0256GPM064
MP_LINKER_FILE_OPTION=,--script="..\Lib\Bootloader\Linker\p32MM0256GPM064\Boot.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1245858882/asm.o: ../Lib/Bootloader/asm.S  .generated_files/flags/default/576cfc42ec08b5345193ccb56160da079a245770 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/asm.o 
	@${RM} ${OBJECTDIR}/_ext/1245858882/asm.o.ok ${OBJECTDIR}/_ext/1245858882/asm.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1245858882/asm.o.d"  -o ${OBJECTDIR}/_ext/1245858882/asm.o ../Lib/Bootloader/asm.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1245858882/asm.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD4=1 -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1245858882/asm.o.d" "${OBJECTDIR}/_ext/1245858882/asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1245858882/asm.o: ../Lib/Bootloader/asm.S  .generated_files/flags/default/7e93fe06af5590eaa5e3c920610a6a650c414e01 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/asm.o 
	@${RM} ${OBJECTDIR}/_ext/1245858882/asm.o.ok ${OBJECTDIR}/_ext/1245858882/asm.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1245858882/asm.o.d"  -o ${OBJECTDIR}/_ext/1245858882/asm.o ../Lib/Bootloader/asm.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1245858882/asm.o.asm.d",--gdwarf-2 -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1245858882/asm.o.d" "${OBJECTDIR}/_ext/1245858882/asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o: ../Lib/Bootloader/BLD_Nvm_PIC32.c  .generated_files/flags/default/d83f851ad09c57476354e0afbbe54f771e43fc43 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o.d" -o ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o ../Lib/Bootloader/BLD_Nvm_PIC32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1245858882/Bootloader.o: ../Lib/Bootloader/Bootloader.c  .generated_files/flags/default/a3dbd991926654ddcee9f1f7653116a8d9a11f23 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/Bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/Bootloader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/Bootloader.o.d" -o ${OBJECTDIR}/_ext/1245858882/Bootloader.o ../Lib/Bootloader/Bootloader.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1245858882/HexParsing.o: ../Lib/Bootloader/HexParsing.c  .generated_files/flags/default/f47a55b8295b1ee939543d84ef77757869371e97 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/HexParsing.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/HexParsing.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/HexParsing.o.d" -o ${OBJECTDIR}/_ext/1245858882/HexParsing.o ../Lib/Bootloader/HexParsing.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/memory/flash.o: mcc_generated_files/memory/flash.c  .generated_files/flags/default/39cec1fc034c63eecd85f174c909f5b91179ca43 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/memory" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory/flash.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory/flash.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/memory/flash.o.d" -o ${OBJECTDIR}/mcc_generated_files/memory/flash.o mcc_generated_files/memory/flash.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/942f11fffb433840267a24ef67c20206773b6aff .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/5860c1b989e6a76d455c48cc885d42a5e528e63c .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/uart3.o: mcc_generated_files/uart3.c  .generated_files/flags/default/3a76c2bc1b99cd80d749b53c5274ae07389d49c3 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart3.o.d" -o ${OBJECTDIR}/mcc_generated_files/uart3.o mcc_generated_files/uart3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/9a33a65361a4762c84a361b12cf001314dfc4407 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/fc9a44bd95fb0683f4b43ff2b733dfd783da8ecb .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/4d6f7b8250101685960748d397d3c57604d0d92d .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/12a27236a18eb003165e04e6720a4b93928e6815 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o: ../Lib/Bootloader/BLD_Nvm_PIC32.c  .generated_files/flags/default/5a43b700abbe1ceaa0fad91205f4357e5c45d091 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o.d" -o ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o ../Lib/Bootloader/BLD_Nvm_PIC32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1245858882/Bootloader.o: ../Lib/Bootloader/Bootloader.c  .generated_files/flags/default/8ad94ae3abf3c42b0aaea8020d5dce61dae6e2da .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/Bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/Bootloader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/Bootloader.o.d" -o ${OBJECTDIR}/_ext/1245858882/Bootloader.o ../Lib/Bootloader/Bootloader.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1245858882/HexParsing.o: ../Lib/Bootloader/HexParsing.c  .generated_files/flags/default/80333bee0669ff48bb0ab1051ce2ec077631a3ad .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/HexParsing.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/HexParsing.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/HexParsing.o.d" -o ${OBJECTDIR}/_ext/1245858882/HexParsing.o ../Lib/Bootloader/HexParsing.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/memory/flash.o: mcc_generated_files/memory/flash.c  .generated_files/flags/default/414d3b482da86ee768ad7b441e5d3f6f65347fa9 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/memory" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory/flash.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory/flash.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/memory/flash.o.d" -o ${OBJECTDIR}/mcc_generated_files/memory/flash.o mcc_generated_files/memory/flash.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/f6c9d54add65204f75adddf6074bae89c15e8890 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/b63d610248cd8bd57cbb5d83a30eed59f7840b54 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/uart3.o: mcc_generated_files/uart3.c  .generated_files/flags/default/5942b5c69a2067191c717c401f43cbc6cfd0b9ce .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart3.o.d" -o ${OBJECTDIR}/mcc_generated_files/uart3.o mcc_generated_files/uart3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/da7355bd4bea887522edbc731df2b65be4ea644c .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/cceee6acc3c3fb0bfcd3ead2c9832acc4217e54f .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/2b171f4134c5f1887f2e551d1fa7e4eaaeb8a1f9 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/1f29d405f6c533050bb44802adc2c28d0775c5c0 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/M256M64_BLD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../Lib/Bootloader/Linker/p32MM0256GPM064/Boot.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_ICD4=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/M256M64_BLD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC016FF -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_ICD4=1,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/M256M64_BLD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../Lib/Bootloader/Linker/p32MM0256GPM064/Boot.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/M256M64_BLD.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/M256M64_BLD.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
	@echo Normalizing hex file
	@"C:/Program Files/Microchip/MPLABX/v5.50/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v5.50/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" dist/${CND_CONF}/${IMAGE_TYPE}/M256M64_BLD.X.${IMAGE_TYPE}.hex -odist/${CND_CONF}/${IMAGE_TYPE}/M256M64_BLD.X.${IMAGE_TYPE}.hex

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
