#!/bin/sh
# $1: Template class name
# $2: Extension
# $3: Template file name
# $4: Class name
# $5: Package name

TemplateClassName=$1
Ext=$2
TemplateFileName=$3
ClassName=$4
PackageName=$5
UpperTemplateClassName=`echo "${TemplateClassName}" | tr '[:lower:]' '[:upper:]'`
UpperTemplateFileName=`echo "${TemplateFileName}" | tr '[:lower:]' '[:upper:]'`
UpperClassName=`echo "${ClassName}" | tr '[:lower:]' '[:upper:]'`

if test    ! -d "src/${PackageName}" \
	-o ! -d "test/${PackageName}" \
	-o ! -d "include/${PackageName}"; then
	echo "Package \"${PackageName}\" directory is missing..."
	exit 1
fi

CopyTemplate() {
	if test -e "$2/$3"; then
		echo "\"$2/$3\" is exists. skip..."
	else
		if test -e "${TemplateDir}/${TemplateFileName}/$1"; then
			cp "${TemplateDir}/${TemplateFileName}/$1" "$2/$3"
			echo "Renaming class $2/$3"
			sed -i -e "s/${TemplateClassName}/${ClassName}/g" \
			       -e "s/${TemplateFileName}/${ClassName}/g" \
			       -e "s/${UpperTemplateClassName}/${UpperClassName}/g" \
			       -e "s/${UpperTemplateFileName}/${UpperClassName}/g" \
			       -e "s/PackageName/${PackageName}/g" \
			       $2/$3
		fi
	fi
}


echo "Copy template..."
CopyTemplate ${TemplateFileName}.${Ext} src/${PackageName} ${ClassName}.${Ext}
CopyTemplate ${TemplateFileName}.protected.h src/${PackageName} ${ClassName}.protected.h
CopyTemplate ${TemplateFileName}.h include/${PackageName} ${ClassName}.h
CopyTemplate ${TemplateFileName}Test.cpp test/${PackageName} ${ClassName}Test.cpp

echo "Done."
cd ${OriginDir}
