echo ~n "Enter the Temperature in Farenheit"
read f 
c=`expr\($f-32\)\*5/9`
echo ~n "Temperature in Celsius : $c"