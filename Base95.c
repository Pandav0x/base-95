#include "base95.h"

void Base95_init(Base95 *tmp)
{
	int i = 0;
	tmp->possible_values[BASE95_PV_SIZE] = '\0';
	for (; i < BASE95_ALPHA_SIZE; i++)
		tmp->possible_values[i] = (char)i + 32;
	i = 0;
	for (; i < BASE95_PV_SIZE; i++)
		tmp->value[i] = (char)31; //init by nothing
	Base95_invertValue(tmp);
	return;
}

void Base95_setValue(Base95 *tmp, char nw_value[BASE95_PV_SIZE])
{
	int i = 0, j = 0;
	if (charlength(nw_value) <= BASE95_PV_SIZE)
	{
		if (charlength(nw_value) < BASE95_PV_SIZE)
		{
			for (; j < (BASE95_PV_SIZE - charlength(nw_value)); j++)
				tmp->value[j] = ' ';
		}
		for (; i < charlength(nw_value); i++)
			tmp->value[i + j] = (char)nw_value[i];
	}
	else
		printf("Value must be %i digits.\n", BASE95_PV_SIZE);
	return;
}

void Base95_plusOne(Base95 *tmp)
{
	if ((int)tmp->value[BASE95_PV_SIZE - 1] % 126 == 0)
	{
		int i = BASE95_PV_SIZE - 1;
		for (; (tmp->value[i] % 126 == 0) && (i > 0); i--) {}
		if (i >= 0)
		{
			tmp->value[i] += 1;
			int j = BASE95_PV_SIZE - 1;
			for (; j != i; j--)
				tmp->value[j] = (char)32;
		}
	}
	else
		tmp->value[BASE95_PV_SIZE - 1] += 1;
	Base95_invertValue(tmp);
	return;
}

void Base95_dispValue(Base95 *tmp)
{
	printf("%s\n", *tmp->value_r);
	return;
}

void Base95_invertValue(Base95 *tmp)
{
	int i = 0;
	for (; i < BASE95_PV_SIZE; i++)
	{
		if ((int)tmp->value[BASE95_PV_SIZE - 1 - i] == 31)
			break;
		tmp->value_r[i] = tmp->value[BASE95_PV_SIZE - 1 - i];
	}
	tmp->value_r[i] = '\0';
	return;
}