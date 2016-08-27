#!/bin/sh

#  PackTextures.sh
#  Timbercat
#
#  Created by jam on 7/17/14.
#

TP="/usr/local/bin/TexturePacker"
#  cd ${PROJECT_DIR}/${PROJECT}
//cd ${../Resources/}
#  cd ${PROJECT_DIR}

if [ "${ACTION}" = "clean" ]; then
echo "cleaning..."

rm -f ../Resources/iPadHD/Atlases/Main.png
rm -f ../Resources/iPadHD/Atlases/Main.plist
rm -f ../Resources/iPadPro/Atlases/Main.png
rm -f ../Resources/iPadPro/Atlases/Main.plist

# ....
# add all files to be removed in clean phase
# ....
else
#ensure the file exists
if [ -f "${TP}" ]; then
echo "building texture sheets..."
# create assets

${TP} --smart-update ../Resources/rawGraphics/iPadHD/texturePackerProjects/graphics.tps
${TP} --smart-update ../Resources/rawGraphics/iPadPro/texturePackerProjects/graphics.tps

# ....
# add other sheets to create here
# ....

exit 0
else
#if here the TexturePacker command line file could not be found
echo "TexturePacker tool not installed in ${TP}"
echo "skipping requested operation."
exit 1
fi

fi
exit 0

