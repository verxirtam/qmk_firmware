#!/bin/bash

rm -r ~/tools/qmk_firmware/keyboards/fortitude60/keymaps/verxirtam/*

cp -p ./* ~/tools/qmk_firmware/keyboards/fortitude60/keymaps/verxirtam/



cd ~/tools/qmk_firmware

make clean

make fortitude60/rev1:verxirtam

#make に失敗した場合は終了する
if [ $? != 0 ]; then
	exit 1
fi

#NASをマウント
~/NAS_mount.sh

#hexのコピー
cp ~/tools/qmk_firmware/fortitude60_rev1_verxirtam.hex /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/
ls -l /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/fortitude60_rev1_verxirtam.hex

#ソースのコピー
cp -r ~/tools/qmk_firmware/keyboards/fortitude60/keymaps/verxirtam /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/fortitude60/keymaps/verxirtam
ls -lR /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/fortitude60/keymaps/verxirtam


