# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/juanj/esp/esp-idf/components/bootloader/subproject"
  "C:/Users/juanj/OneDrive/Desktop/ESP32/ejemplos/lm393/build/bootloader"
  "C:/Users/juanj/OneDrive/Desktop/ESP32/ejemplos/lm393/build/bootloader-prefix"
  "C:/Users/juanj/OneDrive/Desktop/ESP32/ejemplos/lm393/build/bootloader-prefix/tmp"
  "C:/Users/juanj/OneDrive/Desktop/ESP32/ejemplos/lm393/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/juanj/OneDrive/Desktop/ESP32/ejemplos/lm393/build/bootloader-prefix/src"
  "C:/Users/juanj/OneDrive/Desktop/ESP32/ejemplos/lm393/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/juanj/OneDrive/Desktop/ESP32/ejemplos/lm393/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
