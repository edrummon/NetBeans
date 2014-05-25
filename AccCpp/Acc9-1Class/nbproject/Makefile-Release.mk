#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin_4.x-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/445265968/StudentPF.o \
	${OBJECTDIR}/_ext/445265968/Student_info.o \
	${OBJECTDIR}/grade.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/median.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acc9-1class.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acc9-1class.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acc9-1class ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/445265968/StudentPF.o: /cygdrive/C/Users/Instinct212/Documents/NetBeansProjects/AccCpp/Acc9-1Class/StudentPF.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/445265968
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/445265968/StudentPF.o /cygdrive/C/Users/Instinct212/Documents/NetBeansProjects/AccCpp/Acc9-1Class/StudentPF.cpp

${OBJECTDIR}/_ext/445265968/Student_info.o: /cygdrive/C/Users/Instinct212/Documents/NetBeansProjects/AccCpp/Acc9-1Class/Student_info.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/445265968
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/445265968/Student_info.o /cygdrive/C/Users/Instinct212/Documents/NetBeansProjects/AccCpp/Acc9-1Class/Student_info.cpp

${OBJECTDIR}/grade.o: grade.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/grade.o grade.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/median.o: median.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/median.o median.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acc9-1class.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
