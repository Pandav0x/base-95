#ifndef BASE95_H
#define BASE95_H

#define BASE95_ALPHA_SIZE 95 //Size of the alphabet (95 = all the possible characters)
#define BASE95_PV_SIZE 40 //Max length pf the password

typedef struct
{
	char possible_values[BASE95_ALPHA_SIZE]; //Alphabet of all the possible values
	char value[BASE95_PV_SIZE+1]; //Inverted value of the password, used for the +1 operation.
	char value_r[BASE95_PV_SIZE+1]; //Normal value of the password (from left to right). Base95.value will not be affected if modified.
} Base95;

void Base95_init(Base95 *tmp);

void Base95_setValue(Base95 *tmp, char nw_value[BASE95_PV_SIZE]);

void Base95_plusOne(Base95 *tmp);

void Base95_dispValue(Base95 *tmp);

void Base95_invertValue(Base95 *tmp);

#endif
