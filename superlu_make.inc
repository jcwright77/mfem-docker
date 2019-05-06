############################################################################
#
#  Program:         SuperLU_DIST
#
#  Module:          make.inc
#
#  Purpose:         Top-level Definitions
#
#  Creation date:   March 1, 2016	version 5.0.0
#
#  Modified:	    
#		    
#
############################################################################
#
#  The name of the libraries to be created/linked to
#
VERSION		= 5.1.0
SuperLUroot	= ${HOME}/src/SuperLU_DIST_${VERSION}
#DSUPERLULIB   	= $(SuperLUroot)/lib/libsuperlu_dist.a
DSUPERLULIB   	= ${HOME}/lib/libsuperlu_dist.a

# BLASDEF 	= -DUSE_VENDOR_BLAS

PARMETIS_DIR	:= ${HOME}/
I_PARMETIS := -I${PARMETIS_DIR}/include -I${HOME}/include
METISLIB := -L${PARMETIS_DIR}/lib -lmetis
PARMETISLIB := -L${PARMETIS_DIR} -lparmetis

LIBS		= $(DSUPERLULIB) /usr/lib/libblas.so  \
		${PARMETISLIB} ${METISLIB}

#
#  The archiver and the flag(s) to use when building archive (library)
#  If your system has no ranlib, set RANLIB = echo.
#
ARCH         = /usr/bin/ar
ARCHFLAGS    = cr
RANLIB       = /usr/bin/ranlib

CC           = /usr/bin/mpicc
CFLAGS 	     = -DNDEBUG  -DAdd_ -DDEBUGlevel=0 -DPRNTlevel=0 -std=c99 -fPIC -g ${I_PARMETIS} 
# CFLAGS       += -D
# CFLAGS       +=  
NOOPTS       = -O0
FORTRAN	     = /usr/bin/gfortran

LOADER       = $(CC)
LOADOPTS     = -Wl,-rpath=/home/user/src/lib -g # -Wl,-Bdynamic
