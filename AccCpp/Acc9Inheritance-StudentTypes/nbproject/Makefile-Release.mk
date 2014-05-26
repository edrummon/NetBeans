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
	${OBJECTDIR}/_ext/1831566107/Student.o \
	${OBJECTDIR}/_ext/1831566107/grade.o \
	${OBJECTDIR}/_ext/1831566107/median.o \
	${OBJECTDIR}/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acc9inheritance-studenttypes.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acc9inheritance-studenttypes.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acc9inheritance-studenttypes ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1831566107/Student.o: /cygdrive/C/Users/Instinct212/Documents/NetBeansProjects/AccCpp/Acc9Inheritance-StudentTypes/Student.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1831566107
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1831566107/Student.o /cygdrive/C/Users/Instinct212/Documents/NetBeansProjects/AccCpp/Acc9Inheritance-StudentTypes/Student.cpp

${OBJECTDIR}/_ext/1831566107/grade.o: /cygdrive/C/Users/Instinct212/Documents/NetBeansProjects/AccCpp/Acc9Inheritance-StudentTypes/grade.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1831566107
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1831566107/grade.o /cygdrive/C/Users/Instinct212/Documents/NetBeansProjects/AccCpp/Acc9Inheritance-StudentTypes/grade.cpp

${OBJECTDIR}/_ext/1831566107/median.o: /cygdrive/C/Users/Instinct212/Documents/NetBeansProjects/AccCpp/Acc9Inheritance-StudentTypes/median.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1831566107
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1831566107/median.o /cygdrive/C/Users/Instinct212/Documents/NetBeansProjects/AccCpp/Acc9Inheritance-StudentTypes/median.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/acc9inheritance-studenttypes.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
