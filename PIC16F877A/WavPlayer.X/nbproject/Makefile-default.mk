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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=main.c FAT_Lib.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/FAT_Lib.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/FAT_Lib.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/FAT_Lib.o

# Source Files
SOURCEFILES=main.c FAT_Lib.c



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
ProjectDir="F:\Git\SAMPI\Examples\Ex_MCU8\PIC16F877A\WavPlayer.X"
ProjectName=WavPlayer
ConfName=default
ImagePath="${DISTDIR}\WavPlayer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="${DISTDIR}"
ImageName="WavPlayer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [copy ${ImagePath} ".\main.${OUTPUT_SUFFIX}"]"
	@copy ${ImagePath} ".\main.${OUTPUT_SUFFIX}"
	@echo "--------------------------------------"

MP_CC="C:\Program Files (x86)\PICC\CCSCON.exe"
MP_LD="C:\Program Files (x86)\PICC\CCSCON.exe"
sourceline.device=sourceline="\#device PIC16F877A"
sourceline.xccompat=sourceline="\#device ANSI" sourceline="\#device PASS_STRINGS=IN_RAM" sourceline="\#device CONST=READ_ONLY" sourceline="\#case" sourceline="\#TYPE SIGNED" sourceline="\#type INT=16, LONG=32"
sourceline.gcccompat=sourceline="\#device ANSI" sourceline="\#device PASS_STRINGS=IN_RAM" sourceline="\#device CONST=READ_ONLY" sourceline="\#case" sourceline="\#TYPE SIGNED"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk 
	${MKDIR} ${OBJECTDIR} 
ifeq (2,1) 
	${MKDIR} ${DISTDIR} 
	${MP_CC}  out="${OBJECTDIR}"  main.c +FM +EX +DF +CC #__DEBUG=1 +ICD +Y=9 +EA ${sourceline.device} +DF +LN +T +A +M +J +Z -P #__16F877A=1 
	@mv ${OBJECTDIR}/main.cof "${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.cof" 
	@mv ${OBJECTDIR}/main.hex "${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.hex"
else 
	${MP_CC}  out=""${OBJECTDIR}"" main.c +EXPORT +FM +EX +DF +CC #__DEBUG=1 +ICD +Y=9 +EA ${sourceline.device} +DF +LN +T +A +M +J +Z -P #__16F877A=1 +EXPORTD="${OBJECTDIR}"  
	
endif 
	
${OBJECTDIR}/FAT_Lib.o: FAT_Lib.c  nbproject/Makefile-${CND_CONF}.mk 
	${MKDIR} ${OBJECTDIR} 
ifeq (2,1) 
	${MKDIR} ${DISTDIR} 
	${MP_CC}  out="${OBJECTDIR}"  FAT_Lib.c +FM +EX +DF +CC #__DEBUG=1 +ICD +Y=9 +EA ${sourceline.device} +DF +LN +T +A +M +J +Z -P #__16F877A=1 
	@mv ${OBJECTDIR}/FAT_Lib.cof "${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.cof" 
	@mv ${OBJECTDIR}/FAT_Lib.hex "${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.hex"
else 
	${MP_CC}  out=""${OBJECTDIR}"" FAT_Lib.c +EXPORT +FM +EX +DF +CC #__DEBUG=1 +ICD +Y=9 +EA ${sourceline.device} +DF +LN +T +A +M +J +Z -P #__16F877A=1 +EXPORTD="${OBJECTDIR}"  
	
endif 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk 
	${MKDIR} ${OBJECTDIR} 
ifeq (2,1) 
	${MKDIR} ${DISTDIR} 
	${MP_CC}  out="${OBJECTDIR}"  main.c +FM +EX +DF +CC +Y=9 +EA ${sourceline.device} +DF +LN +T +A +M +J +Z -P #__16F877A=1 
	@mv ${OBJECTDIR}/main.cof "${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.cof" 
	@mv ${OBJECTDIR}/main.hex "${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.hex"
else 
	${MP_CC}  out=""${OBJECTDIR}"" main.c +EXPORT +FM +EX +DF +CC +Y=9 +EA ${sourceline.device} +DF +LN +T +A +M +J +Z -P #__16F877A=1 +EXPORTD="${OBJECTDIR}"  
	
endif 
	
${OBJECTDIR}/FAT_Lib.o: FAT_Lib.c  nbproject/Makefile-${CND_CONF}.mk 
	${MKDIR} ${OBJECTDIR} 
ifeq (2,1) 
	${MKDIR} ${DISTDIR} 
	${MP_CC}  out="${OBJECTDIR}"  FAT_Lib.c +FM +EX +DF +CC +Y=9 +EA ${sourceline.device} +DF +LN +T +A +M +J +Z -P #__16F877A=1 
	@mv ${OBJECTDIR}/FAT_Lib.cof "${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.cof" 
	@mv ${OBJECTDIR}/FAT_Lib.hex "${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.hex"
else 
	${MP_CC}  out=""${OBJECTDIR}"" FAT_Lib.c +EXPORT +FM +EX +DF +CC +Y=9 +EA ${sourceline.device} +DF +LN +T +A +M +J +Z -P #__16F877A=1 +EXPORTD="${OBJECTDIR}"  
	
endif 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	${MKDIR} ${DISTDIR} 
ifeq (2,1) 
	
else 
	${MP_LD}   out="${DISTDIR}"  +FM +EX +DF +CC LINK=WavPlayer.X.${IMAGE_TYPE}.hex=${OBJECTDIR}/main.o,${OBJECTDIR}/FAT_Lib.o +Y=9 +EA ${sourceline.device} +DF +LN +T +A +M +J +Z -P
	
endif 
	
else
${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	${MKDIR} ${DISTDIR} 
ifeq (2,1) 
	
else 
	${MP_LD}   out="${DISTDIR}"  +FM +EX +DF +CC LINK=WavPlayer.X.${IMAGE_TYPE}.hex=${OBJECTDIR}/main.o,${OBJECTDIR}/FAT_Lib.o +Y=9 +EA ${sourceline.device} +DF +LN +T +A +M +J +Z -P
	
endif 
	
	@echo Normalizing hex file
	@"C:/Program Files/Microchip/MPLABX/v6.00/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v6.00/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" ${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.hex -o${DISTDIR}/WavPlayer.X.${IMAGE_TYPE}.hex

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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
