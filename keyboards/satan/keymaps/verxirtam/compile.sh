#!/bin/bash

rm -r ~/tools/qmk_firmware/keyboards/satan/keymaps/verxirtam/*

cp -p ./* ~/tools/qmk_firmware/keyboards/satan/keymaps/verxirtam



cd ~/tools/qmk_firmware

make clean

make satan:verxirtam

#make に失敗した場合は終了する
if [ $? != 0 ]; then
	exit 1
fi

#NASをマウント
~/NAS_mount.sh

#hexのコピー
cp ~/tools/qmk_firmware/satan_verxirtam.hex /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/satan_verxirtam.hex
ls -l /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/satan_verxirtam.hex

#ソースのコピー
cp -r ~/tools/qmk_firmware/keyboards/satan/keymaps/verxirtam /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/satan/keymaps/
ls -lR /mnt/LS-VL6D2/daisuke/documents/keyboad/qmk_firmware/satan/keymaps/

