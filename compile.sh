#!/bin/bash

cd `dirname $0`

make satan:verxirtam

make preonic:verxirtam

make fortitude60/rev1:verxirtam

make ergodash/rev2:verxirtam

make namecard2x4:verxirtam

cp *.hex /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/

ls -ltr /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/*.hex


