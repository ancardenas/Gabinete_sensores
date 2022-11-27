# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/anami/esp/esp-idf/components/bootloader/subproject"
  "C:/Users/anami/OneDrive/Documentos/GitHub/Gabinete_sensores/coding/sample_project/build/bootloader"
  "C:/Users/anami/OneDrive/Documentos/GitHub/Gabinete_sensores/coding/sample_project/build/bootloader-prefix"
  "C:/Users/anami/OneDrive/Documentos/GitHub/Gabinete_sensores/coding/sample_project/build/bootloader-prefix/tmp"
  "C:/Users/anami/OneDrive/Documentos/GitHub/Gabinete_sensores/coding/sample_project/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/anami/OneDrive/Documentos/GitHub/Gabinete_sensores/coding/sample_project/build/bootloader-prefix/src"
  "C:/Users/anami/OneDrive/Documentos/GitHub/Gabinete_sensores/coding/sample_project/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/anami/OneDrive/Documentos/GitHub/Gabinete_sensores/coding/sample_project/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/anami/OneDrive/Documentos/GitHub/Gabinete_sensores/coding/sample_project/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
