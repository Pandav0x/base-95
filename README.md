# Base95
Just a C structure and functions to simplify brute-force.
(Contrary to what github says, there are Objective-C in this project)

## Base95.h
The header of the structure and its function.
Include just this file in your project.

##Base95 type
Values:
*possible_values: Alphabet of all the possible values. (char [95])
*value: Inverted value of the password, used for the +1 operation. (char [41])
*value_r: Normal value of the password (from left to right). Base95.value will not be affected if modified. (char [41])

Function:
*Base95_init(Base95*): Initialize the structure, needed before using other functions. (void)
*void Base95_setValue(Base95*, char[40]): WIP (void)
*void Base95_plusOne(Base95*): Make the operation +1 on the Base95.value (next char or next ten) (void)
*void Base95_dispValue(Base95*): Display the value Base95.value_r (void)
*void Base95_invertValue(Base95*): Used in other functions to return Base95.value and set it to Base95.value_r (void)
