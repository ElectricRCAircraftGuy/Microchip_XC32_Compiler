# Copyright (c) 2011, 2012, ARM Limited
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
#     * Redistributions of source code must retain the above copyright notice,
#       this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of ARM nor the names of its contributors may be used
#       to endorse or promote products derived from this software without
#       specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

set -x
usage ()
{
  echo "Usage: $0 --package=... --release_ver= [--date=...]" >&2
  echo "example:" >&2
  echo "$0  --package=../install-mingw --release_ver=2011q4 --date=20111208" >&2
  exit 1
}

if [ $# -ne 2 ] && [ $# -ne 3 ] ; then
    usage
fi

for ac_arg ; do
        case $ac_arg in
                --package=*)
                  package_dir=`echo $ac_arg|sed "s/--package=//"`
                  ;;
                --release_ver=*)
                  release_ver=`echo $ac_arg|sed "s/--release_ver=//"`
                  ;;
                --date=*)
                  date_info=`echo $ac_arg|sed "s/--date=//"`
                  ;;
                *)
                  # Error on other options
                  usage
                  ;;
        esac
done

CUR_DIR=`dirname $0`

if [ ! -d $package_dir ]; then
	echo "Please provide correct source package dir!"
	exit 1
fi

if [ "x$date_info" == "x" ] ; then
    date_info=`date +%Y%m%d`
fi
release_year=${release_ver:0:4}

PKG_DIR=`readlink -f $package_dir`

GCC_VER=`find $PKG_DIR/bin -name arm-none-eabi-gcc-[4-9]\*.exe | sed -e 's/.*arm-none-eabi-gcc-\(.*\)\.exe/\1/'`
GCC_VER=`echo $GCC_VER | cut -d'.' -f1,2`
GCC_VER_NAME=`echo $GCC_VER | sed -e 's/\./_/g'`

cp $CUR_DIR/gccvar.bat $PKG_DIR/bin

app_name_str="GNU Tools for ARM Embedded Processors"
app_name="$app_name_str $GCC_VER $release_ver"
# Add "-win32" in pacakge name because we support mac/linux/win32 in non-4_6 releases.
if [ "x$GCC_VER_NAME" == "x4_6" ] ; then
    package_name=gcc-arm-none-eabi-$GCC_VER_NAME-$release_ver-$date_info
else
    package_name=gcc-arm-none-eabi-$GCC_VER_NAME-$release_ver-$date_info-win32
fi
install_dir_base="GNU Tools ARM Embedded"
install_dir_ver="$GCC_VER $release_ver"

echo "installjammer -DBaseDir $PKG_DIR                   \
              -DAppName "$app_name"                      \
              -DAppNameStr "$app_name_str"               \
              -DPackageName $package_name                \
	      -DReleaseYear $release_year                \
              -DDate $date_info                          \
              -DGcc_Version $GCC_VER                     \
              -DInstallDirBase "$install_dir_base"       \
              -DInstallDirVer "$install_dir_ver"         \
              --build-for-release --build-dir build --build $CUR_DIR/arm-none-eabi-gnu-tools.mpi"
installjammer -DBaseDir $PKG_DIR                         \
              -DAppName "$app_name"                      \
              -DAppNameStr "$app_name_str"               \
              -DPackageName $package_name                \
	      -DReleaseYear $release_year                \
              -DDate $date_info                          \
              -DGcc_Version $GCC_VER                     \
              -DInstallDirBase "$install_dir_base"       \
              -DInstallDirVer "$install_dir_ver"         \
              --build-for-release --build-dir build --build $CUR_DIR/arm-none-eabi-gnu-tools.mpi

