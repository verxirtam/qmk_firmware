#!/bin/bash

cd `dirname $0`

make satan:verxirtam

make preonic/rev2:verxirtam

make fortitude60/rev1:verxirtam

make ergodash/rev2:verxirtam

make namecard2x4:verxirtam

make preonic/rev3:verxirtam

make crkbd:verxirtam

make runner3680/5x8:verxirtam
make runner3680/5x8:verxirtam_jp

cp *.hex /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/

ls -ltr /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/*.hex


