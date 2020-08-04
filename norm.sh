clear
echo "== Made by mburl ==="
echo "=== Welcome to script that checks for norm errors ==="
echo
echo "Files/Folders that will be checked"
ls
echo
ans="*"
global_bool=0
echo "Show all files in folder that didn't pass the norm?(y/n)
\033[33m(It will be slower if there are a lot of files)\033[0m"
read showing
for file in $ans
do
	if ! norminette $file | grep "Error" > /dev/null ; then
		echo $file "\033[32mV\033[0m"
	else
		echo $file "\033[31mX\033[0m"
		case "$ans" in
				"y"|"Y"|"Yes"|"yes")
						norminette $file
						;;
				"n"|"N"|"no"|"No")
						;;
		esac
		global_bool=1
	fi
	echo "------------------------"
done
if [ $global_bool -eq 1 ]; then
	echo "\033[31m== DONE Errors found ==\033[0m"
else
	echo "\033[32m== DONE No errors found ==\033[0m"
fi
