echo ~n "Enter the year to check"
read yr 
c=`expr $yr%4`

if[$c -eq 0]
then 
  echo ~n "leap Year"
else
  echo ~n "Not leap Year"
fi 