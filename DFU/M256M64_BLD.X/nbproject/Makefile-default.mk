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
ProjectDir="F:\Git\SAMPI\Ex\DFU\M256M64_BLD.X"
ProjectName=BLD
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
${OBJECTDIR}/_ext/1245858882/asm.o: ../Lib/Bootloader/asm.S  .generated_files/flags/default/ecad8843daad87f84e25dda9d48e056507e5f5ec .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/asm.o 
	@${RM} ${OBJECTDIR}/_ext/1245858882/asm.o.ok ${OBJECTDIR}/_ext/1245858882/asm.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1245858882/asm.o.d"  -o ${OBJECTDIR}/_ext/1245858882/asm.o ../Lib/Bootloader/asm.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1245858882/asm.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD4=1 -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1245858882/asm.o.d" "${OBJECTDIR}/_ext/1245858882/asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1245858882/asm.o: ../Lib/Bootloader/asm.S  .generated_files/flags/default/e8acb8d33bac64df88ab7a106d6cc0f6fdec183b .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
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
${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o: ../Lib/Bootloader/BLD_Nvm_PIC32.c  .generated_files/flags/default/483e0185497a3cc0053197a1e5a171b405105abf .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o.d" -o ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o ../Lib/Bootloader/BLD_Nvm_PIC32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1245858882/Bootloader.o: ../Lib/Bootloader/Bootloader.c  .generated_files/flags/default/205769d746e0250ac79cd9aa8efe13f8b71cb45a .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/Bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/Bootloader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/Bootloader.o.d" -o ${OBJECTDIR}/_ext/1245858882/Bootloader.o ../Lib/Bootloader/Bootloader.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1245858882/HexParsing.o: ../Lib/Bootloader/HexParsing.c  .generated_files/flags/default/a10f141064e60a8daac575f127e7686480e7f9ff .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/HexParsing.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/HexParsing.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/HexParsing.o.d" -o ${OBJECTDIR}/_ext/1245858882/HexParsing.o ../Lib/Bootloader/HexParsing.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/memory/flash.o: mcc_generated_files/memory/flash.c  .generated_files/flags/default/7fe5ced6155beb1bce0c2e640fd79a2f5f919eeb .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/memory" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory/flash.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory/flash.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/memory/flash.o.d" -o ${OBJECTDIR}/mcc_generated_files/memory/flash.o mcc_generated_files/memory/flash.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/167c118226a917af9b5621ae900c36a63e8f9b6c .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/16704c164f4d948b94e3c8d155431ae403e7124d .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/uart3.o: mcc_generated_files/uart3.c  .generated_files/flags/default/203711a310a1bf883f4faaca205353a67015db42 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart3.o.d" -o ${OBJECTDIR}/mcc_generated_files/uart3.o mcc_generated_files/uart3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/9b8e17e38d61ac9bf83b495dfa118036cf661c5f .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/2b381501fc24f5c9c5158c3b8bea700099304a8f .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/fa22dfdebe50c8f4f1d2ebca834ce2a097bf7979 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/96d4b1e2acb941cfa7a536e45a569e25ec5d585 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o: ../Lib/Bootloader/BLD_Nvm_PIC32.c  .generated_files/flags/default/5a601df4cafd7dbcb20d44b6b63db1e2ba621619 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o.d" -o ${OBJECTDIR}/_ext/1245858882/BLD_Nvm_PIC32.o ../Lib/Bootloader/BLD_Nvm_PIC32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1245858882/Bootloader.o: ../Lib/Bootloader/Bootloader.c  .generated_files/flags/default/f78f472bee9a4d0808b625dcb8b02e7f15d97803 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/Bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/Bootloader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/Bootloader.o.d" -o ${OBJECTDIR}/_ext/1245858882/Bootloader.o ../Lib/Bootloader/Bootloader.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1245858882/HexParsing.o: ../Lib/Bootloader/HexParsing.c  .generated_files/flags/default/911b48737a2e6e7f7818d375b24f8877e0b8fb55 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/_ext/1245858882" 
	@${RM} ${OBJECTDIR}/_ext/1245858882/HexParsing.o.d 
	@${RM} ${OBJECTDIR}/_ext/1245858882/HexParsing.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1245858882/HexParsing.o.d" -o ${OBJECTDIR}/_ext/1245858882/HexParsing.o ../Lib/Bootloader/HexParsing.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/memory/flash.o: mcc_generated_files/memory/flash.c  .generated_files/flags/default/72d6af3af471150a3949a3498c4c9304fb25a4b5 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/memory" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory/flash.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory/flash.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/memory/flash.o.d" -o ${OBJECTDIR}/mcc_generated_files/memory/flash.o mcc_generated_files/memory/flash.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/62101823df97686248b524700c0889c08c4544e4 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/default/1afa616b1c52672b0279a148b4d95f2f0a3bea4f .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/uart3.o: mcc_generated_files/uart3.c  .generated_files/flags/default/f43b8bab32c70f6ee0292e08b41134ef8be6b480 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart3.o.d" -o ${OBJECTDIR}/mcc_generated_files/uart3.o mcc_generated_files/uart3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/8601e06e089d891390485ea20c1e17702a93c28a .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/default/c91f8ab1861449ebceb888df5f266f6c9f2939c6 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/default/9de799cb76a7881e48ee8f53b7d5aeb7f71f40ac .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"usr" -I"cfg" -I"mcc_generated_files" -I"../Lib" -ffunction-sections -fdata-sections -O2 -fno-common -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/bba021bcb201d0c77d9ed3ff878d26d7b2468951 .generated_files/flags/default/5ef9415e1d36cc844a9a54db0dd68d3a003c2aef
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
