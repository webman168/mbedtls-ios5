#!/usr/bin/env bash

SDK_PATH="$HOME/theos/sdks/iPhoneOS5.1.sdk" 

export CC="clang"
export CFLAGS="-target armv7-apple-ios5.1.0 -isysroot $SDK_PATH -miphoneos-version-min=5.1 -arch armv7 -O2 -include $(pwd)/ios5_shim.h"

# FIX: Explicitly target the Apple-compatible LLVM archiver tools from your toolchain
export AR="$HOME/theos/toolchain/linux/iphone/bin/llvm-ar"
export RANLIB="$HOME/theos/toolchain/linux/iphone/bin/llvm-ranlib"

make clean
make CFLAGS="$CFLAGS" lib
