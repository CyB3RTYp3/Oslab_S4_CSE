echo ~n "Enter the 3 numbers"
read a 
read b 
read c 

if[$b -gt $a]
 then 
 if[$b -gt $c]
 then 
  echo ~n "b grestest"
 else
  echo ~n "c grestest"
  fi
else
 if[$a -gt $c]
 then 
 echo ~n "a greatest"
 else
 echo ~n "c greatest"
 fi
fi