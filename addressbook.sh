opt=1

while [ "$opt" -lt 6 ]
do

printf "1. Create address book \n2. View records \n3. Insert new record \n4. delete a record \n5. Modify a record \n6. Exit\n\n"

read opt 
case $opt in

1) 
printf "enter filename: "
read filename

if [ -e $filename ] ; then
rm $filename
fi

cont=1
printf "name\t\tnumber\t\t\taddress\n=========================\n" | 
cat>> $filename

while [ "$cont" -gt 0 ]
do

printf "\nenter name: "
read name

printf "enter phone number of $name : "
read number

printf "enter address of $name : "
read address

printf "$name\t$number\t\t$address\n" | cat >> $filename
printf "enter 0 to stop, 1 to enter next : " 
read cont
done
echo " record created successfully";;

2)
cat $filename;;

3)
printf "\nenter name: "
read name
printf "enter phone number of $name : " 
read number

printf "enter address of $name : "
read address

printf "$name\t$number\t\t$address\n" | cat >> $filename 
echo " record inserted successfully";; 

4)
printf "delete record\nenter name/phone number : "
read pattern

temp="temp"
grep -v $pattern $filename | cat >> $temp
rm $filename
cat $temp | cat >> $filename
rm $temp 
echo " record deleted successfully";;

5)
printf "modify record\nenter name/phone number : "
read pattern
temp="temp"

grep -v $pattern $filename | cat >> $temp
rm $filename

cat $temp | cat >> $filename
rm $temp

printf "enter new name : "
read name

printf "enter new phone number of $name : "
read number

printf "enter new address of $name : "
read address

echo -e "$name\t$number\t\t$address\n : " | cat >> $filename

echo "record modified successfully";;
esac
done


